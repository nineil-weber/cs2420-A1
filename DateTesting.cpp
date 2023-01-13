#include <iostream>
#include "Date.h"
using namespace std;

bool testConstructor();
bool testAddOperators();
bool testExtractionOperators();
bool checkCase(string name, bool condition);

int main()
{
    cout << "Date Class Testing!" << endl;
    bool c1,c2,c3;
    cout << "\n Criteria 01: Constructors in correct format:" << endl;
    c1=testConstructor();
    cout << "\n Criteria 02 y 03: toString() method is able to return correct format and operator+ correctly calculates the number of days:" << endl;
    c2=testAddOperators();
    cout << "\n Criteria 04: operator << displays the date in the correct format:" << endl;
    c3=testExtractionOperators();
    cout << "\n Criteria 05: Program is error-free and passes all test cases:" << endl;
    if(c1&c2&c3)
        cout << "Passed " << endl;
    else
        cout << "Failed" << endl;
    return 0;
}

bool testConstructor()
{
    bool flag = true;
    flag&=checkCase("\tOne Argument Constructor", Date(2018).toString() == "Jan 1, 2018");
    flag&=checkCase("\tTwo Argument Constructor", Date(2018, 7).toString() == "Jul 1, 2018");
    return flag;
}

bool testAddOperators()
{
    Date dd(2018, 9, 10);
    Date d = dd;
    bool flag = true;
    d = dd; flag&=checkCase("\tOperator+ test 1", (d + 23).toString() == "Oct 3, 2018");
    d = dd; flag&=checkCase("\tOperator+ test 2", (d + 38).toString() == "Oct 18, 2018");
    d = dd; flag&=checkCase("\tOperator+ test 3", (d + 56).toString() == "Nov 5, 2018");
    d = dd; flag&=checkCase("\tOperator+ test 4", (d + 91).toString() == "Dec 10, 2018");
    d = dd; flag&=checkCase("\tOperator+ test 5", (d + 134).toString() == "Jan 22, 2019");
    return flag;
}

bool testExtractionOperators()
{
    Date dd(2018, 9, 10);
    stringstream sout;
    sout << dd;

    return checkCase("\tText Extraction Operator", sout.str() == "Sep 10, 2018");
}

bool checkCase(string name, bool condition)
{
    if(!condition)
    {
        cout << "Failed: " << name << endl;
    }
    else
    {
        cout << name << ": passed" << endl;
    }

    return condition;
}
