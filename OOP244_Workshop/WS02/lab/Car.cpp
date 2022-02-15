///* ------------------------------------------------------
//Workshop 2 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC //to get more details
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "cStrTools.h"
#include "Car.h"

using namespace std;

namespace sdds {

	/*
	Car Pointer; A Car pointer to hold the dynamic array of cars(We call this "The Car Pointer" in this text)
	Allocation size; an integer to hold the memory allocationand expansion size when needed
	Number of Cars; an integer to hold the number of cars currently in the dynamic array of cars pointed by The Car Pointer
	Car Array Size; an integer to hold the current allocation size of the array.This value is the maximum size that the Number Of Cars can grow up to(before reallocation for expansion).
	*/
	int allocation;
	int numberOfCar;
	int carArrSize;
	Car* car;

	//Prints the following message:
	void VBPLE_Title() {
		cout << "Vehicle Border Passing Log Entry" << endl << "Enter the data in the following format:" << endl << "Make and model,LicensePlate,MilitaryTime<ENTER>" << endl << "Exit the program by entering the following:" << endl << "X,<ENTER>" << endl;
	}

	//sets the number of cars to zero
	//sets the Car Array Sizeand the Allocation Size to the argument allocSize
	//dynamically allocates an array of Cars to the size of Allocation Sizeand keeps the address in The Car Pointer
	void initialize(int allocSize) {
		numberOfCar = 0;
		allocation = allocSize;
		carArrSize = allocSize;
		car = new Car[allocation];
	}

	//Deletes the allocated memory pointed by the makeand model pointer in the Car structure, then set it to nullptr.
	void deallocate(Car& C) {
		
		delete[] C.makeModel;
		C.makeModel = nullptr;

	}

	bool read(Car& C) {
		bool flag = 1;
		int i = numberOfCar;
		char input[MAX_MAKEMODEL];

		
		read(input, MAX_MAKEMODEL, ',');

		if (strCmp(input, "X") && numberOfCar != carArrSize)
		{
			car[i].makeModel = new char[strLen(input) + 1];
			strCpy(car[i].makeModel, input);
			read(car[i].license, MAX_LICENSE - 1, ',');
			cin >> car[i].time;
			numberOfCar++;
		}
		else
		{
			flag = 0;
		}
		
		return flag;
	}

	void print(const Car& C) {
		
		cout << C.time << ": " << C.makeModel << ',' << C.license << endl;
		
	}

	void record(const Car& C) {

		Car* newC = nullptr;
		int i;

		if (numberOfCar == carArrSize) {
			carArrSize = numberOfCar + allocation;
			newC = new Car[carArrSize];
			for ( i = 0; i < numberOfCar; i++)
			{
				newC[i].makeModel = car[i].makeModel;
				strCpy(newC[i].license, car[i].license);
				newC[i].time = car[i].time;
			}

			delete[] car;
			car = newC;
		}
		
	}

	void endOfDay() {
		int i;
		for ( i = 0; i < numberOfCar; i++)
		{
			print(car[i]);
			deallocate(car[i]);
		}
		delete[] car;
		car = nullptr;
	}
}