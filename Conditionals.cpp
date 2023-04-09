/*
 Created by Nicholas Howland
 Date: 2023-01-24
 Purpose: use logic operators to test math statements in C++
*/
#include <iostream>
using namespace std;
int main()
{


cout << "Hypotheses: false" << endl;
// Hypothisis: evaluates to false
if(0){
cout << "It's true\n";
} else {
cout << "It's false\n";
}

cout << "Hypotheses: True" << endl;
// Hypothisis: Evaluates to true
if(-7){
    cout << "It's true\n";
} else {
    cout << "It's false\n";
}

cout << "Hypotheses: True" << endl;
// Hypothisis: Evaluates to true
if(-1 + -2){
    cout << "It's true\n";
} else {
    cout << "It's false\n";
}

cout << "Hypotheses: False" << endl;
// Hypothisis: Evaluates to false
if(-7 + 7){
    cout << "It's true\n";
} else {
    cout << "It's false\n";
}

cout << "Hypotheses: True" << endl;
// Hypothisis: Evaluates to true
if(7 < 8){
    cout << "It's true\n";
} else {
    cout << "It's false\n";
}

cout << "Hypotheses: False" << endl;
// Hypothisis: Evaluates to false
if(10 > 10){
    cout << "It's true\n";
} else {
    cout << "It's false\n";
}

cout << "Hypotheses: True" << endl;
// Hypothisis: Evaluates to true
if((7 < 10) || (7 > 10)){
    cout << "It's true\n";
} else {
    cout << "It's false\n";
}

cout << "Hypotheses: False" << endl;
// Hypothisis: Evaluates to false
if((7 < 10) && (7 > 10)){
    cout << "It's true\n";
} else {
    cout << "It's false\n";
}

cout << "Hypotheses: False" << endl;
// Hypothisis: Evaluates to false
if(-5 >= 5){
    cout << "It's true\n";
} else {
    cout << "It's false\n";
}

cout << "Hypotheses: False" << endl;
// Hypothisis: Evaluates to false
if((7 > 10) || (-5 == 5)){
    cout << "It's true\n";
} else {
    cout << "It's false\n";
}
cout << "Hypotheses: True" << endl;
// Hypothisis: Evaluates to true
if(!(6 == 7)){
    cout << "It's true\n";
} else {
    cout << "It's false\n";
}

cout << "Hypotheses: False" << endl;
// Hypothisis: Evaluates to false
if((10 != 11) && (7 > 8)){
    cout << "It's true\n";
} else {
    cout << "It's false\n";
}

cout << "Hypotheses: True" << endl;
// Hypothisis: Evaluates to true
if((7 == 6) || (7 == 7) || (7 == 8)){
    cout << "It's true\n";
} else {
    cout << "It's false\n";
}

cout << "Hypotheses: False" << endl;
// Hypothisis: Evaluates to false
if(6 < (8 && 9)){
    cout << "It's true\n";
} else {
    cout << "It's false\n";
}

cout << "Hypotheses: True" << endl;
// Hypothisis: Evaluates to true
if(1 == (6 < 8)){
    cout << "It's true\n";
} else {
    cout << "It's false\n";
}

cout << "Hypotheses: False" << endl;
// Hypothisis: Evaluates to false
if(0 == (0 || 1)){
    cout << "It's true\n";
} else {
    cout << "It's false\n";
}

cout << "Hypotheses: True" << endl;
// Hypothisis: Evaluates to true
if(6 < (5 + 2)){
    cout << "It's true\n";
} else {
    cout << "It's false\n";
}

cout << "Hypotheses: True" << endl;
// Hypothisis: Evaluates to true
if(6 + (5 == 5)){
    cout << "It's true\n";
} else {
    cout << "It's false\n";
}

cout << "Hypotheses: True" << endl;
// Hypothisis: Evaluates to true
if((6 < 7) + (7 >= 5)){
    cout << "It's true\n";
} else {
    cout << "It's false\n";
}

cout << "Hypotheses: True" << endl;
cout << "Evaluates to false because the result of the operation == 0" << endl;
// Hypothisis: Evaluates to true because 0-0 is a true statement
// Hypothisis is incorrect becuase the returned value from the operation is 0
if((0 < 7) - (0 < 7)){
    cout << "It's true\n";
} else {
    cout << "It's false\n";
}


}
