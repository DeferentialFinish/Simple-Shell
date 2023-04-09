/*
 Modified By : Nicholas Howland
 Last modified : 
 Program purpose : Learn about arrays
 	For this assignment you will be creating a series of functions for 
	manipulating an array of data. The data will consist of randomly 
	generated doubles.
*/

// initalize the libraries and variubles needed
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
//---------------Initialize functions--------------------
//int generate(int,int,double,double);

void setData(double* dataLocation, int value){
	// This will set a piece of memory to be the value supplied
        double *data=dataLocation;
        *data=value;
}

double genRandomDouble(double lower, double upper){
// Generates a random double as long as the lower and upper bounds
// are in the tens place.
	int decimal=10;
	int tenUpper=upper*decimal;
	int tenLower=lower*decimal;
	int integerRange;
	int reduceBy=0;
	double random;
 
	// make sure the upper and lower values are correct
	if(tenUpper < tenLower){
		integerRange=tenLower - tenUpper;
		reduceBy=tenUpper;
	}else if(tenUpper > tenLower){
		integerRange=tenUpper - tenLower;
		reduceBy=tenLower;
	}
	// make sure the range is positive
	if(integerRange<0){
		integerRange=integerRange*(-1);
	}
/*
	// debug
	cout << "upper value " << upper << " : " << tenUpper << endl;
	cout << "lower value " << lower << " : " << tenLower << endl;
	cout << "calculated range : " << tenUpper-tenLower << endl;
	cout << "Range value passed : "range << endl;
*/
	if(reduceBy<0){
		reduceBy=reduceBy*(-1);
	}
	random=(rand()%integerRange)-reduceBy;
//	cout << random << endl;
	return random/10.0;

/*
Original description
	print() - This function should print an array of values. The function takes two inputs: an array and the size of the array. Exactly how the values are printed is up to you, but its probably best not to print each value on its own line.
*/

}

void generate(double *pointer, int length, double lower, double upper){
	// fills the array of doubles supplied with random doubles between the range
	// supplied by the upper and lower bounds.
	double random=genRandomDouble(lower,upper);
	for(int i=0; i<length; i++){
//		cout << random << "	: " << &pointer+i << endl;
	    double *data=pointer+i;
        *data=random;
		random=genRandomDouble(upper,lower);
	}
/*
Original function definition
	This function fills an array with random doubles in a specified range. This function takes four inputs: an array of doubles, an integer representing the size of the array, and two doubles representing the lower an upper bounds of the range random values. For example, the function call: generate(data,100,-5.0,5.0); should fill the array called data[] with 100 random values between -5.0 and 5.0.
*/

}


void print(double* data, int length){
	// This get the value of a piece of memory that is supplied
		for(int i =0; i<length; i++){
			// double *data=&dataLocation[0]+i;
			cout << data[i] << " ";
		}
        cout << endl;
}



double average(double* data, int length){
	double dLength=length*1.0;
	double total=0;
	for(int i =0; i<length; i++){
		total=total+data[i];
//		cout << data[i] << " " << total << endl;
	}
	//cout << (total/dLength)*1.0 << endl;
	return (total/dLength)*1.0;
	
	
/*
	average() - This function returns the average of an array of values. The function takes two inputs: an array and the size of the array, and it returns a double.
*/
	
}

double min(double* data, int length){
	double minimum=data[0];
	for(int i=1; i<length; i++){
		if(data[i]<minimum){
			minimum=data[i];
		}
	}
	return minimum*1.0;
/*
	min() This function returns the smallest value from an array of values. The function takes two inputs: an array and the size of the array, and it returns a double.
*/
}
double max(double* data, int length){
	double maximum=data[0];
	for(int i=1; i<length; i++){
		if(data[i]>maximum){
			maximum=data[i];
		}
	}
	return maximum*1.0;
/*
	 max() This function returns the largest value from an array of values. The function takes two inputs: an array and the size of the array, and it returns a double.
*/
}

