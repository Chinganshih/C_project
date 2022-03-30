/* Citation and Sources...
Final Project Milestone 4
Module: Itme
Filename: Itme.h
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

#pragma once
#ifndef ITEM_H_
#define ITEM_H_
#include "iProduct.h"
#include "Status.h"
#include <iostream>

namespace sdds {
	class Item : public iProduct
	{
		/*a double for the price
		an integer for quantity on hand
		an integer for needed quantity.This integer is the target amount for the item to be acquired.
		a dynamic Cstring for (not a C++ string) for the description of the item.
		a boolean flag to dictate to the display function if the next output is going to be linear to descriptive.*/
		double price = 0;
		int hand_qua = 0;
		int need_qua = 0;
		char* desc{};
		bool flag = false;

	protected:
		//a Status object to hold the state of the Item object
		//an integer value to hold the Stock - Keeping Unit number.
		Status s;
		int sku = 0;
		bool linear() const;
	public:
		Item();
		Item(const Item& i);
		Item& operator=(const Item& i);
		~Item();
		int qtyNeeded()const;
		int qty()const;
		operator double()const;
		operator bool()const;
		int operator-=(int qty);
		int operator+=(int qty);
		void linear(bool isLinear);
		Item& clear();
		bool operator==(int sku)const;
		bool operator==(const char* description)const;
		std::ofstream& save(std::ofstream& ofstr)const;
		std::ifstream& load(std::ifstream& ifstr);
		std::ostream& display(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
		int readSku(std::istream& istr);

	};

}

#endif // !ITEM_H_
