// ------------------------------------------------------
//Workshop 8 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------

#pragma once
#ifndef _SHAPE_H_
#define _SHAPE_H_

namespace sdds {
	//Shape; encapsulates a shape that can be drawn on the screen
	//(An interface, that is an abstract base class with only pure virtual functions)
	class Shape
	{
	public:
		//Returns voidand receives a reference to ostream as an argument.This pure virtual function can not modify the current object.
		virtual void draw(std::ostream& ostr) const = 0;

		//Returns voidand receives a reference to istream as an argument.
		virtual void getSpecs(std::istream& istr) = 0;

		//Create a virtual empty destructor for the shape interface.
		//this guarantees that any dynamically allocated derived class from the shape interface pointed by a base class pointer will be removed properly from memory when deleted.
		virtual ~Shape() {};
	};

	//Overload the insertion and extraction operators(using drawand getSpecs functions) so any shape object can be written or read using ostream and istream.
	std::ostream& operator<<(std::ostream& ostr, const Shape& s);
	std::istream& operator>>(std::istream& istr, Shape& s);


}
#endif // !_SHAPE_H_