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
#include <string>
#include <fstream>
#include <sstream>
#include "cStrTools.h"
#include "DNA.h"


using namespace std;

namespace sdds {

	DNA* dna = nullptr;
	DNA* match = nullptr;
	const int MIN_DNA_STRAND = 100;
	const int MAX_DNA_STRAND = 1000;
	int dnaArrSize, matchArrSize;
	int allocation;
	int numberOfDNA, numberOfMatch;
	

	void initialize(int allocSize) {
		numberOfDNA = 0;
		numberOfMatch = 0;
		allocation = allocSize;
		dnaArrSize = allocSize;
		matchArrSize = allocSize;
		dna = new DNA[allocation];
		match = new DNA[allocation];
	}

	bool read(DNA& D, std::vector<std::vector<string>>& content) {
		int i= numberOfDNA, intid;
		bool temp = false;

		if (numberOfDNA != dnaArrSize && i < content.size())
		{
			intid = stoi(content[i][0]);
			dna[i].id = intid;
			dna[i].DNAstrand = new char[strLen(content[i][1].c_str()) + 1];
			strCpy(dna[i].DNAstrand, content[i][1].c_str());
			numberOfDNA++;
			
			temp = true;
		}
		return temp;
	}

	void record(const DNA& D) {
		DNA* newD = nullptr;
		char* dnastrand;
		int i;

		if (numberOfDNA == dnaArrSize) {
			dnaArrSize = allocation + numberOfDNA;
			newD = new DNA[dnaArrSize];

			for (i = 0; i < numberOfDNA; i++)
			{
				newD[i].id = dna[i].id;
				dnastrand = dna[i].DNAstrand;
				newD[i].DNAstrand = new char[strLen(dnastrand) + 1];
				strCpy(newD[i].DNAstrand, dna[i].DNAstrand);
			}
			
			delete[] dna;
			dna = newD;
		}

	}

	//It will try to open the file and initialize any requirements needed for the application.Returns true 
	//if the file is opened successfullyand returns false it fails to open the file.
	bool beginSearch(const char* filename) {
		int i,j, intid;
		bool isopen;
		string line, word;
		vector<string> row;
		vector<vector<string>> content;
		fstream fp;
		fp.open(filename, ios::in);

		if (fp.is_open()) {
			
			initialize(150);
			while (!fp.eof()) {
				while (getline(fp, line))
				{
					row.clear();

					stringstream str(line);

					while (getline(str, word, ','))
						row.push_back(word);
					content.push_back(row);
				}
			}
			
			while (read(*dna, content)) {
				record(*dna);
			}	
			isopen = true;
			cout << "DNA search program" << endl;
			fp.close();
		}
		else isopen = false;
		
		return isopen;
	}

	/*Dynamically creates an array of DNA records to the number of matches found in the file and stores the matches in them.Returns true
	if at least one match is found and false if no match is found in the records.*/
	bool read(const char* subDNA) {
		DNA* reNew = nullptr;
		char* dnastrand;
		bool isMatch = false;
		int i, j;

		for ( i = 0; i < numberOfDNA ; i++)
		{
			if (strStr(dna[i].DNAstrand, subDNA))
			{
				numberOfMatch++;
				if (matchArrSize != numberOfMatch)
				{
					match[numberOfMatch -1].id = dna[i].id;
					dnastrand = dna[i].DNAstrand;
					match[numberOfMatch - 1].DNAstrand = new char[strLen(dnastrand) + 1];
					strCpy(match[numberOfMatch - 1].DNAstrand, dna[i].DNAstrand);

				}
				else
				{
					matchArrSize = numberOfDNA + allocation;
					reNew = new DNA[matchArrSize];
					for (j = 0; j < numberOfDNA; j++)
					{
						reNew[j].id = match[i].id;
						dnastrand = match[i].DNAstrand;
						reNew[j].DNAstrand = new char[strLen(dnastrand) + 1];
						strCpy(reNew[j].DNAstrand, match[j].DNAstrand);
					}

					delete[] match;
					match = reNew;
				}

				isMatch = true;
			}
		}

		return isMatch;
	}

	//Sorts the dynamic array of DNA matches found in the file based on the ids in ascending order.
	void sort() {
		int i, j, tempid=0;
		char* tempdna;

		for (i = 0; i < numberOfMatch-1; i++)
		{
			for ( j = 0; j < numberOfMatch-i-1; j++)
			{
				if (match[j].id > match[j+1].id) {
					tempid = match[j].id;
					match[j].id = match[j + 1].id;
					match[j + 1].id = tempid;

					tempdna = match[j].DNAstrand;
					match[j].DNAstrand = match[j + 1].DNAstrand;
					match[j + 1].DNAstrand = tempdna;
				}
			}
		}
		
	}

	//Displays the dynamic DNA records in the following format.
	void displayMatches() {
		int i;

		for (i = 0; i < numberOfMatch; i++)
		{
			cout << i + 1 << ") " << match[i].id << ":" << endl;
			cout << match[i].DNAstrand << endl;
			cout << "======================================================================" << endl;
		}
		
	}

	//Deallocates all the dynamic memory within the DNA array elementsand the DNA array itself.
	void deallocate() {
		int i;

		//deallocte match[]
		for (i = 0; i < numberOfMatch; i++)
		{
			delete[] match[i].DNAstrand;
			match[i].DNAstrand = nullptr;
		}
		delete[] match;
		match = nullptr;
	}

	//Finalizes the program by releasing the resources allocated by the program(like closing the data fileand etc...).
	//And then Prints : DNA Search Program Closed.
	void endSearch() {
		int i;
		cout << "DNA Search Program Closed." << endl;

		//deallocte dna[]
		for (i = 0; i < numberOfDNA; i++)
		{
			delete[] dna[i].DNAstrand;
			dna[i].DNAstrand = nullptr;
		}
		delete[] dna;
		dna = nullptr;
	}
}