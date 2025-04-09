/* Author: Serene Plummer (SerenePlummer@my.unt.edu)

Date: 3/3/25

Instructor: Mohammed Abutayyem

Description: took number of wheels and tire brand and calculated the total cost of the tires.

*/

#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(){

enum CarType {MotorCycle = 2, Car = 4, Semi = 18};
CarType typeOfCar;

enum TireBrand {Michelin = 'M', Goodyear = 'G', Cooper = 'C'};
//TireBrand brandOfTire;

int numTires;
double pricePerTire;
char brandOfTire;

cout << "Enter the number of tires: ";
cin >> numTires;

do {
    //prompt for tire brand as a char
    cout << "Do you want Michelin, Goodyear, or Cooper tires? (M, G, C): ";
    cin >> brandOfTire;
    //convert char to uppercase
    brandOfTire = toupper(brandOfTire);
    //validate the brand of tire
    switch (brandOfTire){
        case 'M':
        pricePerTire = 268.41;
        break;
        
        case 'G':
        pricePerTire = 146.23;
        break;

        case 'C':
        pricePerTire = 78.34;
        break;

        default:
        pricePerTire = 78.34;
        brandOfTire = 'C'; //assume Cooper for anything other
        break;
    }
    }
    while (brandOfTire != 'M' && brandOfTire != 'G' && brandOfTire != 'C'); //end do-while loop 

    switch(numTires){
        case 2:
        
        cout << "Total cost for MotorCycle tires $" << fixed << setprecision(2) << numTires * pricePerTire << endl;
        break;

        case 4:
        CarType = Car;
        cout << "Total cost for Car tires $" << fixed << setprecision(2) << numTires * pricePerTire << endl;
        break;

        case 18:
        CarType = Semi;
        cout << "Total cost for Semi tires $" << fixed << setprecision(2) << numTires * pricePerTire << endl;
        break;

        default:
        cout << "Invalid number of tires. Unkown vehicle type. No sale." << endl;
        break;
    }

    return 0;
}
