//-----------------------------------------------------
// Filename: Spaceship.cpp
// Purpose:  The implementation of the Spaceship class
//-----------------------------------------------------

#include <iostream>
#include "Spaceship.h"
using namespace std;

//----------- Constructors and Destructors ----------

// Default constructor
Spaceship::Spaceship() 
{
    crewSize = 0;
    name = "NoName";
    impulseSpeed = 0;
    shieldsUp = false;
}

// Non-default constructor
/*Takes in the name, crew size, and impulse (cruising) speed of the spaceship, and also
whether or not its shields are currently up. Sets each parameter to its corresponding class
variable. FYI, Star Trek Voyager’s impulse speed was 74,400 km/sec*/
Spaceship::Spaceship(const int crew, const string n, const long impulse, const bool shields)
{
   crewSize=crew;
   name=n;
   impulseSpeed=impulse;
   shieldsUp=shields;
}

// Copy constructor
/*Takes in another Spaceship object as a parameter. Sets each variable of the class to
equal the values in the parameter Spaceship object.*/
Spaceship::Spaceship(const Spaceship &otherShip)
{
   crewSize=otherShip.crewSize;
   name=otherShip.name;
   impulseSpeed=otherShip.impulseSpeed;
   shieldsUp=otherShip.shieldsUp;
}
// Destructor (already completed for you)
Spaceship::~Spaceship() { }

//----------- Setters -------------------------------
/*Sets the corresponding instance variable to the parameter value passed in.
 Checks that valid values are passed in (see details in Spaceship.h)*/

// SetCrewSize
bool Spaceship::SetCrewSize(const int c)
{
if(c>0 && c<10000)
{
   crewSize=c;
   return true;
}
else
   cout<< "Invalid choice.";
   return false;
}
// SetName
void Spaceship::SetName(const string n)
{
   name=n;
}
// SetImpulseSpeed
bool Spaceship::SetImpulseSpeed(const long i)
{
if(i>0)
{
   impulseSpeed=i;
   return true;
}
else
{
   cout<<"Invalid choice.";
   return false;
}
}
// SetShieldsUp
void Spaceship::SetShieldsUp(const bool shields)
{
   shieldsUp=shields;
}
//----------- Getters -------------------------------
/*Return the corresponding instance variable value*/

// GetCrewSize
int Spaceship::GetCrewSize() const
{
   return crewSize;
}
// GetName
string Spaceship::GetName() const
{
   return name;
}
// GetImpulseSpeed
long Spaceship::GetImpulseSpeed() const
{
   return impulseSpeed;
}
// GetShieldsUp
bool Spaceship::GetShieldsUp() const
{
   return shieldsUp;
}
//----------- Other ---------------------------------

// Print
void Spaceship::Print() const 
{   
    locale mylocale("");
    cout.imbue(mylocale);
    cout << "Name: " << name << endl; 
    cout << "Crew Size: " << crewSize << " crew members." << endl;
    cout << "Impulse Speed: " << impulseSpeed << " km/sec." << endl;
    cout << "Shields Up: ";
    if (shieldsUp) 
        cout << "TRUE" << endl;
    else 
        cout << "FALSE" << endl;
}


// BattleStart
/*Sets the shields up to true.*/
void Spaceship::BattleStart()
{
   shieldsUp=true;
}
// BattleEnd
/*Sets the shields up to false*/
void Spaceship::BattleEnd()
{
   shieldsUp=false;
}
// CurrentSpeed
/*Returns the current speed of the spaceship. If the shields are up, the current speed
should be the impulse (cruising) speed. Otherwise, the speed should be warp speed.*/
long Spaceship::CurrentSpeed() const
{
   if(shieldsUp)
      return impulseSpeed;
   else
      return WARP_SPEED;

}
