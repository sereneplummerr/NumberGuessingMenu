#include "Lab8_Header.h"

void computeMaximum(float array2D[][COLS], int num, float maximum[]) {
    for (int row = 0; row < num; row++) {
        float maxGrade = array2D[row][0];
        for (int col = 1; col < COLS; col++) {
            if (array2D[row][col] > maxGrade) {
                maxGrade = array2D[row][col];
            }
        }
        maximum[row] = maxGrade;
    }
}
