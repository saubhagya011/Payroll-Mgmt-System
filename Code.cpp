#include <bits/stdc++.h>
using namespace std;
typedef class payroll
{
    int yoj, eid;
    float sal, pf, hra, basic, ta, da;
    string fname, lname, subject;
    float gratuity, med_rei, bonus;
    char grade;
    float fir_no;
    char bail;
    string password, ps;
    int leaves;

protected:
    float funds;
    float expenditure, bal;

public:
    char cri;
    void house();
    void travel();
    void dear();
    int year();
    void sal_slip();
    float sal();
    float balance();
    void grat();
    void crime();
    void employer();
    void input();
    void benefits();
    void display();
} pay;
float payroll::balance()
{
    bal = funds - expenditure;
    return bal;
}
void payroll::sal_slip()
{
    cout << "First name of the employee-->" << fname << endl;
    cout << "Last name of the employee-->" << lname << endl;
    cout << "Subject taught-->" << subject << endl;
    cout << "Employee id-->" << eid << endl;
    cout << "Travelling Allowance=" << ta << endl;
    cout << "Dearness Allowance=" << da << endl;
    cout << "Provident Fund=" << pf << endl;
    cout << "Basic Pay=" << basic << endl;
    cout << "House Rent Allowance=" << hra << endl;
    // cout<<
}
void pay::display()
{
    cout << "Eligibility for receiving the gratuity" << endl;
    grat();
}
int payroll::year()
{
    return yoj;
}
void payroll::employer()
{
    cout << "Enter the password" << endl;
    cin >> password;
    string s1 = "Strong";
    if (password == s1)
    {
        cout << "Correct password entered\nAuthenticity established" << endl;
        cout << "Enter the Expenditure of the organization for the current Financial Year" << endl;
        cin >> expenditure;
        cout << "Enter the Funds of the organization for the current Financial Year" << endl;
        cin >> funds;
        cout << "After modification\nExpenditure=" << expenditure << "\nFunds=" << funds << endl;
    }
    else if (password != s1)
    {
        cout << "password is incorrect and due to security reasons you cannot edit the contents of this function" << endl;
    }
}

void payroll::house()
{
    int ch;
    cout << "Enter 1 if you're availing the Residential Accomodation provided by the organization\nEnter 2 if you're not availing the Residential Accomodation provided by the organization" << endl;
    cin >> ch;
    if (ch == 1)
    {
        hra = 0;
        cout << "HRA=" << hra << endl;
    }
    else if (ch == 2)
    {
        hra = 5000;
        //Calculated as per the latest guidelines by the Ministry of Urban & Rural Dev,Govt of India
        cout << "HRA=" << hra << endl;
    }
}
void payroll::input()
{
    cout << "Enter the First Name of the Employee" << endl;
    cin >> fname;
    cout << "Enter the First Name of the Employee" << endl;
    cin >> lname;
    cout << "Enter the employee id" << endl;
    cin >> eid;
    cout << "Enter the subject taught by the teacher" << endl;
    cin >> subject;
    cout << "Enter the grade allocated by the authorities as A/B/C/D" << endl;
    cin >> grade;
    cout << "Is the staff member facing trial for any pending cases in any of the courts within Indian Territoy\n Press Y if the above statement is true \nElse press N " << endl;
    cin >> cri;
    if (cri == 'Y')
    {
        crime();
    }
    else if (cri == 'N')
    {
        cout << "No criminal records found" << endl;
    }
    cout << "Enter the year of joining" << endl;
    cin >> yoj;
    cout << "Enter the number of leaves taken during the previous year" << endl;
    cin >> leaves;
}
void pay::grat()
{
    if (yoj - 2021 >= 5)
    {
        cout << "Congratulations you're eligible for receiving the gratuity" << endl;
    }
    else
    {
        cout << "Please bear with us you cannot receive the gratuity " << endl;
    }
}
void pay::crime()
{
    if (cri == 'Y')
    {
        cout << "Enter the FIR number" << endl;
        cin >> fir_no;
        cout << "Enter the name of Police Station" << endl;
        cin >> ps;
        cout << "Wheather on bail or not enter 1 if on bail else press 0?" << endl;
        cin >> bail;
    }
    else
    {
        cout << "No criminal records found" << endl;
    }
}
int main()
{

    return 0;
}
