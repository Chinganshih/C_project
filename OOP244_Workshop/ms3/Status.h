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



