#ifndef LAB8_HEADER_H
#define LAB8_HEADER_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

const int COLS = 6; // 6 quiz grades
const int ROWS = 10; // 10 students

void computeMaximum(float array2D[][COLS], int num, float maximum[]);
void showArray(float array[], int size);

#endif