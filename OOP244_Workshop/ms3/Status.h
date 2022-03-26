/* Citation and Sources...
Final Project Milestone 3
Module: Status
Filename: Status.h
Version 1.0
Author	Ching an shih
Revision History
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef STATUS_H_
#define STATUS_H_
#include "Utils.h"

namespace sdds {

	class Status : public Utils
	{
		char* desc{};
		int code;
		void setEmpty();

	public:
		Status();
		Status(const char* desc, int code = 0);
		void set(const char* desc, int code);
		Status(const Status& s);
		Status& operator=(const Status& s);
		Status& operator=(int code);
		Status& operator=(const char* desc);
		operator int() const;
		operator const char* () const;
		operator bool()const;
		Status& clear();
		~Status();
	};

	std::ostream& operator<<(std::ostream& ostr, const Status& s);


}

#endif // !STATUS_H_



