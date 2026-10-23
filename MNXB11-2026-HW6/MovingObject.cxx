#include <MovingObject.h>
#include <TObject.h>
#include <cmath>

ClassImp(MovingObject);

// Defult Constructor 
MovingObject::MovingObject ()
: TObject(), fVx(0), fVy(0), fVz(0) {}

// Constructor with parameters
MovingObject::MovingObject(Double_t vx, Double_t vy, Double_t vz)
: TObject(), fVx(vx), fVy(vy), fVz(vz){}


//Destructor
MovingObject::~MovingObject() {}

//Getters
Double_t MovingObject::Vx() const { return fVx; }
Double_t MovingObject::Vy() const { return fVy; }
Double_t MovingObject::Vz() const { return fVz; }

void MovingObject::SetVelocity(Double_t vx, Double_t vy, Double_t vz) {
    fVx = vx;
    fVy = vy;
    fVz = vz;
}

//Double_t MovingObject::Speed() const { return std::sqrt(fVx*fVx + fVy*fVy + fVz*fVz); }
//Double_t MovingObject::HorizontalSpeed() const { return std::sqrt(fVx*fVx + fVy*fVy); }

Double_t MovingObject::Speed() const { 
    return std::sqrt(fVx*fVx + fVy*fVy + fVz*fVz); }

Double_t MovingObject::HorizontalSpeed() const {
    return std::sqrt(fVx*fVx + fVy*fVy);
}    