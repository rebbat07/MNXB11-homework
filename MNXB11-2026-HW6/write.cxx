#include<MovingObject.h>
#include<TFile.h>
#include<TTree.h>
#include<TRandom.h>


void write(){
// Initialize your object e.g. as a pointer
MovingObject* obj = new MovingObject(); // Create a new object

// Create your root file here
TFile* file = new TFile("tree_file.root", "RECREATE");

// Create your TTree here
TTree* tree = new TTree("tree", "Velocity measurements");

// And the associated branches underneath
tree->Branch("object", &obj);

gRandom->SetSeed(12345); // Random number generator
const Int_t nEvents = 10000; // Number of events to generate

 
// For loop here
for (Int_t i{0}; i<nEvents; i++){


// Initialize your new object below
Double_t vx = gRandom->Gaus(0.0, 0.3); // Random velocity in x-direction
Double_t vy = gRandom->Gaus(0.0, 0.3); // Random velocity in y-direction
Double_t vz = gRandom->Gaus(0.0, 0.3); // Random velocity in z-direction
obj = new MovingObject(vx, vy, vz); // Create a new object with the random velocities




obj->SetVelocity(vx, vy, vz); // Set the velocity of the object
tree->Fill();

}


// save the tree/file

tree->Write();
file->Close();
delete file;
delete obj;

}







