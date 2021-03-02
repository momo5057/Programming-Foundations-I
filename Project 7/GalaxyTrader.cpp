#include <fstream>
#include "GalaxyTrader.h"
using namespace::std;
Planet P;
Planet P0;
//constructor
GalaxyTrader::GalaxyTrader()
{
}

//copy constructor
GalaxyTrader::GalaxyTrader(GalaxyTrader& other)
{
}

//destructor
GalaxyTrader::~GalaxyTrader()
{
}

//method name: init
//parameters: the name of the file to read from
//purpose: initializes the planet array using the information in the given file
//         should use the init method of the Planet class
//         if the input file contains a planet outside the bounds of the array immediately return false 
//input file format:
//			position of planet
//			name of planet
//			Number of: Wolves Steaks Rabbits then Prices of: Wolves Steaks Rabbits Fuel
//example: 2
//		   Mars
//         4 13 15 100 10 20 8
//returns: false if any planets were going to be placed out of bounds, true otherwise
// You may assume that the file format is correct, you do not need to error check anything except
// Planet position
bool GalaxyTrader::init(const string filename)
{
   int data[SIZE];
//planets.init(filename, data);
   data[0]=1; data[1]=1; data[2]=9999; data[3]=15; data[4]=24; data[5]=1; data[6]=50;
   planets[0].init("Earth", data);
P.init("Earth", data);
   data[1]=2; data[2]=3; data[3]=4; data[4]=5; data[5]=6; data[6]=7;
   planets[1].init("Not-So-Cold", data);
   data[0]=0; data[1]=1; data[2]=0; data[3]=1; data[4]=30; data[5]=1; data[6]=3;
   planets[7].init("Gas-Station", data);
   data[0]=0; data[1]=2; data[2]=0; data[3]=10; data[4]=30; data[5]=15; data[6]=5;
   planets[2].init("Hard-To-Find", data);
   data[0]=0; data[1]=0; data[2]=0; data[3]=100; data[4]=100; data[5]=100; data[6]=500;
   planets[4].init("Scarsity", data);
   planets[3].isEmpty();
   planets[5].isEmpty();
   planets[6].isEmpty();
   planets[7].isEmpty();
   planets[8].isEmpty();
   planets[9].isEmpty();
wolves=0;
credits=100;
fuel=5;
    return true;
}

//method name: buy
//parameters: none
//purpose: ask the user which good they want to buy and how many they want to buy
//         then this calls the buyFrom method of the planet the ship is on
//         finally if the transaction was sucessful the goods purhased are added to the ship's cargo
//valid inputs: w/s/r for goods, any non negative number for quantity
//returns: true if the transaction was successful, false otherwise
bool GalaxyTrader::buy()
{
   char item;
   int quantity;
   cout << "What good do you wish to buy Captain? (w, s, r)";
   cin >> item;
   while(item!='w' && item!='s' && item!='r')
   {
      cout << "I don't think this planet is familiar with that good captain" << endl;
      cout << "What good do you wish to buy Captain? (w, s, r)";
      cin >> item;
   }
   cout << "how many do you wish to buy Captain?";
   cin >> quantity;
   while(quantity<0)
   {
      cout << "we can't buy negative goods Captain, maybe you meant to sell" << endl;
      cout << "how many do you wish to buy Captain?";
      cin >> quantity;
   }
   bool works=P.buyFrom(item, quantity, credits);
   if(works)
      return true;
   else
      return false;
}

//method name: sell
//parameters: none
//purpose: ask the user which good they want to sell and how many they want to buy
//         then this calls the sellTo method of the planet the ship is on
//         finally if the transaction was sucessful the goods purhased are removed from the ship's cargo
//valid inputs: w/s/r for goods, any non negative number up to the number of the good in the ship's cargo for quantity
//returns: true if the transaction was successful, false otherwise
bool GalaxyTrader::sell()
{
   char item;
   int quantity;
   cout << "What good do you wish to sell Captain? (w, s, r)";
   cin >> item;
   while(item!='w' && item!='s' && item!='r')
   {
      cout << "I don't think this planet is familiar with that good captain" << endl;
      cout << "What good do you wish to sell Captain? (w, s, r)";
      cin >> item;
   }
   cout << "how many do you wish to sell Captain?";
   cin >> quantity;
   while(quantity<0)
   {
      cout << "we can't sell negative goods Captain, maybe you meant to buy" << endl;
      cout << "how many do you wish to sell Captain?";
      cin >> quantity;
   }
   bool works=P.sellTo(item, quantity, credits);
   if(works)
      return true;
   else
      return false;

}

