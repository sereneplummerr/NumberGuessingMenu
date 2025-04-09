#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

    void manipulateText(char orginalText[], char newText[], int& size){
        //copy orgtxt into newtxt
        strcpy(newText, orginalText);
        //Concatenate the text in orgtxt onto the end of newtxt
        strcat(newText, orginalText);
        //returns the length of the new text
        size = strlen(newText);
    }

int main(){
  
    //Declare variables
    char inPhrase[41]; //holds up to 40 characters
    char outPhrase[81]; //holds up to 80 characters
    int length = 0; 

    //prompt user for a phrase of letters up to 40 char into inPhrase
    cout << "Enter a phrase (40 letters max): ";
    cin.getline(inPhrase, 41); //getline reads a line of text, 41 so it counts all 40 chars
    length = strlen(inPhrase); //the length of the phrase

    //call manipulateText function
    manipulateText(inPhrase, outPhrase, length);
    
    cout << "Your old phrase was: " << inPhrase << endl;
    cout << "Your new phrase is: " << outPhrase << endl;
    cout << "It's length is: " << length << endl;

return 0;
}
