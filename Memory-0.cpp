/*
 Modified By : Nicholas Howland
 Last modified : 2/23/2023
 Program purpose :
 understand memory addressing and pointers part 1
*/


#include<iostream>
using namespace std;

int func(int, int &);
void func2(int, int []);

int main(){
   int x = 99, y = 55;
   int a[5] = {1,2,3,4,5};
   int *p;// sets p to be an address pointer
   p = a;// sets the address of p to be the beginning address of the array a
   p++; // adds one to p or shifts it to be equal to the next value in the array of a or a[1]
   *p = 8; // sets the value of a[1] to be equal to 8
   p = &a[3];// sets the address of p to be the address of a[3]
   *p = 12; // sets the value of the address of p which is equal to the address of a[3] to be equal to 12
   p--;// moves the address back one bit so it is equal to the address of a[2]
   *p = 11;// sets the value of a[2] to be equal to 11
   a[0] = func(x,y);// sets the value of a[0] to be equal to the value returned by func() which is 102 and the address of the second variuble, y, passed to the function to be set to 101
   func2(x,a);// changes the values of the variubles passed to the function, the addresses are actually being passed to the function therefore the values at the memory addresses are being changed.
   cout << "x = " << x << endl;// prints 99 because on line 8 the variuble x was set to 99 and it did not change over the course of the program.
   cout << "y = " << y << endl;// outputs 101 because on line 18 the variuble was passed to a function that changed the value stored at its memory address to 101.
   for(int i = 0; i < 5; i++){// array [102,8,11,12,456]
      cout << "a[" << i << "] = " << a[i] << endl;
	/*
		a[0]=102 because it is assigned to be the value returned the function func() on line 18
		a[1]=8 because p was assigned the value of 8 and the memory address of p was assigned the memory address of a[1] line 13
		a[2]=11 because p was assigned the value of 11 while its memory address pointed to a[2] on line 17
		a[3]=12 because p was assigned the value of 12 while its memory address pointed to a[3] on line 15
		a[4]=456 because it was assigned the value of 456 in the function func2 on line 19
	*/

   }
}

int func(int a, int &b){// declares a new variuble and passes the address of the second variuble to the function
   a = 100;// sets the newly initalized variuble to be equal to 100
   b = 101;// sets the address passed to the function to be equal to 101 which will be persistant globally
   return 102;// returns 102
}

void func2(int a, int b[]){// initializes a new variuble and passes the memory addresses of an array to the function
   a = 123;// sets the new variuble to be equal to 123 not globally persistant
   b[4] = 456;// sets the memory address of b[4] to be 456 will be globally persistant
}
