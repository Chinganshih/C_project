// ------------------------------------------------------
//Workshop 8 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Shape.h"
using namespace std;

namespace sdds {

	//Overload the insertionand extraction operators(using drawand getSpecs functions) so any shape object can be written or read using ostreamand istream.
	ostream& operator<<(ostream& ostr, const Shape& s) {
		s.draw(ostr);
		return ostr;
	}

	istream& operator>>(istream& istr, Shape& s) {
		s.getSpecs(istr);
		return istr;
	}
}