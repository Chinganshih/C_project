///* ------------------------------------------------------
//Workshop 3 part 2
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
		if (n != nullptr && strlen(n) > 0 && p >=0 && s > 0 && s <= MAX_SPEED)
		{
			strcpy(name,n);
			people = p;
			speed = s;
		}
		else {
			memset(name, 0, MAX_NAME_LEN);
			people = 0;
			speed = 0.00;
		}

	}

	//The member function getNumberOfPeople : int getNumberOfPeople() const; This query returns the number of people on a train.
	int Train::getNumberOfPeople() const {
		return this->people;
	}

	//The member function getName : const char* getName() const; This query returns the name of a train.
	const char* Train::getName() const {

		if (this->isSafeEmpty())
		{
			return "Seneca Express";
		}
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

	//The member function loadPeople changes the number of people on a train.
	//The value of the input parameter is used to increase or decrease the number of people on a train.
	//It must make sure that the number of people will not be negative or exceed MAX_PEOPLE.
	//It returns true if the operation succeeds.It returns false if the Train object is in a safe empty state
	bool Train::loadPeople(int p)  {
		int newpeople = p + this->people;
		bool succeed = false;

		if (newpeople > MAX_PEOPLE) {
			this->people = MAX_PEOPLE;
		}
		else if (newpeople < 0) {
			this->people = 0;
		}
		else {
			this->people = newpeople;
			succeed = true;
		}

		return succeed;
	}

	//The member function changeSpeed changes the speed of a train.
	//The value of the input parameter is used to increase or decrease the speed of a train.
	//It must make sure that the speed of a train will not be negative or exceed MAX_SPEED.
	//It returns true if the operation succeeds.It returns false if the Train object is in a safe empty state.
	bool Train::changeSpeed(int s)  {
		double newspeed = s + this->speed;
		bool succeed = false;

		if (newspeed > MAX_SPEED) {
			this->speed = MAX_SPEED;
		}
		else if(newspeed < 0)
		{
			this->speed = 0;
		}
		else
		{
			this->speed = newspeed;
			succeed = true;
		}
		cout << setprecision(2) << fixed;
		return succeed;
	}

	//A global function transfer moves as many passengers as possible from the second Train to the first Train.
	//It has two parameters(first, second) that reference two Train objects.
	//The function must make sure that the number of people on both Train objects will not be negative or exceed MAX_PEOPLE.
	//It returns the number of people that have been moved to the first Train
	//It returns - 1 if any of the Train objects is in a safe empty state.

	int transfer(Train& frist, Train& second) {
		int transPeople = frist.getNumberOfPeople() + second.getNumberOfPeople();
		int changeOfPeople;

		if (transPeople > MAX_PEOPLE)
		{
			changeOfPeople = MAX_PEOPLE - frist.getNumberOfPeople();
			frist.loadPeople(changeOfPeople);
			second.loadPeople(-changeOfPeople);
		}
		else if (transPeople < 0) {
			frist.loadPeople(0);
			second.loadPeople(0);
		}
		else if(frist.isSafeEmpty() || second.isSafeEmpty()){
			transPeople = -1;
		}

		return transPeople;
	}
				
	Train::~Train() {

	}
}