#include <fstream>
#include <stdlib.h>
#include "GalaxyTrader.h"
using namespace::std;

//function name: main_menu
//parameters: whether or not there is an non-empty Planet nearby
//purpose: print a menu containing all relavent options
//         asks the user to select one of the given options
//vaild inputs: any number next to a displayed input
//return: the number the user selected
int main_menu(const bool nearby)
{
	int selection = -1;
	bool valid = false;
	while(!valid)
	{
		cout << "What do you wish to do captain?\n" << "\t1) review status\n";
		if (nearby)
		{
			cout << "\t2) scan nearby planet\n" << "\t3) buy cargo from the closest planet\n"
				 <<	"\t4) sell cargo to the closest planet\n" << "\t5) refuel at the closest planet\n";
		}
		cout << "\t6) perform a jump\n" << "\t7) perform a wide scan\n" << "\t8) retire\n" 
             << "Enter one of the above selections: ";
		cin >> selection;
		if ((selection >= 1 || selection <= 8) && (nearby || (selection < 2 || selection > 5))){
			valid = true;
		}
        else
			cout << "Captain I do not recognize this command.\n";
	}
	return selection;
}

int main()
{
	GalaxyTrader GT;
	if (!GT.init("space.txt"))
		cout << "The input file contains an out of bounds Planet, please edit the \"space.txt\" file\n";
    else
    { 
	    system("clear");
	
	    cout << "Welcome captain, and thank you for using the Galaxy Trader simulator.\n" 
             << "Your goal is to make as many credits (money) as possible before retiring.\n\n";
	
	    int command = 0;
	    while(command != 8)
        {
		    command = main_menu(GT.scan());
		    system("clear"); //if not running in a terminal window comment out the system("clear"); lines
		    switch(command)
            {
			    case 1:
				    GT.print_status();
			    break;
			    case 2:
				    GT.print_planet();
			    break;
			    case 3:
				    GT.print_planet();
				    cout << endl;
				    if (GT.buy())
                    {
					    cout << endl;
					    GT.print_status();
					    cout << endl;
					    GT.print_planet();
				    }
                    else
					    cout << "The trade did not go through Captain.\n";
			    break;
			    case 4:
				    if (GT.sell())
                    {
					    cout << endl;
					    GT.print_status();
					    cout << endl;
					    GT.print_planet();
				    }
                    else
					    cout << "The trade did not go through Captain.\n";
			    break;
			    case 5:
				    if (GT.refuel())
                    {
					    cout << endl;
					    GT.print_status();
				    }
                    else
					    cout << "We can't afford any fuel here\n";
			    break;
			    case 6:
				    if (GT.move())
                    {
					    cout << endl;
					    GT.print_status();
					    cout << endl;
					    GT.print_planet();
				    }
                    else
					    cout << "We can't jump if we don't have any fuel Captain.\n";
			    break;
			    case 7:
				    GT.areaScan();
			    break;
			    case 8:
			    break;
			    default:
				    cout << "Command not defined.\n";
			    break;
		    }
		    cout << "\n";
	    }
    } // end else
    return 0;
}
