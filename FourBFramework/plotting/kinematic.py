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
    if len(hists):
        return totalHist 

outputFile.cd()

for category in categories:
    outputFile.mkdir(str(category))
   
outputFile.mkdir("Comparison") 
for histogram in histograms:
    channelHists =[]
    legend_com = TLegend(0.55, 0.55, 0.65, 0.85)
    legend_com.SetBorderSize(0)
    legend_com.SetTextFont(42)
    legend_com.SetFillColor(0)
    legend_com.SetTextSize(0.035)
    Xmin    =  histograms[histogram]["Xmin"]
    Xmax    =  histograms[histogram]["Xmax"]
    Ymin    =  histograms[histogram]["Ymin"]
    Ymax    =  histograms[histogram]["Ymax"]
    for category in categories:
        channelHists.append(drawHollowPlot(histograms[histogram], categories[category]))
        channelHists[-1].SetLineColor(categories[category]["color"])
        channelHists[-1].SetTitle("")
        channelHists[-1].SetStats(0)
        channelHists[-1].SetLineWidth(2)
        channelHists[-1].SetAxisRange(Ymin,Ymax,"y")
        channelHists[-1].SetAxisRange(Xmin,Xmax,"x")
        legend_com.AddEntry(channelHists[-1],categories[category]["name"],"l")
    
    canvas_com = TCanvas("canvas_"+histograms[histogram]["name"],histograms[histogram]["name"],10,10,600,600)
    canvas_com.Divide(1,1,0.008,0.007)
    canvas_com.cd(1)
    gPadSetup(1)
    
    for i in range(0,len(channelHists)):
        if i == 0:
            channelHists[i].Draw("histo")
        else:
            channelHists[i].Draw("same histo")
    drawAtlasLabel("")
    nameX   =  histograms[histogram]["nameX"]
    nameY   =  histograms[histogram]["nameY"]
    
    if (len(channelHists)):
        drawLabel(channelHists[0],nameX,nameY)
    legend_com.Draw("same")
    outputFile.cd("Comparison")
    canvas_com.Write() 
outputFile.Close()


