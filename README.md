# C++ Portfolio
This is a repository of assignments I completed for the spring semester of 2023 for one of my computer science courses. The premis of the course was that the user would supply only expected input to the programs, that being said... just about every program using C++ in this repository will have a buffer overflow vulnerability or produce unexpected output when improper input is supplied to the program. In order to complete the assignments on time it was not fesable to create input validation for every program, however in some places it was possible.

This repository showcases my knowledge and familiarity with the following concepts in programming:
- variuble decleration and types
- public and private data members
- Understand how conditionals work in c++
- if/else statements
- switch case statements
- while loops
- custom function declerations
- custom class decleration and use
- create and use custom libraries
- input and output
- memory management in c++
- file access in c++


# Utilities

## Calculator_Simple.cpp
A very simple calculator in C++ that allows the user to do the following
 - enter two numbers then an operation to be preformed on those numbers
 - detect divide by zero errors
### Issues
  - Could have looping functionality 

## Calculator_Looping.cpp
Improve the calculator by allowing it to loop

## Calculator_Surface.cpp
Add surface calculation to the calculator program.

## Square.cpp
Print a square with a length and width defined by the user. Check input to verify the user entered a valid number.

## RectangleClass.cpp
Use a class to implement something similar to the Square program

## Weather.cpp
Use a file called weather.txt with a standard format to print weather information

## ShellFramework.cpp
not actually in the class but I found the basic structure helpful as a side project
### Issues
  - There is an issue where if a command is supplied with spaces
    the program will output two prompts as if it recieved two
    inputs.
  - Only entering the return charicter will not return the prompt 
    again but instead drops cursor onto a blank line.

# Games

## Pet.cpp
Create a virtual pet, similar to a tamagatchi using classes

## PetsImproved.cpp
Use a custom library from the pets.cpp project to implement a way to create more than one pet per run time of the program. Be sure to download the file pets.h as well if you decide to compile and run this code.

## RacingGame.cpp
Simple racing game that utilizes files to customize the gameplay

## PenTestersRun.cpp
Create a game about something you are passionate about. I chose pen testing and cybersecurity as my general topic and based my game around a pentester on an assignment. Very simple and clunky but the code runs. For completing this task in under a week I was able to get a suprising amount done.

### Issues
- Guard mechanics
- Could display current player location and guard location on the minimap
- Output and input can be confusing and clunky

## NIM.cpp
When supplied with a file and asked to improve the following I was able to complete the project by the deadline.
NIM improved by
		- Adding new outputs for wins and losses
		- Printing the game rules
		- adding exciting commentary
		- Removing the magic numbers
		- Printing sybols that represent the remaining objects
		- Adding a play again option


## Fourtune_Teller.cpp
Simple fortune teller program that uses a number provided by the user to output a fortune.

### Issues
  - Output and fortunes are kind of wierd.
  - Could use a file to print fortunes from
  - lucky number could be more randomly generated


# Concpets in code

## Memory-0.cpp and Memory-1.cpp
Demonstrate basic memory management concepts in C++

## Conditionals.cpp
use logic operators to test math statements in C++

## Ascii.cpp
Use cout to display some ascii art to terminal

## Arrays.cpp
Print out some information about a randomly generated array such as the average, the number of items below and above the average, the range of the array, and the minimum and maximum values in the array

## Fractions.cpp
Output an improper fraction, mixed number, and decimal value of a faction supplied

## Float_Check.cpp
Allow the user to supply a number and determine the following
 - if the number is a decimal aka floating point number
 - if the number is even or odd



## Disclaimer
Understand that each and every program is designed to demonstrate a concept in programming and none of this code should be used for in production purposes. The classes I took did not cover secure coding practices but was mearly an introduction to C++ as a language. It is most likely that every single program in this repository that accepts input has a buffer overflow vulnerability.
