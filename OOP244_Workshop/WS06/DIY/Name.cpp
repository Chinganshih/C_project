// ------------------------------------------------------
//Workshop 6 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include "Name.h"
using namespace std;

namespace sdds {

	void Name::setEmpty() {

		firstName = nullptr;
		middleName = nullptr;
		lastName = nullptr;
	}

	//A Name object can be created in four different ways : 
	//1 - No argument.In this case, the Name is in a safe empty state. 
	//For the latest three, if any of the parts of the name provided are null or empty, the name object will be set into an empty state.
	Name::Name()
	{
		this->setEmpty();
	}

	//2 - One argument(Cstring).Only the first name is set
	Name::Name(const char* firstName) {

		if (firstName != nullptr && strlen(firstName) > 0)
		{
			this->firstName = new char[strlen(firstName) + 1];
			strcpy(this->firstName, firstName);
			this->middleName = nullptr;
			this->lastName = nullptr;
		}
		else this->setEmpty();
	}

	//3 - Two arguments(Cstring), First nameand last name are set. 
	Name::Name(const char* firstName, const char* lastName) {
		if (firstName != nullptr && strlen(firstName) > 0 && lastName != nullptr && strlen(lastName) >0)
		{
			this->firstName = new char[strlen(firstName) + 1];
			strcpy(this->firstName, firstName);
			this->lastName = new char[strlen(lastName) + 1];
			strcpy(this->lastName, lastName);
			this->middleName = nullptr;
		}
		else this->setEmpty();
	}

	//4 - Three arguments(Cstring), First, Middleand Last names are set.
	Name::Name(const char* firstName, const char* middleName, const char* lastName) {
		this->set(firstName, middleName, lastName);
	}

	void Name::set(const char* firstName, const char* middleName, const char* lastName) {
		
		if (firstName != nullptr && strlen(firstName) > 0 )
		{
			this->firstName = new char[strlen(firstName) + 1];
			strcpy(this->firstName, firstName);			
		}

		if (middleName != nullptr && strlen(middleName) > 0)
		{
			this->middleName = new char[strlen(middleName) + 1];
			strcpy(this->middleName, middleName);
		}
		else this->middleName = nullptr;

		if (lastName != nullptr && strlen(lastName) > 0)
		{
			this->lastName = new char[strlen(lastName) + 1];
			strcpy(this->lastName, lastName);
		}
		else this->lastName = nullptr;

	}

	Name::Name(const Name& n1) {
		this->set(n1.firstName, n1.middleName, n1.lastName);
	}

	Name& Name::operator=(const Name& n1) {
		if (&n1 != this) this->set(n1.firstName, n1.middleName, n1.lastName);
		return *this;
	}

	//The name must have a modifier method called "setShort" that accepts a boolean argument.If the argument passed is true, the middle name will be abbreviated when printed. (See Insertion to ostream for more detail)
	void Name::setShort(bool isAbbreviated) {
		char middle[3];
		
		if (isAbbreviated && this->middleName != nullptr) {
			middle[0] = this->middleName[0];
			middle[1] = '.';
			middle[2] = '\0';

			strcpy(this->middleName, middle);
		}
	}

	Name::~Name()
	{
		delete[] this->firstName;
		delete[] this->middleName;
		delete[] this->lastName;

		this->firstName = nullptr;
		this->lastName = nullptr;
		this->middleName = nullptr;
	}

