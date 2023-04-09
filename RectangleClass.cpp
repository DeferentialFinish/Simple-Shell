/*
 Modified By : Nicholas Howland
 Last modified : 2/23/2023
 Program purpose : SP23-CS120-07 Lab #7
	Creating and testing a rectangle class. Rectangle objects should store the size of a rectangle and be able calculate things like the area and perimeter of 'themselves', and draw themselves as a series of *'s. For example,:
	****
	****
	****
	****
	****
	****
	The rectangle class should have the following features: 
	  - The class should have two private data members, a width and a height.
	  - A constructor function that sets the width and height of a rectangle to 0.
	  - A function that takes two integers as inputs and sets width and height of a rectangle object. The function should check that both values are positive and if either value is negative make it positive. For example, if the user tries to set the height to -9, it's set to 9 instead. Zero values are acceptable.
	  - A print function that prints a rectangle object as:
		width = ...
		height = ...
		where ... has the correct value.
	 - A draw() function that draws the rectangle using *'s.
	 - An area() function that returns, but does not print, the area of a rectangle.
	 - An perimeter() function that returns, but does not print, the perimeter of a rectangle.
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

class rectangle{
	private:// intialize the private variubes
		int length;
		int width;
	public:// initialize the public functions
		rectangle(){length=0;width=0;}
		int getLength();
		int getWidth();
		void print();
		void draw();
		int area();
		int perimeter();
		void setLength(int);
		void setWidth(int);
		void set(int, int);
};

void rectangle::print(){// print out the variubles 
	cout << "Width = ";
	for( int i =width; i>0; i--){// for loop to print out the dots of the width
		cout << ".";
	}
	cout << endl;
	cout << "Length = ";
	for( int i =length; i>0; i--){// for loop to print out the dots of the height
		cout << ".";
	}
	cout << endl;
}

int rectangle::getLength(){// return the length of the rectangle 
	return length;
}

int rectangle::getWidth(){// return the width of the rectangle 
	return width;
}

void rectangle::draw(){ // draw the rectangle with the * charicter
	cout<<endl;
	for(int i=getLength(); i>0; i--){// start a for loop for each row
		for(int j=getWidth();j>0; j--){// only print charicters for each new line
			cout << "* ";
		}
		cout<<endl;
	}
	cout<<endl;
}

int rectangle::area(){// return the area
		return length*width;
}

int rectangle::perimeter(){// return the perimeter
		return (2*length)+(2*width);
}

void rectangle::setLength(int newLength){// set the length
	if(newLength < 0){//if the value supplied is a negative then flip it to positive.
		newLength=-1*newLength;
	}
	length=newLength;
}

void rectangle::setWidth(int newWidth){// set the width
	if(newWidth < 0){// if the value supplied is a negative then flip it to be positive.
		newWidth=-1*newWidth;
	}
	width=newWidth;
}

void rectangle::set(int newLength, int newWidth){// set both values
	if(newLength < 0){//if the value supplied is a negative then flip it to positive.
		newLength=-1*newLength;
	}
	if(newWidth < 0){// if the value supplied is a negative then flip it to be positive.
		newWidth=-1*newWidth;
	}
	length=newLength;
	width=newWidth;
}


int main(){
// Run testss
	srand(time(NULL)); // intialize random numbers
	for(int i=0; i<10; i++){ // do a for loop to test the rectangle function
		int randLen=10-rand()%22; // generate a number between 0 and 21 for length
		int randWidth=10-rand()%22;	// generate a number between 0 and 21 for width
		rectangle r1 = rectangle(); // create the rectangle class
		r1.set(randLen,randWidth); // set the variubles
		r1.draw(); // draw the rectangle
		r1.print(); // print out the height and width in graphical form
		cout << "Area = " << r1.area() << endl; // print out the area
		cout << "Perimiter = " << r1.perimeter() << endl; // print out the perimeter
	}
cout << "#################### Required Output ############################"<< endl;
rectangle r1; // creates a rectangle object called r1
r1.set(4,6); // sets the height and width of the rectangle
cout << r1.perimeter() << endl; // should print the perimeter of the rectangle
int a = r1.area(); // should store the area of the rectangle in variable a, nothing is printed
r1.print(); // prints the height and width of the rectangle as described above
r1.draw(); // "draws" the rectangle with *'s as shown above

}
