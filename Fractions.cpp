/*
 Modified By : Nicholas Howland
 Last modified : 2/27/2023
 Program purpose : Fraction identification program

X The class should have two private data members, a numerator and a denominator.
X A function that takes two integers as arguments and sets the numerator and denominator of a fraction object.
  The function should check that the denominator is not zero and set the fraction to 0 over 1 if the denominator
  is zero. (This is almost the same as the set() function that is already part of the class.)
X A print function that prints a fraction object as an improper fraction, e.g. 6/4.
X A print function that prints a fraction object as a mixed number, e.g. 1 2/4. This is new, you will need to use the modulus operator % to make it work.
X A print function that prints a fraction object as a decimal, e.g. 1.5. Each of these print functions should have it's own name.
X A constructor that takes no arguments and sets a fraction to be 1/1.
X A constructor that takes two integers as arguments and sets the numerator and denominator of a fraction object. 
  The function should check that the denominator is not zero and set the fraction to 0 over 1 if the denominator is zero.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

// end of initialization and beginning of
// custom function definitions
class fraction{
        private:
                int numerator,denominator;
        public:
                fraction(){numerator=0;denominator=0;}
                fraction(int, int);
                void setNumerator(int);
                void setDenominator(int);
				void setToOne();
                double getNumerator();
                double getDenominator();
                void printImproper();
                void printMixed();
                void printDecimal();
				void setFraction(int,int);
};

void fraction::printImproper(){
// put both numerator and denominator into postiive forms
	int evenNumerator=numerator;
	int evenDenominator=denominator;
	if(evenNumerator<0){
		evenNumerator=(-1*evenNumerator);
	}
	if(evenDenominator<0){
		evenDenominator=(-1*evenDenominator);
	}
// if either numerator or denominatlor is negatve then output a negative sign in front of the fraction
	if((numerator<0 && denominator>0) ||(numerator>0 && denominator<0)){
		cout << "-";
	}
//else{cout << "double neg\n";}//verify the function was working properly
	cout << evenNumerator<<"/"<<evenDenominator << endl;
}
void fraction::printMixed(){
// put both numerator and denominator into postiive forms
	int evenNumerator=numerator;
	int evenDenominator=denominator;
	if(evenNumerator<0){
		evenNumerator=(-1*evenNumerator);
	}
	if(evenDenominator<0){
		evenDenominator=(-1*evenDenominator);
	}
// if the positive value of the numerator is more than the denominator and the numerator is not a
// factor of denoninator then output the whole number as a result of the divisor which can be negative
// or positive, then the remainder of the division operation ove the even denominator
	if(evenNumerator>evenDenominator && (evenNumerator%evenDenominator)!=0){
		cout << numerator/denominator  << " "<<evenNumerator%evenDenominator <<"/"<<evenDenominator <<endl;
	}else if(evenNumerator==evenDenominator ){
		// output a negative sign if only one numerator is negative
		if(numerator<0&&denominator<0){
			cout << evenNumerator/evenDenominator << endl;
		}else{
			cout << numerator/denominator << endl;
		}
		
	}else{
// dont output a negative number if both numerator and denominator are negative and check to be sure the
// numerator is not a 0 before outputting the negative symbol
		if(numerator<0 && denominator<0){
//			cout << "Double neg\n";
			cout << evenNumerator<<"/"<<evenDenominator << endl;
		}else if(numerator <= -1 || denominator < 0 ){
			cout << "-" << evenNumerator<<"/"<<evenDenominator << endl;
		}else{
			cout << evenNumerator<<"/"<<evenDenominator << endl;
		}
	}
}
void fraction::printDecimal(){
// make a new float variuble, transform the numerator to a floating point number then ensure
// the output is a floating point by multiplying it by 1.0
	float fractionValue=(1.0*numerator)/(1.0*denominator);
	cout<<fractionValue*1.0<<endl;
}

void fraction::setNumerator(int newNumerator){
        numerator=newNumerator;
}
void fraction::setDenominator(int newDenominator){
        denominator=newDenominator;
}
void fraction::setToOne(){
        numerator=1;
        denominator=1;
}
void fraction::setFraction(int newNumerator, int newDenominator){
// check to see if the denominator is equal to zero and if it is then convert
// the numerator to 0 and the denominator to 1
	if(newDenominator == 0){
		denominator=1;
		numerator=0;
	}else{
		denominator=newDenominator;
		numerator=newNumerator;
	}
}
fraction::fraction(int newNumerator, int newDenominator){
        numerator=newNumerator;
        denominator=newDenominator;
}


// beginnning of the main program
int main(){
        srand(time(NULL));
        fraction f;
		int randNumerator=50-rand()%101;
		int randDenominator=50-rand()%101;
// testing function
		for(int i=0; i<100;i++){
			f.setFraction(randNumerator,randDenominator);
			cout << "Improper : ";f.printImproper();
			cout << "Mixed number : ";f.printMixed();
			cout << "Decimal : ";f.printDecimal();
			cout << "##################################################"<<endl;
			randNumerator=50-rand()%101;
			randDenominator=50-rand()%101;
		}
//        p.setX(10); p.setY(5);
//        printPoint(p);
//        p=changePoint(p);// allows for persistant changes in p.
//        printPoint(p);

}

