//sp3155Project1.cpp

#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//used chatgbt to understand the void code and how to write it
void displayInfo() {
	cout << "Computer Science and Engineering" << endl;
	cout << "CSCE 1030 - Computer Science I" << endl;
	cout << "Serene Plummer sp3155" << endl;
	cout << "SerenePlummer@my.unt.edu" << endl;
}



int main() {
	srand(time(0)); // Initialize random number generator
	displayInfo();

	//declaring variables
	int startPoints = 50;
	enum MenuChoice  {ADD = 1, SUBTRACT = 2, DISPLAY = 3, GIVEUP = 4, EXIT = 5};
	MenuChoice choice;
	
	string playerName;
	bool isValid;
	char playAgain;
	char restart;
	

	//prompt user to enter their name
	while(true) {
		cout << "Enter your player name (only letters, numbers, and spaces are allowed):" << endl;
		getline(cin, playerName); //grabs the whole line of code and stores it in playerName
		isValid = true; //assuming the name is valid

		for(char ch: playerName) {
			if(!(isdigit(ch) || isalpha(ch) || ch == ' ')) { //checking if character is not a letter, number, or space
				isValid = false;
				break;
			}
		}
		if (isValid) {
			break; //exit loop
		}
		else {cout << "Invalid player name. Please try again." << endl;}
		}

		cout << "Welcome " << playerName << "!" << endl;
		cout << "You have " << startPoints << " points." << endl;

	//game loop
    while(true){
	int randNum1, randNum2, answer, guess;
	bool displayed = false;
	
	randNum1 = rand() % 51 + 50; // Random between 50 to 100
    randNum2 = rand() % 51 + 50;
	if(randNum1 >= randNum2) {
		randNum1 = rand() % 51 + 50;
	}
		//cout << "Random #1 is: " << randNum1 << " Random #2 is: " << randNum2 << endl;  // (my own check for accuracy, ignore)
		cout << "Your two random numbers have been generated." << endl;

	//automates the menu choices
    while (true) {
	cout << "What would you like to do?" << endl;
	cout << "1. ADD \n2. SUBTRACT \n3. DISPLAY \n4. GIVEUP \n5. EXIT \n";
	scanf("%d", &answer);
	cout << "Your choice: " << answer <<endl; // creates an answer display outside the switch statement rather than inside

	choice = static_cast<MenuChoice>(answer);
	switch (choice) {
	case 1: {
		cout << "Guess the sum of the two random numbers: ";
		scanf("%d", &guess);
		int sum = randNum1 + randNum2;
		if (abs(sum - guess) < 5) { //used copilot to pull the idea of abs
			cout << "Correct! You have earned 5 points." << endl;
			startPoints += 5;
		}
		else {
			cout << "Incorrect! You have lost 1 points." << endl;
			startPoints -= 1;
		}
		cout << "You now have " << startPoints << " points." << endl;


		char playAgain;
		cout << "Would you like to play again? (Y/N): ";
		cin >> playAgain;
		if (toupper(playAgain) != 'Y') {
			//user does not want to play again
			cout << "Goodbye!" << endl;
			return 0;
		}
		else {
			displayed = false;
			//regenerates the random numbers
			randNum1 = rand() % 51 + 50; // Random between 50 to 100
    randNum2 = rand() % 51 + 50;
	if(randNum1 >= randNum2) {
		randNum1 = rand() % 51 + 50;

		}
		break;
	}
	break;
}


	case 2: {
		cout << "Guess the difference of the two random numbers: ";
		scanf("%d", &guess);
		int diff = abs(randNum2 - randNum1);
		if (abs(diff - guess) < 5) {
			cout << "Correct! You have earned 5 points." << endl;
			startPoints += 5;
			cout << "You now have " << startPoints << " points." << endl;
		}
		else {
			cout << "Incorrect! You have lost 1 points." << endl;
			startPoints -= 1;
			cout << "You now have " << startPoints << " points." << endl;
		}

		char playAgain;
		cout << "Would you like to play again? (Y/N): ";
		cin >> playAgain;
		if (toupper(playAgain) != 'Y') {
			//user does not want to play again
			cout << "Goodbye!" << endl;
			return 0;
		}
		else {
			displayed = false;
			//regenerates the random numbers
			randNum1 = rand() % 51 + 50; // Random between 50 to 100
    randNum2 = rand() % 51 + 50;
	if(randNum1 >= randNum2) {
		randNum1 = rand() % 51 + 50;
		}
		break;
	}
	break;
}

	case 3: { 
		if (!displayed) {
		cout << "The first random number is " << randNum1 << " ." << endl;
		startPoints -= 3;
		cout << "You now have " << startPoints << " points." << endl;
            displayed = true;
        }
		else {
			cout << "You have already displayed the first number." << endl;
		}

		break;
	}
	case 4:{
		cout << "You have given up. You have " << startPoints << " points." << endl;
		cout << "The two random numbers were: " << randNum1 << " and " << randNum2 << endl;
		cout << "Would you like to play again? (Y/N): ";
		char playAgain;
		cin >> playAgain;
		if (toupper(playAgain) != 'Y') {
			//user does not want to play again
			cout << "Goodbye!" << endl;
			return 0;
		}
		else {
			cout << endl;
			cout << "Restarting the game... loading... " << endl;
			cout << endl;
			displayed = false;
			//reset points
			startPoints = 50;
			//regenerates the random numbers
			randNum1 = rand() % 51 + 50; // Random between 50 to 100
    randNum2 = rand() % 51 + 50;
	if(randNum1 >= randNum2) {
		randNum1 = rand() % 51 + 50;
	}
		//cout << "Random #1 is: " << randNum1 << " Random #2 is: " << randNum2 << endl;  // (my own check for accuracy, ignore)
		cout << "Your two random numbers have been generated." << endl;

		}
		break;
	}

	case 5:	{
		cout << "Exiting the game. Goodbye!" << endl;
		cout << "The two random numbers were: " << randNum1 << " and " << randNum2 << endl;
		
		return 0;
	}
	default:{
		cout << "Wrong Choice. Please enter a number between 1 and 5." << endl;
	}
	

	char playAgain;
		cout << "Would you like to play again? (Y/N): ";
		cin >> playAgain;
		if (toupper(playAgain) != 'Y') {
			//user does not want to play again
			cout << "Goodbye!" << endl;
			return 0;
		}
		else {
			displayed = false;

		}
			break;
	}


	//If points run out 
	if (startPoints <= 0) {
		cout << "Sadly you have ran out of points. Game Over!" << endl;
		cout << "We'd love for you to play again. Would you like to restart? (Y/N): " << endl;
		cin >> restart;
		if (toupper(restart) != 'Y') {
			//user does not want to play again
			cout << "The two random numbers were: " << randNum1 << " and " << randNum2 << endl;
			cout << "Goodbye!" << endl;
		
			return 0;
		}
		else {
			displayed = false;
		}
		cout << "Your final points: " << startPoints << endl;}
		}	
	}

		return 0;

	}
	









