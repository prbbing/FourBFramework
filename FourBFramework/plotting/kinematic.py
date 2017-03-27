from plotConfig import *
from configurationOptions import *
sys.path.append("modules/")

outputFile = TFile(outputPath, "RECREATE","")

def drawHollowPlot(histogram, category):
    #Retrive parameters in the histogram dictionary
    logy    =  histogram["logy"]
    name    =  category["name"] + "/" + histogram["name"] 
    Xmin    =  histogram["Xmin"]
    Xmax    =  histogram["Xmax"]
    Ymin    =  histogram["Ymin"]
    Ymax    =  histogram["Ymax"]
    nameX   =  histogram["nameX"]
    nameY   =  histogram["nameY"]
    label   =  category["label"]
    
    canvas = TCanvas("canvas_"+histogram["name"],histogram["name"],10,10,600,600)
    canvas.Divide(1,1,0.008,0.007)
    canvas.cd(1)
    gPadSetup(logy)
    
    legend = TLegend(0.55, 0.55, 0.65, 0.85)
    legend.SetBorderSize(0)
    legend.SetTextFont(42)
    legend.SetFillColor(0)
    legend.SetTextSize(0.035)
    
    hists = []
    for QCD in qcdSamples:
        fileName  = sampleLocations["pythiadir"] + QCD + ".root"       
        inputFile = TFile(fileName)
        if inputFile.IsZombie() or not inputFile.GetNkeys():
            print "Can not open file: " + fileName
            continue
        if crossSections[QCD]:
            lumiScale = inputFile.Get(category["name"] + "/cutflow").GetBinContent(1)/crossSections[QCD]  
        if not (inputFile.Get(name)):
   	    continue
        histTmp = inputFile.Get(name).Clone()
        histTmp.SetDirectory(0)
        if lumiScale:
            histTmp.Scale(32900/lumiScale)
        histTmp.SetTitle("")
        histTmp.SetStats(0)
        histTmp.SetLineWidth(2)
        histTmp.SetLineColor(colors[QCD])
        histTmp.SetAxisRange(Ymin,Ymax,"y")
        histTmp.SetAxisRange(Xmin,Xmax,"x")
        legend.AddEntry(histTmp,QCD,"l")
        hists.append(histTmp)
        if len(hists) == 1:
            histTmp.Draw("histo")
        else:
            histTmp.Draw("same histo")
        inputFile.Close()
    if len(hists):
        totalHist = hists[0].Clone()
        for i in range(1,len(hists)):
            totalHist.Add(hists[i])
        totalHist.SetLineColor( 4 )
        totalHist.Draw("same histo")
        legend.AddEntry(totalHist,"Pythia Inclusive","l")
    drawAtlasLabel(label)
    if (len(hists)):
        drawLabel(hists[0],nameX,nameY)

    gPad.RedrawAxis()
    if len(category["name"].split("_")) > 1:
        outputFile.cd(category["name"].split("_")[1])
    else:
        outputFile.cd(category["name"])
    legend.Draw("same")
    canvas.Write()


outputFile.cd()
for category in categories:
    outputFile.mkdir(str(category))
    for histogram in histograms:
        drawHollowPlot(histograms[histogram], categories[category])
outputFile.Close()


