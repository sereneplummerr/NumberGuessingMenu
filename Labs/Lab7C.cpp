#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

//function declaration is provided
double compute_bonus(double base_salary, int experience);

int main(){

double base_salary;
int experience;
// get the values of base_salary
cout << "Enter the base salary: $";
cin >> base_salary;

// and experience from the user
cout << "Enter the experience: ";
cin >> experience;

// call compute_bonus by passing necessary parameters
double bonus = compute_bonus(base_salary, experience);

// display the bonus returned by the function
cout << "Bonus earnerd: $" << fixed << setprecision(2) << bonus << endl;
return 0;
}

//function definition 
double compute_bonus(double base_salary, int experience)
{
    double bonus;
    //compare experience and calculate bonus
    if (experience > 10){
        bonus = 0.05 * base_salary; 
    }
    else {
        bonus = 0.03 * base_salary;
    }
    
 return bonus;   
}


/* Author: Serene Plummer (SerenePlummer@my.unt.edu)

Date: 3/3/25

Instructor: Mohammed Abutayyem

Description: calculating a bonus based on experience and base salary

*/
