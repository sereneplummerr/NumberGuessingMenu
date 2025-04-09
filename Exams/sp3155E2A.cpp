
#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cctype>
using namespace std;

//num for number of elements
int calcMed(int grades[], int num){ 
    int temp;
    for (int i = 0; i < num - 1; i++){
        for (int j = i + 1; j < num; j++){
            if (grades[i] > grades[j]){
                temp = grades[i];
                grades[i] = grades[j];
                grades[j] = temp;
            }
        }
    }
    //return the median value
    return grades[num / 2];
}

int main(){
    //Declare variables
    const int SIZE = 15;
    int grades[SIZE];
    int median = 0;

    srand(time(0)); //seed the random number generator
    
    for (int i = 0; i < SIZE; i++){
    int randGrade = rand() % 101;    
    grades[i] = randGrade; //generate random grades between 0 and 100
    cout << grades[i] << " "; //display the grades
    }
    cout << endl; //newline for better readability

    //call calcMed function
    median = calcMed(grades, SIZE);
    for (int i = 0; i < SIZE; i++){
        cout << grades[i] << " "; //display the grades
    }
    cout << endl; //newline for better readability
    cout << "The median is: " << median << endl; //display the median

return 0;
}

