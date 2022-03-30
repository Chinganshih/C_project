// ------------------------------------------------------
//Workshop 9 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------
#pragma once
#ifndef _TEXT_H_
#define _TEXT_H_

namespace sdds {
	class Text
	{
		//Text class has only one attribute(m_content) that holds the content of the text file dynamically.
		char* m_content{};
	protected:
		const char& operator[](int index)const;
	public:
		Text();
		Text(const Text& t);
		Text& operator=(const Text& t);
		~Text();
		void alloCopy(char*& destination, const char* source);
		std::istream& read(std::istream& istr);
		virtual std::ostream& write(std::ostream& ostr)const;
		int getFileLength(std::istream& is);
		void extractChar(std::istream& istr, char ch) const;
	};

	std::istream& operator>>(std::istream& istr, Text& t);
	std::ostream& operator<<(std::ostream& ostr, const Text& t);

}
#endif // _TEXT_H_
