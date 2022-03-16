// ------------------------------------------------------
//Workshop 7 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Pack.h"
using namespace std;

namespace sdds{

	void Pack::setEmpty() {
		content = nullptr;
		size = 0;
		unitSize = 0;
		numOfUnits = 0;
	}

	Pack::Pack() {
		setEmpty();
		Container::setEmpty();
	}

	Pack::Pack(const char* content, int size, int unitSize, int numOfUnits) {
		
		this->content = nullptr;
		set(content, size, unitSize, numOfUnits);
	}

	/*
	Initialize the Base Container class with :
	- content description(directly passed to the container constructor)
	- capacity(size* unit size)
	- content volume(number of units* unit size)
	*/
	void Pack::set(const char* content, int size, int unitSize, int numOfUnits) {
		delete[] this->content;

		if (unitSize > 0 && Container::isValid(content, size * unitSize, numOfUnits * unitSize))
		{
			Container::alloCopy(this->content, content);
			this->size = size;
			this->unitSize = unitSize;
			this->numOfUnits = numOfUnits;
			Container::set(content, size * unitSize, numOfUnits * unitSize);			
		}
		else {
			setEmpty();
			Container::setEmpty();
		}
	}

	Pack::~Pack()
	{
		delete[] this->content;
		this->content = nullptr;
	}

	int Pack::operator+=(int amount) {
		int addToNumOfUnits = (Container::operator+=(amount * unitSize)) / unitSize;
		numOfUnits += addToNumOfUnits;
		return addToNumOfUnits;
	}
	
	int Pack::operator-=(int amount) {
		int deToNumOfUnits = Container::operator-=(amount * unitSize) / unitSize;
		numOfUnits -= deToNumOfUnits;
		return deToNumOfUnits;
	}

	//returns the unit size attribute
	int Pack::unit() const {
		return this->unitSize;
	}

	//returns the content volume of the Base class divided by the unit size
	int Pack::noOfUnits() const {
		return Container::Volume() / this->unitSize;
	}

	//return the capacity of the base class divided by the unit size
	int Pack::Size() const {
		return Container::Capacity() / this->unitSize;
	}

	//Overloads the clear function of the Base class
	//Accepts three arguments : the Pack size, the unit sizeand the content description.
	//If the unit size is greater than zero it will call the clear of the base class passing the product of pack sizeand the unit sizeand the content description.
	//Then it will set the unit size attribute to the unit size argument.
	void Pack::clear(int size, int unitSize, const char* content) {
		if (unitSize > 0)
		{ 
			Container::clear(size * unitSize, content);
			this->unitSize = unitSize;
			this->size = size;
		}
	}

	ostream& Pack::print(std::ostream& ostr) const {
		if (this->size > 0)
		{
			Container::print(ostr);
			ostr << ", " << this->numOfUnits << " in a pack of " << this->size;
		}

		return ostr;
	}

	istream& Pack::read(std::istream& istr) {
		int enter = -1, flag = 1;

		if (this->content == nullptr)
		{
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.ignore(100, '\n');
		}
		else
		{
			if (this->numOfUnits < this->size)
			{
				cout << "Add to " << this->content << ": (" << Container::Volume() << "cc/" << Container::Capacity() << "), " << this->numOfUnits << " in a pack of " << this->size << endl;
				cout << "> ";
				enter = getint(1, size - numOfUnits);
				cout << "Added " << operator+=(enter) << endl;
			}
			else {
				cout << "Pack is full!, press <ENTER> to continue...";
				istr.ignore();
			}
		}
		return istr;
	}

	int Pack::getint(int min, int max) {
		int enter = -1, flag =1;
		do
		{
			cin >> enter;
			cin.clear();
			cin.ignore(1000, '\n');
			if (!enter)
			{
				cout << "Invalid Integer, retry: ";
			}
			else if (numOfUnits + enter > size)
			{
				cout << "Value out of range [" << 1 << "<=val<=" << max << "]: ";
			}
			else flag = 0;
		} while (flag);

		return enter;
	}

	ostream& operator<<(ostream& ostr, const Pack& p) {
		return p.print(ostr);
	}

	istream& operator>>(istream& istr, Pack& p) {
		return p.read(istr);
	}
}