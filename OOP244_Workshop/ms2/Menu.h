/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
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

#ifndef MENU_H_
#define MENU_H_
#include "Utils.h"

namespace sdds {

	class Menu : public Utils
	{
		const int max_options = 15;

		//A dynamically allocated text that contains the list of options the user can select from.
		//An unsigned integer that holds the number of available options.
		char* menuContent;
		unsigned int option;

		void setEmpty();
		void dellocate();

	public:
		Menu();
		Menu(const char* menuContent, unsigned int option);
		Menu(const Menu& m);
		void set(const char* menuContent, unsigned int option);
		Menu& operator=(const Menu& m);
		Menu& operator=(int option);
		Menu& operator=(const char* menuContent);
		~Menu();
		unsigned int run();
			
	};

}
#endif // !MENU_H_
