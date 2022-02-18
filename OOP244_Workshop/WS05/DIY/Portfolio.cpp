///* ------------------------------------------------------
//Workshop 5 part 2
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"
#include <cstring>
using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
       emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && ( type == 'V' || type == 'G' || type == 'I') ) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const{
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Value: ";
            cout.width(10);
            cout << double(*this);
            cout << " | ";
            cout << " Type: ";
            cout << char(*this);
    }

    bool Portfolio::isVaild() const {
        return (this->operator bool() && this->m_value > 0);
    }

    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    //Portfolio can be casted to a bool(boolean type).
    //This will return TRUE if the type of the investment m_type is Growth 'G' or Value 'V or Investment 'I'.
    //For any other types, it will return FALSE.
    Portfolio::operator bool() const {
        return (this->m_type == 'G' || this->m_type == 'V' || this->m_type == 'I');
    }

    //Portfolio can be casted to a double(double type).
    //The result would be the value of the Portfolio m_value.This operator can not modify the Portfolio object.
    Portfolio::operator double() const {
        return this->m_value;
    }

    //Portfolio can be casted to C - string(const char* type).
    //The result would be the name of the stock m_stock.This operator can not modify the Portfolio object.
    Portfolio::operator const char*() const {
        return this->m_stock;
    }

    //Portfolio can be casted to a char(char type).
    //The result would be the type of investment m_type.This operator can not modify the Portfolio object.
    Portfolio::operator char() const {
        return this->m_type;
    }

    //A double can be added to the value of the Portfolio m_value using += operator; 
    //if the Portfolio does not evaluate TRUE or the double value is negative, 
    //the action is omitted.Reference of the Portfolio is returned after the operation.
    Portfolio& Portfolio::operator+=(double value) {
        if (this->isVaild()) this->m_value += value;
        return *this;
    }

    //A double can be subtracted from the value of the Portfolio m_value using -= operator; 
    //if the Portfolio does not evaluate TRUE or the double value is negative, the action is omitted.
    //Reference of the Portfolio is returned after the operation.
    Portfolio& Portfolio::operator-=(double value) {
        if (this->isVaild()) this->m_value -= value;
        return *this;
    }
    
    //The bool operator ~() will return true if m_value is negative.This operator can not modify the Portfolio object.
    bool Portfolio::operator~() const {
        return (this->m_value < 0);
    }

    //overload the << operator* (left shift operator) to move $dollar investment value m_value from Portfolio in the right to the left.
    //After this operation, the total investment value of the Portfolio on the left will be the sum of both Portfolios.
    //The Portfolio on the right is set to empty.
    Portfolio& Portfolio::operator<<(Portfolio& right) {
        if (this->isVaild() && right.isVaild()) {
            this->m_value += right.m_value;
            right.emptyPortfolio();
        }
        return *this;
    }

    //overload the >> operator* (right shift operator) to move $dollar investment value m_value from Portfolio in the left to the right.
    //After this operation, the total investment value of the Portfolio on the right will be the sum of both Portfolios.
    //The Portfolio on the left is set to empty.
    Portfolio& Portfolio::operator>>(Portfolio& right) {
        if (this->isVaild() && right.isVaild()) {
            right.m_value += this->m_value;
            this->emptyPortfolio();
        }
        return *this;
    }

    //create a binary stand alone helper + operator that accepts a constant Portfolio reference at left and another constant Portfolio reference at right and returns a double value.
    //The double value should be the sum of the m_values of the two Flights.
    //If any of the two Portfolios don't evaluate to TRUE, then zero is returned.
    double operator+(Portfolio& left, Portfolio& right) {
        double sum = 0;
        if (left.isVaild() && right.isVaild()) {
            sum = left.operator double() + right.operator double();
        }
        return sum;
    }

    //create a binary stand alone helper += operator that accepts a double reference at left and a constant Portfolio reference at right and returns a double value.
    //The $dollar investment value of the right operand(Portfolio reference) should be added to the left operand(double reference)
    //Then the value of the double reference is returned.
    double operator+=(double& left, Portfolio& right) {

        left += right.operator double();
        
        return left;
    }
}