/*
 Created by: Nicholas Howland
 Date modified: 2023-1-30
 Purpose:
  A cli for demonstrative purposes and to learn the language c plus plus

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// grab a string from the user, implemented here for ease of updates
string getString(string pretext="")
{
 string output="";
 cout << pretext;// prints the string supplied by the user, if none then no string is output
 cin >> output;
 return output;
}
// get a number from the user and validate its a number
unsigned getNum(string pretext="")
{
 unsigned output=0;
 cout << pretext;// prints the string supplied by the user, if none then no string is output
 cin >> output; // grab the number
 while(cin.fail()){ // if cin fails to recieve a number then proceed with error checking
  cout << "please try again using a number\n";
  cin.clear();
  cin.ignore();
  cin >> output;
  }
 return output;
}

char getChar()
{
 string output="";
 cin >> output;
 return output[0];
}


/*
random number generator function
*/
void rng()
{
srand(time(NULL));
cout << "The demigod of random numbers has heard your prayers... \nHere is a random number: " << rand() << endl;
}

void calc()
{
// declaration of variubles
 double x=0;
 double y=0;
 char opt;
 int exit=1;
// program explanation
 cout << "This is a simple calculator that preforms an operation on variubles assigned by you\n"<<endl;
// user chooses an option
 cout << "it supports addition, subtraction, multiplication, and division\n";
// user assigns intigers
 cout << "Enter variuble types\n";
 cout << "x="; x=getNum();
 cout << "operator(+-*/):";opt=getChar();
 cout << "y="; y=getNum();
 cout << "\n";// print a buffer line for better output
// input checking
 if(opt==43){// addition operation
  cout << x << "+" << y << "=" << x+y << endl;
 }
 else if(opt==45){// subtraction operation
  cout << x << "-" << y << "=" << x-y << endl;
 }
 else if(opt==42){// multiplication operation
  cout << x << "*" << y << "=" << x*y <<endl;
 }
 else if(opt=47){// division operation
  if(x == 0 | y==0 ){// check for divide by zero error
   cout<<"Cannot divide by zero please try again\n";
  }
  else{
  cout << x << "/" << y << "=" << x/y <<endl;
  }
 }
 else{// if no known operator supplied then print help
  cout << "only the following operators are supported\naddtion +\nsubtraction -\ndivision /\nmultiplication *\n";
 }
}


// Message of the day function
void motd()
{
cout << "Step 1: Learn a thing\nStep 2: ???\nStep 2.5: Have fun (optional)\nStep 3: Profit\n";
}

void printHelp(){
// cout << "" << endl;
 cout << "rng                   Random Number Generator" << endl;
 cout << "motd                  print the message of the day" << endl;
 cout << "calc                  a simple calculator\n";
 cout << "exit                  leave the program" << endl;
 cout << "help                  print avialable commands" << endl;
 cout << "whoami                        print username" << endl;

 }


int main()
{
 string name="";// username
 string command="";// command string
 string stripppedComm="";
 int comCode=0;// command code mapped from getCommand function
 string prompt="";// system prompt to be repeated
 int exit=0; // initalize the exit break code used for the shell loop

// begin setting up the shell
 cout << "Simple Shell" << endl;
 cout << "Name: ";
 name=getString();// get username from user
 cout << "Hello " << name << "!"<<endl; // print the opening message
 cout << "use exit and help respectively\n"; // print the opening message

 while(exit==0){// start the shell loop
  string prompt=name+"> ";// create the prompt using the username
  string command="";// clear the command string every time
  cout << prompt;// print the prompt
  command = getString();// get the command from the user

//  comCode=getCommand(command);// get the command code using the current command
  if(command=="exit"){
    exit=1;
    break;
  }
   else if(command=="help"){
   printHelp();
  }
   else if(command=="motd"){
   motd();
  }
  else if(command=="calc"){
    calc();
  }
  else if(command=="whoami"){
    cout << name+"\n";
  }
  else if(command=="rng"){
    rng();
  }
  else{
    cout << "\"" << command << "\" command not found try help\n" ;
  }

 }
}
