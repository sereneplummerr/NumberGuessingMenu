#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <unistd.h>
#include <limits>
using namespace std;

// Global enumeration constant for menu choices
enum MenuChoice {Match = 1, Display = 2, Giveup = 3, Exit = 4};

//Global int constant for array size
const int SIZE = 4;

//Function to get and validate player's name
string getName() {
    string playerName;
    bool isValid;
    while (true) {
        cout << "Enter your player name (only letters, numbers, and spaces are allowed):" << endl;
        getline(cin, playerName); // grabs the whole line of input and stores it in playerName
        isValid = true; // assuming the name is valid

        for (char ch : playerName) {
            if (!(isdigit(ch) || isalpha(ch) || ch == ' ')) { // checking if character is not a letter, number, or space
                isValid = false; // mark input as invalid
                break;
            }
        }

        if (isValid) {
            break; // exit loop if the name is valid
        } else {
            cout << "Invalid player name. Please try again." << endl;
        }
    }
    return playerName;
}

//Function to generate a random index of a 2D array
int genRandomIndex(){
    return rand() % SIZE; //generate a random number between 0 and size-1
}

//Function to shuffle the cards in the 2D array 
void shuffle(int cards[][SIZE]) {
    // perform 15 random swaps
    for (int i = 0; i < 15; i++) {
        // first card
        int row1 = genRandomIndex();
        int col1 = genRandomIndex();
        // second card
        int row2 = genRandomIndex();
        int col2 = genRandomIndex();
        // swap the cards
        int hold = cards[row1][col1]; // declare hold here
        cards[row1][col1] = cards[row2][col2];
        cards[row2][col2] = hold;
    }
}

//Function to initialize card array with pairs of numbers 1-8
void initalize(int cards[][SIZE], int status[][SIZE]) {
    // card array with pairs of numbers 1-8
    int cardValue = 1;
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            cards[row][col] = cardValue;

            // after every 2 cards, increment the value (1-8)
            if ((row * SIZE + col + 1) % 2 == 0) {
                cardValue++;
            }
        }
    }

    // set all cards to be faced down
    for (int row = 0; row < SIZE; row++) { // increment row here
        for (int col = 0; col < SIZE; col++) {
            status[row][col] = 0;
        }
    }

    // shuffle the cards
    shuffle(cards);
}

//Function to display the cards 
void showCards(int cards[][SIZE], int status[][SIZE], bool showReal = false){
    const int width = 25;
    cout << endl;
    cout << "    0     1     2     3" << endl;
    cout << setfill('-') << setw(width) << "-" << endl; // seperator line
    //print each row
    for (int row = 0; row < SIZE; row++){
        cout << row << " | "; // row header
        for (int col = 0; col < SIZE; col++){
            if(showReal || status[row][col] == 1){ //if card is faced up
                cout << cards[row][col] << "     ";
        }
        else { // for face down cards
            cout << "*     ";
        }
    }
    cout << endl;
}
}

//Function to check if cards are face up
bool allFaceUp(int status[][SIZE]){
    for (int row = 0; row < SIZE; row++){
        for (int col = 0; col < SIZE; col++){
            if (status[row][col] == 0){
                return false; //found a card that is face down
            }
        }
    }
    return true; //All cards are face up
}

// check if the Input is valid 
bool checkInputs(int status[][SIZE], int row, int col){
    //check if coordinates are within valid range
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE){
        //check if the card is face down
        if (status[row][col] == 0){
            return true; //valid input
        }
       
            return false; //card is already face up
        }
    }

//Function to match two cards
int match(int cards[][SIZE], int status[][SIZE], int& points){
    int row1, col1, row2, col2;
    //Show card arrangement by calling showCards function
    showCards(cards, status);

    //Ask users for the first card
    cout << "Enter coordinate for first card: (row column) "; // used ai to help with this
        cin >> row1 >> col1;
        if (cin.fail()) {
        cin.clear(); // clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        cout << "Invalid input. Please enter numeric coordinates." << endl;
    return -1;
}
    if (!checkInputs(status, row1, col1)){
        cout << "Invalid input. This card is already faced up!" << endl;
        return -1; //invalid input - card already face up
    }

    //Ask users for the second card
    cout << "Enter coordinate for second card: (row column) "; 
    cin >> row2 >> col2;
    if (row2 < 0 || row2 >= SIZE || col2 < 0 || col2 >= SIZE){
        cout << "Invalid input. Try asking for a card in range next time!" << endl;
        return -1; //invalid input - cordinates out of range
    }
    if (!checkInputs(status, row2, col2)){
        cout << "Invalid input. This card is already faced up!" << endl;
        return -1; //invalid input - card already face up
    }

    if (row1 == row2 && col1 == col2){
        cout << "Invalid input. Try inputting different coordinates next time!" << endl;
        return -1; //invalid input - same coordinates
    }

    //extract the values of the cards
    int card1 = cards[row1][col1];
    int card2 = cards[row2][col2];
    //show cards to user
    status[row1][col1] = 1; //set card to face up
    status[row2][col2] = 1; //set card to face up
    showCards(cards, status); //show cards
    //check if the two cards match
    if (card1 == card2){
        cout << "Cards match at locations: (" << row1 << ", " << col1 << ") and (" << row2 << ", " << col2 << ")" << endl;
        points += 5; //increment points
        cout << "Your updated points are: " << points << endl;
    } 
    
    else {
        cout << "Cards do not match at locations: (" << row1 << ", " << col1 << ") and (" << row2 << ", " << col2 << ")" << endl;
        sleep(7); //pause for 7 seconds bc i 
        cout << "(screen clear)" << endl;
        system("clear"); //clear the screen
        status[row1][col1] = 0; // face down
        status[row2][col2] = 0; //set cards back to face down
        points -= 1; //decrement points
        cout << "Your updated points are: " << points << endl;
    }
}

