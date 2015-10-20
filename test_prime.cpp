/*
Test Prime

User inputs an integer, output prime or composite after some calculations

First set of consecutive digits are taken from user input
Input can handle signed and decimal numbers
*/

#include <iostream>
#include <string>
#include <sstream>  // transform input string to float
#include <math.h>   // we need sqrt

using namespace std;

bool isPrime( int number );

int main(int argc, char *argv[])
{	
	if(argc < 2)
	{
		cout << "No command line arguments given" << endl;
		return 0; 
	}

	int num;
	string arg;

	arg = string(argv[1]);
	stringstream(arg) >> num;
		
	// if argument is valid
	if(num)
	{
		// check if prime
		if(isPrime(num))
		{
			cout << "prime\n";
		}
		else
		{
			cout << "composite\n";
		}
		return 0;
	}	
	
	// argument was invalid
	cout << "Input was invalid" << endl;
	return 0;
}

bool isPrime( int number )
{
	if(number)
	{
		if(number < 0) // assuming no negatives are prime for our purposes
		{
		    return false;
		}
		if (number <= 1) // if number is 0 or 1 composite
		{
			return false;
		}
		else if (number == 2) // 2 is prime     
		{
			return true;
		}
		else if (number % 2 == 0) // even numbers are composite
		{
			return false;
		}
		else
		{			
			bool prime = true;
			int divisor = 3;
			double num_d = static_cast<double>(number); // cast number to double so we can take square root
			int upperLimit = static_cast<int>(sqrt(num_d) + 1); // we only need to check divisors up to the square root
			
			while (divisor <= upperLimit)
			{
				if (number % divisor == 0)
					prime = false;
				divisor += 2; // check all odd divisors between 3 and sqrt( number )
			}
			

			return prime;
		}
	}
}
	
