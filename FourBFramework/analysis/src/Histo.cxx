#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include<iostream>
#include"TFile.h"
#include"TH1D.h"
#include"TH2D.h"
#include"Histo.h"
#include<stdlib.h>

#include<TClonesArray.h>
#include <TROOT.h>
#include <TTree.h>
#include <TFile.h>
#include <TMath.h>
#include "Global.h"
#include "SystemOfUnits.h"
#include "TMultiGraph.h"
#include "TCanvas.h"

extern string floatToString(float);
extern Global glob;


// constructor
Histo::Histo() {}


// constructor
void Histo::setOutput(string output) {

    string ffile="output/"+output+".root";
    cout << "\n -> Output file is =" << ffile << endl;
    RootFile = new TFile(ffile.c_str(), "RECREATE", "Histogram file");

}

void Histo::setChannel(string channel) {

    RootFile->cd(); 
    RootFile->mkdir(channel.c_str()); 

}

void Histo::setSkim(string channel, int index, TTree *inputTree) {

    ostringstream temp;
    temp<<index;
    string nameSeg = channel+"_"+temp.str();
    string ffile="output/"+nameSeg+".root";
    cout << "\n -> Skim file is =" << ffile << endl;
    TFile *tmpFile = new TFile(ffile.c_str(), "RECREATE", "Skim file");
    TTree *tmpTree = inputTree->CloneTree(0);
    skimFiles.insert(pair<string, TFile*>(nameSeg,tmpFile));
    skimTrees.insert(pair<string, TTree*>(nameSeg,tmpTree));
   
}

void Histo::writeTrees(string channel, int index) {
    
    ostringstream temp;
    temp<<index;
    string nameSeg = channel+"_"+temp.str();
    //skimFiles[nameSeg]->cd();
    skimTrees[nameSeg]->Write();
    //skimFiles[nameSeg]->Close(); 
    delete skimTrees[nameSeg];
    //RootFile->cd();
}

// constructor
void Histo::setParameters() {
  //1st and 2nd jets
  oneDHistogramPara.insert(pair<string, vector<double>>("pt_1",pTBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("pt_2",pTBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("eta_1",etaBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("eta_2",etaBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("phi_1",phiBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("phi_2",phiBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("mjj_12",mjjBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("dphi_12",dphiBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("deta_12",detaBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("dR_12",dRBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("ystar_12",yStarBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("mboost_12",mboostBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("mv2c10_1",mv2c10Binning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("mv2c10_2",mv2c10Binning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("sv1_1",sv1Binning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("sv1_2",sv1Binning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("ip3d_1",ip3dBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("ip3d_2",ip3dBinning));     
  //3rd and 4th jets
  oneDHistogramPara.insert(pair<string, vector<double>>("pt_3",pTBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("pt_4",pTBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("eta_3",etaBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("eta_4",etaBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("phi_3",phiBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("phi_4",phiBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("mjj_34",mjjBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("dphi_34",dphiBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("deta_34",detaBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("dR_34",dRBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("ystar_34",yStarBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("mboost_34",mboostBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("mv2c10_3",mv2c10Binning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("mv2c10_4",mv2c10Binning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("sv1_3",sv1Binning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("sv1_4",sv1Binning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("ip3d_3",ip3dBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("ip3d_4",ip3dBinning));     
  //2D histograms 
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("dphi_12_vs_dphi_34",{dphiBinning,dphiBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("dphi_12_vs_dphi_14",{dphiBinning,dphiBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("dphi_12_vs_dphi_23",{dphiBinning,dphiBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("dphi_12_vs_dphi_24",{dphiBinning,dphiBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("dphi_12_vs_dphi_34",{dphiBinning,dphiBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("dphi_13_vs_dphi_14",{dphiBinning,dphiBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("dphi_13_vs_dphi_23",{dphiBinning,dphiBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("dphi_13_vs_dphi_24",{dphiBinning,dphiBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("dphi_13_vs_dphi_34",{dphiBinning,dphiBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("dphi_14_vs_dphi_23",{dphiBinning,dphiBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("dphi_14_vs_dphi_24",{dphiBinning,dphiBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("dphi_14_vs_dphi_34",{dphiBinning,dphiBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("dphi_23_vs_dphi_24",{dphiBinning,dphiBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("dphi_23_vs_dphi_34",{dphiBinning,dphiBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("dphi_34_vs_dphi_24",{dphiBinning,dphiBinning}));     
}

void Histo::setHistograms(string channel) {
  RootFile->cd(channel.c_str());
  map<string, vector<double>>::iterator it; 
  for(it=oneDHistogramPara.begin(); it!=oneDHistogramPara.end(); it++){
    TH1D *histTmp;//!
    histTmp = new TH1D(it->first.c_str(),it->first.c_str(),(int)it->second.at(0),it->second.at(1),it->second.at(2));
    histTmp->Sumw2();
    oneDHistograms[channel].push_back(histTmp);
  }
  map<string, vector<vector<double>>>::iterator itr; 
  for(itr=twoDHistogramPara.begin(); itr!=twoDHistogramPara.end(); itr++){
    TH2D *histTmp;//!
    histTmp = new TH2D(itr->first.c_str(),itr->first.c_str(),(int)itr->second.at(1)[0],itr->second.at(1)[1],itr->second.at(1)[2],(int)itr->second.at(0)[0],itr->second.at(0)[1],itr->second.at(0)[2]);
    histTmp->Sumw2();
    twoDHistograms[channel].push_back(histTmp);
  }
  cutflow = new TH1F("cutflow","cutflow",8,0,8);
  cutflow->Sumw2();
  cutflow->GetXaxis()->SetBinLabel(1,"Original Number of Events");
  cutflow->GetXaxis()->SetBinLabel(2,"Skimmed Number of Events");
  cutflow->GetXaxis()->SetBinLabel(3,"HLT_4j25");
  cutflow->GetXaxis()->SetBinLabel(4,"Leading Jet pT > 250 GeV");
  cutflow->GetXaxis()->SetBinLabel(5,"Sub-leading Jet pT > 250 GeV");
  cutflow->GetXaxis()->SetBinLabel(6,"Third-leading Jet pT > 120 GeV");
  cutflow->GetXaxis()->SetBinLabel(7,"All jet |#eta| < 2.5");
  cutflow->GetXaxis()->SetBinLabel(8,"Pass Region Selection");
}

/*
* Destructor
**/

Histo::~Histo() { }



// write histograms
void Histo::finalize() {
    RootFile->Write();
    RootFile->Close();
}
