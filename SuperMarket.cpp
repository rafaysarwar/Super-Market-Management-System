#include<iostream>
#include<windows.h>
#include<string.h>
using namespace std;
class Stock_M
{
	private:  
		int item_no;
		string item; 
		double price; 
		
	public:		
		Stock_M(int in=0, string i="", double p=0)
		{
			item_no=in;
			item=i;
			price=p;
		}
		
		int getin()
		{
			return item_no;
		}
		
		string getname()
		{
			return item;
		}
		
		double getprice()
		{
			return price;
		}
		
		void add()
		{
			cout<<"Enter Item Number: ";
			cin>>item_no; 
			cout<<"Enter Item Name: ";
			cin>>item;
			cout<<"Enter Price: ";
			cin>>price;
			cout<<endl;	
		}
		
		void update()
		{
			cout<<"Enter Item's New Number: ";
			cin>>item_no;
			cout<<"Enter Item's New Name: ";
			cin>>item;
			cout<<"Enter Item's New Price: ";
			cin>>price;	
		}
		
		void del()
		{
			item_no=0;
			item="";
			price=0;
		}
		
		void show()
		{
			cout<<"Item Number: "<<item_no<<endl;
			cout<<"Item Name: "<<item<<endl;
			cout<<"Item Price: "<<price<<endl<<endl;
		}
};
 
class User_M
{
	private:
		string name;
		string pass1, pass2;
	
	public:
		
		User_M(string n="")
		{
			name=n;
		}
		
		void setn(string s)
		{
			name=s;
		}
		
		string getn()
		{
			return name;
		}
		
		void add()
		{
			cout<<"Enter Username: ";
			cin>>name;
			do
			{	
				cout<<"Enter Password: ";
				cin>>pass1;
				cout<<"Re-enter Password: ";
				cin>>pass2;	
				if(pass1!=pass2)
				cout<<"Password Not Match\nEnter Again"<<endl<<endl;
			}	while(pass1!=pass2);
			
			cout<<"User Added"<<endl<<endl;
		}
	
		void del()
		{
			name="";
			pass1="";
			pass2="";
		}
	
		void show()
		{
			cout<<name<<endl;
		}
	
};

class Billing
{
	private:
		int number;
		string name; 
		double cost;
		
	public:
		Billing(int no=0, string n="", double c=0)
		{
			number=no;
			name=n;
			cost=c;
		}
				
		int getin()
		{
			return number;
		}
				
		string getname()
		{
			return name;
		}
		
		double getprice()
		{
			return cost;
		}
		
		void user()
		{
			string input, pass="hi";
			do
			{
				system("CLS");
				cout << "To access the system, please login" << endl;
				cout << "Password: ";
				cin >> input; 
				if (input == pass)
				{
					cout << "\nAccess Granted\n" << endl; 
					Sleep(1000);
					system("CLS");
								
				}
				else
				{
					cout << "Wrong Password" <<endl<<endl;
				}
		
			} while(input!=pass);
		}
				
		void checkout()
		{
			cout<<"Total Bill: "<<cost;
		}
};

