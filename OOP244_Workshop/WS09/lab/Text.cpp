// ------------------------------------------------------
//Workshop 9 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Text.h"
using namespace std;

namespace sdds {

	//This index operator provides read - only access to the content of the text for the derived classes of Text.
	//The behaviour of the operator is not defined if the index goes out of bounds or if the content is null.
	const char& Text::operator[](int index)const {
		return *m_content;
	}

	Text::Text() : m_content(nullptr) {}

	Text::Text(const Text& t) {
		//deep copy
		if (t.m_content != nullptr)
		{
			delete[] m_content;
			alloCopy(m_content, t.m_content);
		}
	}

	Text& Text::operator=(const Text& t) {
		if (this != &t)
		{
			//deep copy
			if (t.m_content != nullptr)
			{
				delete[] m_content;
				alloCopy(m_content, t.m_content);
			}
		}
		return *this;
	}

	Text::~Text()
	{
		delete[] m_content;
		m_content = nullptr;
	}

	void Text::alloCopy(char*& destination, const char* source) {
		if (source != nullptr)
		{
			destination = new char[strlen(source) + 1];
			strcpy(destination, source);
		}
		else
		{
			delete[] destination;
			destination = nullptr;
		}
	}

	istream& Text::read(istream& istr) {
		string content;
		int fileLen = getFileLength(istr);

		//deallocates the content
		delete[] m_content;
		m_content = nullptr;
		//allocates memory to the size of the file on the disk + 1 (for the null byte).
		m_content = new char[fileLen + 1];
		//reads the file into the allocated memory(character by character to the end)
		getline(istr, content, '\0');
		strcpy(m_content, content.c_str());
		extractChar(istr, '\n');
		//if any data is read, it will clear() the state of the istream object, otherwise, it will leave it as is.
		if (m_content != nullptr) istr.clear();

		return istr;
	}

	//This virtual function will insert the content of the Text class into the ostream if m_content is not null.
	//Also, this function does not change the content of a file.
	ostream& Text::write(ostream& ostr)const {
		if (m_content != nullptr) ostr << m_content;
		return ostr;
	}

	//To be able to allocate dynamic memoryand read the content of a file into the memory, you need to know the size of the text file in bytes.
	//The following function returns the number of bytes in an istream object or the value zero if the stream is in an invalid state.
	int Text::getFileLength(istream& is) {
		int len{};
		if (is) {
			// save the current read position
			streampos cur = is.tellg();
			// go to the end
			is.seekg(0, ios::end);
			// let what is the positions (end position = size)
			len = is.tellg();
			// now go back to where you were.
			is.seekg(cur);
		}
		return len;
	}

	void Text::extractChar(istream& istr, char ch) const {

		if (istr.peek() == ch)
		{
			istr.ignore();
		}
		else {
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}
	}

	istream& operator>>(istream& istr, Text& t) {
		return t.read(istr);
	}
	
	ostream& operator<<(ostream& ostr, const Text& t) {
		return t.write(ostr);
	}
}