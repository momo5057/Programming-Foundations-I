
#include <iostream>
using namespace std;
#include <iomanip>
#include <cmath>

//-----------------------------------------------------------
//Name:       earthETA
//Purpose:    Find the Earth year the user will arrive at Not-So-Cold planet
//Parameters: Pass by Value: year - the year that the user will depart
//            Pass by Value: averageSpeed - the current average rocket speed for that year
//Return:     The Earth year that the user will arive at the planet
//-----------------------------------------------------------
double earthETA (int year, double averageSpeed)
{
   double finalYear=0;
   //convert agerage speed from km/sec to km/year
   averageSpeed=averageSpeed*31536000;
   finalYear=year+(1e+14/averageSpeed);
   return finalYear;
} 

//-----------------------------------------------------------
//Name:       yourETA
//Purpose:    Find the year the user will arrive at Not-So-Cold planet using the Lorenzo factor
//Parameters: Pass by Value: year - the year the user will depart
//            Pass by Value: v - the current average rocket speed for that year
//Return:     The Lorenzo factored year the user will arive at the planet
//-----------------------------------------------------------
double yourETA (int year, double v)
{
   double finalYear=0;
   int c = 299792; //speed of light
   double lorenzo=0;
   c = (c * c); //just to make my calculation easier
   lorenzo = 1 - (( v * v ) / c ); //bottom half of my calculation with out square root
   if(lorenzo<0)
      lorenzo=lorenzo*(-1); //because a negative cannot be in the square root
   lorenzo = (sqrt ( lorenzo ))/1;
   v=v*31536000;
   finalYear=year+(1e+14/v)-lorenzo;
   return finalYear;
}

int main()
{
   //Gathering precent improvements and how long user is willing to wait
   double precentFaster = -1;
   int longestWait = 0;
   double averageSpeed=10000;
   int yearLeave=0;
   double yourTimeLeave=0;
   double earthTimeLeave=10000;
   earthETA(0, 0);
   yourETA(0, 0);
   cout << endl << "The distance to planet Not-So-Cold is 100 trillion km." << endl;
   cout << "The current average rocket speed is 10000 km/sec." << endl << endl;
   cout << "What precentage closer to the speed of light will rockets get each year? (0 to 100):";
   while (precentFaster < 0||precentFaster>100)
      cin >> precentFaster;
   cout << "What is the longest you will wait to get on the rocket before the cold becomes unberable?";
   cin >> longestWait;
   while(longestWait < 0)
   {
      cout << "Invalid choice. Number must be positive";
      cin >> longestWait;
   }
   // setw(10) << setprecision(5) to format table
   //setus up format of table
   cout << setw(15) << "Start Year|"
      << setw(15) << "Avg Speed|"
      << setw(15) << "EarthETA|"
      << setw(15) << "Your ETA|" << endl;
   for(int i=2018; i<= longestWait+2018; i++)
   {
      cout << setw(14) << i << "|"
      << setw(14) << fixed << setprecision(2) << averageSpeed << "|"
      << setw(14) << fixed << setprecision(2) << earthETA(i, averageSpeed) << "|"
      << setw(14) << fixed << setprecision(2) << yourETA(i, averageSpeed) << endl;
      if(earthETA(i, averageSpeed)<earthTimeLeave)
      {
         yearLeave=i;
         yourTimeLeave=yourETA(i, averageSpeed);
         earthTimeLeave=earthETA(i, averageSpeed);
      }
      averageSpeed=averageSpeed+((299792-averageSpeed)*(precentFaster/100));
   }

   cout << "To get there soonest, you should leave in " << yearLeave << ". You will arrive in year "
      << fixed << setprecision(2) << yourTimeLeave << " your time (year "
      << fixed << setprecision(2) << earthTimeLeave << " Earth time.)" << endl;
   return 0;
}
