/* Citation and Sources...
Final Project Milestone 1
Module: Date
Filename: Utils.cpp
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


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstring>
#include "Utils.h"

using namespace std;
namespace sdds {
    Utils ut;
    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }

    void Utils::alocpy(char*& destination, const char* source) {
        /*Safely allocates memory in destinationand copies the source into it.
        deletes the destination dynamic arrayand sets it to null
        if the source is not null
        Allocates memory in the destination to the size of the sourceand copies the source into it.*/

        if (source != nullptr)
        {
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
        else {
            delete[] destination;
            destination = nullptr;
        }
    }

    /*If the prompt is not null, it will display it.Then it performs a foolproof entry of an integer.
    If the user enters an invalid integer it will display "Invalid Integer, retry: " and will not let the user leave the function until a valid integer is entered.*/
    int Utils::getint(const char* prompt) {
        int enter = -1;

        if (prompt != nullptr)
        {
            while (!(cin >> enter))
            {
                cin.clear();
                cin.ignore(1000, '\n'); 
                cout << "Invalid Integer, retry: ";
            }

        }
        return enter;
    }

    /*If the prompt is not null it will be displayed before getting a valid integer.(reuse the previous getint())
     If the entered integer is not within the acceptable range(minand max) then an error message is displayedand it will not let the user leave the function until an acceptable value is entered.
     When printing the error message,
     if the errMes argument is not null it will be displayed followed by ", retry: " otherwise the general error message "Value out of range [min<=val<=max]: " is displayed(replacing min and max with their values)*/
    int Utils::getint(int min, int max, const char* prompt, const char* errMes) {
        int enter = -1;
        bool flag = 0;

        if (prompt != nullptr)
        {
            do
            {
                flag = 0;
                enter = getint(prompt);
                if (enter < min || enter > max)
                {
                    if (errMes != nullptr && !enter)
                    {
                        cout << ", retry: ";
                    }
                    else cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
                    flag = 1;
                }
            } while (flag);
        }
        return enter;
    }

}