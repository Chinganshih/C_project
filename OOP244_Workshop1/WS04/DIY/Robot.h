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
		void resetRobot();

	public:
		Robot();
		~Robot();
		Robot(const char* name, const char* location, double weight, double width, double height, double Speed, bool deployed);
		Robot& set(const char* name, const char* location, double weight, double width, double height, double Speed, bool deployed);
		const char* setLocation(const char* location);
		bool setDeployed(bool deployed);
		const char* getName() const;
		const char* getLocation() const;
		bool isDeployed() const;
		bool isValid() const;
		double speed() const;
		void title() const;
		void display() const;
		
	};

	int conrtolRooomReport(const Robot robot[], int num_robots);
	void fastest(const Robot robot[], int num_robots);
	void summary(const int inValid);
}
#endif // !_ROBOT_H_