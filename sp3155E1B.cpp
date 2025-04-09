/* Author: Serene Plummer (SerenePlummer@my.unt.edu)

Date: 3/3/25

Instructor: Mohammed Abutayyem

Description: guessing game where user guesses a number between 1 and 100. User can play multiple times. */

*/


#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(){
srand(time(0));
string name;
int guess;
int randNum;
int counter;
char response;


do{
    cout << "Enter your name: ";
    cin >> name;
    name[0] = toupper(name[0]);
    cout << "Hello " << name << "!" << endl;

    cout << name << ", can you guess a number between 1 and 100? (Y or N): "; 
    cin >> response;
    if(toupper(response) != 'Y'){
        cout << "That's too bad. We'll play another time!" << endl;
        return 0;
    }
    else{
        cout << "I'm so excited. Let's start..." << endl;
    }

    randNum = rand() % 100 + 1; // random number between 1 and 100
    counter = 0;
    do{
        cout << "Enter your guess :";
        cin >> guess;
        counter++;
        if(guess < randNum){
            cout << guess << " is too low. Try again." << endl;
        }
        else if(guess > randNum){
            cout << guess << " is too high. Try again." << endl;
        }
        else{ 
            cout << "Congratulations " << name << "! " << guess << " is correct in " << counter << " guesses." << endl;
        } 
}

while (guess != randNum); // Keep asking until guessed correctly

    cout << "Would you like to play again "<< name << " ? (Y or N): ";
        cin >> response;

    } 
    

    while (toupper(response) == 'Y'); // Loop if user wants to play again
    cout << "Thank you for playing! You did great" << endl;
    

return 0;
}