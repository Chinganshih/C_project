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
	//Sets the m_length member variable to zero, and invokes the default constructor of the base class.
	Line::Line() : LblShape()
	{
		m_length = 0;
	}

	//Receives a Cstringand a value for the length of the line.
	//Passes the Cstring to the constructor of the base classand sets the m_length member variable to the value of the second argument.
	Line::Line(const char* label, int length):LblShape(label) {
		this->m_length = length;
	}

	//Reads comma - separated specs of the Line from istream.
	//This function overrides the getSpecs function of the base class as follows.
	//First, it will call the getSpecs function of the base class then it will read the value of the m_length attribute from the istream argument, and then it will ignore The rest of the characters up toand including the newline character '\n'.
	void Line::getSpecs(istream& istr) {
		int length;

		LblShape::getSpecs(istr);
		istr >> length;
		m_length = length;
		istr.ignore(1000, '\n');
	}

	//This function overrides the draw function of the base class.
	//If the m_length member variable is greater than zeroand the label() is not null, 
	//this function will first print the label() and then go to the new line.
	//Afterwards it keeps printing the '=' (assignment character) to the value of the m_length member variable.
	//Otherwise, it will take no action.
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