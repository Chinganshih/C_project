// ------------------------------------------------------
//Workshop 6 part 1
//Name   : chinganshih
//ID     : 148221195
//Email  : cshih9@myseneca.ca
//Section: OOP244 NMM
//-----------------------------------------------------------


#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "HealthCard.h"
using namespace std;
namespace sdds {

    //Full name is a Cstring that is not null and not empty.
    //The main health number consists of 10 digits(> 999999999 and < 9999999999)
    //The version number consists of two characters
    //The Stock control number consists of nine characters
    //Returns true is the four parts of the ID card are valid.
    bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const{
        return (name != nullptr && strlen(name) > 0 && strlen(name) < MaxNameLength && number > 999999999 && number < 9999999999 && strlen(vCode) == 2 && strlen(sNumber) == 9);
    }

    //Sets the HeathCard object to a recognizable empty(invalid) state by setting m_name to nullptr;
    void HealthCard::setEmpty() {
        m_name = nullptr;
        m_number = 0;
        m_vCode[0] = '\0';
        m_sNumber[0] = '\0';
    }

    //Free the memory pointed by m_name
    //Allocate enough memory to store name Cstring
    //Copy the Cstring pointed by name into the newly allocated memory pointed by m_name
    void HealthCard::allocateAndCopy(const char* name) {
        delete[] this->m_name;
        this->m_name = new char[strlen(name) + 1];
        strcpy(this->m_name, name);
    }

    /*"peek()" and see if the next character in the keyboard buffer is the same as the ch argument
    If it is the same, Remove it from the keyboard and throw it away!(i.e.istr.ignore())
    If not:
    Ignore all the remaining characters(up to 1000 characters) or the value of ch(use istr.ignore(int n, char c))
    Set the istream into a fail state(use istr.setstate(iso::failbit))*/
    void HealthCard::extractChar(istream& istr, char ch) const {

        if (istr.peek() == ch)
        {
            istr.ignore();
        }
        else {
            istr.ignore(1000, ch);
            istr.setstate(ios::failbit);
        }
    }

    //Inserts the three parts related to the main card number, version codeand stock number of the health card information into the istr object in the following format :
    //1234567890 - AB, XY7652341
    //and then returns the istr object reference
    ostream& HealthCard::printIDInfo(ostream& ostr) const {
        
        ostr << this->m_number << "-" << this->m_vCode << ", " << this->m_sNumber ;
        return ostr;
    }

    /*Validates the arguments, reallocates memory for the nameand sets the object attributes to their corresponding values.
    If the nameand the three parts are valid(see Validation) call the private function to validate
    Calls the reallocateAndCopy function to set the name
    Sets the three parts to their values(m_number, m_vCode, m_sNumber)
    If not, it deletes the memory pointed by m_nameand sets the object to a safe empty state(setEmpty())*/
    void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]) {

        if (this->validID(name, number, vCode, sNumber))
        {
            this->allocateAndCopy(name);
            this->m_number = number;
            strcpy(this->m_vCode, vCode);
            strcpy(this->m_sNumber, sNumber);
        }
        else
        {
            delete[] this->m_name;
            this->setEmpty();
        }
    }
    
    HealthCard::HealthCard() {

        this->setEmpty();
    }

    HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) {
        if (this->validID(name, number, vCode, sNumber)) {
            this->set(name, number, vCode, sNumber);
        }
        else
        {
            this->setEmpty();
        }
    }

    //if the hc object is valid it will set the values of the current object to those of the incoming argument(hc using assignment to* this).
    HealthCard::HealthCard(const HealthCard& hc) {

        if (this->validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber)) this->set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
    }

   /* First, it will make sure that this is not a "self-copy" by comparing the address of the current object and the address of the incoming argument.
    If it is not a self copy this function works exactly like the copy constructor
    If it is a self copy don't perform any action At the end return the reference of the current object.*/
    HealthCard& HealthCard::operator=(const HealthCard& hc) {

        if (&hc != this) this->set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
        return *this;
    }

    //deletes the memory pointed by m_name.
    HealthCard::~HealthCard() {
        delete[] this->m_name;
        this->m_name = nullptr;
    }

    //Returns true if m_name is not nullptr, else it will return false
    HealthCard::operator bool() const {
        return (this->validID(this->m_name, this->m_number, this->m_vCode, this->m_sNumber));
    }

    /*if toFile is true, prints the data in a comma - separated format :
    prints the name
    print comma
    print the health card ID information using the private function printIDInfo
    if toFile is false prints the data in the following format :
    In 50 characters, left - justified and padded with dots('.') : prints the name
    print the health card ID information using the private function printIDInfo
    At the end, it returns the ostr reference*/
    ostream& HealthCard::print(ostream& ostr, bool toFile) const {
        
        if (toFile && this->operator bool())
        {
            ostr << this->m_name << ',';
            this->printIDInfo(ostr) << endl;
        }
        else if (this->operator bool())
        {
            ostr << left << setw(50) << setfill('.') << this->m_name;
            this->printIDInfo(ostr);
        }
        
        return ostr;
    }

    /*define local variables for the four parts.
    using istream::get() read the name up to MaxNameLength or a comma(do not extract comma)
    extract a comma using extractChar private function
    extract the main health number into a local variable(istr >> m_number;)
    extract a dash '-' using extractChar private function
    extract the version number code into a vCode local variable using get for 3 char or up to ',' whichever comes first
    extract a comma ',' using extractChar private function
    extract the stock control number to the local variable(using get to read 10 char or up to '\n' whichever comes first)
    extract a new line character '\n' (using extractChar private function)
    if istr is not in a failure state
    all data were read successfully, use the set private function to set values of the object to read value
    before returning, clear the state using istr.clear() and ignore the remaining of the line until '\n'
    at the end return the istr reference*/
    istream& HealthCard::read(istream& istr) {
        char* name = new char[100];
        long long number;
        char vCode[3];
        char sNumber[10];
      
        istr.get(name, 100, ',');
        this->extractChar(istr, ',');
        istr >> number;
        this->extractChar(istr, '-');
        istr.get(vCode, 3, ',');
        this->extractChar(istr, ',');
        istr.get(sNumber, 10, '\n');
        this->extractChar(istr, '\n');

        if (!istr.fail()) {
            this->set(name, number, vCode, sNumber);
        }else istr.clear(), istr.ignore(1000,'\n');
        delete[] name;
       
        return istr;
    }
    
    /*if hc is valid it will print it using the print function on the screen and not on File, (i.e.onFile is false).Otherwise, it will print "Invalid Card Number".
    In the end, it will return the ostr reference.*/
    ostream& operator<<(ostream& ostr, const HealthCard& hc) {
        if (hc)
        {
            hc.print(ostr, false);
        }
        else {
            ostr << "Invalid Health Card Record";
        }
        return ostr;
    }

    //returns the read method of the hc argument.
    istream& operator>>(istream& istr, HealthCard& hc) {
        return hc.read(istr);
    }

    
}
