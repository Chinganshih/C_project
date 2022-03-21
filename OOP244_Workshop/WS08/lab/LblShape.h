// ------------------------------------------------------
//Workshop 8 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------

#pragma once
#ifndef _LBISHPAE_H_
#define _LBISHPAE_H_
#include "Shape.h"

namespace sdds {
	//LblShape; encapsulates a shape that can be labelled
	//(An abstract base class that represents a labelled shape)
	class LblShape : public Shape
	{
		//Add a character pointer member variable called m_labeland initialize it to null.This member variable will be used to hold the dynamically allocated label for the Shape.
		char* m_label{};
	protected:
		//Add a query called label that returns the unmodifiable value of m_label member variable.
		const char* label() const;
	public:
		LblShape();
		LblShape(const char* m_label);
		~LblShape();
		void extractChar(std::istream& istr, char ch) const;
		void getSpecs(std::istream& istr);
	};

	
}
#endif // ! _LBISHPAE_H_