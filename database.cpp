#include<iostream>
#include<string>
using namespace std;

class Student
{

	private:
		string name;
		int rollno;
		char *div;
		string dob;
		char *blood;
		string address;
		

	public:
		Student()
		{
			name = "";
			rollno = 0;
			div = new char[4];
			dob = "dd/mm/yy";
			blood = new char[4];
			address = "";
			
		}

		~Student()
		{
			delete div;
			delete blood; 
		}

		void set_data(Personal* data)
		{
			cout<<"\nEnter name : ";
			getline(cin,name);
			cout<<"Enter Roll no : ";
			cin>>rollno;
			cout<<"Enter Division : ";
			cin>>div;
			cout<<"Enter Date of Birth : ";
			getline(cin,dob);
			cout<<"Enter Blood Group : ";
			cin>>blood;
			data->getPersonalData();
		}

		void display(Personal* data)
		{
			cout<<"\nName : "<<name;
			cout<<"\nRoll NO : "<<rollno;
			cout<<"\nDivion : "<<div;
			cout<<"\nDate of Birth "<<dob;
			cout<<"\nEnter BLood Group : "<<blood;
			cout<<"\nAddress : "<<address;
			cout<<"\nTelephone No : "<<tel_no;
			cout<<"\nDriving License No : "<<drive_no;
			data->displayPersonalData();
		}

};


class Personal
{
	private:
	string address;
	long tel_no;
	long license;
	friend class Student;
	
	public:
	Personal
	{
		address = " ";
		tel_no = 0;
		license = 0;
	}

	~Personal{
		
	}

	inline void getPersonalData()
	{
		cout<<"Enter address : ";
		getline(cin,address);
		cout<<"Enter telephone no : ";
		cin>>tel_no;
		cout<<"Enter license no : ";
		cin>>license;
	}

	inline void displayPersonalData()
	{
		cout<<"\nAddress : "<<address;
		cout<<"\nTelephone : "<<tel_no;
		cout<<"\nLicense : "<<license;
	}


};


int main()
{
	s = new Student;
	p = new Personal;
	s -> set_data(&p);
	s -> display(&p);

}
