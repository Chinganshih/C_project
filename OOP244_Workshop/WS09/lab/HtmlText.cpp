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
#include "HtmlText.h"
using namespace std;

namespace sdds {

	HtmlText::HtmlText() : m_title(nullptr) {}

	HtmlText::HtmlText(const char* title) {
		if (title != nullptr)
		{
			delete[] m_title;
			alloCopy(m_title, title);
		}
		else m_title = nullptr;
	}

	HtmlText::HtmlText(const HtmlText& h) {
		if (h.m_title != nullptr)
		{
			Text::operator=(h);
			delete[] m_title;
			alloCopy(m_title, h.m_title);
		}
		else m_title = nullptr;
	}

	HtmlText& HtmlText::operator=(const HtmlText& h) {
		if (this != &h)
		{
			if (h.m_title != nullptr)
			{
				Text::operator=(h);
				delete[] m_title;
				alloCopy(m_title, h.m_title);
			}
			else m_title = nullptr;
		}
		return *this;
	}

	HtmlText::~HtmlText()
	{
		delete[] m_title;
		m_title = nullptr;
	}

	//This override will convert the text file to a simple HTML format when writing file as follows :
	ostream& HtmlText::write(ostream& ostr)const {
		//First the open tags for html page, headerand title are inserted into ostream proceeding with the open body tag.Then for all the content of the file when writing :
		//create a boolean variableand set it to false to keep track of the occurrence of multiple spaces(let's call it MS for Multiple Spaces)
		bool MS = false;
		int index = 0;
		char ch = Text::operator[](index);

		ostr << "<html><head><title>";
		//1. if m_title is not null, insert the title, otherwise insert "No Title"
		(m_title != nullptr) ? ostr << m_title : ostr << "No Title";
		//2. insert "</title></head>\n<body>\n"
		ostr << "</title></head>\n<body>\n";
		//3. if the m_title property is not null insert "<h1>" << m_title << "</h1>\n"
		if (m_title != nullptr) ostr << "<h1>" << m_title << "</h1>\n";
		//4. loop through all the elements of the m_content(using the protected index operator) and convert the characters as follows :
		do
		{
			ch = Text::operator[](index);
			index++;
			switch (ch)
			{
			case ' ':
				(MS) ? ostr << "&nbsp;" : (MS = 1, ostr << ' ');
				break;
			case '<':
				MS = 0;
				ostr << "&lt;";
				break;
			case '>':
				MS = 0;
				ostr << "&gt;";
				break;
			case '\n':
				MS = 0;
				ostr << "<br />\n";
				break;
			default:
				MS = 0;
				ostr << ch;
				break;
			}
		} while (ch != '\0');

		//5. at the end insert "</body>\n</html>" to end the html page.
		ostr << "</body>\n</html>";

		return ostr;
	}
}