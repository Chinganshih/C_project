// ------------------------------------------------------
//Workshop 9 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------

#pragma once
#ifndef _HTMLTEXT_H_
#define _HTMLTEXT_H_
#include "Text.h"

namespace sdds {
	class HtmlText : public Text
	{
		char* m_title{};
	
	public:
		HtmlText();
		HtmlText(const char* title);
		HtmlText(const HtmlText& h);
		HtmlText& operator=(const HtmlText& h);
		~HtmlText();
		std::ostream& write(std::ostream& ostr)const;
	};

	
}

#endif // _HTMLTEXT_H_