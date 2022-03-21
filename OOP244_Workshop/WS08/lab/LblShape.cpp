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
	const char* LblShape::label() const {
		return this->m_label;
	}
	LblShape::LblShape() {}

	LblShape::LblShape(const char* m_label) {
		this->m_label = nullptr;
		delete[] this->m_label;

		this->m_label = new char[strlen(m_label) + 1];
		strcpy(this->m_label, m_label);
	}

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

	void LblShape::getSpecs(std::istream& istr) {
		char* label = new char[100];

		istr.get(label, 100, ',');
		extractChar(istr, ',');

		this->m_label = new char[strlen(label) + 1];
		strcpy(this->m_label, label);
		if (istr.peek() == ',') istr.ignore();
	}
}