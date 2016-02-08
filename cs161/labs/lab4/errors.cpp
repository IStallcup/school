#include <iostream>
#include <cmath>

using namespace std; //no namespace originally

//Defines the specific weight of water

#define WATER_WEIGHT 64.2;
#define PI 3.14; // pi not defined

int main(){
   //Variables needed to calculate bouyancy
   float radius, b_force, volume; //b_force was"bforce"

   //Prompt usee for weight and radius of sphere
   cout << "Please enter the weight (lbs): "; //added semicolon
   int weight; //defined weight
   cin >> weight;

   cout << "Please enter the radius: ";
   cin >> radius;

   //Calculate the volume and bouyancy force
   volume = 4./3. * PI; //added newline
   volume = volume * pow(radius, 3); //radius was "r", pow was "power", parenthesis around 4./3.
   b_force = volume * WATER_WEIGHT; //spelling of volume

   //Determine if the sphere will sink or float
   if(b_force >= weight) //b_force misspelled, >==
   {
   	cout << "The sphere will float! \n"; //cout had >>
   } // missing from original program
   else //semicolon here was improperly placed
   { // was not originally here
   	cout << "The sphere will sink!\n"; //cout had >>
   }
   return 0; //originally no zero



}
