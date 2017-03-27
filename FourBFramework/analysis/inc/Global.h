using namespace std;
#include<iostream>
#include<fstream>
#include "TFile.h"
#include "TH1D.h"
#include "TStopwatch.h"
#include "TSpline.h"
#include <string>
#include <vector>
#include <map>

class Global {
  public:
    Global ();
    virtual ~Global ();

    int TotalEvents;
    void getNtuples(string name);
    void getIni();
    void getLumi();
    int nev;			// events processed 
    vector <string> ntup;	// ntuple list

    TFile *RootFile;
    TH1F *h1;
    TStopwatch timer;
    char *ffile;
    int MaxEvents;
    int debug;
    int systematics;
    int gen_events;
    string ttree;
    map<string,float> channelAcceptance;    
    map<string,float> channelWeightedAcceptance;    

    ofstream outBsf;
    ifstream inBsf;

    vector <double> tilerun,tilelb,tileevt;
    TSpline3* line;
    TSpline3* line1;
    int  m_run, m_evt;
    int  LumiBlockNumber;
    int  BCIDbeamCrossId;
    bool dobtagSF;
    bool dobtagSF1up;
    bool dobtagSF1down;
    bool dobtagSF1para[60];
    bool dobJES1up;
    bool dobJES1down;
    bool dofavorplot;
    bool dotriggerEff1up;
    bool dotriggerEff1down;

    void print_init() {
      cout << "\n\n  --Job input--: " << endl;
      cout << "\n   Max events=" << MaxEvents <<
              "\n   Debug=" << debug << 
              "\n   Systematics=" << systematics <<
              "\n   Tree=" << ttree << 
              "\n   dobtagSF=" << dobtagSF <<
              "\n   dobtagSF1up=" << dobtagSF1up <<
              "\n   dobtagSF1down=" << dobtagSF1down <<
              "\n   dobJES1up=" << dobJES1up <<
              "\n   dobJES1down=" << dobJES1down <<
              "\n   dofavorplot=" << dofavorplot <<
              "\n   dotriggerEff1up=" << dotriggerEff1up <<
              "\n   dotriggerEff1down=" << dotriggerEff1down <<
              endl; 
     for (int i = 0; i<60;i++) cout<<"dobtagSF1para[" << i << "]="<<dobtagSF1para[i] <<endl;
   };
};
