#include<iostream>
#include<fstream>
#include<cctype>
#include<string>
#include<iomanip>
using namespace std;

void intro();
void ad_login();
void createAccount(); // User creates own username/password to and is stored in accounts.txt
void login(void); // Login achieved by using the accounts.txt file to check for username/password match
int ad_menu();
int menu();
char bankingMenu();

class account
{
	int acno;
	char name[50];
	int deposit;
	char type;
	char address[100];
    char adharno[80];
    char phno[80];
public:
	void create_account();	//function to get data from user
	void show_account() const ;	//function to show data on screen
	void modify();	//function to add new data
	void dep(int);	//function to accept amount and add to balance amount
	void draw(int);	//function to accept amount and subtract from balance amount
	void report() const;	//function to show data in tabular format
	int retacno() const;	//function to return account number
	int retdeposit() const;	//function to return balance amount
	char rettype() const;	//function to return type of account
};         //class ends here

void account::create_account()
{
	cout<<"\nEnter The account No. :\t";
	cin>>acno;
	cout<<"\n\nEnter The Name of The account Holder :\t ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter The Address of the account Holder:\t ";
	cin.ignore();
	cin.getline(address,50);
	cout<<"\nEnter Aadhar Number of the account Holder: \t";
	cin.ignore();
	cin.getline(adharno,100);
	cout<<"\nEnter Phone Number of the account Holder: \t";
	cin.ignore();
	cin.getline(phno,80);
	cout<<"\nEnter Type of The account (C/S) :\t ";
	cin>>type;
	cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : \t";
	cin>>deposit;
	cout<<"\n\n\n Congrats!!!!Account Created......";
}

void account::show_account() const
{
	cout<<"\nAccount No. : \t"<<acno;
	cout<<"\nAccount Holder Name : \t"<<name;
	cout<<"\nAccount Holder Address :\t"<<address;
	cout<<"\nAccount Holder Aadhar Number :\t"<<adharno;
	cout<<"\nAccounnt Holder Phone Number :\t"<<phno;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
}


void account::modify()
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nModify Account Holder Name :\t ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nModify Type of Account :\t ";
	cin>>type;
	cout<<"\nModify Account Holder Address:\t ";
	cin.ignore();
	cin.getline(address,50);
	cout<<"\nModify Account Holder Phone Number: \t";
	cin.ignore();
	cin.getline(phno,80);
	cout<<"\nModify Balance amount :\t ";
	cin>>deposit;
}

	
void account::dep(int x)
{
	deposit+=x;
}
	
void account::draw(int x)
{
	deposit-=x;
}
	
void account::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(30)<<" "<<type<<setw(20)<<" "<<" $"<<deposit<<endl;
}

	
int account::retacno() const
{
	return acno;
}

int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type;
}

void write_account();	//function to write record in binary file
void display_sp(int);	//function to display account details given by user
void modify_account(int);	//function to modify record of file
void delete_account(int);	//function to delete record of file
void display_all();		//function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void intro();	//introductory screen function


int main()
{
char choice;
intro();
system("cls");
cout<< "\n\n\t*******************WELCOME**************************"<<endl;

while(1)
{

	cout<<"\n\nA -> Admin"<<endl;
	cout<<"U -> User"<<endl;
	cout<<"Q -> Quit"<<endl;
	cin>>choice;
	system("cls");  
switch(choice)
{
case 'a':
case 'A':
    ad_login();
    break;
case 'u':
case 'U':
    menu();
case 'q':
case 'Q':
    cout<<"Thank you visiting our database"<<endl;
    exit(0);
default:
cout<<"Invalid choice";
}
}
return 0;
}
void ad_login() // Takes information stored in create account. Most loaded function, also holds banking menu.
{
   string user_name,u_n="admin";
   string pass_word,pass="test123";
   int choice;
   int ch;
   int num;
   cout << "Enter your username:" << endl;
   cin >> user_name;
   cout << "Enter your password:" << endl;
   cin >> pass_word;
   if((user_name==u_n)&&(pass_word==pass))
   {
    cout<<"***Welcome Admin***"<<endl;
    ad_menu();
}
else
{
		cout << "Incorrect login! Create new account or try again." << endl;
}
}

