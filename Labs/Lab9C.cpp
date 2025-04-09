#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// sort the array.
//input array array
//size of the array: size 
void mySort(double array[], const int size){
    for (int i = 0; i < size; ++i){
        for (int j = i+1; j < size; ++j){
            if (array[i] > array[j]) {
                //write code here to:
                //swap the values between array[i] and array [j]
                double temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}


int main (){

    //constants
    const int MAX_SIZE = 100; // maximum size of the array

    //variables
    double numbers[MAX_SIZE];
    int count = 0;
    double number;

    //open the input file for reading
    ifstream inFile("unsorted.dat");

    //check if the file opened successfully
    if (!inFile){
        cout << "There was an error opening the input file: unsorted.dat" << endl;
        return 1; 
    }

    //read numbers from the file and store them in the array
    while (inFile >> number && count < MAX_SIZE){
        numbers[count] = number; // store the number in the array
        count++; // increment the count
    }

    //close the input file
    inFile.close();

    //display the unsorted array
    cout << "Unsorted array: " << endl;
    for (int i = 0; i < count; i++){
        cout << fixed << setprecision(2) << numbers[i] << " ";
    }
    cout << endl;

    mySort(numbers, count); // sort the array
    cout << "Sorted array (ascending order): " << endl;
    for (int i = 0; i < count; i++){
        cout << fixed << setprecision(2) << numbers[i] << " ";

    }
    cout << endl;

    return 0;

}



/* Author: Serene Plummer (SerenePlummer@my.unt.edu)

Date: 4/1/25

Instructor: Mohammed Abutayyem

Description: this program reads numbers from a file, sorts them in ascending order, and displays the sorted array

*/
