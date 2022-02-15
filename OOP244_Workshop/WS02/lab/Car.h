#pragma once

#ifndef CAR_H // replace with relevant names
#define CAR_H


namespace sdds {

	const int  MAX_LICENSE = 9;
	const int MAX_MAKEMODEL = 60;

	struct Car
	{
		char license[MAX_LICENSE];
		char* makeModel;
		int time;
	};

	void VBPLE_Title();

	void initialize(int allocSize);

	void deallocate(Car& C);

	bool read(Car& C);

	void print(const Car& C);

	void record(const Car& C);

	void endOfDay();

}

#endif