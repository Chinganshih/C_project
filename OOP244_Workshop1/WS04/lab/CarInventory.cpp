#define _CRT_SECURE_NO_WARNINGS
#include "CarInventory.h"
#include <cstring>
#include <iostream>
using namespace std;


namespace sdds {

	CarInventory::CarInventory() {
		this->resetInfo();
	}

	void CarInventory::resetInfo() {
		this->m_type = nullptr;
		this->m_brand = nullptr;
		this->m_model = nullptr;
		this->m_year = 0;
		this->m_code = 0;
		this->m_price = 0;
	}

	//The default constructor will initialize the member variables by calling the resetInfo() method(the details of this method will be provided in the Private Member section.
	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) {
		if (type != nullptr && brand != nullptr && model != nullptr && year >= 1990 && (code > 99 || code <1000) && price >0) {
			this->setInfo(type, brand, model, year, code, price);
		}
		else {
			this->resetInfo();
		}
		
	}

	//This destructor should deallocate the dynamically allocated memory in type, brand, and model.
	CarInventory:: ~CarInventory() {
		if (m_type != nullptr && m_brand != nullptr && m_model != nullptr) {
			delete[] this->m_type;
			delete[] this->m_brand;
			delete[] this->m_model;
		}
		
	}

	//This method will first deallocate all the allocated memoryand then sets the attributes to the corresponding arguments exactly like the 6 argument constructor.
	//Note: this function does not have any default values for its arguments.
	//In the end, it will return the reference of the current object.
	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
		this->resetInfo();
		delete[] this->m_type;
		delete[] this->m_brand;
		delete[] this->m_model;
		this->m_type = new char[strlen(type)+1];
		this->m_brand = new char[strlen(brand) + 1];
		this->m_model = new char[strlen(model) + 1];
		strcpy(this->m_type, type);
		strcpy(this->m_brand, brand);
		strcpy(this->m_model, model);
		this->m_year = year;
		this->m_code = code;
		this->m_price = price;

		return *this;
	}

	//This method prints the values of all the member variables on the screen in following format.
	//Order:TYPE, BRAND, MODEL, YEAR, CODE, PRICE
	//| 10  spaces | 16        spaces | 16        spaces | 9999 | 999 | 999999.99 |
	void CarInventory::printInfo() const {
		printf("| %-11s| %-17s| %-17s| %-5d|  %-4d|%10.2lf |\n", this->m_type, this->m_brand, this->m_model, this->m_year, this->m_code, this->m_price);
	}

	//This method returns whether all member variables have valid values or not based on the criteria stated at the Private Member Variables.
	bool CarInventory::isValid() const {
		bool isvalid = 0;
		
		if (this->m_type != nullptr && this->m_brand != nullptr && this->m_model != nullptr && this->m_year >= 1990 && (this->m_code > 99 || this->m_code < 1000) && this->m_price > 0){
			isvalid = 1;
		}
		return isvalid;
	}

	//This function is to check whether the type, make, brand and year of an object of CarInventory are equal to another object of this class.
	//The function will return true only if all those values match.
	bool CarInventory::isSimilarTo(const CarInventory& car) const {
		bool isSimilar = 0;
		if (this->isValid())
		{
			if (!strcmp(this->m_type, car.m_type) && !strcmp(this->m_model, car.m_model) && !strcmp(this->m_brand, car.m_brand) && this->m_year == car.m_year)
			{
				isSimilar = 1;
			}
		}
		
		return isSimilar;
	}

	//Also, implement a global function in the sdds namespace to check whether there are duplicate entries in the entire inventory.
	//It returns true if it finds two CarInventory objects that have similar information in the car array.See below for the function implementation logic :
	bool find_similar(CarInventory car[], const int num_cars) {
		bool isSimilar = 0;
		int i, j;

		for (i = 0; i < num_cars; i++) {
			for (j = i + 1; j < num_cars; j++) 
			{
				if (car[i].isSimilarTo(car[j]) )
				{
					isSimilar = 1;
				}
			}
		}
		return isSimilar;
	}

}