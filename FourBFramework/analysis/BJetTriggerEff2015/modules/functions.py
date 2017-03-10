#!/usr/bin/env python
import sys
from math import log,sqrt,acos,exp




# asymetric gaussian
class GaussAss:
   def __call__( self, x, par ):

       out=0.0
       gaus1=0.0
       gaus2left=0.0
       gaus2right=0.0
       gaus1=par[0]*exp((-0.5)*(x[0]-par[1])*(x[0]-par[1])/(par[2]*par[2]))
       gaus2left=par[5]*exp((-0.5)*(x[0]-par[1])*(x[0]-par[1])/(par[3]*par[3]))
       gaus2right=par[5]*exp((-0.5)*(x[0]-par[1])*(x[0]-par[1])/(par[4]*par[4]))

       cc=par[2]*par[3]*par[4]

       if x[0]<=par[1] and cc>0:
                       out=gaus1+gaus2left;
       if x[0]>par[1] and cc>0:
                       out=gaus1+gaus2right;

       return out

# P1
class P1:
   def __call__( self, x, par ):
       out=par[0] + par[1]*x[0]; 
       return out;



# GaussAss+P1
class GaussAssBkg:
   def __call__( self, x, par ):

       out=0.0
       gaus1=0.0
       gaus2left=0.0
       gaus2right=0.0

       gaus1=par[0]*exp((-0.5)*(x[0]-par[1])*(x[0]-par[1])/(par[2]*par[2]))
       gaus2left=par[5]*exp((-0.5)*(x[0]-par[1])*(x[0]-par[1])/(par[3]*par[3]))
       gaus2right=par[5]*exp((-0.5)*(x[0]-par[1])*(x[0]-par[1])/(par[4]*par[4]))

       cc=par[2]*par[3]*par[4]

       if x[0]<=par[1] and cc>0:
                       out=gaus1+gaus2left;
       if x[0]>par[1] and cc>0:
                       out=gaus1+gaus2right;


       back = par[6] + par[7]*x[0];
       # add backg 
       backout=out+ back;

       return backout;

# threshold
class Bkg:
   def __call__( self, x, par ):
      xx=x[0]-1.435944
      f3g2=0.
      if par[1] < 0: return 1.e30;
      if (xx > 0.0 ):
           f3g2=par[0]* (xx**par[1])*(1+par[2]*xx)
           return f3g2;

class MGauss:
   def __call__( self, x, par ):
      f3g2=0.
      cost=1./math.sqrt(2*acos(-1.));
      f3g2=(par[0]*cost*exp(-((x[0]-par[1])*(x[0]-par[1]))/(2*par[2]*par[2]) ));
      return f3g2;

# 3-parameter function for dijet analysis of 2015
class  ThreeParam2015:
  def __call__( self, x, par ):
    Ecm=13000.;
    fCenterOfMassEnergy = Ecm;
    fUseWindowExclusion = False;
    x=x[0];
    ff=par[0]*pow((1-x/fCenterOfMassEnergy),par[1])*pow((x/fCenterOfMassEnergy),par[2]);
    return ff;

# 4-parameter function for dijet analysis of 2015
# FourParamFitFunction in src_util/SearchPhase.cxx
class  FourParam2015:
  def __call__( self, x, par ):
    Ecm=13000.;
    fCenterOfMassEnergy = Ecm;
    fUseWindowExclusion = False;
    x = x[0] / fCenterOfMassEnergy;
 
    ff=par[0]*pow((1-x),par[1])*pow(x,(par[2]+par[3]*log(x)));
    return ff;
 

class Massimo2:
   def __call__( self, x, par ):
      xx=x[0]-1.435944
      f3g2=0.
      xcost=1.0/math.sqrt(2.0*math.acos(-1.))
      if ( par[7] < 0): return 1.e30;
      if (xx > 0.0 ):
          f3g2=par[6]*(xx**par[7])*(1+par[8]*xx);
          f3g2=f3g2+(par[0]*xcost*exp(-((x[0]-par[1])*(x[0]-par[1]))/(2*par[2]*par[2]) ));
          f3g2=f3g2+(par[3]*xcost*exp(-((x[0]-par[4])*(x[0]-par[4]))/(2*par[5]*par[5]) ));
          return f3g2;
