	/*
	 Modified By : Nicholas Howland
	 Last modified :03/08/2023
	 Program purpose : Use a weather.txt file to calculate the high and low temperatures for an area
	*/

	// initalize the libraries and variubles needed
	#include <iostream>
	#include <cstdlib>
	#include <ctime>
	#include <cmath>
	#include <fstream>
	using namespace std;
	// beginnning of the main program
	int main(){
	// intialize the array bounds.
		int numberOfDays=31;
		int numberOfRows=8;
	//	string test[numberOfDays][numberOfRows]; // testing string array intialization
	// Initialize the arrays
		int day[numberOfDays];
		string month[numberOfDays];
		int year[numberOfDays];
		double tempHigh[numberOfDays];
		double tempLow[numberOfDays];
		double inchesPrecipitation[numberOfDays];
		double inchesSnowPrecip[numberOfDays];
		double inchesSnowDepth[numberOfDays];
	// Initialize the data counters
		double highest=0.0;
		double lowest=0.0;
		double totalHigh=0.0;
		double totalLow=0.0;
		double lastSnowDepth=0.0;
	// access the file
		ifstream infile;
		infile.open("weather.txt");
	// start the for loop
		for(int i=0;i<numberOfDays;i++){
					infile >> day[i];
					infile >> month[i];
					infile >> year[i];
					infile >> tempHigh[i];
					infile >> tempLow[i];
					infile >> inchesPrecipitation[i];
					infile >> inchesSnowPrecip[i];
					infile >> inchesSnowDepth[i];

	//			for(int j=0;j<numberOfRows;j++){
	//				infile >> test[i][j]; // testing string array
	//				cout << test[i][j] << endl; // testing string array output
	//			}
		}
		infile.close(); // close the file
		highest=tempHigh[0];// start the high temperature off as the first high temp
		lowest=tempLow[0];// start the lowest temperature off as the first low temp
		lastSnowDepth=inchesSnowDepth[0];// start last snow off as first snow depth
		totalHigh=highest;// start the total high off as the first high temp
		totalLow=lowest;// start the total low temp off as the first low temp
	// output loop
		for(int i=1;i<numberOfDays-1;i++){
	// print out the snow depth of today minus the last snow depth as the change of snow depth
			cout << "Daily Snow Depth Change : " << (inchesSnowDepth[i])-lastSnowDepth << endl;
			lastSnowDepth=inchesSnowDepth[i];

	// if the daily high is higher than the current total high then set the current high to
	// current high
			if(tempHigh[i]>highest){
				highest=tempHigh[i];
			}
	// if the daily low is higher than the current total low then set the current low to
	// current low
			if(tempLow[i]<lowest){
				lowest=tempLow[i];
			}
	// add to the total highs and lows
			totalLow=totalLow+tempLow[i];
			totalHigh=totalHigh+tempHigh[i];
		}

	// final data output
		cout << "Highest temperature was : " << highest << endl;
		cout << "Lowest temperature was : " << lowest << endl;
	// output the average highs and lows
		cout << "Average highest temperature was: " << totalHigh/numberOfDays << endl;
		cout << "Average lowest temperature was: " << totalLow/numberOfDays << endl;

	}







