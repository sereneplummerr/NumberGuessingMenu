#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;


int main(){
  const int SIZE = 10;
  int numbers[SIZE];
  int max;
  srand(static_cast<unsigned>(time(0)));

  for (int i = 0; i < SIZE; i++){
    numbers[i] = rand() % 51 + 50;
    cout << "Random #" << i + 1 << ": " << numbers[i] << endl;
  }

    max = numbers[0];
    for (int i = 0; i < SIZE; i++){
    if (numbers[i] > max){
        max = numbers[i];
    }
  }

  cout << "Maximun: " << max << endl;
return 0;
}


/* Author: Serene Plummer (SerenePlummer@my.unt.edu)

Date: 3/27/25

Instructor: Mohammed Abutayyem

Description: This program generates 10 random numbers between 50 and 100 and outputs the numbers. The program then finds the maximum number in the array and outputs it.    

*/
