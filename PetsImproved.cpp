/*
 Modified By : Nicholas Howland
 Last modified : 3/10/2023
 Program purpose : 
  Use a custom library from the pets.cpp project to implement a way to create more than one pet per run time of the program
*/

#include <iostream>
#include "pet.h" // custom library file

using namespace std;



int main() {
	int numberOfPets=0;
	int exit=1;
	int petSelection=0;
	int livingPets=0;
	int deadPet=0;
// Ask the user how many pets they want
	while(numberOfPets < 1 || numberOfPets > 200){
		cout << "How many pets would you like to have?\nEnter a number from 1 to 200: "; cin >> numberOfPets;
		cin.clear();
	}
// Create and initialize that many pets
	pet pets[numberOfPets];
// Game loop:
	do{
// Ask the player which pet they want to interact with
		cout << "What pet would you like to interact with?\n";
		for(int i=0; i <numberOfPets; i++){
			cout << "(" << i << ") " << pets[i].returnName() << endl;
		}
		cout << "("<< numberOfPets<<") exit pet pin\n";
		do{
			cout << "Choice : ";cin >> petSelection;
			if(petSelection<0 || petSelection >petSelection+1 || cin.fail()){
				cout << "\nPlease select a valid pet or exit with " << (numberOfPets) << endl;;
				cin.clear();
				cin.ignore();
				petSelection=-1;
			}
		}while(petSelection<0 || petSelection >petSelection+1);

// Have the player interact with that pet
		cout << "Interacting with " << pets[petSelection].returnName() << endl;
		pets[petSelection].interact();
		livingPets=0;
		for(int i=0; i <numberOfPets; i++){
// Add 2 hunger and subtract 2 happy from every pet
			pets[i].atrophy();
// Print all of the pets
			pets[i].print();
// Use check_health to see if all of the pets are healthy
			if(pets[i].check_health()!=0){
				livingPets+=1;
			}else{
				deadPet=i;
			}
		}
// If a pet died, or the player asked to quit, exit the loop, otherwise loop
		if(livingPets!=numberOfPets){
			petSelection=numberOfPets+1;
			cout << "Unfortunately one or more of your pets has either fell into a coma or died\n";
			cout << "You must make sure they are taken care of properly and must leave the pet pin.\n"<< endl;
			// Print an appropriate exit message
		}
	}while(petSelection<numberOfPets);
cout << "Press enter to exit." << endl;
cin.ignore();
return 0;
}
