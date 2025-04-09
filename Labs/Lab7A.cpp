/* Author: Serene Plummer (SerenePlummer@my.unt.edu)

Date: 3/3/25

Instructor: Mohammed Abutayyem

Description: allows the user to enter a 2D matrix 
and display it. Compile and run the following program to understand what it does.
*/


#include <iomanip>
#include <iostream>
using namespace std;

int main(){

const int ROW_SIZE = 2; // number of rows
const int COLUMN_SIZE = 5; // number of columns
int matrix[ROW_SIZE][COLUMN_SIZE]; // 2D Array

// input matrix elements
for (int i = 0; i < ROW_SIZE; ++i){
    for (int h = 0; h < COLUMN_SIZE; ++h){
        cout << "Enter data for row #" << i + 1 << " and column #" << h + 1 << ": ";
        cin >> matrix[i][h]; // read matrix elements
        cout << endl;
    }
}

cout << "You entered: " << endl;
for (int i = 0; i < ROW_SIZE; ++i){
    for (int h = 0; h < COLUMN_SIZE; ++h){
        cout  << setw(5) << matrix[i][h] << "\t"; // display matrix elements
    }
    cout << endl;
}


//find minimum in each row
int min_row[ROW_SIZE];
int min_col[COLUMN_SIZE];

for (int i = 0; i < ROW_SIZE; ++i){
    min_row[i] = matrix[i][0]; // first variable
    for (int h = 1; h < COLUMN_SIZE; ++h){
        if (matrix[i][h] < min_row[i]){
            min_row[i] = matrix[i][h]; // revalues the minimum
        }
    }
}

//find minimum in each column
for (int h = 0; h < COLUMN_SIZE; ++h){
    min_col[h] = matrix[0][h]; //first variable
    for (int i = 1; i < ROW_SIZE; ++i){
        if (matrix[i][h] < min_col[h]){
            min_col[h] = matrix[i][h]; // revalues the minimum
        }
    }
}

//display minimum in each row
cout << "\n Minimum in each row: " << endl;
for (int i = 0; i < ROW_SIZE; ++i){
    cout << "Row #" << i + 1 << ": " << min_row[i] << endl;
}

//display minimum in each column
cout << "\n Minimum in each column: " << endl;
for (int h = 0; h < COLUMN_SIZE; ++h){
    cout << "Column #" << h + 1 << ": " << min_col[h] << endl;
}


return 0;
}
