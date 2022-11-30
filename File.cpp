#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    int n, roll_no[10];
    string name[50];
    cout << "Enter the number of students whose data is to be saved \n";
    cin >> n;
    cout << "  " << endl;

    ofstream outf;
    outf.open("stud_data.txt", ios::trunc);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter name : ";
        cin >> name[i];
        outf << name[i] << "\n";

        cout << "Enter Roll number : ";
        cin >> roll_no[i];
        outf << roll_no[i] << "\n";
        cout << "     " << endl;
    }

    outf.close();

    ifstream inf;
    inf.open("stud_data.txt");

    for (int i = 0; i < n; i++)
    {
        while (inf)
        {
            inf >> name[i];
            inf >> roll_no[i];
            if (inf.eof() != 0)
            {
                cout << "End of file\n";
                exit(1);
            }

            cout << "Name is        : " << name[i] << endl;
            cout << "roll number is : " << roll_no[i] << endl;
        }
    }

    inf.close();

    return 0;
}

