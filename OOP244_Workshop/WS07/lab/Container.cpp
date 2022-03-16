// ------------------------------------------------------
//Workshop 7 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Container.h"
using namespace std;

namespace sdds{

	Container::Container()
	{
		setEmpty();
	}

	Container::Container(const char* content, int capacity, int volume) {
		
		if (isValid(content, capacity, volume))
		{
			this->content = nullptr;
			this->set(content, capacity, volume);
		}
		else setEmpty();
		
	}

	void Container::set(const char* content, int capacity, int volume) {
		delete[] this->content;
		this->content = nullptr;

		if (isValid(content, capacity, volume))
		{
			alloCopy(this->content, content);
			this->capacity= capacity;
			this->volume = volume;
		}
		else setEmpty();
	}

	void Container::alloCopy(char*& destination, const char* source) {
		if (source != nullptr)
		{
			destination = new char[strlen(source) + 1];
			strcpy(destination, source);
		}
		else {
			delete[] destination;
			destination = nullptr;
		}
	}

	//A value can be added to the Container.
	//If the container has enough space for the value, it will be added to the content volume.
	//If not, only a portion of value will be added to fill the container to its capacity.
	int Container::operator+=(int amount) {
		
		if ((amount + volume) <= capacity)
		{
			volume += amount;
		}
		else {
			amount = capacity - volume;
			volume = capacity;
		}

		return amount;
	}

	//A value can be deducted from the Container.
	//If the container has enough amount, it will reduce the content volume by the value.
	//If not, the container will be emptied.
	int Container::operator-=(int amount) {
		if (volume-amount >= 0)
		{
			volume -= amount;
		}
		else {
			amount = volume;
			volume = 0;
		}
		return amount;
	}

	//Returns true if the Container is in a valid state or false if it is not.
	Container::operator bool(){
		return isValid(this->content, this->capacity, this->volume);
	}

	//Accepts two arguments : the capacityand the content description.
	//If the capacity is a positive valueand the content description is a valid cString, it will set the corresponding attributesand therefore making the Container valid.
	void Container::clear(int capacity, const char* content) {
		if (capacity > 0 && content != nullptr && strlen(content) <= 50)
		{
			this->set(content, capacity);
		}
		else
		{
			delete[] this->content;
			this->content = nullptr;
		}
	}

	//Receivingand returning an ostream reference, the print will display a valid container as follows :
	//Printing an invalid container will result in printing the following : "****: (**cc/***)"
	ostream& Container::print(ostream& ostr) const{
		if (this->content == nullptr)
		{
			ostr << "****: (**cc/***)";
		}
		else ostr << this->content << ": (" << this->volume << "cc/" << this->capacity << ")";
		
		return ostr;
	}

	//Receivingand returning an istream reference, read will get an amount to be added to the container as follows :
	
	istream& Container::read(istream& istr) {
		
		int enter=-1;
		if (this->content == nullptr)
		{
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.ignore(100, '\n');
		}
		else
		{
			cout << "Add to "<< this->content << ": (" << this->volume << "cc/" << this->capacity << ")" << endl;
			cout << "> ";
			enter = getint(1, 999);
			cout << "Added " << (*this+=enter) << " CCs" << endl;
		}
		return istr;
	}

	/*If the prompt is not null it will be displayed before getting a valid integer.(reuse the previous getint())
	 If the entered integer is not within the acceptable range(minand max) then an error message is displayedand it will not let the user leave the function until an acceptable value is entered.
	 When printing the error message,
	 if the errMes argument is not null it will be displayed followed by ", retry: " otherwise the general error message "Value out of range [min<=val<=max]: " is displayed(replacing min and max with their values)*/
	int Container::getint(int min, int max) {
		int enter = -1;
		bool flag = 1;

		do
		{
			cin >> enter;
			cin.clear();
			cin.ignore(1000, '\n');
			if (!enter)
			{
				cout << "Invalid Integer, retry: ";
			}
			else if (enter < min || enter > max)
			{
				cout << "Value out of range [" << 1 << "<=val<=" << max << "]: ";
			}
			else flag = 0;
		} while (flag);
		
		return enter;
	}

	Container::~Container()
	{
		delete[] this->content;
		this->content = nullptr;
	}

	bool Container::isValid(const char* content, int capacity, int volume) const{
		return (strlen(content) <= 50 && content != nullptr && volume <= capacity);
	}

	//Sets the Container to an invalid empty state
	void Container::setEmpty() {
		content = nullptr;
		capacity = 0;
		volume = 0;
	}

	//returns the capacity of the container
	int Container::Capacity() const {
		return this->capacity;
	}

	//returns the content volume of the container
	int Container::Volume() const{
		return this->volume;
	}

	//Overload operator<<and operator>> to be able to printand read A container using coutand cin.
	ostream& operator<<(ostream& ostr, const Container& c) {
		return c.print(ostr);
	}

	istream& operator>>(istream& istr, Container& c) {
		return c.read(istr);
	}
}