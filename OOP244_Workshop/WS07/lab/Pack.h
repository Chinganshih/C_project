// ------------------------------------------------------
//Workshop 7 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------

#ifndef PACK_H_
#define PACK_H_
#include "Container.h"

namespace sdds {
	class Pack : public Container
	{
		/*
		1. content description(same as container)
		2. size: The maximum number of units the Pack can hold
		3. unit size : The capacity of each unit in the pack in CCs, defaulted to 330.
		4. Number of units : The number of units in the pack to the maximum of the size of the pack.Defaulted to 0
		*/
		char* content;
		int size;
		int unitSize;
		int numOfUnits;
		void setEmpty();
	public:
		Pack();
		Pack(const char* content, int size, int unitSize = 330, int numOfUnits = 0);
		~Pack();
		void set(const char* content, int size, int unitSize = 330, int numOfUnits = 0);
		int operator+=(int amount);
		int operator-=(int amount);
		int unit() const;
		int noOfUnits() const;
		int Size() const;
		void clear(int size, int unitSize, const char* content);
		int getint(int min, int max);
		std::ostream& print(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};

	std::ostream& operator<<(std::ostream& ostr, const Pack& p);
	std::istream& operator>>(std::istream& istr, Pack& p);
}

#endif // !PACK_H_
