///* ------------------------------------------------------
//Workshop 1 part 2
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
#include "Phone.h"
#include "cStrTools.h"
using namespace std;

namespace sdds {

	const int MAX_PHONE_INDEX = 50;

	void SearchTitle(const char* programTitle) {
		cout << programTitle << " phone direcotry search" << endl << "-------------------------------------------------------" << endl;
	}

	int readFile(FILE* fp, Phone* phone, int MAX_PHONE_INDEX) {
		int i=0;

		while (!feof(fp) && i < MAX_PHONE_INDEX)
		{
			fscanf(fp, "%[^\t]\t%s\t%s\t%s\n", phone[i].name, phone[i].areaCode, phone[i].prefix, phone[i].number);			
			i++;
		}
		return i;
	}

	void displayRecord(Phone phone) {
		cout << phone.name << ": (" << phone.areaCode << ") " << phone.prefix << "-" << phone.number << endl;
	}

	void searchDir(Phone phone[], int numberOfPhone, char* pname) {
		int i;
		char lowerName[MAX_NAME_LENGTH];

		for ( i = 0; i < numberOfPhone; i++)
		{
			toLowerCaseAndCopy(lowerName, phone[i].name);
			if (strStr(lowerName, pname)) {
				displayRecord(phone[i]);
			}
		}
	}

	void phoneDir(const char* programTitle, const char* fileName) {
		struct Phone phone[MAX_PHONE_INDEX] = { {0} };
		int numberOfPhone;
		char pname[MAX_NAME_LENGTH];

		SearchTitle(programTitle);

		FILE* fp = fopen(fileName, "r");

		if (fp)
		{
			numberOfPhone = readFile(fp, phone, MAX_PHONE_INDEX);
			do
			{
				cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl << "> ";
				cin >> pname;
				toLowerCaseAndCopy(pname, pname);
				searchDir(phone, numberOfPhone, pname);

			} while (strCmp(pname, "!"));

		}
		else {
			cout << fileName << " file not found!" << endl;
		}

		cout << "Thank you for using " << programTitle << " directory." << endl;
		fclose(fp);

	}
}