#ifndef _ROBOT_H_
#define _ROBOT_H_

namespace sdds {
	class Robot
	{
	private:

		char* name;
		char* location;
		double weight;
		double width;
		double height;
		double Speed;
		bool deployed;


	public:
		Robot();
		~Robot();
		Robot(const char* name, const char* location, double weight, double width, double height, double Speed, bool deployed);
		void set(const char* name, const char* location, double weight, double width, double height, double Speed, bool deployed);
		const char* setLocation();
		bool setDeployed();
		const char* getName() const;
		const char* getLocation() const;
		bool isDeployed() const;
		bool isValid() const;
		double speed() const;
	};
}
#endif // !_ROBOT_H_