int main()
{
	int cond, cond2, n, s;
	char ch;
	string pass, input;
	string ss;
	Stock_M i[50], ii[50];
	User_M u[50];
	Billing b;
	pass="hello";

	cout<<"\n\n\n\n\n\t\t\t\t\tWELCOME TO SUPER MARKET\n\n";
	Sleep(3000);
	system("CLS");
	main:
	{
		cout<<"Access as:\n\n1) Admin\n2) User\n";
		cin>>n;
		if (n==1)
		goto admin;
		if (n==2)
		goto bill;
	}
	
		admin:
		{
			do
			{
				system("CLS");
				cout << "To access the system, please login" << endl;
				cout << "Password: ";
				cin >> input; 
				if (input == pass)
				{
					cout << "\nAccess Granted\n" << endl; 
					Sleep(1000);
					system("CLS");
								
				}
				else
				{
					cout << "Wrong Password" <<endl<<endl;
				}
		
			} while(input!=pass);
	
		cout<<"Enter Your Choice\n1. Stock Management\n2. User Management\n";
		cin>>n;
		
		switch(n)
		{
			case 1:
				goto sm;
				break;
				
			case 2:
				goto um;
				break;
				
			default:
				return 0;
		}
	}
	
	sm:
	{	
		cout << "Enter total number of items: "; // array size
		cin >> n;
		cout<<"\nEnter Your Choice\n1. Add Item\n2. Update Item\n3. Delete Item\n4. Show List"<<endl;
		cin>>cond;
		
		switch (cond)
		{
			case 1:
				
				for(int p=0; p<n; p++)
				{
					i[p].add();
				}
				break;
			
			case 2: 
				cout << "Enter item number you want to update: ";
				cin >> s;
				for(int p=0; p<n; p++)
				{ 	
					if(s==i[p].getin())
					{
						ii[p].update();
						i[p]=ii[p];
					} 
			 }
				break;
			
			case 3:
				cout << "Enter item number you want to delete: ";
				cin >> s;
				for(int p=0; p<n; p++)
				{ 	
					if(s==i[p].getin())
					{
						i[p].del();
					}
				}
				break;
			
			case 4:
				for(int p=0; p<n; p++)
				{
					i[p].show();
				}
				break; 
				
			default:
				cout<< "INVALID ENTRY";
		}	
	}
	cout<<"\nDo you want to exit (y/n): ";
	cin>>ch;
	if(ch=='y')
	return 0;
	else
	system("CLS");
	goto main;
	
	um:
	{
		cout << "Enter total number of users: "; //array size 
		cin >> n;
		cout<<"\nEnter Your Choice\n1. Add User\n2. Delete User\n3. Show Accounts"<<endl;
		cin>>cond2;
		
		switch (cond2)
		{
			case 1:
				for(int p=0; p<n; p++)
				{
					u[p].add();
				}
				break;
			
			case 2: 
				cout << "Enter account name you want to delete: ";
				cin >> ss;
				for(int p=0; p<n; p++)
				{ 	
					if(ss==u[p].getn())
					{
						u[p].del();
					}
				}
				break;
				
			case 3:
				cout<<"Account Names: "<<endl;
				for(int p=0; p<n; p++)
				{
					u[p].show();
				}
				break;
				
			default:
				cout<< "INVALID ENTRY";
		}	
	}
	
	cout<<"\nDo you want to exit (y/n): ";
	cin>>ch;
	if(ch=='y')
	return 0;
	else
	system("CLS");
	goto main;
	
	bill:
	{
		int no;
		string na;
		double co;
		char ch;
		system("CLS");	
		b.user();
		system("CLS");
		cout << "Enter total number of items in inventory: "; //array size
		cin >> n;
		cout<<"\nSearch by: \n1. Item Number \n2. Item Name \n3. Item Price"<<endl;
		cin>>cond2;
		
		switch (cond2)
		{
			case 1:
				cout << "Enter Item Number: ";
				cin>>no;
				for(int p=0; p<n; p++)
				{
					if(b.getin()==i[p].getin())
					i[p].show();
				}
				cout<<"Do you want to checkout: ";
				cin>>ch;
				if(ch=='y')
				b.checkout();
				
				break;
			
			case 2: 
				cout << "Enter Item Name: ";
				cin>>na;
				for(int p=0; p<n; p++)
				{
					if(b.getname()==i[p].getname())
					i[p].show();
				}
				cout<<"Do you want to checkout: ";
				cin>>ch;
				if(ch=='y')
				b.checkout();
				
				break;
				
			case 3: 
				cout << "Enter Item Price: ";
				cin>>co;
				for(int p=0; p<n; p++)
				{
					if(b.getprice()==i[p].getprice())
					i[p].show();
				}
				cout<<"Do you want to checkout: ";
				cin>>ch;
				if(ch=='y')
				b.checkout();
				
				break;
				
			default:
				cout<< "INVALID ENTRY";
		}			
	}
	
	cout<<"\nDo you want to exit (y/n): ";
	cin>>ch;
	if(ch=='y')
	return 0;
	else
	system("CLS");
	goto main;
}
