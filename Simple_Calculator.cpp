/*
 Created by Nicholas Howland
 Date:
 Purpose:
 create a simple calculator in C++ that allows the user to do the following
 - enter a number of their choice, an oporator, then another number
 - detect divide by zero errors
*/
#include <iostream>
using namespace std;
int main()
{
// declaration of variubles
 double x=0;
 double y=0;
 int opt=0;
 int exit=1;
// program explanation
 cout << "This is a simple calculator that preforms an operation on variubles assigned by you\n"<<endl;
// user assigns intigers
 cout << "Enter variuble types\n";
 cout << "x="; cin >> x;
 cout << "y="; cin >> y;
// user chooses an option
 cout << "Enter a number that corrosponds to a mathmatic operation\n  1) addition\n  2) subtraction\n  3) multiplication\n  4) division\n";
// while loop that asks the user for a valid option
 while(exit==1)
 {
  cout << "option: ";cin >> opt;
  if(opt >= 5){
   cout << "Choose an option between 1 and 4\n";
  }
  else if(opt <= 0){
   cout << "Choose an option between 1 and 4\n";
  }
  else{
   exit=0;
  }
 }
// once a valid option has been chosen print the operation and result
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
  if(x == 0 | y==0 )
  {cout<<"Cannot divide by zero please try again\n";}
  else
  {
  cout << x << "/" << y << "=" << x/y <<endl;
  }
 }
}
