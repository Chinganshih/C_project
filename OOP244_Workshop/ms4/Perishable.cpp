/* Citation and Sources...
Final Project Milestone 4
Module: Date
Filename: Perishable.cpp
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
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "Perishable.h"
#include "Utils.h"
using namespace std;

namespace sdds {
	
	//A Perishable object is created using the default constructor that creates an empty perishable item.
	Perishable::Perishable() {
		instruction = nullptr;
	}

	//Implement the rule of three so a Perishable Item can be copied or assigned to another perishable item.
	Perishable::~Perishable(){
		delete[] instruction;
		instruction = nullptr;
	}

	Perishable& Perishable::clear() {
		delete[] instruction;
		instruction = nullptr;

		return *this;
	}

	Perishable::Perishable(const Perishable& p):instruction(nullptr) {
		//shallow copy
		this->expiryDate = p.expiryDate;
		//deep copy
		delete[] instruction;
		ut.alocpy(this->instruction, p.instruction);
	}

	Perishable& Perishable::operator=(const Perishable& p) {
		if (this != &p)
		{
			//shallow copy
			this->expiryDate = p.expiryDate;
			//deep copy
			delete[] instruction;
			ut.alocpy(this->instruction, p.instruction);
		}
		else instruction = nullptr;

		return *this;
	}

	//Create a constant query that returns a constant reference of the expiry date.
	const Date& Perishable::expiry() const {
		return this->expiryDate;
	}

	//Override readSKU function to only receive SKU numbers between 10000 and 39999 (only SKUs starting with digits 1 to 3)
	int Perishable::readSku(istream& istr) {
		cout << "SKU: ";
		sku = ut.getint(10000, 39999, "validSKU");
		istr.clear();
		istr.ignore(1000, '\n');
		return sku;
	}

	/*it will call the save of the Base class.
	writes a tab
	writes the handling instructions, if handling instructions existand the attribute is not empty.
	writes a tab
	writes an unformatted copy of the expiry date*/
	ofstream& Perishable::save(ofstream& ofstr)const {
		if (this != nullptr)
		{
			Item::save(ofstr);
			ofstr << '\t';
			if (instruction) ofstr << instruction << '\t';
			ofstr << expiryDate;
		}

		return ofstr;
	}

	/*calls the load of the Base class.
	reads the handling instructions dynamically into the handling instructions attribute
	ignores the tab
	reads the expiry date
	ignores the newline.
	if the ifstream object has failed, it will set the state of the Item to "Input file stream read (perishable) failed!"*/
	ifstream& Perishable::load(ifstream& ifstr) {
		string instr;
		char ch;

		delete[] instruction;
		instruction = nullptr;
		clear();

		//calls the load of the Base class.
		Item::load(ifstr);
		ch = ifstr.peek();
		if (!isdigit(ch))
		{
			getline(ifstr, instr, '\t');
			ut.alocpy(instruction, instr.c_str());
		}
		ifstr >> expiryDate;
		ut.extractChar(ifstr, '\n');

		if (ifstr.fail()) s = "Input file stream read (perishable) failed!";

		return ifstr;
	}

	//if the Perishable Item is in a bad state, the state is printed
	ostream& Perishable::display(ostream& ostr)const {

		if (this == nullptr)
		{
			ostr << s;
		}
		else if (linear())
		{
			//display of the base class is called
			Item::display(ostr);
			//if handling instructions are not null and not empty a single asterisk('*') is printed otherwise a single space(' ') is printed.
			if (instruction != nullptr && strlen(instruction) > 0)
			{
				ostr << "*";
			}
			else ostr << " ";
			//the expiry date is printed
			ostr << expiryDate;
		}
		else
		{
			//prints "Perishable "
			ostr << "Perishable ";
			//displays the base class
			Item::display(ostr);
			//prints "Expiry date: "
			//printed the expiry date(formatted)
			ostr << "Expiry date: " << expiryDate;
			//if handling instructions attribute is not null and is not empty "Handling Instructions: " and the content of the instructions are printed
			if (instruction != nullptr && strlen(instruction) > 0) {
				ostr << endl;
				ostr << "Handling Instructions: " << instruction;
			}
			//new line is printed
			ostr << endl;
		}
		return ostr;
	}

	istream& Perishable::read(istream& istr) {
		char* instr = new char[1000];

		//read of the base class is called
		Item::read(istr);
		//the handling instructions memory is deletedand the attribute is set to null
		delete[] instruction;
		instruction = nullptr;

		/*prompts: "Expiry date (YYMMDD): "
		the expiry date is read
		newline is ignored*/
		cout << "Expiry date (YYMMDD): ";
		istr >> expiryDate;
		ut.extractChar(istr, '\n');

		//peeksand if the very first character is not '\n' it will read the instructions dynamically into the instructions attribute.
		//otherwise, nothing is readand the attribute remains null.
		cout << "Handling Instructions, ENTER to skip: ";
		if (istr.peek() != '\n')
		{
			istr.get(instr, 1000, '\n');
			ut.alocpy(instruction, instr);
		}

		if (istr.fail()) s = "Perishable console date entry failed!";
		
		delete[] instr;
		instr = nullptr;

		return istr;
	}
}