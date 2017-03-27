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

void Histo::setSkim(string output, string channel, int index, TTree *inputTree, TH1F *cutflow, TH1F *cutflowWeighted) {

    ostringstream temp;
    temp<<index;
    string nameSeg = channel+"_"+temp.str();
    string ffile="output/"+output+"_"+nameSeg+".root";
    cout << "\n -> Skim file is =" << ffile << endl;
    TFile *tmpFile = new TFile(ffile.c_str(), "RECREATE", "Skim file");
    TTree *tmpTree = inputTree->CloneTree(0);
    skimFiles.insert(pair<string, TFile*>(nameSeg,tmpFile));
    skimTrees.insert(pair<string, TTree*>(nameSeg,tmpTree));
    skimCutflows.insert(pair<string, TH1F*>(nameSeg,cutflow));
    skimCutflowsWeighted.insert(pair<string, TH1F*>(nameSeg,cutflowWeighted));
   
}

void Histo::writeTrees(string channel, int index) {
    
    ostringstream temp;
    temp<<index;
    string nameSeg = channel+"_"+temp.str();
    skimTrees[nameSeg]->Write();
    skimCutflows[nameSeg]->Write();
    skimCutflowsWeighted[nameSeg]->Write();
    delete skimTrees[nameSeg];
}

void Histo::fillCutflow(string channel) {

    cutflow->SetBinContent(cutflow->GetNbinsX(), glob.channelAcceptance[channel]);    
    cutflowWeighted->SetBinContent(cutflowWeighted->GetNbinsX(), glob.channelWeightedAcceptance[channel]);    
    
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
  oneDHistogramPara.insert(pair<string, vector<double>>("angle_12",angleBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("deltaMass_12",deltaMassBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("deltaPt_12",deltaPtBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("sumPVec_12",sumPVecBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("sumPtVec_12",sumPtVecBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("theta_12",thetaBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("mv2c10_1",mv2c10Binning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("mv2c10_2",mv2c10Binning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("sv1_1",sv1Binning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("sv1_2",sv1Binning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("ip3d_1",ip3dBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("ip3d_2",ip3dBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("truthId_1",truthIdBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("truthId_2",truthIdBinning));     
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
  oneDHistogramPara.insert(pair<string, vector<double>>("angle_34",angleBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("deltaMass_34",deltaMassBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("deltaPt_34",deltaPtBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("sumPVec_34",sumPVecBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("sumPtVec_34",sumPtVecBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("theta_34",thetaBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("mv2c10_3",mv2c10Binning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("mv2c10_4",mv2c10Binning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("sv1_3",sv1Binning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("sv1_4",sv1Binning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("ip3d_3",ip3dBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("ip3d_4",ip3dBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("truthId_3",truthIdBinning));     
  oneDHistogramPara.insert(pair<string, vector<double>>("truthId_4",truthIdBinning));     
  //2D histograms
  //Kinematic corrrelations
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("mjj_12_vs_ystar_12",{mjjBinning,yStarBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("mjj_34_vs_ystar_34",{mjjBinning,yStarBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("sumPVec_12_vs_angle_12",{sumPVecBinning,angleBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("sumPVec_34_vs_angle_34",{sumPVecBinning,angleBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("sumPVec_34_vs_angle_12",{sumPVecBinning,angleBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("sumPVec_12_vs_angle_34",{sumPVecBinning,angleBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("mjj_12_vs_mboost_12",{mjjBinning,mboostBinning}));     
  twoDHistogramPara.insert(pair<string, vector<vector<double>>>("mjj_34_vs_mboost_34",{mjjBinning,mboostBinning}));     
  //Event topologies
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

void Histo::setHistograms(string channel, TH1F *inputCutflow, TH1F *inputCutflowWeighted) {
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
  cutflow = new TH1F("cutflow","cutflow",inputCutflow->GetNbinsX()+6,0,inputCutflow->GetNbinsX()+6);
  cutflow->Sumw2();
  for (int i = 1; i < inputCutflow->GetNbinsX(); i++) {
    cutflow->GetXaxis()->SetBinLabel(i,inputCutflow->GetXaxis()->GetBinLabel(i));
    cutflow->SetBinContent(i,inputCutflow->GetBinContent(i));
    cutflow->SetBinError(i,inputCutflow->GetBinError(i));
  }
  cutflow->GetXaxis()->SetBinLabel(inputCutflow->GetNbinsX()+1,"HLT_4j25");
  cutflow->GetXaxis()->SetBinLabel(inputCutflow->GetNbinsX()+2,"Leading Jet pT > 250 GeV");
  cutflow->GetXaxis()->SetBinLabel(inputCutflow->GetNbinsX()+3,"Sub-leading Jet pT > 250 GeV");
  cutflow->GetXaxis()->SetBinLabel(inputCutflow->GetNbinsX()+4,"Third-leading Jet pT > 120 GeV");
  cutflow->GetXaxis()->SetBinLabel(inputCutflow->GetNbinsX()+5,"All jet |#eta| < 2.5");
  cutflow->GetXaxis()->SetBinLabel(inputCutflow->GetNbinsX()+6,"Pass Region Selection");
  //Setup weighted cutflow
  cutflowWeighted = new TH1F("cutflowWeighted","cutflowWeighted",inputCutflowWeighted->GetNbinsX()+6,0,inputCutflowWeighted->GetNbinsX()+6);
  cutflowWeighted->Sumw2();
  for (int i = 1; i < inputCutflowWeighted->GetNbinsX(); i++) {
    cutflowWeighted->GetXaxis()->SetBinLabel(i,inputCutflowWeighted->GetXaxis()->GetBinLabel(i));
    cutflowWeighted->SetBinContent(i,inputCutflowWeighted->GetBinContent(i));
    cutflowWeighted->SetBinError(i,inputCutflowWeighted->GetBinError(i));
  }
  cutflowWeighted->GetXaxis()->SetBinLabel(inputCutflowWeighted->GetNbinsX()+1,"HLT_4j25");
  cutflowWeighted->GetXaxis()->SetBinLabel(inputCutflowWeighted->GetNbinsX()+2,"Leading Jet pT > 250 GeV");
  cutflowWeighted->GetXaxis()->SetBinLabel(inputCutflowWeighted->GetNbinsX()+3,"Sub-leading Jet pT > 250 GeV");
  cutflowWeighted->GetXaxis()->SetBinLabel(inputCutflowWeighted->GetNbinsX()+4,"Third-leading Jet pT > 120 GeV");
  cutflowWeighted->GetXaxis()->SetBinLabel(inputCutflowWeighted->GetNbinsX()+5,"All jet |#eta| < 2.5");
  cutflowWeighted->GetXaxis()->SetBinLabel(inputCutflowWeighted->GetNbinsX()+6,"Pass Region Selection");
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
