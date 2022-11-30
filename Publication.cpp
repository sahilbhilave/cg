#include<iostream>
#include<string>

using namespace std;

class Publication
{
	string title;
	float price;

	public:
	Publication()
	{
		title = "";
		price = 0.0;
	}

	void get_data()
	{

		cout<<"Enter title : ";
		cin.ignore();
		getline(cin,title);
		cout<<"Enter Price : ";
		cin>>price;
	}

	void display_data()
	{
		cout<<"-------------------------------------------------------------------------";
		cout<<"\nTitle : "<<title<<"\n";

		try{
			if(price<=0)
			{
				throw price;
			}
			else
			{
				cout<<"Price : "<<price<<"\n";
			}
		}catch(float f)
		{
			cout<<"Invalid Price : "<<f<<"\n";
			price = 0;
			title = "";
		}
	}	
};

class Book : public Publication
{
	int pc;
	public:
	Book()
	{
		pc=0;
	}
	void get_data()
	{
		Publication::get_data();
		cout<<"Enter pages : ";
		cin>>pc;
	}

	void display_data()
	{
		Publication::display_data();
	try{
		if(pc<=0)
		{
			throw pc;
		}
		else
		{
			cout<<"Pages : "<<pc<<"\n";
		}
	}
	catch(int f)
	{
		cout<<"Pages are invalid : "<<f<<"\n";
		pc = 0;
		title = "";
		price = 0.0;
	}

	cout<<"---------------------------------------------------------------------\n";
	}

	
};

class Tapes : public Publication
{
	int tapes;
	public:
	Tapes()
	{
		tapes = 0;
	}

	void get_data()
	{
		Publication::get_data();
		cout<<"Enter Tapes Size : ";
		cin>>tapes;
	}

	void display_data()
	{
		Publication::display_data();
		try{
			if(tapes<=0){
				throw tapes;
			}
			else
			{
				cout<<"Tapes Size : "<<tapes<<"\n";
			}
		}catch(int f)
		{
			cout<<"Invalid Tape Size : "<<f<<"\n";
			tapes = 0;
			title = "";
			price = 0.0;
		}
		cout<<"-----------------------------------------------------------------------------\n";
	}
};

int main()
{
	Book b[100];
	Tapes t[100];

	int n=-1,ib=0,it=0,c=0;
	while(n!=0)
	{
		cout<<"\n1.Enter Pages";
		cout<<"\n2.Enter Tapes";
		cout<<"\n3.Display Pages Data";
		cout<<"\n4.Display Tapes Data";
		cout<<"\n0.Exit";
		cout<<"\n\nEnter your choice : ";
		cin>>n;
		
		switch(n)
		{
			case 1:
				b[ib].get_data();
				ib++;
				break;
			case 3:
				if(ib==0)
				{
					cout<<"\nNo Data to Display\n";
				}
				else
				{
					for(int j=0;j<ib;j++)
						b[j].display_data();
				}
				break;
			case 2:
				t[it].get_data();
				it++;
				break;
			case 4:
				if(it==0)
				{
					cout<<"\nNo Data to Display\n";
				}
				else
				{
					for(int j=0;j<it;j++)
						t[j].display_data();
				}
				break;
			case 0:
				cout<<"\nThank You!!";
				break;
		}
	}

}
