#define _CRT_SECURE_NO_WARNINGS
#include "Robot.h"
#include <iostream>
#include <iomanip>

using namespace std;
namespace sdds {

	int numberOfBroken = 0;

	//Default constructor for a robot with no information to set the robot into an empty state
	Robot::Robot()
	{
		this->resetRobot();
	}

	void Robot::resetRobot() {
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
		if (name != nullptr && location != nullptr) {
			this->resetRobot();
			this->set(name, location, weight, width, height, Speed, deployed);
		}
		else
		{
			this->resetRobot();
		}
	}

	//to set the robot information(same order as the constructor)
	Robot& Robot::set(const char* name, const char* location, double weight, double width, double height, double Speed, bool deployed) {
		delete[] this->name;
		delete[] this->location;

		this->name = new char[strlen(name) + 1];
		this->location = new char[strlen(location) + 1];
		strcpy(this->name, name);
		strcpy(this->location, location);
		this->weight = weight;
		this->width = width;
		this->height = height;
		this->Speed = Speed;
		this->deployed = deployed;

		this->setLocation(location);
		this->setDeployed(deployed);
		return *this;
	}

	//to set the robot location
	const char* Robot::setLocation(const char* location) {
		strcpy(this->location, location);
		return this->location;
	}

	//to set the robot deployment status(true or false)
	bool Robot::setDeployed(bool deployed) {
		this->deployed = deployed;
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
		bool isVaild = 0;

		if (this->name != nullptr && this->location != nullptr && this->height > 0 && this->Speed > 0 && this->weight > 0) {
			isVaild = 1;
		}

		return isVaild;
	}

	double Robot::speed() const {
		return this->Speed;
	}

	void Robot::title() const {
		cout << setw(55) << "------ Robot Control Room -----" << endl;
		cout << setw(60) << "---------------------------------------" << endl;
		cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
	}

	void Robot::display() const{
		char deployed[4] = "";

		(this->deployed) ? strcpy(deployed, "YES") : strcpy(deployed, "NO");
		printf("| %-11s| %-16s| %6.1lf | %6.1lf | %6.1lf | %6.1lf | %-9s|\n", this->name, this->location, this->weight, this->width, this->height, this->Speed, deployed);
		
	}

	int conrtolRooomReport(const Robot robot[], int num_robots) {
		int i, inValid =-1, deployed=0;
		robot[num_robots].title();

		for ( i = 0; i < num_robots; i++)
		{
			if (!robot[i].isValid()) {
				numberOfBroken++;
				inValid++;
				return i;
			}
			else
			{
				robot[i].display();
			}

			if (robot[i].isDeployed()) deployed++;
		}
		
		if (deployed) summary(deployed);

		fastest(robot, num_robots);
		return inValid;
	}

	void fastest(const Robot robot[], int num_robots) {
		int i, fastest=0;
		double temp=0;
		
		for  (i = 0; i < num_robots; i++)
		{
			if (robot[i].speed() > temp) {
				temp = robot[i].speed();
				fastest = i;
			}
		}

		cout << "| The fastest robot is:                                                       |" << endl;
		cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
		robot[fastest].display();
	}

	void summary(const int inValid) {
		cout << "|=============================================================================|" << endl;
		cout << "| SUMMARY:                                                                    |" << endl;
		cout << "| " << inValid << "  robots are deployed.                                                     |" << endl;
		cout << "|=============================================================================|" << endl;
	}
}