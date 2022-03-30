/* Citation and Sources...
Final Project Milestone 4
Module: Itme
Filename: Itme.cpp
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

#define CRT_SECURE_NO_WARNINGS
#include "Item.h"
#include "Utils.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
namespace sdds {

	Item::Item() : desc(nullptr)
	{
		price = 0;
		hand_qua = 0;
		need_qua = 0;
		desc = nullptr;
		flag = false;
		sku = 0;
	}

	//create a query called linear that returns the linear flag of the Item
	bool Item::linear() const {
		return flag;
	}

	//Rule of three
	//Rule of three is implemented to make sure there is no memory leak in case of copying, assignment or destruction.
	Item::Item(const Item& i) :desc(nullptr) {
		//shallow copy
		price = i.price;
		hand_qua = i.hand_qua;
		need_qua = i.need_qua;
		flag = i.flag;

		//dynamic allocation for description
		delete[] desc;
		ut.alocpy(desc, i.desc);
	}

	Item& Item::operator=(const Item& i) {
		// check for self-assignments
		if (this != &i)
		{
			// shallow copy non-resource variables
			price = i.price;
			hand_qua = i.hand_qua;
			need_qua = i.need_qua;
			flag = i.flag;
			// deallocate previously allocated dynamic memory 
			delete[] desc;
			// allocate new dynamic memory, if needed
			// deep copy
			ut.alocpy(desc, i.desc);
		}
		else desc = nullptr;

		return *this;
	}

	Item::~Item()
	{
		delete[] this->desc;
		this->desc = nullptr;
	}

	//the qtyNeeded method returns the needed - quantity attribute
	int Item::qtyNeeded()const {
		return need_qua;
	}

	//the qty method returns the on - hand quantity attribute
	int Item::qty()const {
		return hand_qua;
	}

	//the double conversion operator overload returns the price
	Item::operator double()const {
		return price;
	}

	//the boolean conversion operator overload returns the state of the object being good.
	Item::operator bool()const {
		return flag;
	}

	// the operator-= reduces the on-hand quantity by the received value
	int Item::operator-=(int qty) {
		return hand_qua -= qty;
	}

	// the operator+= increases the on-hand quantity by the received value
	int Item::operator+=(int qty) {
		return hand_qua += qty;
	}

	//the linear modifier sets the linear flag attribute to true or false.
	void Item::linear(bool isLinear) {
		flag = isLinear;
	}

	Item& Item::clear() {

		delete[] this->desc;
		desc = nullptr;
		price = 0;
		hand_qua = 0;
		need_qua = 0;
		flag = false;
		sku = 0;

		return *this;
	}

	//the integer comparison returns true if the SKU attribute matches the received value
	bool Item::operator==(int sku)const {
		return (this->sku == sku) ? true : false;
	}

	//the constant character pointer comparison searches in the description of the Item for the appearance of the received Cstring.
	//If a match was found it returns true.If any of the descriptions(The Items or the received value) are null or the match is not found, it will return false.
	bool Item::operator==(const char* description)const {
		char* match;
		match = strstr(this->desc, description);
		if (match) {

		}
		return (match && this->desc != nullptr && description != nullptr) ? true : false;
	}

	//If the state of the Item is good, it will write SKU, description, on - hand quantity, needed quantityand price in tab - separated format.
	//note that the price should be written with 2 digits after the decimal point.
	ofstream& Item::save(ofstream& ofstr)const {
		if (desc)
		{
			ofstr << sku << "\t" << desc << "\t" << hand_qua << "\t" << need_qua << "\t" << fixed << setprecision(2) << price;
		}
		return ofstr;
	}

	//The tab - separated SKU, description, on-hand quantity, needed quantityand price are read into their corresponding attributes and then a single character is discarded from the file.
	ifstream& Item::load(ifstream& ifstr) {
		//char* indesc = new char[1000];
		string indesc;

		if (ifstr.good())
		{
			delete[] desc;
			ifstr >> sku;
			ut.extractChar(ifstr, '\t');
			getline(ifstr, indesc, '\t');
			//ifstr.get(indesc, 1000, '\t');
			ut.alocpy(desc, indesc.c_str());
			ifstr >> hand_qua;
			ut.extractChar(ifstr, '\t');
			ifstr >> need_qua;
			ut.extractChar(ifstr, '\t');
			ifstr >> price;
			ut.extractChar(ifstr, '\t');

			//If ifstream is in a bad state after the read the state of the item will be set to "Input file stream read failed!"
			if (ifstr.bad()) s = "Input file stream read failed!";
		}
		else ifstr.setstate(ios::badbit);

		//ensure to delete any dynamic allocation
		/*delete[] indesc;
		indesc = nullptr;*/

		return ifstr;
	}

	//If the state is bad, the state is printed instead.
	//If the state is good the following will be done.
	ostream& Item::display(ostream& ostr)const {
		//Note that if the description is too long only the first 35 characters will be printed
		string str_desc = desc;
		str_desc = str_desc.substr(0, 35);

		if (ostr.fail())
		{
			ostr << s;
		}
		else if (linear()) {
			ostr << setw(5) << sku << " | "
				<< setw(35) << setfill(' ') << left << str_desc <<  " | "
				<< setw(4) << right << hand_qua << " | "
				<< setw(4) << right << need_qua << " | "
				<< setw(7) << right << fixed << setprecision(2) << price << " |";
		}
		else
		{
			ostr << "AMA Item:" << endl;
			ostr << sku << ": " << desc << endl;
			ostr << "Quantity Needed: " << need_qua << endl;
			ostr << "Quantity Available: " << hand_qua << endl;
			ostr << "Unit Price: $" << price << endl;
			ostr << "Needed Purchase Fund: $" << fixed << setprecision(2) << price * ((double)need_qua - (double)hand_qua) << endl;
		}
		return ostr;
	}

	//read will first prompt the user with the title "AMA Item" and then displays the SKU and reads the rest of the information in a full - proof way(the same as SKU).
	istream& Item::read(istream& istr) {
		char* indesc = new char[100];
		//After deleting the descriptionand clearing the state.
		delete[] desc;
		desc = nullptr;
		istr.clear();

		if (istr.fail())
		{
			s = "Console entry failed!";
		}
		else {
			cout << "AMA Item:" << endl;
			cout << "SKU: " << sku << endl;
			cout << "Description: ";
			istr.get(indesc, 100, '\n');
			ut.extractChar(istr, '\n');
			ut.alocpy(desc, indesc);
			delete[] indesc;
			cout << "Quantity Needed: ";
			need_qua = ut.getint(1, 9999, "validNeed");
			ut.extractChar(istr, '\n');
			cout << "Quantity On Hand: ";
			hand_qua = ut.getint(0, need_qua, "validhand");
			ut.extractChar(istr, '\n');
			cout << "Unit Price: $";
			price = ut.getDouble(0.0, 9999.0, "validPrice");
			ut.extractChar(istr, '\n');
		}

		return istr;
	}

	//Reads the SKU from the screen with the prompt "SKU: ".It makes sure the SKU number begins with digits 4 to 9 and it is 5 digits long.
	int Item::readSku(istream& istr) {
		cout << "SKU: ";
		sku = ut.getint(40000, 99999, "validSKU");
		istr.clear();
		istr.ignore(1000, '\n');
		return sku;
	}

}