#include <iostream>
#include <string>
using namespace std;
class Data
{
    string name;
    int roll;
    int year;
    char *div = new char[1];
    char *clas = new char[3];
    string dob;
    long int phone;
    string college;
    char *bloodgrp = new char[3];
    string address;

public:
    static int count;
    Data()
    {
        name = "";
        roll = 0;
        year = 0;
        dob = "";
        phone = 0;
    }
    ~Data()
    {
        delete[] div;
        delete[] clas;
        delete[] bloodgrp;
    }
    Data(Data &obj)
    {
        this->college = obj.college;
    }
    inline static int getCount()
    {
        return count;
    }
    void inputData()
    {
        cout << "Enter Student Name : ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Roll No : ";
        cin >> roll;
        cout << "Enter Year : ";
        cin >> year;
        cout << "Enter Division : ";
        cin >> div;
        cout << "Enter Date of Birth (dd/mm/yy) : ";
        cin.ignore();
        getline(cin, dob);
        cout << "Enter Blood Group : ";
        cin >> bloodgrp;
        cout << "Enter Address : ";
        cin.ignore();
        getline(cin, address);
        cout << "Enter Phone No : ";
        cin >> phone;
        count++;
        cout << "\n\n";
    }
    void setCollege(string college)
    {
        this->college = college;
    }
    friend class Display;
};
int Data::count = 0;
class Display
{
public:
    void display(Data &obj)
    {
        cout << "\nCollege Name : " << obj.college;
        cout << "\nStudent Name : " << obj.name;
        cout << "\nRoll No : " << obj.roll;
        cout << "\nYear : " << obj.year;
        cout << "\nClass : " << obj.clas;
        cout << "\nDivision : " << obj.div;
        cout << "\nDate of Birth : " << obj.dob;
        cout << "\nBlood Group : " << obj.bloodgrp;
        cout << "\nAddress : " << obj.address;
        try
        {
            if (obj.phone >= 1000000000 && obj.phone <= 9999999999)
                cout << "Phone No : " << obj.phone;
            else
                throw obj.phone;
        }
        catch (long int phone)
        {
            cout << "Invald Phone Number";
        }
    }
};
int main()
{
    string college;
    cout << "Enter College Name : ";
    getline(cin, college);
    Data a;
    a.inputData();
    a.setCollege(college);
    Display ad;
    Data b(a);
    b.inputData();
    ad.display(a);
    ad.display(b);
    cout << "\nTotal Student Entries : " << a.getCount() << "\n";
}
