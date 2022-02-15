#pragma once

#ifndef DNA_H // replace with relevant names
#define DNA_H
#include <vector>

namespace sdds {

	struct DNA {
		int id;
		char* DNAstrand;
	};

	void initialize(int allocSize);

	bool read(DNA& D, std::vector<std::vector<std::string>> &content);

	void record(const DNA& D);

	//It will try to open the fileand initialize any requirements needed for the application.Returns true 
	//if the file is opened successfullyand returns false it fails to open the file.
	bool beginSearch(const char* filename);

	/*Dynamically creates an array of DNA records to the number of matches found in the fileand stores the matches in them.Returns true 
	if at least one match is found and false if no match is found in the records.*/
	bool read(const char* subDNA);

	//Sorts the dynamic array of DNA matches found in the file based on the ids in ascending order.
	void sort();

	//Displays the dynamic DNA records in the following format.
	void displayMatches();

	//Deallocates all the dynamic memory within the DNA array elementsand the DNA array itself.
	void deallocate();

	//Finalizes the program by releasing the resources allocated by the program(like closing the data fileand etc...).
	//And then Prints : DNA Search Program Closed.
	void endSearch();
}

#endif