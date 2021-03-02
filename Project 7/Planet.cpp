#include <fstream>
#include "Planet.h"
using namespace::std;

//constructor
Planet::Planet()
{
	empty = true;
	name = "default";
	wolves = 0;
	steaks = 0;
	rabbits = 0;
	price_wolves = 0;
	price_steaks = 0;
	price_rabbits = 0;
	price_fuel = 99999;
}

//copy constructor
Planet::Planet(Planet& other)
{	
	empty = other.empty;
	name = other.name;
	wolves = other.wolves;
	steaks = other.steaks;
	rabbits = other.rabbits;
	price_wolves = other.price_wolves;
	price_steaks = other.price_steaks;
	price_rabbits = other.price_rabbits;
}

//destructor
Planet::~Planet()
{
}

//method name: init
//parameters: the name of the planet
//            an array containing the quantities and prices for goods on the Planet
//purpose: sets a Planet as none empty and populates it's member variables with the given values
//returns: none
void Planet::init(const string n, const int data[])
{
	name = n;
	wolves = data[NUM_W];
	steaks = data[NUM_S];
	rabbits = data[NUM_R];
	price_wolves = data[PRICE_W];
	price_steaks = data[PRICE_S];
	price_rabbits = data[PRICE_R];
	price_fuel = data[PRICE_F];
	empty = false;
}

//method name: print
//parameters: none
//purpose: display all meaningful values the Planet has to the user
//         in the case that the planet is uninitialized print only a message indicating this
//returns: none
void Planet::print() const
{
	if(!empty)
	{
		cout << "\tWelcome to planet " << name << endl;
		cout << "\tOur " << wolves << " wolves are going for " << price_wolves << " credits each." << endl;
		cout << "\tOur " << steaks << " steaks are going for " << price_steaks << " credits each." << endl;
		cout << "\tOur " << rabbits << " rabbits are going for " << price_rabbits << " credits each." << endl;
		cout << "\tFuel can be purchased for " << price_fuel << "credits." << endl;
	}
    else
		cout << "This planet is uninhabited\n";
}

//method name: buyFrom
//parameters: the first letter of the good the user wished to buy
//            the quantity the user wishes to purchase
//            a reference to the credits the user has
//purpose: check to make sure that the offer makes sense
//         if it does update the number of goods on the planet and the credits the user has
//returns: true if the offer made sense, false otherwise
bool Planet::buyFrom(const char good, const float amount, int& credits)
{
	bool valid = false;
	switch(good)
    {
		case 'w':
			if(amount * price_wolves <= credits && amount <= wolves)
            {
				wolves -= amount;
				credits -= amount * price_wolves;
				valid = true;
			}
		break;
		case 's':
			if(amount * price_steaks <= credits && amount <= steaks)
            {
				steaks -= amount;
				credits -= amount * price_steaks;
				valid = true;
			}
		break;
		case 'r':
			if(amount * price_rabbits <= credits && amount <= rabbits)
            {
				rabbits -= amount;
				credits -= amount * price_rabbits;
				valid = true;
			}
		break;
	}
	return valid;
}

//method name: sellTo
//parameters: the first letter of the good the user wished to buy
//            the quantity the user wishes to purchase
//            a reference to the credits the user has
//purpose: update the number of goods on the planet and the credits the user has
//returns: false if the given good doesn't exist, true otherwise
bool Planet::sellTo(const char good, const float amount, int& credits)
{
        bool valid = false;
        switch(good)
    {
                case 'w':
                                wolves += amount;
                                credits += amount * price_wolves;
                                valid = true;
                break;
                case 's':
                                steaks += amount;
                                credits += amount * price_steaks;
                                valid = true;
                break;
                case 'r':
                                rabbits += amount;
                                credits += amount * price_rabbits;
                                valid = true;
                break;
        }
        return valid;
}


//method name: getFuel
//parameters: none
//returns: the price of fuel on this planet
int Planet::getFuel() const
{
	return price_fuel;
}

//method name: isEmpty
//parameters: none
//returns: true if the planet is empty, false otherwise
bool Planet::isEmpty() const
{
	return empty;
}

//method name: getName
//parameters: none
//returns: the name of the Planet
string Planet::getName() const
{
	return name;
}
