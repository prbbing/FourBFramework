//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Oct 21 18:25:56 2015 by ROOT version 6.02/12
// from TTree outTreeJET_GroupedNP_3__3down/outTreeJET_GroupedNP_3__3down
// found on file: /data3/sryu/dijet/10202015/QStar/user.soryu.mc15_13TeV.301304.Pythia8EvtGen_A14NNPDF23LO_ExcitedQ4500Lambda4500f1.All.QStar_20151019_tree.root
//////////////////////////////////////////////////////////

#ifndef analysis_h
#define analysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

using namespace std;
// Header file for the classes stored in the TTree if any.
#include <vector>
#include <map>
#include <TClonesArray.h>
#include <TLorentzVector.h>
class analysis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           runNumber;
   Int_t           eventNumber;
   Int_t           mcEventNumber;
   Int_t           mcChannelNumber;
   Float_t         mcEventWeight;
   Float_t         weight_pileup;
   Int_t           NPV;
   Float_t         actualInteractionsPerCrossing;
   Float_t         averageInteractionsPerCrossing;
   Int_t           lumiBlock;
   Double_t        rhoEM;
   Float_t         yStar;
   Float_t         yBoost;
   Float_t         mjj;
   Float_t         pTjj;
   Float_t         m3j;
   Float_t         deltaPhi;
   Float_t         Insitu_Segs_response_E;
   Float_t         Insitu_Segs_response_pT;
   Int_t           punch_type_segs;
   Float_t         pTBalance;
   Float_t         MHT;
   Float_t         MHTPhi;
   Float_t         MHTJVT;
   Float_t         MHTJVTPhi;
   Float_t         weight;
   Float_t         weight_xs;
   Float_t         weight_prescale;
   Float_t         weight_resonanceKFactor;
   Int_t           passL1;
   Int_t           passHLT;
   Int_t           masterKey;
   Int_t           lvl1PrescaleKey;
   Int_t           hltPrescaleKey;
   vector<string>  *passedTriggers;
   Float_t         metFinal;
   Float_t         metFinalPx;
   Float_t         metFinalPy;
   Float_t         metFinalSumEt;
   Float_t         metFinalPhi;
   Int_t           njets;
   vector<float>   *jet_E;
   vector<float>   *jet_pt;
   vector<float>   *jet_phi;
   vector<float>   *jet_eta;
   vector<float>   *jet_rapidity;
   vector<float>   *jet_HECFrac;
   vector<float>   *jet_EMFrac;
   vector<float>   *jet_CentroidR;
   vector<float>   *jet_FracSamplingMax;
   vector<float>   *jet_FracSamplingMaxIndex;
   vector<float>   *jet_LowEtConstituentsFrac;
   vector<float>   *jet_GhostMuonSegmentCount;
   vector<float>   *jet_Width;
   vector<float>   *jet_constitScaleEta;
   vector<float>   *jet_emScaleE;
   vector<float>   *jet_emScaleEta;
   vector<float>   *jet_emScalePhi;
   vector<float>   *jet_minDeltaR;
   vector<int>     *jet_numberCloseJets;

   // List of branches
   TBranch        *b_runNumber;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_mcEventNumber;   //!
   TBranch        *b_mcChannelNumber;   //!
   TBranch        *b_mcEventWeight;   //!
   TBranch        *b_weight_pileup;   //!
   TBranch        *b_NPV;   //!
   TBranch        *b_actualInteractionsPerCrossing;   //!
   TBranch        *b_averageInteractionsPerCrossing;   //!
   TBranch        *b_lumiBlock;   //!
   TBranch        *b_rhoEM;   //!
   TBranch        *b_yStar;   //!
   TBranch        *b_yBoost;   //!
   TBranch        *b_mjj;   //!
   TBranch        *b_pTjj;   //!
   TBranch        *b_m3j;   //!
   TBranch        *b_deltaPhi;   //!
   TBranch        *b_Insitu_Segs_response_E;   //!
   TBranch        *b_Insitu_Segs_response_pT;   //!
   TBranch        *b_punch_type_segs;   //!
   TBranch        *b_pTBalance;   //!
   TBranch        *b_MHT;   //!
   TBranch        *b_MHTPhi;   //!
   TBranch        *b_MHTJVT;   //!
   TBranch        *b_MHTJVTPhi;   //!
   TBranch        *b_weight;   //!
   TBranch        *b_weight_xs;   //!
   TBranch        *b_weight_prescale;   //!
   TBranch        *b_weight_resonanceKFactor;   //!
   TBranch        *b_passL1;   //!
   TBranch        *b_passHLT;   //!
   TBranch        *b_masterKey;   //!
   TBranch        *b_lvl1PrescaleKey;   //!
   TBranch        *b_hltPrescaleKey;   //!
   TBranch        *b_passedTriggers;   //!
   TBranch        *b_metFinal;   //!
   TBranch        *b_metFinalPx;   //!
   TBranch        *b_metFinalPy;   //!
   TBranch        *b_metFinalSumEt;   //!
   TBranch        *b_metFinalPhi;   //!
   TBranch        *b_njets;   //!
   TBranch        *b_jet_E;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_rapidity;   //!
   TBranch        *b_jet_HECFrac;   //!
   TBranch        *b_jet_EMFrac;   //!
   TBranch        *b_jet_CentroidR;   //!
   TBranch        *b_jet_FracSamplingMax;   //!
   TBranch        *b_jet_FracSamplingMaxIndex;   //!
   TBranch        *b_jet_LowEtConstituentsFrac;   //!
   TBranch        *b_jet_GhostMuonSegmentCount;   //!
   TBranch        *b_jet_Width;   //!
   TBranch        *b_jet_constitScaleEta;   //!
   TBranch        *b_jet_emScaleE;   //!
   TBranch        *b_jet_emScaleEta;   //!
   TBranch        *b_jet_emScalePhi;   //!
   TBranch        *b_jet_minDeltaR;   //!
   TBranch        *b_jet_numberCloseJets;   //!

   analysis(TTree *tree=0);
   virtual ~analysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef analysis_cxx
