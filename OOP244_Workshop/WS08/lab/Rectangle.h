// ------------------------------------------------------
//Workshop 8 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------

#pragma once
#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_
#include "LblShape.h"

namespace sdds {
	//Rectangle; encapsulates a rectangle on the screen that can be labelled
	//(this concrete class draws a rectangle with a label inside).
	class Rectangle : public LblShape
	{
		int m_width;
		int m_height;
		void setEmpty();
	public:
		Rectangle();
		Rectangle(const char* label, int width, int height);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr) const;
	};

	
}
#endif // !_RECTANGLE_H_