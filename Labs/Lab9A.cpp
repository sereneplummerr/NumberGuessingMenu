#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main (){
    //open the input file for reading
    ifstream inFile("data.dat");   
    //check if the file opened successfully
    if (!inFile){
        cout << "There was an error opening the input file." << endl;
        return 1; 
    }

    //open the output file for writing
    ofstream outFile("average.dat");
    //check if the file opened successfully
    if (!outFile){
        cout << "There was an error opening the output file." << endl;
        inFile.close();
        return 1; 
    }

    int num1, num2, num3; // store three numbers from each line

    outFile << fixed << setprecision(2); // set output format for floating point numbers

    while (inFile >> num1 >> num2 >> num3){
        double average = (num1 + num2 + num3) / 3.0; // calculate average
        outFile << average << endl;
        cout  << fixed << setprecision(2) << average << endl; // print average to console
    }

    inFile.close(); // close the input file
    outFile.close(); // close the output file
    cout << "Program completed successfully." << endl;
    return 0;

    //to run code and check for accuracy : cat average.dat

}


/* Author: Serene Plummer (SerenePlummer@my.unt.edu)

Date: 4/1/25

Instructor: Mohammed Abutayyem

Description: this program reads the entire contents of an input file and writes it to an output file
and calculates the average of three numbers from each line

*/
