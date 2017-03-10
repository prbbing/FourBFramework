// Developed at ASC ANL
// S.Chekanov (ANL). chakanau@hep.anl.gov
// Feb. 2010 

#include "analysis.h"
#include <TROOT.h>
#include <TTree.h>
#include <TH1D.h>

// main analysis class. inherent analysis.h which should be rebuilkd each time

using namespace std;

class Ana: public analysis  {

    public:
          Ana(TTree *tree, string channel);
          virtual ~Ana();
          int    CutEvent(Long64_t entry);
          void   Loop(string channel);
          double findValue(vector<int> indices, string val);
          vector<string> getStringSegments(string input, char delim);
          void fillOneDHistogram(vector<int> indices, vector<TH1D*> hists, double weight); 
          bool channelDecision(vector<int> indices, string channel); 
          bool passPreselection(vector<int> indices, TH1F* cutflow, double weight);
          vector<int> sortIndices(vector<int> indices);
};
