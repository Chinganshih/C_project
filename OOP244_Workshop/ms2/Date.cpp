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
#include "Utils.h"

using namespace std;

namespace sdds {

	bool Date::validate() {
		bool isValid = 0;

		//If the year value is invalid(less than the current year or more than the maximum year value), the State is set to "Invalid year in date" and then set to the code 1.
		if (this->year < 2022 || this->year > max_year)
		{
			s = "Invalid year in date";
			s = 1;
		}
		//If the month value is invalid(less than 1 or more than 12), the State is set to "Invalid month in date" and then set to the code 2.
		else if (this->month < 1 || this->month > 12)
		{
			s = "Invalid month in date";
			s = 2;
		}
		//If the day value is invalid(less than one or more than the maximum number of days in the month based on the year), the State is set to "Invalid day in date" and then set to the code 3.
		else if (this->day < 1 || this->day > Utils::daysOfMon(this->month, this->year))
		{
			s = "Invalid day in date";
			s = 3;
		}
		else {
			Status::clear();
			isValid = 1;
		}

		return isValid;
	}

	//Create a method to return a unique integer value tied to the date.Use this value to compare two dates.Use the following formula to obtain the unique integer value :
	int Date::uniqueDate() {
		return this->year * 372 + this->month * 31 + this->day;
	}

	Date::Date()
	{
		this->set(sdds_testYear, sdds_testMon, sdds_testDay);
		this->isFormat = 1;
	}

	Date::Date(int year, int month, int day) {
		this->set(year, month, day);
	}

	void Date::set(int year, int month, int day) {
		if (year != 0 && month != 0 && day != 0) {
			this->year = year;
			this->month = month;
			this->day = day;
			this->isFormat = 1;
		}
		else
			Utils::getSystemDate(&this->year, &this->month, &this->day);
	}

	Date::Date(const Date& date) {
		this->set(date.year, date.month, date.day);
	}

	Date& Date::operator=(const Date& date) {
		if (this != &date)
		{
			//shallow copy
			year = date.year;
			month = date.month;
			day = date.day;
		}
		return *this;
	}
	Date::~Date() {}

	//Overload all the six comparison operators : == , != , <, >, <= , >=
	//Use the private method, unique date value for the comparison
	bool Date::operator==(Date& date) {
		return (this->uniqueDate() == date.uniqueDate());
	}

	bool Date::operator!=(Date& date) {
		return (this->uniqueDate() != date.uniqueDate());
	}

	bool Date::operator<(Date& date) {
		return (this->uniqueDate() < date.uniqueDate());
	}

	bool Date::operator>(Date& date) {
		return (this->uniqueDate() > date.uniqueDate());
	}

	bool Date::operator<=(Date& date) {
		return (this->uniqueDate() <= date.uniqueDate());
	}

	bool Date::operator>=(Date& date) {
		return (this->uniqueDate() >= date.uniqueDate());
	}

	//Create an accessor method called state that returns a constant reference to the State of the Date.
	const Date::Status& Date::state() {
		return this->s;
	}

	//Create a modifier method called formatted to set the Formatted flag(attribute) of the Date.
	//This method should return the reference of the current object.
	Date& Date::formatted(bool flag) {
		this->isFormat = flag;
		return *this;
	}

	//If the Date object is casted to a boolean, the state of the date object is returned.
	Date::operator bool()const {
		return (this->s);
	}

	//Create a method called write that receivesand returns a reference of the ostream object in which it inserts the date value as follows :
	ostream& Date::write(ostream& ostr) const {

		if (this->isFormat)
		{
			//If the Formatted attribute is true, it will print the date in the following format :
			//YYYY / MM / DD, monthand day are printed in 2 spaces padded with zero.
			ostr << this->year << "/" << setfill('0') << setw(2) << this->month << "/" << setfill('0') << setw(2) << this->day;
		}
		//If the Formatted attribute is false it will print the date in the following format :
		//YYMMDD, monthand day are printed in 2 spaces padded with zero.
		else ostr << this->year - (this->year / 100) * 100 << setfill('0') << setw(2) << this->month << setfill('0') << setw(2) << this->day;

		return ostr;
	}

	istream& Date::read(istream& istr) {

		int date, year, mon, day;
		cin >> date;

		if (!date)
		{
			s = "Invalid date value";
			s = 0;
			istr.setstate(ios::badbit);
		}
		else if (date > 9 && date < 100) {
			s = "Invalid month in date";
			s = 2;
			istr.setstate(ios::badbit);
		}
		//If the value is a four digits integer then the Date is read as : MMDD and the year is set to the current system year.
		else if (date > 999 && date < 10000)
		{
			mon = date / 100;
			day = date - mon * 100;
			this->set(2022, mon, day);
			if (!validate()) istr.setstate(ios::badbit);
		}
		//If the value is a six digits integer then the date is read as : YYMMDD.
		else if (date > 99999 && date < 1000000)
		{
			year = date / 10000;
			mon = (date - year * 10000) / 100;
			day = date - year * 10000 - mon * 100;
			this->set(year + 2000, mon, day);
			if (!validate())istr.setstate(ios::badbit);
		}
		//Then the data is validated and if the validation fails the istream object is set to a fail state.istream::setstate(ios::badbit);
		else
		{
			istr.setstate(ios::badbit);
		}

		return istr;
	}

	//Overload the insertionand extraction operators to writeand read a date object through ostreamand istream respectively. (cout and cin)
	istream& operator>>(istream& istr, Date& date) {
		return date.read(istr);
	}

	ostream& operator<<(ostream& ostr, const Date& date) {
		return date.write(ostr);
	}

}