/*
   By Dr. Jan Pearce to explore classes, arrays, and pseudo-randomness
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
		auto seed = chrono::system_clock::now().time_since_epoch().count(); //gets a new seed for the randomness
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
	int thisrolla, thisrollb;
	int numrolls;
	int tallyroll[13] = {0}; // intializes tallyroll to 0


	Dice die6a;					// makes a six-sided die using the default constructor
	
								//FIXME: Create the second die you need here.

	cout << "How many rolls of the dice would you like? ";
	cin >> numrolls; 

	cout << "This loop displays " << numrolls << " rolls of a "<< die6a.get_sides() << "-sided die:\n" << endl;
	
	for (int i = 0; i < numrolls; i++){
		thisrolla = die6a.roll(); //roll the die and assign value to variable thisroll.

		//FIXME: Roll the second dice and store it in thisrollb

		//FIXME: Add the two dice together and put the result into sum

		//FIXME: Increment the appropriate position in the tallroll array.

		cout << "Roll " << i << " is " << thisrolla << "." << endl; 
		//FIXME: Change the previous line to print the sum instead of a single diceroll 
	}
	cout << "\nRolled the dice " << die6a.get_roll_count() << " times.\n" << endl;


	//FIXME: Write a new loop that outputs the meaningful values of tallyroll[] and their counts
	//       The user should see someting like "The number of rolls of 2 was 34." etc.

	cin >> stopme; //holds open the window in some cases
	return 0;
}
