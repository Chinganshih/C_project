#pragma once
#ifndef TRAIN_H_
#define TRAIN_H_

namespace sdds {
	const int MAX_NAME_LEN = 21;
	const int MAX_PEOPLE = 1000;
	const int MAX_SPEED = 320;

	/*Declare three private data members.Declare an array to hold the name of a train, not exceeding MAX_NAME_LEN characters.
	Declare an integer variable for the number of people on a train.
	Declare a double variable for the speed of a train.*/
	class Train {
	private:
		char name[MAX_NAME_LEN];
		int people;
		double speed;

	/*The member function set() : void set(const char*, int, double); It uses three input parameters to initialize a Train object.
	It receives the name of the train, the number of people on the trainand the speed of the train.
	It validates the data values receivedand uses these data values to set the respective data members, only if all of them are valid.*/
	public:
		Train();
		~Train();
		void set(const char* n, int p, double s);
		int getNumberOfPeople() const;
		const char* getName() const;
		double getSpeed() const;
		bool isSafeEmpty() const;
		void display() const;
	};
}


#endif // TRAIN_H_
