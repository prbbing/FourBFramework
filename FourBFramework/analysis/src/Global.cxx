// put here some global variables 
using namespace std;

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<TROOT.h>
#include"Global.h"
#include"TRandom3.h"
#include <algorithm>
#include <vector>

// constructor
Global::Global() {

  timer.Start();
  nev = 0;
  debug=false; 
  systematics=0;
  MaxEvents=1e12;

}

// destructor
Global::~Global () {
    cout << "real time=" << timer.RealTime() << endl;
    timer.Stop();
}

// read ntuple list
void Global::getNtuples(string xname) {
    string name="inputs/"+xname;
    ifstream myfile;
    myfile.open(name.c_str(), ios::in);


    if (!myfile) {
      cerr << "Global::getNtuples(): Can't open input file:  " << name << endl;
      exit(1);
    } else {
        cout << "-> Read data file=" << name << endl;
      }

     string temp;
     while (myfile >> temp) {

 //the following line trims white space from the beginning of the string
           temp.erase(temp.begin(), std::find_if(temp.begin(), temp.end(), not1(ptr_fun<int, int>(isspace))));
            if (temp.find("#") == 0) continue; 
            ntup.push_back(temp);

     }
    cout << "-> Number of runs=" << ntup.size()  << endl;
    myfile.close();

    for (unsigned int i=0; i<ntup.size(); i++) {
           cout << ".. file to analyse="+ntup[i] << endl;
    }

}

// read initial parameters
void Global::getIni() {
    nev=0;
    string name="main.ini";
    ifstream myfile;
    myfile.open(name.c_str(), ios::in);

    if (!myfile) {
      cerr << "\nGlobal::getIni(): Can't open input file:  " << name << endl;
      exit(1);
    } else {
        cout << "\nRead file=" << name << endl;
    }

    string message;
    int    number;
    myfile >> message >> MaxEvents;
    myfile >> message >> number;
    myfile >> message >> systematics;
    debug=false;  
    if (number==1) debug=true;
    myfile.close();

    string name1="sys.ini";
    ifstream myfile1;
    myfile1.open(name1.c_str(), ios::in);
    int i = 0;
    string tmp;
    while (i<88){
      if(i == systematics){myfile1>>ttree;break;}
      else myfile1>>tmp;
      i++;
    }
    myfile1.close();
    dobtagSF=true;
    if(systematics ==27) dobtagSF1down=true;
    if(systematics ==28) dobtagSF1up=true;
    if (systematics ==29) dobtagSF=false;
    if(systematics ==30) dobJES1up=true;
    if(systematics ==31) dobJES1down=true;
    if (systematics ==0) dofavorplot=true;
    if(systematics == 25) dotriggerEff1up=true;
    if(systematics == 26) dotriggerEff1down=true;
    for(int i = 1; i<60;i++){
      if(systematics == 35+i)dobtagSF1para[i]=true;
    }

    print_init();               // print initialisations

}






