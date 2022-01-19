#pragma once
#ifndef PHONE_H // replace with relevant names
#define PHONE_H
#include <cstdio>

namespace sdds {

	const int MAX_NAME_LENGTH = 51;
	const int MAX_PHONE_LENGTH = 5;

	struct Phone
	{
		char name[MAX_NAME_LENGTH];
		char areaCode[MAX_NAME_LENGTH];
		char prefix[MAX_NAME_LENGTH];
		char number[MAX_PHONE_LENGTH];
	};

	//display title of program
	void SearchTitle(const char* programTitle);

	//read file from Phones.txt
	int readFile(FILE* fp, struct Phone* phone, int MAX_PHONE_INDEX);

	//display record when it matches partial name
	void displayRecord(struct Phone phone);

	//Search partial name input by user and phone directory
	void searchDir(struct Phone phone[], int numberOfPhone, char* pname);

	// runs the phone directory appication
	void phoneDir(const char* programTitle, const char* fileName);

}

#endif