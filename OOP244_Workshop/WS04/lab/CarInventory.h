#pragma once
#ifndef CARINVENTORY_H_
#define CARINVENTORY_H_

namespace sdds {

	
	class CarInventory {
	
	//Designand implement a class named CarInventory that stores the following information for a car entry :
	private:
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
		void resetInfo();
	public:
		
		CarInventory();
		~CarInventory();
		CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1);
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const CarInventory& car) const;
	};


	bool find_similar(CarInventory car[], const int num_cars);

}

#endif