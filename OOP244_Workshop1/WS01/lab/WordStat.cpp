/*
	==================================================
	Workshop 1 part 1:
	==================================================
	Name   : chinganshih
	ID     : 148221195
	Email  : cshih9@myseneca.ca
	Section: OOP244 NMM
*/

#include <iostream>
#include "Word.h"
#include "cStrTools.h"
using namespace sdds;
using namespace std;

int main() {
   char filename[256];
   cout << "Enter the following file name" << endl
      << "> FoxInSocks.txt" << endl << "---------------------" << endl;
   programTitle();
   cout << "Enter filename: ";
   cin >> filename;
   wordStats(filename);
   return 0;
}
