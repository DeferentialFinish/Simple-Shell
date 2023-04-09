/*
 Created by Nicholas Howland
 Date: 1-31-2023
 Purpose: Looping calculator
*/
#include <iostream>
using namespace std;
int main()
{
 int exit=1; // exit flag condition
// print intial dialogue that does not repeat
 cout << "This is a simple calculator that preforms an operation on variubles assigned by you\n";

// enter the calculator loop
 while(exit==1){// while exit flag is not set to true
// intialize variubles
  double x=0;
  double y=0;
  int opt=0;
  char choice;
// user inputs the variubles
  cout << "Enter variubles\n";
  cout << "x="; cin >> x;
  cout << "y="; cin >> y;

// Get the mathmatic operation from the user
  cout << "Enter a number that corrosponds to a mathmatic operation\n  1) addition\n  2) subtraction\n  3) multiplication\n  4) division\n";
  cout << "option: ";cin >> opt;
// check if the input is valid
  while  (opt > 4 || opt < 1){
   cout << "Choose an option between 1 and 4\n";
   cout << "option: ";cin >> opt;
  }
// preform the operation based on the option supplied
  if(opt==1){
   cout << x << "+" << y << "=" << x+y << endl;
  }
  else if(opt==2){
   cout << x << "-" << y << "=" << x-y << endl;
  }
  else if(opt==3){
   cout << x << "*" << y << "=" << x*y <<endl;
  }
  else{
// error check for divide by zero errors in division
   if(x == 0 | y==0 ){
    cout<<"Cannot divide by zero please try again\n";}
   else{
    cout << x << "/" << y << "=" << x/y <<endl;
   }
  }
// give the user the option to preform another calculation
  cout << "Preform another calculation?(y/n): "; cin >> choice;
  if(choice == 121 || choice == 89 ){
   exit=1;
  }
  else if(choice == 110 || choice == 78 ){
   exit=0;
  }
 }
}