	//A Cstring can be added to a Name object using a += operator, returning the reference of the object as follows.
	//When a Cstring is added to the name, it will be used to set the next available part of the name :
	//If the first name is null, it will set the first name.Otherwise, if the middle name is null it will set the middle name, or else, 
	//if the last name is null, it will set the last name.
	//If the name has all the three parts, the operation failsand sets the object into an invalid empty state.
	//If there are spaces in the Cstring the operation fails.The Name object is then set to an invalid state
	//If the string is null or empty the operation is aborted and the object will not change.
	Name& Name::operator +=(const char cstring[]) {

		bool hasSpace = false;
		int i;

		for (i = 0; i < strlen(cstring); i++)
		{
			if (isspace(cstring[i])) hasSpace = true;
		}

		if (cstring != nullptr && strlen(cstring) > 0 && !hasSpace)
		{
			if (this->firstName == nullptr) {
				this->firstName = new char[strlen(cstring) + 1];
				strcpy(this->firstName, cstring);
			}
			else if (this->middleName == nullptr) {
				this->middleName = new char[strlen(cstring) + 1];
				strcpy(this->middleName, cstring);
			}
			else if (this->lastName == nullptr) {
				this->lastName = new char[strlen(cstring) + 1];
				strcpy(this->lastName, cstring);
			}
			else this->setEmpty();
		}
		
		
		return *this;
	}

	/*If a Name object is casted to the Boolean type it should return false 
	//if it is in an invalid empty state otherwise it should return true; (A Name is valid if at least the first name is not null)*/
	Name::operator bool() const {
		bool result = false;
		
		if (this->firstName != nullptr) result = true;

		return result;
	}

	istream& Name::read(std::istream& istr) {
		string firstName;
		string middleName;
		string lastName;
		char* first = nullptr;
		char* middle = nullptr;
		char* last = nullptr;
		bool inValid = false;
		int nameNum = 0;

		istr >> firstName;
		first = new char[firstName.length() + 1];
		strcpy(first, firstName.c_str());
		nameNum++;
		
		if (!istr.eof())
		{
			if (istr.peek() != '\n') {
				istr >> middleName;
				middle = new char[middleName.length() + 1];
				strcpy(middle, middleName.c_str());
				nameNum++;
			}
			if (istr.peek() != '\n') {
				istr >> lastName;
				last = new char[lastName.length() + 1];
				strcpy(last, lastName.c_str());
				nameNum++;
			}
			if (istr.peek() != '\n') inValid = true;
			if (!inValid)
			{
				switch (nameNum)
				{
				case 1:
					this->set(first, nullptr, nullptr);
					break;
				case 2:
					this->set(first, nullptr, middle);
					break;
				case 3:
					this->set(first, middle, last);
				}

			}
			else this->setEmpty(), istr.clear();
		}
		else istr.fail();
		

		delete[] first;
		delete[] middle;
		delete[] last;
		first = nullptr;
		middle = nullptr;
		last = nullptr;

		return istr;
	}

	ostream& Name::print(std::ostream& ostr) const{
		
		if (this->firstName != nullptr && this->middleName != nullptr && this->lastName != nullptr)
		{
			ostr << this->firstName << " " << this->middleName << " " << this->lastName;
		}
		else if (this->firstName != nullptr && this->middleName == nullptr && this->lastName != nullptr) {
			ostr << this->firstName << " " << this->lastName;
		}
		else if (this->firstName != nullptr && this->middleName != nullptr && this->lastName == nullptr) {
			ostr << this->firstName << " " << this->middleName;
		}
		else if (this->firstName != nullptr && this->middleName == nullptr && this->lastName == nullptr) {
			ostr << this->firstName;
		}
		else ostr << "Bad Name";

		return ostr;
	}

	//Using operator>>, a Name can be extracted from the istream.A name entry is space separated ending with a newline.
	//A valid name can be :
	//1. FirstName < NEW LINE>
	//2. FirstName<SPACE>LastName < NEW LINE>
	//3. FirstName<SPACE>MiddleName<SPACE>LastName<NEW LINE>
	istream& operator>>(istream& istr, Name& n1) {
		
	
		return n1.read(istr);
	}

	ostream& operator<<(ostream& ostr, const Name& n1) {
		
		n1.print(ostr);
		return ostr;
	}

	bool hasSpace(const char* str) {
		int i;
		bool hasSpace = false;

		for (i = 0; i < strlen(str); i++)
		{
			if (isspace(str[i])) hasSpace = true;
		}

		return hasSpace;
	}

}