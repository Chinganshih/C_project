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

	void Name::deallocate() {
		delete[] this->firstName;
		delete[] this->middleName;
		delete[] this->lastName;
		
		this->firstName = nullptr;
		this->middleName = nullptr;
		this->lastName = nullptr;
	}

	bool Name::validName(const char* name) {
		return (name != nullptr && strlen(name) > 0);
	}

	//Allocate FirstName
	void Name::allocateFirst(const char* firstname) {
		delete[] this->firstName;
		this->firstName = new char[strlen(firstname) + 1];
		strcpy(this->firstName, firstname);
	}

	//Allocate MiddleName
	void Name::allocateMiddle(const char* middlename) {
		delete[] this->middleName;
		this->middleName = new char[strlen(middlename) + 1];
		strcpy(this->middleName, middlename);	
	}

	//Allocate LastName
	void Name::allocateLast(const char* lastname) {
		delete[] this->lastName;
		this->lastName = new char[strlen(lastname) + 1];
		strcpy(this->lastName, lastname);
	}

	//2 - One argument(Cstring).Only the first name is set
	Name::Name(const char* firstName) {

		if (validName(firstName))
		{
			this->setEmpty();
			this->set(firstName, "", "");
		}
		else this->setEmpty();
	}

	//3 - Two arguments(Cstring), First nameand last name are set. 
	Name::Name(const char* firstName, const char* lastName) {
		
		if (validName(firstName) && validName(lastName))
		{
			this->setEmpty();
			this->set(firstName, "", lastName);
		}
		else this->setEmpty();
	}

	//4 - Three arguments(Cstring), First, Middleand Last names are set.
	Name::Name(const char* firstName, const char* middleName, const char* lastName) {
		
		this->setEmpty();
		this->set(firstName, middleName, lastName);
	}

	void Name::set(const char* firstName, const char* middleName, const char* lastName) {
		
		this->deallocate();

		if (validName(firstName) && validName(middleName) && validName(lastName))
		{
			this->allocateFirst(firstName);
			this->allocateMiddle(middleName);
			this->allocateLast(lastName);
		}
		else if (validName(firstName) && !validName(middleName) && validName(lastName)) {
			
			this->allocateFirst(firstName);
			this->allocateLast(lastName);
		}
		else if (validName(firstName)) {
			this->allocateFirst(firstName);
		}
		else
		{
			this->setEmpty();
		}
	}

	Name::Name(const Name& n1) {
		this->setEmpty();
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
		unsigned i;
		
		for (i = 0; i < strlen(cstring); i++)
		{
			if (isspace(cstring[i])) hasSpace = true;
		}

		if (validName(cstring) && !hasSpace)
		{

			if (this->firstName == nullptr) {
				this->firstName = nullptr;
				delete[] firstName;
				this->allocateFirst(cstring);
			}
			else if (this->middleName == nullptr) {
				this->middleName = nullptr;
				delete[] middleName;
				this->allocateMiddle(cstring);
			}
			else if (this->lastName == nullptr) {
				this->lastName = nullptr;
				delete[] lastName;
				this->allocateLast(cstring);
			}
			else {
				this->deallocate();
			}
			
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

		//deallocate first ---> otherwise it causes memory leak
		deallocate();
		//extract firstname
		istr >> firstName;
		first = new char[firstName.length() + 1];
		strcpy(first, firstName.c_str());
		nameNum++;
		
		if (!istr.eof())
		{
			//extract middlename
			if (istr.peek() != '\n') {
				istr >> middleName;
				middle = new char[middleName.length() + 1];
				strcpy(middle, middleName.c_str());
				nameNum++;
			}
			//extract lastname
			if (istr.peek() != '\n') {
				istr >> lastName;
				last = new char[lastName.length() + 1];
				strcpy(last, lastName.c_str());
				nameNum++;
			}
			//if there is more value, set to inValid
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
		unsigned i;
		bool hasSpace = false;

		for (i = 0; i < strlen(str); i++)
		{
			if (isspace(str[i])) hasSpace = true;
		}

		return hasSpace;
	}

}