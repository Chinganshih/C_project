// ------------------------------------------------------
//Workshop 7 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------

#ifndef CONTAINER_H_
#define CONTAINER_H_

namespace sdds {
	class Container
	{
		char* content;
		int capacity;
		int volume;
		
	public:
		Container();
		Container(const char* content, int capcity, int volume = 0);
		void set(const char* content, int capcity, int volume = 0);
		void alloCopy(char*& destination, const char* source);
		int operator+=(int amount);
		int operator-=(int amount);
		operator bool();
		void clear(int capacity, const char* content);
		std::ostream& print(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
		int getint(int min, int max);
		~Container();
	protected:
		bool isValid(const char* content, int capacity, int volume) const;
		void setEmpty();
		int Capacity() const;
		int Volume() const;
	};

	std::ostream& operator<<(std::ostream& ostr, const Container& c);
	std::istream& operator>>(std::istream& istr, Container& c);
}

#endif // !CONTAINER_H_
