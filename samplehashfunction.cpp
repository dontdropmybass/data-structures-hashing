// samplehashfunction.cpp : Super simple application to demonstrate a simple
// hashing function. It converts an input string in to an integer index 
// to be used later in a table.
//
//	Author: Hal O'Connell
//	April 2015
//

#include <iostream>
#include <string>

using namespace std;

#define SIZE 13  // Size of the sample hash table - note the use of a prime number
#define CATS 11
//#define DEBUG 1;


int hashfn(string keyString)
// Accepts an input string and returns the calculated index (to use later with a hash table)
{
	int i, sum, address;

	sum = 0;
	int len = keyString.length();
	for (i = 0; i < len; i++)
		sum += (int)keyString[i]; // cast each character of the string as int to get ascii value

	// the modulus, or remainder, of integer division gives a result between 0 and SIZE-1, perfect for an index
	address = sum % SIZE;


#ifdef DEBUG
	cout << "DEBUG - Sum: " << sum << "  Address: " << address << "\n\n";
#endif
	return address;
}


int main(int argc, char* argv[])
{
	string keyString;
	int address;
	string cats[CATS] = { "Rumpleteaser", "Mungo Jerry", "Grizabella", "Mister Mistoffelees", "Rum Tum Tugger", 
		"Skimbleshanks", "McCavity", "Growltiger", "Jennyanydots", "Bustopher Jones", "Old Deuteronomy" };

	cout << "Herding the cats..." << endl;
	for (int i = 0; i < CATS; i++) {
		keyString = cats[i];
		address = hashfn(keyString);
		cout << endl << keyString << " jumped in bucket " << address << endl;
	}
	
	cin.ignore();
	return 0;
}