//Function to display one identical pair of cards that has not been faced up yet
int display(int cards[][SIZE], int status[][SIZE], int& points){
    if (points < 10){
        cout << "You do not have enough points to display a pair of cards!" << endl;
        return -1; //not enough points to display a card
    }
    //find the first pair of cards that are not face up
    for (int row1 = 0; row1 < SIZE; row1++){
        for (int col1 = 0; col1 < SIZE; col1++){
            if (status[row1][col1] == 0){ //if card is face down
            int cardValue = cards[row1][col1]; //get the value of the card

            //FIND THE MATCHING CARD
            for (int row2 = 0; row2 < SIZE; row2++){
                for (int col2 = 0; col2 < SIZE; col2++){
                    if (status[row2][col2] == 0 && cards[row2][col2]==cardValue && !(row1 == row2 && col1 == col2)){
                        //show cards
                        status[row1][col1] = 1;
                        status[row2][col2] = 1;

                        //Display the updated cards
                        showCards(cards, status);

                        //Deduct 10 points
                        points -= 10;
                        cout << "Your updated points are: " << points << endl;
                        return 0;
                    }
                }
            }
        }
    }
}
    //If no matching pair is found
    cout << "No identical pair of cards available!" << endl;
}

//Function to display the menu
void displayInfo() {
    // Function to display author information
    const int width = 50;
    cout << setfill('-') << setw(width) << "-" << endl;
    cout << setfill(' ') << setw((width + 30 )/ 2) <<"Computer Science and Engineering" << endl;
    cout << setfill(' ') << setw((width + 30)/ 2) <<"CSCE 1030 - Computer Science I" << endl;
    cout << setfill(' ') << setw((width + 30)/ 2) <<  "Serene Plummer sp3155 SerenePlummer@my.unt.edu" << endl;
    cout << setfill('-') << setw(width) << "-" << endl;
}


int main() {
	displayInfo();
    srand(time(0)); //seed the random number generator
    
    //initalize the card array
    int points = 50; //points
    int cards[SIZE][SIZE]; // holds the arrangement of cards
    int status[SIZE][SIZE]; // holds the status of cards (face up or face down)
    initalize(cards, status); //initialize the cards


    //Prompt user to enter their name
    string name = getName();
	cout << "Welcome " << name << "!" << endl;


    //Variable for menu choice
        int choice;
        MenuChoice menuOption;

            //Game Loop
            while(true){
                //check if points are below zero
                if (points < 0){
                    cout << "Oh no! Looks like you've ran out of points!" << endl;
                    cout << "Would you like to play again " << name << "? (Y/N): ";
                    char playAgain;
                    cin >> playAgain;

                    if (toupper(playAgain) != 'Y') { //user does not want to play again
                    cout << "Your final points are: " << points << endl;
                    cout << "Goodbye, " << name << "." <<  endl;
                    return 0;
                    } else {
                        points = 50;
                        initalize(cards, status); //reinitialize the cards
                        cout << "Restarting the game... loading... " << endl;
                        cout << endl;
                    }
                break;
                }

                //Display menu
                const int width = 50;
                cout << setfill('-') << setw(width) << "-" << endl;
                cout << "1. Match" << endl;
                cout << "2. Display" << endl;
                cout << "3. Giveup" << endl;
                cout << "4. Exit" << endl;
                cout << "What would you like to do? (1-4): ";
                cin >> choice;

                //validate input 
                if (choice < 1 || choice > 4){
                    cout << "Invalid input. Please enter a number between 1 and 4." << endl;
                    continue; //continue to the next iteration of the loop
                }  

                //Process menu choice
                choice = static_cast<MenuChoice>(choice);
	            switch (choice) {
	            case 1: { // Match
                    match(cards, status, points);
                    break;
                }
                case 2: { // Display
                    display(cards, status, points);
                    break;
                }
                case 3: { // Giveup
                    cout << "Locations of cards were: " << endl;
                    showCards(cards, status, true); //show all cards

                    char playAgain;
		            cout << "Would you like to play again? (Y/N): ";
                    cin >> playAgain;

                    if (toupper(playAgain) != 'Y') { //user does not want to play again
                    cout << "Your final points are: " << points << endl;
                    cout << "Goodbye, " << name << "." <<  endl;
                    return 0;
                    } else {
                        points = 50;
                        initalize(cards, status); //reinitialize the cards
                        cout << "Restarting the game... loading... " << endl;
                        cout << endl;
                    }
                break;
                }
                case 4: { // Exit
                    cout << "Exiting the game... Goodbye, " << name << endl;
                    cout << "Your final points are: " << points << endl;
                    return 0;
                }
                default: { // Invalid choice
                    cout << "Invalid choice. Please eneter a number between 1 and 4." << endl;
                    break;
                }
    }

            if(allFaceUp(status)){
                cout << "Wow! Looks like you've matched all the cards. Good job!" << endl;
                cout << "Your final points are: " << points << endl;
                cout << "Would you like to play again? (Y/N): ";
                char playAgain;
                cin >> playAgain;

                if (toupper(playAgain) != 'Y') { //user does not want to play again
                    cout << "Goodbye, " << name << "." <<  endl;
                    return 0;
                } else {
                    points = 50;
                    initalize(cards, status); //reinitialize the cards
                    cout << "Restarting the game... loading... " << endl;
                    cout << endl;
                }
            }
    }
}
    