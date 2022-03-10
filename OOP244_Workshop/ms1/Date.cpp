/* Citation and Sources...
Final Project Milestone 1
Module: Date
Filename: Date.cpp
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
#include "Date.h"

namespace sdds {
	
	bool Date::validate() {
		bool isValid = 0;

		//If the year value is invalid(less than the current year or more than the maximum year value), the State is set to "Invalid year in date" and then set to the code 1.
		if (this->year < 2022 || this->year > max_year)
		{
			Status::set("Invalid year in date", 1);
		}
		//If the month value is invalid(less than 1 or more than 12), the State is set to "Invalid month in date" and then set to the code 2.
		else if (this->month < 1 || this->month > 12)
		{
			Status::set("Invalid month in date", 2);
		}
		//If the day value is invalid(less than one or more than the maximum number of days in the month based on the year), the State is set to "Invalid day in date" and then set to the code 3.
		else if (this->day < 1 || this->day > Utils::daysOfMon(this->month, this->year))
		{
			Status::set("Invalid day in date", 3);
		}
		else Status::clear(); isValid = 1;

		return isValid;
	}

	//Create a method to return a unique integer value tied to the date.Use this value to compare two dates.Use the following formula to obtain the unique integer value :
	int Date::uniqueDate() {
		return this->year * 372 + this->month * 31 + this->day;
	}


	Date::Date()
	{
		Utils::getSystemDate(&this->year, &this->month, &this->day);
	}

	Date::Date(int year, int month, int day) {
		if (validate()) {
			this->year = year;
			this->month = month;
			this->day = day;
		}
		else
			Utils::getSystemDate(&this->year, &this->month, &this->day);
	}

	Date::~Date(){}


}