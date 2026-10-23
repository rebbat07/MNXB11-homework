
#include <iostream>
#include <TFile.h>
#include <TTree.h>
#include <MovingObject.h>
#include <TH2D.h>


R__LOAD_LIBRARY(MovingObject_cxx.so)



void read () {

    TFile* file = new TFile("tree_file.root", "READ");

    // Check if the file was opened successfully
    if (!file->IsOpen()) {
        std::cerr << "Error: Could not open file 'tree_file.root'." << std::endl;
        return;
    }
    // Get the TTree from the file
    TTree* tree = (TTree*)file->Get("tree");
    if (!tree) {
        std::cerr << "Error: Could not find tree 'tree' in file." << std::endl;
        file->Close();
        return;
    }

    tree->Print(); // Print the structure of the tree

    // Set up a pointer to hold the MovingObject instances
    MovingObject* obj = nullptr;
    tree->SetBranchAddress("object", &obj);

    // Create a 2D histogram to visualize the velocity distribution
    TH2D* hist = new TH2D("hist", "Velocity Histogram", 100, -1.5, 1.5, 100, -1.5, 1.5);



    
    Long64_t nEntries = tree->GetEntries();
    std::cout << "Number of entries in the tree: " << nEntries << std::endl;
    
    
    for (Long64_t i = 0; i < nEntries; ++i) {
        tree->GetEntry(i);
        hist->Fill(obj->Vx(), obj->Vy());
        }
    
        // plot for Vx and Vy
    TCanvas* c1 = new TCanvas("c1", "Velocity Histogram", 800, 600);
    gStyle->SetOptStat(0); // Disable the statistics box
    hist->Draw("COLZ"); // Draw the histogram with color mapping
    hist->SetTitle("Velocity Components Histogram (Vx vs Vy)");
    hist->GetXaxis()->SetTitle("V_{x} [m/s]");
    hist->GetYaxis()->SetTitle("V_{y} [m/s]");
    c1->Modified();
    c1->Update();
    c1 -> SaveAs("velocity_components.pdf"); // Save the histogram as an image

        //plot for Vxy and Vz
    TCanvas* c2 = new TCanvas("c2", "Velocity Histogram", 800, 600);
    gStyle->SetOptStat(0); // Disable the statistics box
    tree->Draw("sqrt(object.fVx*object.fVx + object.fVy*object.fVy):object.fVz",
    "sqrt(object.fVx*object.fVx + object.fVy*object.fVy + object.fVz*object.fVz) > 0.5"); 
    
    TH2F* hist2 = (TH2F*)gPad->GetPrimitive("htemp");
    hist2->SetTitle("Graph to Show Vxy vs Vz for v.> 0.5");
    hist2->GetXaxis()->SetTitle("V_{z} [m/s]");
    hist2->GetYaxis()->SetTitle("V_{xy} [m/s]");
    c2->Modified();
    c2->Update();
    
    c2 -> SaveAs("Scatter_Plot.pdf"); // Save the histogram as a PDF
}

