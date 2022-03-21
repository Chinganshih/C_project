// ------------------------------------------------------
//Workshop 8 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Line.h"
#include <iomanip>
using namespace std;

namespace sdds {

	Line::Line() : LblShape()
	{
		m_length = 0;
	}

	Line::Line(const char* label, int length):LblShape(label) {
		this->m_length = length;
	}

	void Line::getSpecs(istream& istr) {
		int length;

		LblShape::getSpecs(istr);
		istr >> length;
		m_length = length;
		istr.ignore(1000, '\n');
	}

	void Line::draw(ostream& ostr) const {
		int i;
		if (m_length > 0 && LblShape::label() != nullptr)
		{
			ostr << LblShape::label() << endl;
			for ( i = 0; i < m_length; i++)
			{
				ostr << "=";
			}
			
		}
	}
}