analysis::analysis(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/data3/sryu/dijet/10202015/QStar/user.soryu.mc15_13TeV.301304.Pythia8EvtGen_A14NNPDF23LO_ExcitedQ4500Lambda4500f1.All.QStar_20151019_tree.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/data3/sryu/dijet/10202015/QStar/user.soryu.mc15_13TeV.301304.Pythia8EvtGen_A14NNPDF23LO_ExcitedQ4500Lambda4500f1.All.QStar_20151019_tree.root");
      }
      f->GetObject("outTreeJET_GroupedNP_3__3down",tree);

   }
   Init(tree);
}

analysis::~analysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t analysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t analysis::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void analysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   passedTriggers = 0;
   jet_E = 0;
   jet_pt = 0;
   jet_phi = 0;
   jet_eta = 0;
   jet_rapidity = 0;
   jet_HECFrac = 0;
   jet_EMFrac = 0;
   jet_CentroidR = 0;
   jet_FracSamplingMax = 0;
   jet_FracSamplingMaxIndex = 0;
   jet_LowEtConstituentsFrac = 0;
   jet_GhostMuonSegmentCount = 0;
   jet_Width = 0;
   jet_constitScaleEta = 0;
   jet_emScaleE = 0;
   jet_emScaleEta = 0;
   jet_emScalePhi = 0;
   jet_minDeltaR = 0;
   jet_numberCloseJets = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("mcEventNumber", &mcEventNumber, &b_mcEventNumber);
   fChain->SetBranchAddress("mcChannelNumber", &mcChannelNumber, &b_mcChannelNumber);
   fChain->SetBranchAddress("mcEventWeight", &mcEventWeight, &b_mcEventWeight);
   fChain->SetBranchAddress("weight_pileup", &weight_pileup, &b_weight_pileup);
   fChain->SetBranchAddress("NPV", &NPV, &b_NPV);
   fChain->SetBranchAddress("actualInteractionsPerCrossing", &actualInteractionsPerCrossing, &b_actualInteractionsPerCrossing);
   fChain->SetBranchAddress("averageInteractionsPerCrossing", &averageInteractionsPerCrossing, &b_averageInteractionsPerCrossing);
   fChain->SetBranchAddress("lumiBlock", &lumiBlock, &b_lumiBlock);
   fChain->SetBranchAddress("rhoEM", &rhoEM, &b_rhoEM);
   fChain->SetBranchAddress("yStar", &yStar, &b_yStar);
   fChain->SetBranchAddress("yBoost", &yBoost, &b_yBoost);
   fChain->SetBranchAddress("mjj", &mjj, &b_mjj);
   fChain->SetBranchAddress("pTjj", &pTjj, &b_pTjj);
   fChain->SetBranchAddress("m3j", &m3j, &b_m3j);
   fChain->SetBranchAddress("deltaPhi", &deltaPhi, &b_deltaPhi);
   fChain->SetBranchAddress("Insitu_Segs_response_E", &Insitu_Segs_response_E, &b_Insitu_Segs_response_E);
   fChain->SetBranchAddress("Insitu_Segs_response_pT", &Insitu_Segs_response_pT, &b_Insitu_Segs_response_pT);
   fChain->SetBranchAddress("punch_type_segs", &punch_type_segs, &b_punch_type_segs);
   fChain->SetBranchAddress("pTBalance", &pTBalance, &b_pTBalance);
   fChain->SetBranchAddress("MHT", &MHT, &b_MHT);
   fChain->SetBranchAddress("MHTPhi", &MHTPhi, &b_MHTPhi);
   fChain->SetBranchAddress("MHTJVT", &MHTJVT, &b_MHTJVT);
   fChain->SetBranchAddress("MHTJVTPhi", &MHTJVTPhi, &b_MHTJVTPhi);
   fChain->SetBranchAddress("weight", &weight, &b_weight);
   fChain->SetBranchAddress("weight_xs", &weight_xs, &b_weight_xs);
   fChain->SetBranchAddress("weight_prescale", &weight_prescale, &b_weight_prescale);
   fChain->SetBranchAddress("weight_resonanceKFactor", &weight_resonanceKFactor, &b_weight_resonanceKFactor);
   fChain->SetBranchAddress("passL1", &passL1, &b_passL1);
   fChain->SetBranchAddress("passHLT", &passHLT, &b_passHLT);
   fChain->SetBranchAddress("masterKey", &masterKey, &b_masterKey);
   fChain->SetBranchAddress("lvl1PrescaleKey", &lvl1PrescaleKey, &b_lvl1PrescaleKey);
   fChain->SetBranchAddress("hltPrescaleKey", &hltPrescaleKey, &b_hltPrescaleKey);
   fChain->SetBranchAddress("passedTriggers", &passedTriggers, &b_passedTriggers);
   fChain->SetBranchAddress("metFinal", &metFinal, &b_metFinal);
   fChain->SetBranchAddress("metFinalPx", &metFinalPx, &b_metFinalPx);
   fChain->SetBranchAddress("metFinalPy", &metFinalPy, &b_metFinalPy);
   fChain->SetBranchAddress("metFinalSumEt", &metFinalSumEt, &b_metFinalSumEt);
   fChain->SetBranchAddress("metFinalPhi", &metFinalPhi, &b_metFinalPhi);
   fChain->SetBranchAddress("njets", &njets, &b_njets);
   fChain->SetBranchAddress("jet_E", &jet_E, &b_jet_E);
   fChain->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_rapidity", &jet_rapidity, &b_jet_rapidity);
   fChain->SetBranchAddress("jet_HECFrac", &jet_HECFrac, &b_jet_HECFrac);
   fChain->SetBranchAddress("jet_EMFrac", &jet_EMFrac, &b_jet_EMFrac);
   fChain->SetBranchAddress("jet_CentroidR", &jet_CentroidR, &b_jet_CentroidR);
   fChain->SetBranchAddress("jet_FracSamplingMax", &jet_FracSamplingMax, &b_jet_FracSamplingMax);
   fChain->SetBranchAddress("jet_FracSamplingMaxIndex", &jet_FracSamplingMaxIndex, &b_jet_FracSamplingMaxIndex);
   fChain->SetBranchAddress("jet_LowEtConstituentsFrac", &jet_LowEtConstituentsFrac, &b_jet_LowEtConstituentsFrac);
   fChain->SetBranchAddress("jet_GhostMuonSegmentCount", &jet_GhostMuonSegmentCount, &b_jet_GhostMuonSegmentCount);
   fChain->SetBranchAddress("jet_Width", &jet_Width, &b_jet_Width);
   fChain->SetBranchAddress("jet_constitScaleEta", &jet_constitScaleEta, &b_jet_constitScaleEta);
   fChain->SetBranchAddress("jet_emScaleE", &jet_emScaleE, &b_jet_emScaleE);
   fChain->SetBranchAddress("jet_emScaleEta", &jet_emScaleEta, &b_jet_emScaleEta);
   fChain->SetBranchAddress("jet_emScalePhi", &jet_emScalePhi, &b_jet_emScalePhi);
   fChain->SetBranchAddress("jet_minDeltaR", &jet_minDeltaR, &b_jet_minDeltaR);
   fChain->SetBranchAddress("jet_numberCloseJets", &jet_numberCloseJets, &b_jet_numberCloseJets);
   Notify();
}

Bool_t analysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void analysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t analysis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef analysis_cxx
