/* Citation and Sources...
Final Project Milestone 4
Module: Date
Filename: Perishable.h
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
#ifndef PERISHABLE_H_
#define PERISHABLE_H_
#include "Item.h"
#include "Date.h"
namespace sdds {

	class Perishable : public Item
	{
		Date expiryDate;
		char* instruction{};
	public:
		Perishable();
		~Perishable();
		Perishable(const Perishable& p);
		Perishable& operator=(const Perishable& p);
		const Date& expiry() const;
		int readSku(std::istream& istr);
		std::ofstream& save(std::ofstream& ofstr)const;
		std::ifstream& load(std::ifstream& ifstr);
		std::ostream& display(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
	};
	

}
#endif // !PERISHABLE_H_
