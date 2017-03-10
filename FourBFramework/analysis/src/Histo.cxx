// Developed at ASC ANL
// S.Chekanov (ANL). chakanau@hep.anl.gov
// Feb. 2010

#include <iostream>
using namespace std;

#include<iostream>
#include"TFile.h"
#include"TH1D.h"
#include"TH2F.h"
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

// constructor
void Histo::setParameters() {
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
}

void Histo::setHistograms(string channel) {
  RootFile->cd(channel.c_str());
  map<string, vector<double>>::iterator it; 
  for(it=oneDHistogramPara.begin(); it!=oneDHistogramPara.end(); it++){
    TH1D *histTmp;//!
    histTmp = new TH1D(it->first.c_str(),it->first.c_str(),(int)it->second.at(0),it->second.at(1),it->second.at(2));
    histTmp->Sumw2();
    oneDHistograms.push_back(histTmp);
  }
  cutflow = new TH1F("cutflow","cutflow",4,0,4);
  cutflow->Sumw2();
  cutflow->GetXaxis()->SetBinLabel(1,"HLT_j380");
  cutflow->GetXaxis()->SetBinLabel(2,"Leading Jet pT > 430 GeV");
  cutflow->GetXaxis()->SetBinLabel(3,"Sub-leading Jet pT > 60 GeV");
  cutflow->GetXaxis()->SetBinLabel(4,"All jet |#eta| < 2.5");
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
