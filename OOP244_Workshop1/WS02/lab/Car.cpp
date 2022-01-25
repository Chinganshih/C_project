///* ------------------------------------------------------
//Workshop 2 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
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
		int i=0;
		char input[MAX_MAKEMODEL];
		
		for ( i = 0; i < carArrSize && flag; i++)
		{
			read(input, MAX_MAKEMODEL, ',');
			if (strCmp(input, "X"))
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
		}

		return flag;
	}

	void print(const Car& C) {
		int i;

		for ( i = 0; i < carArrSize-1; i++)
		{
			cout << (&C)[i].time << ": " << (&C)[i].makeModel << ',' << (&C)[i].license << endl;
		}
	}

	void record(const Car& C) {
<<<<<<< HEAD
		Car* newC = nullptr;
=======
		Car* newC;
>>>>>>> afaec8227bca6e9239b0fb39d04bbdfe9f4ecb1c
		
		if (numberOfCar == carArrSize) {

			newC = new Car[numberOfCar + allocation];
			memcpy(newC, &C, sizeof(C));
			delete[] C.makeModel;
		}
		numberOfCar++;
	}

	void endOfDay() {
		print(*car);
		deallocate(*car);
	}
}