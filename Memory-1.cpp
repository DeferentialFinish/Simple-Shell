/*
 Modified By : Nicholas Howland
 Last modified : 2/23/2023
 Program purpose :
 understand memory addressing and pointers part 2
*/

#include<iostream>
using namespace std;

void fill(int a[][6], int, int);
void increment(int a[][6], int, int);

int main(){
   int a[3][6];
   fill(a,3,6);// fills the entiere array with values of the place number times itself
   increment(a,3,4);// increments each value up to the fourth row by one
   int *p; 
   p = (int *)a;// assigns p to be the calue of a
   *p = 99; // assigns p and a to be the value of 99
   p[6] = 77;// seventh value in array beginning from the first value, p[1][0], is set to 77
   p = &a[2][2];// memory address of p is statically assigned to the memory of &a[2][2]
   p--;// memory address jumps backwards one to point to a[2][1]
   *p = 66;// a[2][1] is assigned the value of 66
   p = (int *)(a[0]+4);// will contain the fourth value from 0 in the array of a
   *p = 44;// assigns current value of a[0][4] to 44
   p = (int *)(a+2);// changes the pointer of p to be aimed at the value of a[2][0]
   *p = 55;// changes value of a[0][2] to equal 55
   for(int r = 0; r < 3; r++){
     for(int c = 0; c < 6; c++){
        cout << a[r][c] << ", ";
     }
     cout << endl;  // Why?
	 /* INITIAL CONCLUSION
	a[0][0] = 99, // result replaced by code on line 28 in which value of the first variuble of the array is replaced with 99
	a[0][1] = 3, // result of fill function then increment function
	a[0][2] = 55, // result of line 36 where the pointer was increased by one
	a[0][3] = 4, // result of fill function then increment function
	a[0][4] = 44, // result of fill function then increment function
	a[0][5] = 7, // result of fill function then increment function
	a[1][0] = 77, // result replaced by value on line 29. The seventh or [6] memory value in the array is actualy a[1][0] because memory is allocated sequentally.
	a[1][1] = 5, // result of fill function then increment function
	a[1][2] = 6, // result of fill function then increment function
	a[1][3] = 9, // result of fill function then increment function
	a[1][4] = 11, // result of fill function then increment function
	a[1][5] = 12, // result of fill function then increment function
	a[2][0] = 4, // result of fill function then increment function
	a[2][1] = 7, // result replaced by value of 66 from line 32
	a[2][2] = 10, // result of fill function then increment function
	a[2][3] = 13, // result of fill function then increment function
	a[2][4] = 15, // result of fill function then increment function
	a[2][5] = 18, // result of fill function then increment function

// TRUE RESULTS AND WHY

a[0][0] = 99 because of code on line 28 where p was assigned 99 and pointed to the address of a[0][0],
a[0][1] = 3, // altered by increment function
a[0][2] = 4, // altered by increment function
a[0][3] = 5, // altered by increment function
a[0][4] = 44 because of lines 33 and 34 where p pointed to a[0]+4 meaning that the very first address of the array a[0] was incremented forward 4 memory addresses then the value assigned was 44
a[0][5] = 6 // result of fill function 

a[1][0] = 77 // result replaced by value on line 29. The seventh or [6] memory value in the array is actualy a[1][0] because memory is allocated sequentally. 
a[1][1] = 5 // result of fill and increment functions 
a[1][2] = 7 // result of fill and increment functions
a[1][3] = 9 // result of fill and increment functions
a[1][4] = 10 // result of fill function
a[1][5] = 12 // result of fill function 

a[2][0] = 55 because of line 36 (int *) (a+2) points to the first row, first column a[2][0]
a[2][1] = 66 because p was assigned the memory address of a[2][2] then decremented by one making it point to the address of a[2][1]
a[2][2] = 10 // result of fill and increment functions
a[2][3] = 13 // result of fill and increment functions
a[2][4] = 15 // result of fill function
a[2][5] = 18 // result of fill function
	 
	 
	 */
	 
	 
	 
   }
}


void fill(int data[][6], int rows, int columns){
  for(int r = 0; r < rows; r++){
     for(int c = 0; c < columns; c++){
        data[r][c] = (r+1)*(c+1);
     }
  }
}

void increment(int data[][6], int rows, int columns){
  for(int r = 0; r < rows; r++){
     for(int c = 0; c < columns; c++){
        data[r][c] += 1;
     }
  }
}
