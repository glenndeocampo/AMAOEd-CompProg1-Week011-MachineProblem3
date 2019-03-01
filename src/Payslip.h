#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

class Payslip{
    private:
        string Name;
        char PayGrade;
        double BasicSalary, SSS = 500, PagIbig = 200, PhilHealth = 100, FixedValues = SSS + PagIbig + PhilHealth;
        int OTHours, OT;
        float OTPay, TaxRate, GrossPay, NetPay;

public:
    Payslip(string name, int OT_hours, double basic_salary) {
        Name = name;
        BasicSalary = basic_salary;
        OTHours = OT_hours;

        cout << " Employee Name             : " << Name << endl;
        cout << " Basic Salary              : Php " << fixed << setprecision(2) << BasicSalary << endl;
    }
        int PayGradeAndTaxRate();
        int OvertimePay();
        void ComputePay();
};

int Payslip::OvertimePay() {
    OT = BasicSalary * .01;
    OTPay = OTHours * OT;
        cout << " No. of OT Hours           : " << OTHours << endl;
        cout << " OT Pay                    : Php " << fixed << setprecision(2) << OTPay << endl;
}

int Payslip::PayGradeAndTaxRate() {
    if ((BasicSalary >=10000 && BasicSalary <=14999) || (BasicSalary >=20000 && BasicSalary <=24999)) {
        PayGrade = 'A';
        cout << " Pay Grade                 : " << PayGrade << endl;
    }
    else if ((BasicSalary >=15000 && BasicSalary <=19999) || (BasicSalary >=25000 && BasicSalary <=29999)) {
        PayGrade = 'B';
        cout << " Pay Grade                 : " << PayGrade << endl;
    }
    else if ((BasicSalary >=30000 && BasicSalary <=34999) || (BasicSalary >=40000 && BasicSalary <=44999)) {
        PayGrade = 'A';
        cout << " Pay Grade                 : " << PayGrade << endl;
    }
    else if ((BasicSalary >=35000 && BasicSalary <=39999) || (BasicSalary >=45000 && BasicSalary <=49999)) {
        PayGrade = 'B';
        cout << " Pay Grade                 : " << PayGrade << endl;
    }
    else if ((BasicSalary >=50000 && BasicSalary <=54999) || (BasicSalary >=50000)) {
        PayGrade = 'B';
        cout << " Pay Grade                 : " << PayGrade << endl;
    }

    if (BasicSalary >= 10000 && BasicSalary <= 15000) {
        TaxRate = BasicSalary * .10;
        cout << " Witholding Tax            : Php " << fixed << setprecision(2) << TaxRate << endl;
    }
    else if (BasicSalary >= 20000 && BasicSalary <= 25000) {
        TaxRate = BasicSalary * .15;
        cout << " Witholding Tax            : Php " << fixed << setprecision(2) << TaxRate << endl;
    }
    else if (BasicSalary >= 30000 && BasicSalary <= 35000) {
        TaxRate = BasicSalary * .20;
        cout << " Witholding Tax            : Php " << fixed << setprecision(2) << TaxRate << endl;
    }
    else if (BasicSalary >= 40000 && BasicSalary <= 45000) {
        TaxRate = BasicSalary * .25;
        cout << " Witholding Tax            : Php " << fixed << setprecision(2) << TaxRate << endl;
    }
    else if (BasicSalary >= 50000) {
        TaxRate = BasicSalary * .30;
        cout << " Witholding Tax            : Php " << fixed << setprecision(2) << TaxRate << endl;
    }
}

void Payslip::ComputePay() {
    GrossPay = BasicSalary + OTPay;
    NetPay = GrossPay - TaxRate - FixedValues;
        cout << " Gross Pay                 : Php " << fixed << setprecision(2) << GrossPay << endl;
        cout << " Net Pay                   : Php " << fixed << setprecision(2) << NetPay << endl;
}