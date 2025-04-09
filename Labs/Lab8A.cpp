#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int getRandom(){
    //generate a rand num from 1 to 100
    int randNum1 = rand() % 101 + 1;
    return randNum1;
}

void compare(int guess){
    int g = getRandom();
    if (guess == g){
        cout << "Random number was " << g << ". You guessed correctly!" << endl;
    }
    else if (guess > g){
        cout << "Random number was " << g << ". Your guess was higher!" << endl;
    }
    else{
        cout << "Random number was " << g << ". Your guess was lower!" << endl;
    }
    }
    

int main(){
  
    int guess;
    cout << "Enter a number between 1 and 100: ";
    cin >> guess;
    compare(guess);


return 0;
}


/* Author: Serene Plummer (SerenePlummer@my.unt.edu)

Date: 3/27/25

Instructor: Mohammed Abutayyem

Description: This program generates a random number between 1 and 100 and asks the user to guess the number. The program will then compare the user's guess to the random number and output if the guess was higher, lower, or correct.

*/
