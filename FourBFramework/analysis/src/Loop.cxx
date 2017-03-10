#include "Ana.h"
#include "Global.h"
#include "Preselection.h"
#include "SystemOfUnits.h"
#include "Histo.h"
#include "TSpline.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include <sstream>
using namespace std;

extern Global glob;
extern Preselection  pre;
extern Histo  h;

// Event loop.
void Ana::Loop(string channel)
{
   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   cout << " -> number of entries =" << nentries << endl;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t n=0; n<nentries; n++) {
      
      if (glob.nev>=glob.MaxEvents) break;

      Long64_t ientry = LoadTree(n);
      if (ientry < 0) break;
      nb = fChain->GetEntry(n);   
      nbytes += nb;

      if ((glob.nev<=10 && glob.nev<=100 && (glob.nev%10) == 0) || (glob.nev<=10000 && (glob.nev%10000) == 0) || (glob.nev>=1000000 && (glob.nev%1000000) == 0) || (glob.nev>=100000000 && (glob.nev%10000000) == 0))
        cout << "Events= " << glob.nev << endl; 

      glob.nev++;
      
      if (CutEvent(ientry) <0) continue;

      double weight=1.0;


      #if montecarlo
        weight=mcEventWeight*weight_pileup;
      #endif

      //=============================
      //get all the jets in the event
      //=============================
      vector<int> selected;
      for(int i = 0; (int)i < njets ; i++){
        if (jet_pt->at(i)<60) continue;
          selected.push_back(i);
      } // end loop over jets 
      
      if (selected.size()<=1) continue;

      vector<int> selectedSorted;
      selectedSorted = sortIndices(selected);
      
      //=================================
      //apply channel specific selections
      //=================================
      
      if (!passPreselection(selectedSorted,h.cutflow,weight)) continue;
      //=================================
      //apply channel specific selections
      //=================================
     
      if (!channelDecision(selectedSorted, channel)) continue;
      //===============
      //fill histograms
      //===============
      
      fillOneDHistogram(selectedSorted, h.oneDHistograms, weight);      
      glob.TotalEvents++;
  }//end loop over all events
}//end loop method

//retrieve values for given variables
double Ana::findValue(vector<int> indices, string var) {
  double value = 0;
  if (indices.size() == 1) {
    if (var == "pt")  value = jet_pt->at(indices.at(0));   
    if (var == "eta") value = jet_eta->at(indices.at(0));   
    if (var == "phi") value = jet_phi->at(indices.at(0));   
  }
  if (indices.size() == 2) {
    TLorentzVector j_1 = TLorentzVector(0,0,0,0);
    TLorentzVector j_2 = TLorentzVector(0,0,0,0);
    j_1.SetPtEtaPhiE(jet_pt->at(indices.at(0)),jet_eta->at(indices.at(0)),jet_phi->at(indices.at(0)),jet_E->at(indices.at(0)));
    j_2.SetPtEtaPhiE(jet_pt->at(indices.at(1)),jet_eta->at(indices.at(1)),jet_phi->at(indices.at(1)),jet_E->at(indices.at(1)));
    if (var == "mjj")  value = (j_1 + j_2).M();
    if (var == "dphi") value = j_1.DeltaPhi(j_2);
    if (var == "dR")   value = j_1.DeltaR(j_2);
    if (var == "deta") value = abs(j_1.Eta() - j_2.Eta()); 
    if (var == "ystar") value = (j_1.Rapidity() - j_2.Rapidity())/2; 
  }
  return value; 
}

//Split a string by a given staing, used to decode the histogram names
vector<string>
Ana::getStringSegments(string input, char delim)
{
  vector<string> elems;
  stringstream ss(input);
  string item;
  while (getline(ss, item, delim)) {
      elems.push_back(item);
  }
  return elems;
} 

//Fill one D histograms
void
Ana::fillOneDHistogram(vector<int> indices, vector<TH1D*> hists, double weight){
  for (int i = 0; i < (int)hists.size(); i++){
    string name = hists.at(i)->GetName();
    string variable = getStringSegments(name,'_').at(0);
    int objIndex = atoi(getStringSegments(name,'_').at(1).c_str());
    vector<int> filteredIndices = {};
    if (objIndex < 10) filteredIndices.push_back(indices.at(objIndex - 1));
    if (objIndex > 10) {
      filteredIndices.push_back(indices.at((int)(objIndex/10) - 1));
      filteredIndices.push_back(indices.at(objIndex - 10*(int)(objIndex/10) - 1));
    }
    hists.at(i)->Fill(findValue(filteredIndices, variable), weight);
  }
}


//Sor the jet index by jet pT
vector<int>
Ana::sortIndices(vector<int> indices){
  map<double,int> pTMap;
  for (int i = 0; i < (int)indices.size(); i++) {
    pTMap.insert(pair<int,double>(jet_pt->at(indices.at(i)), indices.at(i)));
  }
  vector<int> tmp = indices;
  map<double,int>::iterator it; 
  int j = 0;
  for(it=pTMap.begin(); it!=pTMap.end(); it++){
    tmp.at(indices.size() - 1 - j) = it->second;
    j++; 
  } 
  return tmp; 
} 

//Determine whether an event passes selections of a given channel
bool
Ana::channelDecision(vector<int> indices, string channel){
  bool pass = false;
  if (channel == "Inclusive")     pass = true; 
  if (channel == "InclusiveOneB") pass = (jet_MV2c20->at(indices.at(0)) > 0.175848 || jet_MV2c20->at(indices.at(1)) > 0.175848) ? true:false;
  if (channel == "ExclusiveOneB") pass = ((jet_MV2c20->at(indices.at(0)) > 0.175848 && jet_MV2c20->at(indices.at(1)) < 0.175848) || (jet_MV2c20->at(indices.at(0)) < 0.175848 && jet_MV2c20->at(indices.at(1)) > 0.175848)) ? true:false; 
  if (channel == "ExclusiveTwoB") pass = (jet_MV2c20->at(indices.at(0)) > 0.175848 && jet_MV2c20->at(indices.at(1)) > 0.175848) ? true:false;
  return pass;
} 

//
bool
Ana::passPreselection(vector<int> indices, TH1F* cutflow, double weigh){
  bool pass = false;
  if (find(passedTriggers->begin(), passedTriggers->end(), pre.trigger) == passedTriggers->end()) return pass;
  cutflow->Fill(0.0,weight);
  if (jet_pt->at(indices.at(0)) < pre.pTCut_1) return pass;
  cutflow->Fill(1.0,weight);
  if (jet_pt->at(indices.at(1)) < pre.pTCut_2) return pass;
  cutflow->Fill(2.0,weight);
  if (abs(jet_eta->at(indices.at(0))) > pre.etaCut|| abs(jet_eta->at(indices.at(1))) > pre.etaCut) return pass;
  cutflow->Fill(3.0,weight);
  return pass = true;
} 
