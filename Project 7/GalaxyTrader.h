#include <iostream>
#include <fstream>
#include "Planet.h"
using namespace::std;

class GalaxyTrader
{
	public:
		GalaxyTrader();
		GalaxyTrader(GalaxyTrader& other);
		~GalaxyTrader();

		bool init(const string filename);
		bool buy();
		bool sell();
		bool refuel();
		bool move();
		void print_status() const;
		void print_planet() const;
		bool scan() const;
		void areaScan() const;

	private:
		const static int MAX_FUEL = 5;
		const static int SIZE = 10;

		Planet planets[SIZE];

		int ship_pos;
		int wolves;
		int steaks;
		int rabbits;
		int fuel;
		int credits;
};
