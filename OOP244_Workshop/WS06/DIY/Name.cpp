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
		
		if (firstName != nullptr && strlen(firstName) > 0 && lastName != nullptr && strlen(lastName) > 0 && middleName != nullptr && strlen(middleName) > 0)
		{
			this->firstName = new char[strlen(firstName) + 1];
			strcpy(this->firstName, firstName);
			this->lastName = new char[strlen(lastName) + 1];
			strcpy(this->lastName, lastName);
			this->middleName = new char[strlen(middleName) + 1];
			strcpy(this->middleName, middleName);
		}
		else this->setEmpty();
	}

	//The name must have a modifier method called "setShort" that accepts a boolean argument.If the argument passed is true, the middle name will be abbreviated when printed. (See Insertion to ostream for more detail)
	void Name::setShort(bool isAbbreviated) {
		
		if (isAbbreviated) strcpy(this->middleName, (&this->middleName[0] + '.'));
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
				strcpy(this->firstName, cstring);
			}
			else if (this->lastName == nullptr) {
				strcpy(this->lastName, cstring);
			}
			else if (this->middleName == nullptr) {
				strcpy(this->middleName, cstring);
			}
		}
		else if (this->firstName != nullptr && this->lastName != nullptr && this->middleName != nullptr || hasSpace) {
			this->setEmpty();
		}
		
		return *this;
	}

	/*If a Name object is casted to the Boolean type it should return false 
	//if it is in an invalid empty state otherwise it should return true; (A Name is valid if at least the first name is not null)*/
	Name::operator bool() const {
		bool result = false;
		
		if (this->firstName != nullptr) result = true;
		if (this) result = false;

		return result;
	}
	
	void Name::extractChar(std::istream& istr, char ch) const {
		if (istr.peek() == ch || isspace(ch))
		{
			istr.ignore();
		}
		else {
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}
	}

	istream& Name::read(std::istream& istr) {
		char* firstName = nullptr;
		char* middleName = nullptr;
		char* lastName = nullptr;
		string str;
		bool inValid = false;

		getline(istr, str, ' ');
		firstName = new char[str.length() + 1];
		strcpy(firstName, str.c_str());
		this->extractChar(istr, ' ');
		
		if (getline(istr, str, ' ')) {
			middleName = new char[str.length() + 1];
			strcpy(middleName, str.c_str());
			
		}
		
		if (getline(istr, str, '\n')) {
			lastName = new char[str.length() + 1];
			strcpy(lastName, str.c_str());
			(hasSpace(lastName)) ? inValid = true : 0;
			
		}

		if (!inValid) {
			this->set(firstName, middleName, lastName);
		}

		delete[] firstName;
		delete[] middleName;
		delete[] lastName;
		
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
		
		n1.read(istr);
		return istr;
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