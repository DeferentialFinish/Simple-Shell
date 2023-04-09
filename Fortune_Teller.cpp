/*
 Modified by Nicholas Howland
 Last Modified: 2023-01-13
 Purpose: The fortune Teller
  a simple program introducing some
  fundimental programming concepts.
 Modificiations:
  changed the lucky numbers and added some unique output
*/

#include<iostream> // include a library
using namespace std;
int main()  // main() starts the program
{
// -------------- Variable Declarations ------------------
int favorite;  // create a variable to store the favorite number
int disliked;  // create a variable to store the disliked number
int lucky;     // create a variable to store the lucky number
int dogs;      // create a variable to store the number of dogs the user has seen today
int cats;      // create a variable to store the numeer of cats the user has seen today
// ------------- Get user input -------------------------
cout << "Enter your favorite number (no decimals): ";  // output
cin >> favorite;   // user input
cout << "Enter a number you don't like (no decimals): ";
cin >> disliked;
cout << "Enter the number of dogs you have seen today (no decimals): ";
cin >> dogs;
cout << "Finaly enter the number of cats you have seen today (no decimals): ";
cin >> cats;

// Changed lucky operation from multiplication to something else
//lucky = (favorite*disliked) % 10;
lucky = (favorite*disliked+dogs+cats) % 10;

cout << endl << "Your secret, lucky number is: " << lucky << endl;
if(lucky < 0){  // conditional, calues less than 0
cout << "Try to be less negative." << endl;
}
if(lucky >= 0 && lucky < 5){ // 0 to 4 inclusive
cout << "Think bigger!" << endl;
}
if(lucky >= 5 && lucky < 9){ // 5 to 8 inclusive
cout << "Today you should embrace technology." << endl;
}
if(lucky == 9){ // exactly 9
cout << "Today is your lucky day!" << endl;
}
if(cats > dogs){ // print message if the user has seen more cats than dogs today
cout << "Do you like cats or do cats like you?" << endl;
}
else if(cats < dogs){ // print message if the user has seen more dogs than cats today
cout << "You might be a good person or just smell like kibble." << endl;
}
else if(cats==dogs){ // print message if the user has seen the same number of cats and dogs today
cout << "Your K-9 to Feline energy is at an equilibrium." << endl;
}
// ---------- Code to help the program exit "gracefully" -----
cin.ignore();
cout << "Press enter to quit." << endl;
cin.ignore();
return 0;
}




