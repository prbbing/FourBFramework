using namespace std;
#include<iostream>
#include "TROOT.h"
#include "TFile.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TTree.h"
#include "TProfile.h"

class Histo {

  public:
    
    map<string,vector<TH1D*>>  oneDHistograms; 
    map<string,vector<TH2D*>>  twoDHistograms; 
    map<string,TFile*> skimFiles;
    map<string,TTree*> skimTrees;
     
    map<string, vector<double>> oneDHistogramPara;
    map<string, vector<vector<double>>> twoDHistogramPara;
    
    vector<double> mjjBinning    = {150,0,7500};
    vector<double> pTBinning     = {150,0,3000};
    vector<double> etaBinning    = {100,-5,5};
    vector<double> phiBinning    = {64,-3.2,3.2};
    vector<double> idBinning     = {25,0,25};
    vector<double> dphiBinning   = {32,0,3.2};
    vector<double> detaBinning   = {50,0,5.0};
    vector<double> dRBinning     = {50,0,5.0};    
    vector<double> mv2c10Binning = {200,-1,1};    
    vector<double> sv1Binning    = {100,-5,15};    
    vector<double> ip3dBinning   = {200,-100,100};    
    vector<double> yStarBinning  = {100,-5,5};    
    vector<double> mboostBinning = {150,0,7500};

    TH1F *cutflow;
 
    // ---- do not modify below -----
    Histo();
    virtual ~Histo();
    void setHistograms(string channel, TH1F *inputCutflow);
    void setOutput(string output);
    void setChannel(string channel);
    void setSkim(string channel, int index, TTree *inputTree);
    void writeTrees(string channel, int index);
    void fillCutflow(string channel);
    void setParameters();
    void finalize();
    char *ffile;
    TFile *RootFile;
};
