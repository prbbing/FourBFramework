/*
 *      Cut.cxx
 *      
 *      Copyright 2010 Sergei Chekanov <chakanau@hep.anl.gov>
 *      
 */


#include "Ana.h"
#include "Global.h"
#include "Histo.h"
#include<stdio.h>
#include<stdlib.h>
#include "SystemOfUnits.h"
#include<TROOT.h>
#include<stdio.h>
#include<TMath.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

extern Global glob;


/*
*     Event selection goes here
*     S.Chekanov, 08.04.2010
*/
Int_t Ana::CutEvent(Long64_t entry)
{

       // event information
       glob.m_run=runNumber;
       glob.m_evt=eventNumber;

       
#if montecarlo
//       glob.MET_Final_et=MET_RefFinal_et;
//       glob.MET_Final_phi=MET_RefFinal_phi;
#endif




#if !montecarlo




#endif


// Monte Carlo has negative runs
#if montecarlo
             glob.m_run=-1*runNumber;
#endif



// returns  1 if entry is accepted.
// returns -1 otherwise.
    return 1;
}
