// ------------------------------------------------------
//Workshop 6 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------


namespace sdds {
	class Name
	{
		char* firstName;
		char* middleName;
		char* lastName;
		void setEmpty();
		void extractChar(std::istream& istr, char ch) const;
		
	public:
		Name();
		Name(const char* firstName);
		Name(const char* firstName, const char* lastName);
		Name(const char* firstName, const char* middleName, const char* lastName);
		void set(const char* firstName, const char* middleName, const char* lastName);
		operator bool() const;
		void setShort(bool isAbbreviated);
		Name& operator +=(const char cstring[]);
		std::istream& read(std::istream& istr);
		std::ostream& print(std::ostream& ostr) const;
		~Name();
	};
	std::istream& operator>>(std::istream& istr, Name& n1);
	std::ostream& operator<<(std::ostream& ostr, const Name& n1);
}