//method name: refuel
//parameters: none
//purpose: buys as much fuel as possible from the planet the ship is on, at most enough to fill the reserves to MAX_FUEL
//returns: true if any fuel was purchased, false otherwise
bool GalaxyTrader::refuel()
{
   if(fuel<MAX_FUEL && credits>P.getFuel())
   {
      while(fuel<MAX_FUEL && credits>P.getFuel())
      {
         fuel=fuel+1;
         credits=credits-P.getFuel();
      }
      return true;
   }
   else
      return false;
}

//method name: move
//parameters: none
//purpose: immediately returns false if the user has no fuel
//         otherwise it asks the user what direction they want to move
//         then the ship's position is updated to reflect the move and fuel is decreased by one
//note: if the ship exceeds the limits of the array it should "reapear" on the other side
//valid inputs: l for left, r for right
//returns: true if the ship's position changed, false otherwise
bool GalaxyTrader::move()
{
   char dir;
   if(fuel==0)
      return false;
   cout << "What direction do you want to go captain? (l,r): ";
   cin >> dir;
   while(dir!='l' && dir!='r')
   {
      cout << "Unfortunately, I can only move us in 1 dimension Captain" << endl;
      cout << "What direction do you want to go captain? (l,r): ";
      cin >> dir;
   }
   if(dir=='l')
      if(ship_pos==0)
         ship_pos=9;
      else
         ship_pos=ship_pos-1;
   else
      if(ship_pos==9)
         ship_pos=0;
      else
         ship_pos=ship_pos+1;
   fuel=fuel-1;
	return true;
}

//method name: print_status
//parameters: none
//purpose: print the coordinates of the ship
//         the credits availble
//         currentfuel/MAX_FUEL
//         and everything in the ships cargo (should say it is empty if it contains nothing)
//returns: none
void GalaxyTrader::print_status() const
{
   cout << "Current space coordinates: " << ship_pos << endl << "Credits avaliable :" << credits << endl <<
   "Fuel reserves: " << fuel << "/5" << endl << "Cargo Status: " << endl;
   if(wolves!=0)
      cout << "   " << wolves << " units of wolves" << endl;
   else if(steaks!=0)
      cout << "   " << steaks << " units of steaks" << endl;
   else if (rabbits!=0)
      cout << "   " << rabbits << " units of rabbits" << endl;
   else
      cout << "   Empty"; 
}

//method name: print_planet
//parameters: none
//purpose: checks to see if the Planet the ship is on is empty
//         if it is print a message saying so
//         otherwise call the print method of the planet the ship is on
//returns: none
void GalaxyTrader::print_planet() const
{
   if(scan())
      P.print();
   else
      cout << "Planet is empty" << endl;
}

//method name: scan
//parameters: none
//returns: false if the Planet the ship is at is empty, true if it is not
bool GalaxyTrader::scan() const
{
   if(P.isEmpty())
      return false;
   else
      return true;
}

//method name: areaScan
//parameters: none
//purpose: asks the user how wide a scan they would like to perform
//         then areaScan prints out a grid of 1 tall and 2*radius+1 wide
//         each spot on the grid contains either an [ ] or a [?]
//         [ ] represents a location with no planet
//         [?] represents a location with a planet (? should be replaced with the first character of the name of the planet)
//         the center of the grid represents where the ship currently is and should have a small arrow indicating where the ship currently i
//valid inputs: a number between 1 and SIZE
//returns: none
void GalaxyTrader::areaScan() const
{
}
