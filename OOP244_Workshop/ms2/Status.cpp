/* Citation and Sources...
Final Project Milestone 1
Module: Date
Filename: Status.cpp
Version 1.0
Author	Ching an shih
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Status.h"
using namespace std;

namespace sdds {

	void Status::setEmpty() {
		this->desc = nullptr;
		this->code = 0;
	}

	/*A Status object can be constructed with or without a CString as a description.
	If the description is provided, a dynamic copy of it will be kept in the class description.
	If the description is not provided, the class description will be set to null.
	In both cases the Code will be zero.*/
	Status::Status()
	{
		setEmpty();
	}

	Status::Status(const char* desc, int code)
	{
		if (desc != nullptr)
		{
			this->setEmpty();
			this->set(desc, code);
		}
		else setEmpty();
	}

	void Status::set(const char* desc, int code) {
		delete[] this->desc;

		if (desc != nullptr)
		{
			Utils::alocpy(this->desc, desc);
			this->code = code;
		}
		else setEmpty();

	}

	Status::Status(const Status& s) {
		this->setEmpty();
		this->set(s.desc, s.code);
	}

	Status& Status::operator=(const Status& s) {
		if (&s != this) this->set(s.desc, s.code);
		return *this;
	}

	Status::~Status()
	{
		delete[] this->desc;
		this->desc = nullptr;
	}

	//Assignment operator overloads
	//A Status object should be able to be assigned to an integer or a CString.
	//The results of the assignments should set the code or the description dynamically(with no memory leak).
	Status& Status::operator=(int code) {
		this->code = code;
		return *this;
	}

	Status& Status::operator=(const char* desc) {
		delete[] this->desc;
		Utils::alocpy(this->desc, desc);
		return *this;
	}

	//Casting a Status object to an integer should return the code
	Status::operator int() const {
		return this->code;
	}

	//Casting a Status object to a constant character pointer should return the description.
	Status::operator const char* () const {
		return this->desc;
	}

	//Casting a Status object to a boolean should return true if the description is null and false if it is not.
	//Which means if the Status has no description, the owner class is in a valid state. (No news is good news.)
	Status::operator bool()const {
		return (this->desc == nullptr) ? true : false;
	}

	//Create a method called clear() that safely deallocates the descriptionand sets the code to zero.This method will return a reference to the current object at the end.
	Status& Status::clear() {
		delete[] this->desc;
		this->desc = nullptr;
		this->code = 0;

		return *this;
	}

	//Overload the insertion operator to be able to print a Status object using ostream.
	//This operator overload should print the Status only if it is in an invalid state.
	//When printing the status object the code is printed only if it is not zero as follows `"ERR# ? ? ? : " where ??? replaced with the code.
	//Then the description of the Status object is printed.
	ostream& operator<<(std::ostream& ostr, const Status& s) {
		int code = s.operator int();

		if (!s)
		{
			if (code != 0) ostr << "ERR#" << code << ": ";
			ostr << s.operator const char* ();
		}
		return ostr;
	}



}