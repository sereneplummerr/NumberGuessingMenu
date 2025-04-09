//this program reads the entire contents of an input file and writes it to an output file
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
    char c;
    string inputFileName, outputFileName; //file names

    //prompt user for input file name
    cout << "Enter the name of the input file: ";
    cin >> inputFileName; //get the name of the input file

    //prompt user for output file name
    cout << "Enter the name of the output file: ";
    cin >> outputFileName; //get the name of the output file

    //open the input file for reading
    ifstream inFile(inputFileName);
        if (!inFile){
        cout << "There was an error opening the input file " << inputFileName << endl;
        return 1; //exit the program
    }

     //open the output file for reading
     ofstream outFile(outputFileName);
     if (!outFile){
     cout << "There was an error opening the output file " << outputFileName << endl;
     inFile.close(); //close the input file
     return 1; //exit the program
 }

    inFile.get(c); //get the first character from the input file
    
    while (!inFile.eof()){ //check if end of file is reached
        outFile.put(c); //output the character to the output file
        inFile.get(c); //get the next character from the input file
    }

    inFile.close(); //close the input file
    outFile.close(); //close the output file

    cout << "File copied successfully from " << inputFileName << " to " << outputFileName << endl;

    // to run code and check for accuracy : ./Lab9B
                                        //  cat out9B.txt

    return 0; //exit the program
}

/* Author: Serene Plummer (SerenePlummer@my.unt.edu)

Date: 4/1/25

Instructor: Mohammed Abutayyem

Description: this program reads the entire contents of an input file and writes it to an output file

*/
