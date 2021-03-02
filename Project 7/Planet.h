#include <iostream>
#include <fstream>
using namespace::std;

const int NUM_DATA = 7; // The number of data items stored about each planet

const int NUM_W = 0; // The number of wolves for sale
const int NUM_S = 1; // The number of steaks for sale
const int NUM_R = 2; // The number of rabbits for sale
const int PRICE_W = 3; // The price for a wolf
const int PRICE_S = 4; // The price for a steak
const int PRICE_R = 5; // The price for a rabbit
const int PRICE_F = 6; // The price for fuel


class Planet
{
	public:
		Planet();
		Planet(Planet& other);
		~Planet();
		
		void print() const;
		void init(const string n, const int data[7]);

		bool buyFrom(const char good, const float amount, int& credits);
                bool sellTo(const char good, const float amount, int& credits);
		int getFuel() const;
		bool isEmpty() const;
		string getName() const;
	
	private:
		string name;
		bool empty;
		
		int wolves;
		int steaks;
		int rabbits;
		
		int price_wolves;
		int price_steaks;
		int price_rabbits;
		
		int price_fuel;
};
