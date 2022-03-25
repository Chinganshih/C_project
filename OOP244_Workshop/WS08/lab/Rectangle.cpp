// ------------------------------------------------------
//Workshop 8 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Rectangle.h"
using namespace std;

namespace sdds {

	void Rectangle::setEmpty() {
		m_width = 0;
		m_height = 0;
	}

	//Sets the widthand height member variables to zero.
	//It will also invoke the default constructor of the base class.
	Rectangle::Rectangle()
	{
		setEmpty();
	}

	//Receives a Cstring for the label, and two values for the widthand height of the Rectangle from the argument list.
	//Passes the Cstring to the constructor of the base class and sets the m_widthand m_height member variables to the corresponding values received from the argument list.
	//However if the m_height is less than 3 or m_width is less the length of the label() + 2 it will set the Rectangle to an empty state.
	Rectangle::Rectangle(const char* label, int width, int height):LblShape(label) {
		
		if (height > 3 || (unsigned)width >= (strlen(LblShape::label() + 2)))
		{
			m_width = width;
			m_height = height;
		}
		else setEmpty();
	}

	//Reads comma - separated specs of the Rectangle from istream.
	//This function overrides the getSpecs function of the base class as follows.
	//First, it will call the getSpecs function of the base class, 
	//then it will read two comma - separated values from istream for m_widthand m_lengthand then ignores the rest of the characters up toand including the newline character('\n').
	void Rectangle::getSpecs(istream& istr) {
		LblShape::getSpecs(istr);
		istr >> m_width;
		extractChar(istr, ',');
		istr >> m_height;
		if (istr.peek() == '\n')
		{
			istr.clear();
			istr.ignore(1000, '\n');
		}
	}

	//This function overrides the draw function of the base class.
	//If the Rectangle is not in an empty state, this function will draw a rectangle with a label inside as follows, otherwise, it will do nothing :
	//1. First line : prints '+', then prints the '-' character(m_width - 2) times and then prints '+' and goes to newline.
	//2. Second line : prints '|', then in(m_width - 2) spaces it prints the label() left justifiedand then prints '|' and goes to new line.
	//3. In next(m_height - 3) lines : prints '|', (m_width - 2) spaces then prints '|' and goes to new line.
	//Last line : exactly like first line.
	void Rectangle::draw(ostream& ostr) const {
		int i, spaceLine = m_height - 3, space = m_width -2;

		if (LblShape::label() != nullptr && m_height > 0 && m_width > 0)
		{
			//First Line
			ostr << '+';
			for (i = 0; i < space; i++) ostr << "-";
			ostr << '+' << endl;

			//Second Line
			ostr << '|' << left << setw(space) << LblShape::label() << '|' << endl;

			while (spaceLine)
			{
				//In next (m_height - 3) lines:
				ostr << '|' ;
				for (i = 0; i < space; i++) ostr << " ";
				ostr << '|' << endl;
				spaceLine--;
			}
			
			//Last Line
			ostr << "+";
			for (i = 0; i < (m_width - 2); i++) ostr << "-";
			ostr << "+";

		}
	}

}