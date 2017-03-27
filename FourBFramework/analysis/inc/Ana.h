#include "analysis.h"
#include <TROOT.h>
#include <TTree.h>
#include <TH1D.h>
#include <TH2D.h>

// main analysis class. inherent analysis.h which should be rebuild each time

using namespace std;

class Ana: public analysis  {
  public:
    Ana(TTree *tree, string channel);
    virtual ~Ana();
    int    CutEvent(Long64_t entry);
    void   Loop(string channel, int index);
    double findValue(vector<int> indices, string val);
    vector<string> getStringSegments(string input, char delim);
    void fillOneDHistogram(vector<int> indices, vector<TH1D*> hists, double weight); 
    void fillTwoDHistogram(vector<int> indices, vector<TH2D*> hists, double weight); 
    bool channelDecision(vector<int> indices, string channel); 
    bool passPreselection(vector<int> indices, TH1F* cutflow, TH1F* cutfloWeighted, double weight);
    vector<int> sortIndices(vector<int> indices);
};