int ad_menu()
{
char ch;
int num;
do
	{
		system("cls");
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t1. NEW ACCOUNT";
		cout<<"\n\n\t2. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n\t3. CLOSE AN ACCOUNT";
		cout<<"\n\n\t4. MODIFY AN ACCOUNT";
		cout<<"\n\n\t5. EXIT";
		cout<<"\n\n\tSelect Your Option (1-5) ";
		cin>>ch;
		system("cls");
		switch(ch)
		{
		case '1':
			write_account();
			break;
	
			break;
		case '2':
			display_all();
			break;
		case '3':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		 case '4':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
		 case '5':
			cout<<"\n\n\tThanks for using bank managemnt system";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
	}while(ch!='5');
	return 0;
}
int menu() 
{
    char choice;
    cout << "********** MAIN MENU ********** " << endl << endl;
    cout << "l(L) -> Login to Banking Menu" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit the Program" << endl;
    cout << "Enter your choice:" << endl;
    cin >> choice;
    while (choice != 'q' || choice != 'Q')
 {
     if (choice == 'q' || choice == 'Q'){
         cout << "Thanks for visiting our  Banking system!";   break;} 
        switch (choice)
        {
        case 'l':
        case 'L':
            login();
            break;
        case 'c':
        case 'C':
            createAccount();
            break;

        default:

            cout << "Invalid choice!" << endl;
        }
    }    
    return 0;

}


void createAccount() // Takes and stores users login information, username and password
{
   string username;
   string password;
   cout << "Please create a username" << endl;
   cin >> username;
   cout << "Please create a password" << endl;
   cin >> password;
   ofstream createaccount;
   createaccount.open("accounts.txt", ios::app); // Will store the users information.
   createaccount << username << " " << password << endl;
   createaccount.close();
   cout << "Account created!" << endl;

}
void login(void) // Takes information stored in create account. Most loaded function, also holds banking menu.
{
   string username;
   string password;
   char choice;
   account decision;
   int num;
   ifstream savedaccount;
   savedaccount.open("accounts.txt"); // accounts.txt will verify user information.
   cout << "Enter your username:" << endl;
   cin >> username;
   cout << "Enter your password:" << endl;
   cin >> password;
   string username2, password2;
   savedaccount >> username2 >> password2;
   savedaccount.close();
   if (username != username2 || password != password2)
    cout << "Incorrect login! Create new account or try again." << endl;
    while(username == username2 && password == password2) // Achieved by using accounts.txt match
    {
        choice = bankingMenu(); // Placed function here so that it will only appear if user logins.
        if (choice == 'q' || choice =='Q') break;
        switch (choice){
	case 'd':
    case 'D':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
    case 'w':
    case 'W':
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
	case 'b':
    case 'B': 
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			display_sp(num);
default:
    cout << "Invalid choice!" << endl;

        }
}
}

char bankingMenu() // Banking menu, only opens if user achieves login.
{
    char choice;
    cout << "********* BANKING MENU *********" << endl << endl;
    cout << "d. Deposit Money" << endl;
    cout << "w. Withdraw Money" << endl;
    cout << "b. Check Balance" << endl;
    cout << "q. Return to Main Menu" << endl;
    cout << "Enter your choice:" << endl;
    cin >> choice;
    return choice;
    }

void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("accounts.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
}

void display_sp(int n)
{
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("accounts.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nAccount number does not exist";
}



void modify_account(int n)
{
	bool found=false;
	account ac;
	fstream File;
	File.open("accounts.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}

void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("accounts.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("accounts.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\n\tRecord Deleted ..";
}

void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("accounts.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"============================================================================================\n";
	cout<<"A/c no.      NAME                                Type                   Balance\n";
	cout<<"=============================================================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
}

void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	account ac;
	fstream File;
	File.open("accounts.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited";
				cin>>amt;
				ac.dep(amt);
			}
			if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
			}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
	       }
         }
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
}

void intro()
{
	cout<<"\n\n\n\t********************************* BANK RECORD SYSTEM**********************************";
	cin.get();
}

