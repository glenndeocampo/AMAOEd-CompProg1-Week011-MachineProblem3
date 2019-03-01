#include <string>
#include <cstdlib>
#include <iostream>
#include "Payslip.h"

using namespace std;

struct separated: numpunct<char>
{
    string do_grouping() const { return "\03"; }
};

int main () {
    locale our_local( cout.getloc(), new separated);
    cout.imbue (our_local);
    string name;
    double BasicSalary;
    int OTHours, OTPay;

    cout << "Enter Employee name                         : ";
    getline(cin, name);
    cout << "Enter Basic Salary (min. Php 10,000.00)     : ";
    cin >> BasicSalary;
    if (BasicSalary < 10000) {
        cout << "Invalid amount!" << endl;
        cout << "Enter Basic Salary (min. Php 10,000.00)     :";
        cin >> BasicSalary;
    }
    cout << "Enter OT Hours                              : ";
    cin >> OTHours;
    cout << endl;

    cout << "*************************************************************" << endl;
    Payslip emp(name, OTHours, BasicSalary);
    emp.PayGradeAndTaxRate();
    emp.OvertimePay();
    emp.ComputePay();





cout << endl;
system("pause");
return EXIT_SUCCESS;

}