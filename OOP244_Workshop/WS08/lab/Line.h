// ------------------------------------------------------
//Workshop 8 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------

#pragma once
#ifndef _LINE_H_
#define _LINE_H_
#include "LblShape.h"

namespace sdds {
	//Line; encapsulates a horizontal line on a screen with the label
	//(this concrete class draws a labelled line)
	class Line: public  LblShape
	{
		//Create a member variable called m_length to hold the length of the Line in characters.
		int m_length=0;
	public:
		Line();
		Line(const char* label, int length);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr) const;
	};


}
#endif // !_LINE_H_

