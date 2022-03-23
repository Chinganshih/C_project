/* Citation and Sources...
Final Project Milestone 3
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
#define _CRT_SECURE_NO_WARNINGS
#include "iProduct.h"
#include <iostream>
#include <cstring>

using namespace std;
namespace sdds {

	istream& operator>>(istream& istr, iProduct& i) {
		i.read(istr);
		return istr;
	}

	ostream& operator<<(ostream& ostr, const iProduct& i) {
		i.display(ostr);
		return ostr;
	}
}