void addX(double *pointer, int length, double addThis){
	for(int i=0; i<length; i++){
//		cout << addThis+pointer[i] << "	: " << &pointer+i << endl;
        pointer[i]=pointer[i]+addThis+1.0;
	}
	
/*    
	addX() This function adds a value to every element in an array. function takes three inputs: an array, the size of the array, and the value to be added to each element of the array. For example, if you have an array [5.5, 6.6, 7.7] and you call: add(array, 3, 2.5) the array should become [8, 9.1, 10.2], that is each element had 2.5 added to it.
*/
}



int num_more(double *pointer, int length, double average){
	int itemsAboveAverage=0;
	for(int i =0; i<length; i++){
		if(pointer[i]>average){
			itemsAboveAverage++;
		}

	}
	return itemsAboveAverage;
/*
	num_more() This function returns the number of values that are higher than the average value of an array of values. That is it counts how many values are less than the average and returns that number. The function takes two inputs: an array and the size of the array, and it returns an integer (the number of values above the average).
*/
}
int num_less(double *pointer, int length, double threshold){
	int itemsBelowThreshold=0;
	for(int i =0; i<length; i++){
		if(pointer[i]<threshold){
			itemsBelowThreshold++;
		}

	}
	return itemsBelowThreshold;
/*
	double num_less() This function returns the number of values that are lower than the average value of an array of values. That is it counts how many values are less than the average and returns that number. The function takes two inputs: an array and the size of the array, and it returns an integer (the number of values below the average).
*/
}


double range(double *pointer, int length){
	double totalRange=0.0;
	double upper=pointer[0];
	double lower=pointer[0];
	for(int i=1;i<length-1;i++){
		if(pointer[i]<lower){
			lower=pointer[i];
		}else if(pointer[i]>lower){
			upper=pointer[i];
		}


	}
	
 	// make sure the upper and lower values are correct
	if(upper < lower){
		totalRange=lower - upper;
	}else if(upper > lower){
		totalRange=upper - lower;
	}else{// if the upper and lower values are the same return 0
		return 0.0;
	}
	// make sure the range is positive
	if(totalRange<0){
		totalRange=totalRange*(-1.0);
	}
/*
	// debug
	cout << "upper value " << upper << endl;
	cout << "lower value " << lower << endl;
	cout << "Range value passed : "<<totalRange << endl;
*/
	return totalRange;


/*
	range() This returns the range of values in the array, i.e. the difference between the largest and smallest values in the array. The function takes two inputs: an array and the size of the array. It returns a double, which is the range.
*/
}



//----------------Main program execution-----------------
int main(){ 
	srand(time(NULL));
//----------------Variuble decleration-------------------
int LENGTH=99;
double upper = 10.1;
double lower = -10.1;
double data[LENGTH];
//----------------Data Generation------------------------
generate(&data[0], LENGTH, lower, upper);// generate the data
double x=genRandomDouble(-10.2,10.2);


//-----------------Function testing loop-----------------
for(int i; i<10; i++){
	// print the data generated
	print(&data[0],LENGTH);
	// set variubles for the stats of the data generated
	double avg=average(&data[0],LENGTH);// set the average variuble
	double numAboveAvg=num_more(&data[0],LENGTH,avg);// set the number of values above the average
	double numBelowAvg=num_less(&data[0],LENGTH,avg);// set the number of values below the average
	int belowThresh=num_less(&data[0],LENGTH,4);// set the value below a specific threshold
	int arrayMin=min(&data[0],LENGTH);
	int arrayMax=max(&data[0],LENGTH);
	double rangeOfArray=range(&data[0],LENGTH);
	cout << "Average : " << avg << endl;
	cout << "Number of items below average : " << numBelowAvg << endl;
	cout << "Number of items above average : " << numAboveAvg << endl; 
	cout << "Range of Array : " << rangeOfArray << endl;
	cout << "Minimum : " << min(&data[0],LENGTH) << endl;
	cout << "Maximum : " << max(&data[0],LENGTH) << endl;
	cout << "\n*****************\n";
	x=genRandomDouble(-10.2,10.2);
	addX(&data[0],LENGTH,x);
}
}




