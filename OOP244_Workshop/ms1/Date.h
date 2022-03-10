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
		Status s;
		bool formatted;
		bool validate();
		int uniqueDate();

	public:
		Date();
		Date(int year, int month, int day);
		~Date();



	};
}

#endif // !DATE_H_


