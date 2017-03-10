import sys
sys.path.append("modules/")
import math


print 'Number of arguments:', len(sys.argv), 'arguments.'
print 'Argument List:', str(sys.argv)
print 'Use as: script.py -b 0 (or 1,2)'
myinput="interactive"
xdir=""
cross=0
expected_pb=1000.
if (len(sys.argv) ==2):
   myinput = sys.argv[1]
print "Mode=",myinput

# import atlas styles
from AtlasStyle import *
from AtlasUtils import *
from initialize  import *
# from array import array
# from functions import *
from ROOT import TFile,THStack, TGraphAsymmErrors


gROOT.Reset()
gStyle.SetOptStat(111111)

gROOT.SetStyle("ATLAS");

#=======================================
ff=TFile("BJetTriggerEff-00-01-01.root")
h=ff.Get("Pt_offBTag70_bMedium_Total")

# write SF and Err
cfile="./SFandErr.d"
fff=open(cfile,"w")
#fff.write("# bjet trigger SF and Error\n")
for i in xrange(1,h.GetSize()-1):
  fff.write(str(h.GetBinLowEdge(i))+" "+str(h.GetBinLowEdge(i)+h.GetBinWidth(i))+" "+str(h.GetBinContent(i))+" "+str(h.GetBinError(i))+"\n")
fff.close()
print cfile, " is done"
#print  "Write with cross sections written=",out
if (myinput != "-b"):
              if (raw_input("Press any key to exit") != "-9999"): 
                         sys.exit(1);
