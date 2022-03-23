#pragma once
#ifndef IPRODUCT_H
#define IPRODUCT_H

namespace sdds {
	class iProduct
	{
	public:
		~iProduct() {};
		~iProduct() {};
		// to read the Stock-Keeping Unit from console before
		// main data entry
		int readSku(std::istream& istr) {};
		// to reduce the quantity on hand
		int operator-=(int qty) {};
		// to increase the quantity on hand
		int operator+=(int qty) {};
		// returns the price of the produce
		operator double()const {};
		// returns if the iProduct is in a good state
		operator bool()const {};
		// returns the number of products needed
		int qtyNeeded()const {};
		// retuns the quantity on hand
		int qty()const {};
		// determines if the iProduct is displayed in a linear format or 
		// descriptive format
		void Linear(bool isLinear) {};
		// saves the iProduct into a file
		std::ofstream& save(std::ofstream& ofstr)const {};
		// loads an iProduct from a file
		std::ifstream& load(std::ifstream& ifstr) {};
		// displays the iProduct on the screen
		std::ostream& display(std::ostream& ostr)const {};
		// reads the iProduct from the console
		std::istream& read(std::istream& istr) {};
		// return true if the sku is a match to the iProduct's sku
		bool operator==(int sku)const {};
		// rtrns true if the description is found in the iPorduct's description
		bool operator==(const char* description)const {};
	};
	std::ostream& operator<<(std::ostream& ostr, const iProduct& i);
	std::istream& operator>>(std::istream& istr, const iProduct& i);
}

#endif // !IPRODUCT_H
