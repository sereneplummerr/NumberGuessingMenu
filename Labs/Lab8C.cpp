#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Lab8_Header.h"
using namespace std;

const int COLS = 6; //6 quiz grades
const int ROWS = 10; // 10 students
void computeMaximum(float grades[][COLS], int num, float maximum[]); 
void showArray(float array[], int size);

int main(){
  float grades[ROWS][COLS]; // 2D array to store grades
  float maximum[ROWS]; // array to store maximum grades
  int num; //number of students in class

  cout << "How many students in the class?"; 
  cin >> num; // get number of students

  for (int row = 0; row < num; row++){
    // enter 6 quiz grades for each student
    
    for (int col = 0; col < COLS; col++){
        cout << "Enter QUIZ # " << col + 1 << " for STUDENT # " << row + 1 << ": ";
        cin >> grades[row][col];
    }
  }

  //call function to compute maximum grade for each student
    computeMaximum(grades, num, maximum);
    for (int row = 0; row < num; row++){
        for (int col = 0; col < COLS; col++){
            cout << grades[row][col] << " ";
        }
        cout << endl;
    }

    cout << "The maximum grades: \n";
    showArray(maximum, num);
    cout << endl;




return 0;
}

/* Author: Serene Plummer (SerenePlummer@my.unt.edu)



Instructor: Mohammed Abutayyem

Description:swaps letters from greatest to least 

*/
