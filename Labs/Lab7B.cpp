/* Author: Serene Plummer (SerenePlummer@my.unt.edu)

Date: 3/3/25

Instructor: Mohammed Abutayyem

Description: declaring two C-strings, then checking if they are the same length outputting results to the usr

*/


#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;

int main(){

char str1[50];
char str2[50];

//copying the string
strcpy(str1, "We are completing Lab7 today.");

//prompt the user to enter a string
cout << "Enter a phrase with more than one word: "; 
cin.getline(str2, 50);

//storing length
int length1 = strlen(str1);
int length2 = strlen(str2);

//check length is the same
if(length1 != length2){
    cout << "The C-strings are NOT the same length and must be different words" << endl;
    return 0;
}
else{
    cout << "The C-strings are the same length." << endl;
}

if (strncmp(str1, str2, 50) == 0){
    cout << "The two C-strings are the same." << endl;
}
else {
    cout << "The two C-strings are NOT the same." << endl;
}

return 0;
}
