/** 
   By Dr. Jan Pearce to explore arrays and pseudo-randomness
   Created for CSC 236 Data Structures at Berea College
 */

#include <iostream> //for input & output
#include <random> //needed for Getrandom
#include <chrono> //needed for Getrandom's seed

using namespace std;

//---------------------------------------------------------------------
// Program illustrating use of C++ classes called Dice and Getrandom
//---------------------------------------------------------------------

class Getrandom {
	/** Uses <random> and <chrono> from C++11 to return a random integer in range [1..size] */
public:
	Getrandom(int size) {
		unsigned seed = chrono::system_clock::now().time_since_epoch().count(); //gets a new seed for the randomness
		default_random_engine generator(seed);			//seeds our randomness
		uniform_int_distribution<int> intdist(1, size); //a distibution to make each in-range integer equally likely
		self_rand_int_ = intdist(generator);			//generates the randme number
	}
	int roll() {
		return self_rand_int_;
	}
private:
	int self_rand_int_;
};


class Dice{
/** class that can be used to make dice.
Dependent upon the Getrandom class above. */
public:
	Dice(){// default constructor assumes a 6-sided die.
		self_roll_count_ = 0;
		self_sides_ = 6;	
	}
	Dice(int sides){        // constructor for any size dice
		self_roll_count_ = 0;
		self_sides_ = sides;
	}
	int roll() {             // return the random roll of the die
		// postcondition: number of rolls updated, random 'die' roll returned

		Getrandom newrandom(self_sides_);
		self_roll_count_ = self_roll_count_ + 1;         // update # of times die rolled
		return(newrandom.roll());
	}
	int get_sides() const{   // how many sides this die has
		// postcondition: return # of sides of die
		return self_sides_;
	}
	int get_roll_count() const{   // # times this die rolled
		// postcondition: return # of times die has been rolled
		return self_roll_count_;
	}
private:
	int self_roll_count_;       // # times die rolled
	int self_sides_;           // # sides on die
}; //a semi colon must end every C++ class declaration.


//---------------------------------------------------------------------
// main begins here

int main(){
	char stopme;
	int start = 1, stop = 12;
	int whatroll[13], storeroll[13]; // these are array declarations for arrays of 13 integers
	storeroll[0] = 0; // this will remain unused, but we can initialize it.

	Dice die;					// make a six-sided die
	//Dice die(16);             // make a 16-sided die

	cout << "This loop displays " << stop - start + 1 << " rolls of a "<< die.get_sides() << "-sided dice:\n" << endl;
	for (int i = start; i <= stop; i++){
		whatroll[i] = die.roll(); // put the roll into the array whatroll
		cout << "Roll " << i << " is " << whatroll[i] << "." << endl;
	}
	cout << "\nRolled the die " << die.get_roll_count() << " times.\n" << endl;

	//FIXME: you will write code here

	cin >> stopme; //holds open the window in some cases
	return 0;
}



