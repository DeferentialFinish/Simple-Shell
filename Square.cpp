#include <iostream>
using namespace std;
/*
	 Modified By : Nicholas Howland
	 Last modified :
	 Program purpose : Print a square with a length and width defined by the user. Check input to verify the user entered a valid number.
*/
int get_side();
char get_symbol();
int print_rectangle(int,int,char);

int main(){
  int side1, side2, num_symbols;
  char c;
  side1 = get_side();
  side2 = get_side();
  c = get_symbol();
  num_symbols = print_rectangle(side1,side2,c);
  cout << num_symbols << " characters were printed.\n\n";
}

//*** put your functions here ****

int get_side(){
	int user_choice;
	cout << "Please enter a side length between 1 and 10 (inclusive): "; cin >> user_choice;
	while(user_choice > 10 || user_choice < 1){
		cout << "The side must be between 1 and 10."<<endl;
		cout << "Please try again: "; cin >> user_choice;
	}
	cout <<"Thank you."<<endl;
	return user_choice;
}
char get_symbol(){
	char user_symbol;
	cout << "Please enter a character: "; cin >> user_symbol;
	return user_symbol;
}
int print_rectangle(int sideA,int sideB,char symbol){
	int count =0;
	for(int a = sideA; a>0; a--){
		for( int b = sideB; b>0; b--){
			cout << symbol;
		count+=1;
		}
	cout << endl;
	}
	return count;
}
