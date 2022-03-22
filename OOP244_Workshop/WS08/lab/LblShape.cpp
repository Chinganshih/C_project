// ------------------------------------------------------
//Workshop 8 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "LblShape.h"
using namespace std;

namespace sdds {

	//Add a query called label that returns the unmodifiable value of m_label member variable.
	const char* LblShape::label() const {
		return this->m_label;
	}
	
	//Allocates memory large enough to hold the incoming Cstring argument pointed by the m_label member variable.
	//Then copies the Cstring argument to the newly allocated memory.
	LblShape::LblShape(const char* m_label) {
		delete[] this->m_label;
		this->m_label = new char[strlen(m_label) + 1];
		strcpy(this->m_label, m_label);
	}

	//Deletes the memory pointed by m_label member variable.
	LblShape::~LblShape() {

		delete[] this->m_label;
		this->m_label = nullptr;
	}

	void LblShape::extractChar(istream& istr, char ch) const {

		if (istr.peek() == ch)
		{
			istr.ignore();
		}
		else {
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}
	}

	//Reads a comma - delimited Cstring form istream :
	//Override the Shape::getSpecs pure virtual function to receive a Cstring(a label) from istream up to the ',' character(and then extract and ignore the comma).Afterward, follow the same logic as was done in the one argument constructor; allocate memory large enough to hold the Cstringand copy the Cstring into the newly allocated memory.
	void LblShape::getSpecs(std::istream& istr) {
		char* label = new char[100];

		istr.get(label, 100, ',');
		extractChar(istr, ',');

		delete[] this->m_label; // without it --> cause memory leak
		this->m_label = new char[strlen(label) + 1];
		strcpy(this->m_label, label);
		if (istr.peek() == ',') istr.ignore();

		delete[] label;
		label = nullptr;
	}
}