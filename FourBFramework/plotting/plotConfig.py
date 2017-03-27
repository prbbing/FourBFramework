import sys
sys.path.append("modules/")
import math
# import atlas styles
from AtlasStyle import *
from AtlasUtils import *
from initialize  import *
from configurationOptions import *
# from array import array
# from functions import *
#from ROOT import THStack

gROOT.Reset()
gStyle.SetOptStat(111111)

gROOT.SetStyle("ATLAS");

def drawAtlasLabel(label):
    myText(0.5,0.89,1,0.04,CMELUMI)
    ATLASLabel(0.19,0.89,0.13,AtlasLabel)
    myText(0.25,0.83,1,0.05,label)

def gPadSetup(logy):
    gPad.SetLogy(logy)
    gPad.SetLogx(0)
    gPad.SetTopMargin(0.05)
    gPad.SetBottomMargin(0.15)
    gPad.SetLeftMargin(0.15)
    gPad.SetRightMargin(0.09)
    
def drawLabel(h,nameX,nameY):
    ax=h.GetXaxis();ax.SetTitleOffset(0.5)#
    ax.SetTitle( nameX );
    ay=h.GetYaxis(); ay.SetTitleOffset(0.8)
    ay.SetTitle( nameY );
    ax.SetLabelSize(0.04);
    ay.SetLabelSize(0.04);
    ax.SetTitleOffset(1.1); ay.SetTitleOffset(1.3)
    ax.Draw("same")
    ay.Draw("same")

def flavorLabel(xflavor,yflavor):
    myBoxText(xflavor,yflavor-0.04*0,0.02,7,"ll")
    myBoxText(xflavor,yflavor-0.04*1,0.02,6,"lc")
    myBoxText(xflavor,yflavor-0.04*2,0.02,5,"lb")
    myBoxText(xflavor,yflavor-0.04*3,0.02,4,"cc")
    myBoxText(xflavor,yflavor-0.04*4,0.02,3,"cb")
    myBoxText(xflavor,yflavor-0.04*5,0.02,2,"bb")
