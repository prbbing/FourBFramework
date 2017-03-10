//Here we define all the cuts used for the preselection 
#include "Preselection.h"
using namespace std;

// constructor
Preselection::Preselection() {
  
  //====================== 
  // Cuts for all channels
  //======================
  trigger   = "HLT_j380"; 
  pTCut_1   = 430.0;
  pTCut_2   = 60.0;
  etaCut    = 2.5;
  yStarCut  = 0.8;
  
  cout << "########  Preselection is applied" << endl;
  cout << "  Event passes " << trigger << endl;
  cout << "  Leading jet pT > " << pTCut_1 << " GeV"  << endl;
  cout << "  Sub-leading jet pT > " << pTCut_2 << " GeV"  << endl;
  cout << "  Both jets have |eta| <  " << etaCut << endl;
  cout << "########  Cuts=" << endl;
}

// destructor
Preselection::~Preselection () {
}






