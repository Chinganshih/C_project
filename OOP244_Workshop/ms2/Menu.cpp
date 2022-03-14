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

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "Utils.h"
#include "Menu.h"

using namespace std;
namespace sdds {

	void Menu::setEmpty() {
		menuContent = nullptr;
		option = 0;
	}

	void Menu::dellocate() {
		delete[] this->menuContent;
		this->menuContent = nullptr;
	}

	Menu::Menu() {
		setEmpty();
	}

	//A Menu is created using an unsigned integerand a CString.The unsigned integer is used to initialize the number of optionsand a dynamic copy of the CString is held in the menu content.The maximum number of options is 15, if the number of options is more than 15 or if the CString is null, then the menu is rendered invalid.
	Menu::Menu(const char* menuContent, unsigned int option) {
		setEmpty();
		this->set(menuContent, option);
	}

	void Menu::set(const char* menuContent, unsigned int option) {
		dellocate();

		if (menuContent != nullptr || option > (unsigned)max_options)
		{
			Utils::alocpy(this->menuContent, menuContent);
			this->option = option;
		}
		else setEmpty();
	}

	//Rule of three
	//A Menu cannot be copied or assigned to another Menu.When going out of scope the menu content is deallocated to prevent a memory leak.
	Menu::Menu(const Menu& m) {
			this->set(m.menuContent, m.option);
	}

	Menu& Menu::operator=(const Menu& m) {
		if (this != &m)
		{
			this->set(m.menuContent, m.option);
		}
		return *this;
	}

	Menu::~Menu() {
		delete[] this->menuContent;
		this->menuContent = nullptr;
	}

	Menu& Menu::operator=(int option) {
		this->option = option;
		return *this;
	}

	Menu& Menu::operator=(const char* menuContent) {
		Utils::alocpy(this->menuContent, menuContent);
		return *this;
	}

	//This method receives nothingand returns an unsigned integerand will not change the state of the Menu object.
	//The run method will first display the menu contentand then prints "0- Exit" and goes to newline.Then it will display "> " as a prompt and waits for the user to enter an integer between 0 and the number of options.This integer entry is foolproof.The user can not exit this stage unless a valid integer number with a valid value is entered.
	//If the user enters a non - integer value the error message should be : "Invalid Integer, retry: ".
	//If the user enters an invalid integer then the error message should be : "Value out of range [0<=val<=X]: ".Where X is the number of options.
	unsigned int Menu::run() {
		int option;

		cout << this->menuContent;
		cout << "0- Exit" << endl;
		cout << "> ";

		option = Utils::getint(0, this->option, "menutest", NULL);
		return option;
	}
}