using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include<stdlib.h>
#include <vector>

class Preselection {
  public:
    Preselection ();
    virtual ~Preselection ();
    double pTCut_1;
    double pTCut_2;
    double etaCut;
    double yStarCut;
    string trigger;
};
