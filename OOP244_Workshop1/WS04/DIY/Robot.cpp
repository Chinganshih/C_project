#include "Robot.h"

namespace sdds {

	//Default constructor for a robot with no information to set the robot into an empty state
	Robot::Robot()
	{
		this->name = nullptr;
		this->location = nullptr;
		this->weight = 0;
		this->width = 0;
		this->height = 0;
		this->Speed = 0;
		this->deployed = 0;
	}

	//The destructor must handle any potential memory leak.
	Robot::~Robot()
	{
		delete[] this->name;
		delete[] this->location;
		this->name = nullptr;
		this->location = nullptr;
	}

	//Constructor with 7 arguments to initialize the robot information in the following order :
	//name, location, weight, width, height, speed, deployment
	Robot::Robot(const char* name, const char* location, double weight, double width, double height, double Speed, bool deployed) {

	}

	//to set the robot information(same order as the constructor)
	void Robot::set(const char* name, const char* location, double weight, double width, double height, double Speed, bool deployed) {
		
	}

	//to set the robot location
	const char* Robot::setLocation() {
		return this->location;
	}

	//to set the robot deployment status(true or false)
	bool Robot::setDeployed() {
		return this->deployed;
	}

	const char* Robot::getName() const {
		return this->name;
	}

	const char* Robot::getLocation() const {
		return this->location;
	}

	bool Robot::isDeployed() const {
		return this->deployed;
	}

	bool Robot::isValid() const {
		return 0;
	}

	double Robot::speed() const {
		return this->Speed;
	}
}