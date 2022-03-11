#ifndef DATE_H_
#define DATE_H_
#include "Status.h"

namespace sdds {
	class Date : public Status
	{
		const int max_year = 2030;
		int year;
		int month;
		int day;
		bool isFormat;
		Status s;
		bool validate();
		int uniqueDate();

	public:
		Date();
		Date(int year, int month, int day);
		void set(int year, int month, int day);
		Date(const Date& date);
		Date& operator=(const Date& date);
		~Date();
		bool operator==(Date& date);
		bool operator!=(Date& date);
		bool operator<(Date& date);
		bool operator>(Date& date);
		bool operator<=(Date& date);
		bool operator>=(Date& date);
		const Date::Status& state();
		Date& formatted(bool flag);
		operator bool()const;
		std::ostream& write(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	};

	std::istream& operator>>(std::istream& istr, Date& date);
	std::ostream& operator<<(std::ostream& ostr, const Date& date);


}

#endif // !DATE_H_


