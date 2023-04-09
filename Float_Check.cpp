/*
 Created by Nicholas Howland
 Date: 2/1/2023
 Purpose: Allow the user to supply a number and determine the following
 - if the number is a decimal aka floating point number
 - if the number is even or odd
 
*/
#include <iostream>
using namespace std;


// Used to determine if a floating point number is even or odd by comparing the multiples of ten
int evenOrOdd(double userNumber){
 double floatCheck=0;
 int convertedFloat=0;
 if(userNumber<0){// if number is negave, convert it to a postive
  floatCheck=userNumber*-1.0;
  convertedFloat=userNumber*-1.0;
 }else{
  floatCheck=userNumber; // initalize the floating point variuble
  convertedFloat=userNumber; // convert the floating point supplied to an integer
 }

 do{
  floatCheck=floatCheck*10;// multipy the float by 10 and keep it as a float
  convertedFloat=floatCheck;// convert the float to an integer
 }while((convertedFloat%10) != 0 && convertedFloat <= floatCheck);
// above condition checks to see if the converted floating point number is now
// divisable by ten and greater than the value of the original floating point
// number multiplied to the current decimal place.
// the floating point of 10.1 converted to an integer would be 10 but not accurate
// for determining if the number is even or odd. By checking if 10.1 is greater
// than 10 the loop continues until no more decimals are left.

 convertedFloat=convertedFloat/10;// removes the extra multiple of 10
 if((convertedFloat%2)==0){
 return 1;// if even return 1
 }else if((convertedFloat%2)==1){
 return 2;// if odd return 2
 }else{
 return 0;// if the unknown occurs return 0 and the user input is treated as an integer
 }
}

int main()
{
double userNumber=0;
// explain the program purpose
cout << "This program determines if the number you enter is an integer or decimal, even or odd, and positive or negative\n";
// user number prompt
cout << "Enter your number: "; cin >> userNumber;

// print out the beginning of the output sequence
cout << "The number " << userNumber << " is an ";
float floatUserNumber=userNumber;// floating value check var
int intUserNumber=userNumber;// integer value check var
int floatCheck=0; // by default number is not a floating point

if(floatUserNumber==intUserNumber){ // if the user number in floating point and integer format are the same print integer
 cout << "integer, ";
 floatCheck=0;
}else{// if there is a difference in the floating point and integer values print decimal and addtionally
 cout << "decimal, ";
 floatCheck=evenOrOdd(userNumber);// perform floatCheck() to find out if the floating point number is even or odd
}

if(floatCheck==0){// if the number supplied is a floating point
 if((intUserNumber%2)==0){// and divisable by 2 print even
  cout << "even and ";
 }else{// otherwise print odd
  cout << "odd and ";
 }
}else{
 if(floatCheck==1){// if the floatCheck() determined that the number was even print that
  cout << "even and ";
 }else{// otherwise print that the number must be odd, because otherwise the floatCheck function returns 0
  cout << "odd and ";
 }
}

if(userNumber > 0){// simply check to see if the number is positive or negative
 cout << "positive ";
}else{
 cout << "negative ";
}
 cout << endl;

}
