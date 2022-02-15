///* ------------------------------------------------------
//Workshop 5 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title , "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title,title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char *)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    //operator bool
    //Returns true if the Flight number of passengers is greater than 0, and the amount of fuel in the plane's tank is equal to or greater than the minimum required to carry the number of passengers currently on the plane. otherwise false. 
    //This operator can not modify the Flight object.
    Flight::operator bool() const {
        return (this->m_passengers > 0 && this->m_fuel >= 600*this->m_passengers);
    }

    //operator int
    //Returns the Flight number of passengers.This operator can not modify the Flight object.
    Flight::operator int() const {
        return this->m_passengers;
    }

    //operator double
    //Returns the Flight Fuel.This operator can not modify the Flight object.
    Flight::operator double() const {
        return this->m_fuel;
    }

    //operator string
    //Returns the Flight Title.This operator can not modify the Flight object.
    Flight::operator char*() const {
        return (char*)this->m_title;
    }

    //bool operator ~()
    //This operator returns true if the Flight number of passengers is equal to 0, otherwise, it will return false.
    //This operator can not modify the Flight object.
    bool Flight::operator ~() const {
        return (this->m_passengers == 0);
    }

    //overload the assignment operator so a Flight can be set to another Flight object.
    //This action should move the Flight passengersand the Flight fuel, Flight title from one Flight to another; 
    //therefore unlike the usual assignment operator that affects the left operand only, this operator will affect both operands; 
    //the details of the left Flight will be set to the details of the right Flightand the right Flight number of passengers will be set to 0, 
    //fuel to 0.00, and title to EmptyPlane.
    Flight& Flight::operator=(Flight& first) {
        this->m_passengers += first.m_passengers;
        this->m_fuel += first.m_fuel;
        strcpy(this->m_title, first.m_title);
        first.emptyPlane();

        return *this;
    }

    //Overload the assignment operator so a Flight can be set to an integer.Doing so should set the Flight number of passengers of the Flight to the integer value, 
    //only if the integer value is positiveand less than or equal to the Boeing 747 Passenger Max Capacity.
    Flight& Flight::operator=(int passenger) {
        if (passenger > 0 && passenger <= Boen747Capacity) this->m_passengers = passenger;
        return *this;
    }

    //Overload the assignment operator so a Flight can be set to a double.Doing so should set the Flight fuel of the Flight to the double value, 
    //only if the double value is positiveand less than the Boeng747 Fuel Tank Max Capacity.
    Flight& Flight::operator=(double fuel) {
        if (fuel > 0 && fuel <= FuelTankCapacity) this->m_fuel = fuel;
        return *this;
    }

    //Overload the += operator to add a double value to a Flight.
    //This should act like adding fuel into the Flight Tank. (i.e.the value of the double should be added to the m_fuel)
    Flight& Flight::operator+=(double fuel) {
        
        if(fuel > 0 && this->m_fuel < FuelTankCapacity) this->m_fuel += fuel;
        return *this;
    }

    //Overload the += operator to add an integer value to a Flight.
    //This should act like adding more passengers to the Flight. (i.e.the value of the integer should be added to the m_passengers)
    Flight& Flight::operator+=(int passenger) {
        if (passenger > 0 && this->m_passengers < Boen747Capacity) this->m_passengers += passenger;
        return *this;
    }

    //overload the -= operator to reduce a Flight fuel by a double value.
    //This should act like pumping out fuel from the Flight Fuel Tank. (i.e.the value of the Flight fuel should be reduced by the double value)
    Flight& Flight::operator-=(double fuel) {
        if (fuel > 0 && this->m_fuel > 0) this->m_fuel -= fuel;
        return *this;
    }

    //Overload the -= operator to reduce the number of passengers in a Flight fuel by an integer value.
    //This should act like disembarking a number of passengers from the Flight. (i.e.the value of the Flight m_passengers should be reduced by the integer value)
    Flight& Flight::operator-=(int passenger) {
        if (passenger > 0 && this->m_passengers > 0) this->m_passengers -= passenger;
        return *this;
    }

    //Overload the >> operator (right shift operator) to move passengers from the left Flight to the right.
    //After this operation, the total number of passengers in the right Flight will be the sum of both up to the Maximum Capacity of the Boeing 747, 
    //and the number of passengers in the left Flight will be zero or the remaining number of passengers after the right plane reached its maximum capacity.
    Flight& Flight::operator>>(Flight& right) {
        int movePassenger = this->m_passengers + right.m_passengers;
        int remianPassenger = 0;

        if (right.operator bool() && this->operator bool() )
        {
            if (movePassenger > Boen747Capacity)
            {
                remianPassenger = movePassenger - Boen747Capacity;
                right.m_passengers = Boen747Capacity;
                this->m_passengers = remianPassenger;
            }
            else
            {
                right.m_passengers = movePassenger;
                this->m_passengers = 0;
            }
            
        }

        return *this;
    }

    //Overload the << operator* (left shift operator) to move passengers from the right Flight to the left.
    //After this operation, the total number of passengers in the left Flight will be the sum of both up to the Maximum Capacity of the Boeing 747, 
    //and the number of passengers in the right Flight will be zero or the remaining number of passengers after the left plane reached its maximum capacity.
    Flight& Flight::operator<<(Flight& left) {
        int movePassenger = this->m_passengers + left.m_passengers;
        int remianPassenger = 0;

        if (left.operator bool() && this->operator bool())
        {
            if (movePassenger > Boen747Capacity)
            {
                remianPassenger = movePassenger - Boen747Capacity;
                left.m_passengers = Boen747Capacity;
                this->m_passengers = remianPassenger;
            }
            else
            {
                left.m_passengers = movePassenger;
                this->m_passengers = 0;
            }

        }

        return *this;
    }

    //--create a binary stand alone helper + operator that accepts a constant Flight reference at left and another constant Flight reference at right and returns a int value.
    //The int value should be the sum of the number of passengers of the two Flights.
    //If any of the two Flights don't evaluate to TRUE, then zero is returned.
    int operator+ (Flight& left, Flight& right) {
        int sum = 0;
        if (left.operator bool() && right.operator bool()) {
            sum = left.operator int() + right.operator int();
        }
        else
        {
            sum = 0;
        }

        return sum;
    }

    //--create a binary stand alone helper += operator that accepts an int reference at left and a constant Flight reference at right and returns an int value.
    //The number of the passengers of the right operand(Flight reference) should be added to the left operand(integer reference)
    //Then the value of the integer reference is returned.
    int operator+=(int& left , Flight& right) {
        left += right.operator int();

        return left;
    }

}