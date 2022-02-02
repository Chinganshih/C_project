///* ------------------------------------------------------
//Workshop 3 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "Train.h"
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

namespace sdds {

	Train::Train() {
		memset(name, 0, MAX_NAME_LEN);
		people = 0;
		speed = 0.00;
	}


	void Train::set(const char* n, int p, double s) {
		if (n != nullptr && strlen(n) > 0 && (p >=0 && p <= MAX_PEOPLE) && (s >= 0 && s <= MAX_SPEED))
		{
			strcpy(this->name,n);
			this->people = p;
			this->speed = s;
		}
		else {
			this->name[0] = '\0';
			this->people = -1;
			this->speed = -1;
		}

	}

	//The member function getNumberOfPeople : int getNumberOfPeople() const; This query returns the number of people on a train.
	int Train::getNumberOfPeople() const {
		return this->people;
	}

	//The member function getName : const char* getName() const; This query returns the name of a train.
	const char* Train::getName() const {
		return this->name;
	}
	
	//The member function getSpeed : double getSpeed() const; This query returns the speed of a train.
	double Train::getSpeed() const {
		cout << setprecision(2) << fixed;
		return this->speed;
	}

	//The member function isSafeEmpty : bool isSafeEmpty() const; This query returns true if the Train object is in a safe empty state; false otherwise.
	bool Train::isSafeEmpty() const {
		bool empty = true;

		if (name[0] != '\0')
		{ 
			empty = false;
		}
		return empty;
	}

	//The member function display : void display() const; 
	//This member function sends the information about a Train to standard output in the following format if the object holds valid data values.
	void Train::display() const {

		if (this->isSafeEmpty())
		{
			cout << "Safe Empty State!" << endl;
		}
		else
		{
			cout << "NAME OF THE TRAIN : " << name <<  endl;
			cout << "NUMBER OF PEOPLE  : " << people << endl;
			cout << "SPEED             : " << speed << " km/h" << endl;
		}
		
	}

	Train::~Train() {

	}

}