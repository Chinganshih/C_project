/* Citation and Sources...
Final Project Milestone 2
Module: AidMan
Filename: AidMan.cpp
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

#ifndef AIDMAN_H_
#define AIDMAN_H_
#include "Menu.h"

namespace sdds {
	class AidMan : public Menu
	{
		//file name -> Dynamically holding the name of a data file holding the aidand product information.
		//main menu -> A Menu object.
		char* fileName{};
		Menu m;
		unsigned int menu();
	public:
		AidMan();
		AidMan(const AidMan& a);
		void set(const char* fileName);
		AidMan& operator=(const AidMan& a);
		~AidMan();
		void run();
	};

}
#endif // !AIDMAN_H_
