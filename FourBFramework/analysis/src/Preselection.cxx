//Here we define all the cuts used for the preselection 
#include "Preselection.h"
using namespace std;

// constructor
Preselection::Preselection() {
  
  //====================== 
  // Cuts for all channels
  //======================
  trigger   = "HLT_4j25"; 
  pTCut_1   = 150.0;
  pTCut_2   = 150.0;
  pTCut_3   = 25.0;
  etaCut    = 2.5;
  yStarCut  = 0.8;
  
  cout << "########  Preselection is applied" << endl;
  cout << "  Event passes " << trigger << endl;
  cout << "  Leading jet pT > " << pTCut_1 << " GeV"  << endl;
  cout << "  Sub-leading jet pT > " << pTCut_2 << " GeV"  << endl;
  cout << "  Third-leading jet pT > " << pTCut_3 << " GeV"  << endl;
  cout << "  All jets have |eta| <  " << etaCut << endl;
  cout << "######## End of preselection ########" << endl;
}

// destructor
Preselection::~Preselection () {
}






