#include<iostream>
#include<sstream>
#include<fstream>
#include<stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <TROOT.h>
#include <TTree.h>
#include <TChain.h>
#include <TFile.h>
#include <TBrowser.h>
#include <TStyle.h>
#include "TApplication.h"
#include "TObject.h"
#include "TH1.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TRandom.h"
#include "TThread.h"
#include "TSpline.h"

// analysis
#include "Ana.h"
#include "Global.h"
#include "Preselection.h"
#include "Histo.h"
using namespace std;

Global glob;
Histo  h;
Preselection  pre;


int main(int argc, char **argv)
{
  int i=1;
  if(argc < 3) {
    printf("More than two arguments are needed, aborting!\n");
    exit(0);
  }
 // report settings
 for (;i<argc;i++) printf("Argument %d:%s\n",i,argv[i]);
 char * inp = argv[1];
 string name=std::string(inp);
 cout << "Input file=" << name << endl; 
    
 vector<string> channels;
 for (i = 2;i<argc;i++){
   char * cha = argv[i];
   string channel=std::string(cha);
   channels.push_back(channel);
 }
 // get dictionary for vector
 gROOT->ProcessLine("#include <vector>");
 // initialize
 glob.getIni();
 // read list of ntuples
 glob.getNtuples(name);

 // set output and histograms
 h.setOutput(name);
 h.setParameters();
 for (int c = 0; c < (int)channels.size();c++){
   string channel = channels.at(c); 
    
   glob.nev = 0;
   const int Nfiles = glob.ntup.size();
   cout << " -> Nr of files to read:" << Nfiles << endl;
   cout << " -> Nr of events to process:" <<  glob.MaxEvents << endl;
   if (!Nfiles) break;   
   glob.channelAcceptance.insert(pair<string,float>(channel,0.0));  
   glob.channelWeightedAcceptance.insert(pair<string,float>(channel,0.0));  
 
   //Get the cutflow from ntuple
   TFile scout(glob.ntup[0].c_str());
   TH1F* cutflow = (TH1F*)scout.Get("cutflow");
   TH1F* cutflowWeighted = (TH1F*)scout.Get("cutflow_weighted");
   h.setChannel(channel);
   h.setHistograms(channel, cutflow, cutflowWeighted);
   scout.Close(); 

   for (int i = 0; i < Nfiles; i++) {
     float donefiles= (float)i / (float)Nfiles;
     cout << "\nPercentage done = " << (int)(donefiles*100) <<  " %" << endl;
     cout << "\nfile to read:" << glob.ntup[i] << endl;

     TFile f(glob.ntup[i].c_str());
     if (f.IsZombie()) continue; 

     TTree *tree = (TTree *)f.Get(glob.ttree.c_str());
     TH1F* cutflow = (TH1F*)f.Get("cutflow");
     TH1F* cutflowWeighted = (TH1F*)f.Get("cutflow_weighted");
     glob.m_run=i;

     if (glob.nev >= glob.MaxEvents) break;
        
     Ana ana(tree, channel);

     ana.Notify();
     h.setSkim(name,channel,i,tree,cutflow,cutflowWeighted);
        
     ana.Loop(channel,i);      // Loop on all entries
     
     h.writeTrees(channel,i);

     delete tree;
     f.Close();
   }
   h.fillCutflow(channel);
 }
  // write histograms
  h.finalize();
  cout << "--> Number of events requested:" <<  glob.MaxEvents  << endl;
  cout << "--> Number of events processed:" <<  glob.nev  << endl;
  cout << "--> Number of events  selected:" <<  glob.TotalEvents << endl;
  
  return 0;
}
