#include <iostream>
using namespace std;
#include <iomanip>

int main()
{
   //output welcome statement
   cout << "\nYou’re a wizard Harry! Pick an animal familiar to deliver your mail and strike down your enemies. Here are the options:\n\n 1. Owl \n 2. Cat \n 3. Rat \n";
   //get animal familiar
   int animal=0;
   cout << endl  << "Your choice of animal familiar: ";
   cin >> animal;
   string animals;
   switch(animal)
   {
      case 1:
      {
         animals="Owl";
         break;
      }
      case 2:
      {
         animals="Cat";
         break;
      }
      case 3:
      {
         animals="Rat";
         break;
      }
      default:
         animals="Default";
   }
   //output directions
   cout << endl << "Now we must sort you into a House. For each category, please enter a positive integer. The highest integer will determine which house you are sorted into.\n \n";
   //declare variables
   float bravery=-1;
   float loyalty=-1;
   float intelligence=-1;
   float cunning=-1;
   //input variables && test variables
   while(bravery<0 || loyalty<0 || intelligence<0 || cunning<0)
   {
      cout << "Bravery: ";
      cin >> bravery;
      cout << "Loyalty: ";
      cin >> loyalty;
      cout << "Intelligence: ";
      cin >> intelligence;
      cout << "Cunning: ";
      cin >> cunning;
      if(bravery<0 || loyalty<0 || intelligence<0 || cunning<0)
         cout << "All integers must be postitive.\n";
   }
   //output precents
   int total=bravery+loyalty+intelligence+cunning;
   bravery=(bravery/total)*100;
   loyalty=loyalty/total*100;
   intelligence=intelligence/total*100;
   cunning=cunning/total*100;
   cout << "\n You are: \n";
   cout << fixed << setprecision(2) << bravery << "% Gryffindor" << endl;
   cout << fixed << setprecision(2) << loyalty << "% Hufflepuff" << endl;
   cout << fixed << setprecision(2) << intelligence << "% Ravenclaw" <<  endl;
   cout << fixed << setprecision(2) << cunning << "% Slytherin" << endl;
   //output house and animal
   string house=" ";
   if(bravery>=loyalty && bravery>=intelligence && bravery>=cunning)
      house="Gryffindor";
   else if(loyalty>bravery && loyalty>=intelligence && loyalty>=cunning)
      house="Hufflepuff";
   else if(intelligence>bravery && intelligence>loyalty && intelligence>=cunning)
      house="Ravenclaw";
   else if(cunning>bravery && cunning>loyalty && cunning>intelligence)
      house="Slytherin";
   cout << "\nCongratulations! You are a " << house << " with a beautiful pet " << animals <<".\n\n";

   return 0;
}
