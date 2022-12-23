#include <fstream>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include<conio.h>
using namespace std;
class alogin
{
    string admin;

public:
    int adlogin()
    {
        cout << "enter the ADMIN code" << endl;
        cin >> admin;
        if (admin == "admin")
        {

            int p = getadpassword();
            if (p == 1)
            {
                cout << "LOGIN Succesful" << endl;
                return 1;
            }
        }
        else
        {
            cout << "user name not found" << endl;
            adlogin();
            cout << "LOGIN Failed" << endl;
            return 0;
        }
        return 0;
    }
    int getadpassword();
};

int alogin::getadpassword()
{

    char pin[100];
    int k=0;
    cout << "enter the password" << endl;
    while(pin[k-1]!='\r') {
        pin[k]=getch();
        if(pin[k-1]!='\r') {
            cout<<"*";
        }
        k++;
    }
    pin[k-1]='\0';
    string s=pin;
    if (s =="fitgym")
    {
        cout<<"\n";
        cout<<endl<< "WELCOME!!" <<endl;
        return 1;
    }
    else
    {
        cout << "entered password is incorrect" << endl;
        getadpassword();
        return 0;
    }
}

void allotment_gold(int gc, int sc)
{
	if (gc != 0)
	{

		cout << "trainer" << gc << " alloted\n";
	}
	else
	{
		cout << "\nno trainer available\n";
	}
}

void allotment_silver(int gc, int sc)
{
	if (sc != 0)
	{

		cout << "trainer" << sc << " alloted\n";
	}
	else
	{
		cout << "\nno trainer available\n";
		if (gc != 0)
		{
			cout << "enter  another class\n";
			allotment_gold(gc, sc);
		}
	}
}

int trainee_allotment(char *c)
{
	char class_type[10];
	int i, gold_class = 2, silver_class = 3;
	strcpy(class_type, c);

	if ((gold_class != 0) || (silver_class) != 0)
	{

		if (strcmp(class_type, "gold") == 0)
		{
			gold_class--;
			allotment_gold(gold_class, silver_class);
		}
		else if (strcmp(class_type, "silver") == 0)
		{
			silver_class--;
			allotment_silver(gold_class, silver_class);
		}
	}

	else
	{

		cout << "no trainer availbale\n";
		return 1;
	}

	return 0;
}

class member
{
	int member_number, j;
	char mem_name[50], classs[50], timings[50], mem_phonenum[11];
	float fee;

	long long int contact;

public:
    int time_slots()
	{
		int k;

		cout << "Please select your preferred timings\npress 1 for: morining 6-7\npress 2 for: morning 7-8\n";
		cout << "press 3 for: evening 4-5\npress 4 for:evening 5-6\npress 5 for:evening 6-7\n";
		cin >> k;
		switch (k)
		{
		case 1:
			strcpy(timings, "6AM-7AM");
			break;
		case 2:
			strcpy(timings, "7AM-8AM");
			break;
		case 3:
			strcpy(timings, "4PM-5PM");
			break;
		case 4:
			strcpy(timings, "5PM-6PM");
			break;
		case 5:
			strcpy(timings, "6PM-7PM");
			break;
		}
		return 0;
	}

	void create_mem()
	{
		int k, l, j;
		cout << endl
			 << "Please Enter The member Number: ";
		cin >> member_number;
		cout << endl
			 << "Please Enter The Name of The member: ";
		getchar();
		cin.getline(mem_name, 50);
		cout << endl
			 << "Please Enter The contact number: ";
		cin >> contact;

		cout << "1.gold class\n2.silver class\n";
		cout << "enter the choice\n";
		cin >> k;
		ofstream t1;
		if(k==1)
		{
		t1.open("trainer1.txt",ios::app);
		t1<<mem_name<<endl;	
		}
		ofstream t2;
		if (k==2){
			t2.open("trainer2.txt",ios::app);
			t2<<mem_name<<endl;
		}
		switch (k)
		{
		case 1:
		{
			strcpy(classs, "gold");
			fee = 2500;
			cout << "your monthly fee would be: " << fee << endl;
			l = trainee_allotment(classs);
		}
		break;
		case 2:
		{
			strcpy(classs, "silver");
			fee = 2000;
			cout << "your monthly fee would be: " << fee << endl;
			l = trainee_allotment(classs);
		}
		break;
		}
		time_slots();
	}

	void show_mem()
	{
		cout << endl
			 << "member code: " << member_number;
		cout << endl
			 << "Name: " << mem_name;
		cout << endl
			 << "category: " << classs;
		cout << endl
			 << "fee: " << fee;
		cout << endl
			 << "contact: " << contact;
		cout << endl
			 << "timings: " << timings << endl;
	}

	int getmem()
	{
		return member_number;
	}

	float getfee()
	{
		return fee;
	}

	char *getName()
	{
		return mem_name;
	}

	long long int getcontact()
	{
		return contact;
	}
};

fstream fp;
member m1;

void save_member()
{
	fp.open("list_of_members.txt", ios::app);
	m1.create_mem();
	fp.write((char *)&m1, sizeof(m1));
	fp.close();
	cout << endl
		 << endl
		 << "The member has been succesfully added ";
		 cout<<"\n";
		 cout<<"\n";

	getchar();
}

void show_all()
{
	cout << endl
		 << "\t\tRECORDS...";
	fp.open("list_of_members.txt", ios::in);
	while (fp.read((char *)&m1, sizeof(m1)))
	{
		m1.show_mem();
		getchar();
	}
	fp.close();
}

void display_record(int num)
{
	bool found = false;
	fp.open("list_of_members.txt", ios::in);
	while (fp.read((char *)&m1, sizeof(m1)))
	{
		if (m1.getmem() == num)
		{
			system("cls");
			m1.show_mem();
			found = true;
		}
	}

	fp.close();
	if (found == true)
		cout << "\n\nNo record found";
	getchar();
}

void edit_member()
{
	int num;
	bool found = false;
	system("cls");
	cout << endl
		 << endl
		 << "\tPlease Enter The member number: ";
	cin >> num;

	fp.open("list_of_members.txt", ios::in | ios::out);
	while (fp.read((char *)&m1, sizeof(m1)) && found == false)
	{
		if (m1.getmem() == num)
		{
			m1.show_mem();
			cout << "\nPlease Enter The New details of the member: " << endl;
			m1.create_mem();
			int pos = 1 * sizeof(m1);
			fp.seekp(pos, ios::cur);
			fp.write((char *)&m1, sizeof(m1));
			cout << endl
				 << endl
				 << "\t Record Successfully Updated...";
			found = true;
		}
	}
	fp.close();
	if (found == false)
		cout << endl
			 << endl
			 << "Record Not Found...";
	getchar();
}

void delete_member()
{
	int num;
	system("cls");
	cout << endl
		 << endl
		 << "Please Enter The member number: ";
	cin >> num;
	fp.open("list_of_members.txt", ios::in | ios::out);
	fstream fp2;
	fp2.open("Temp.txt", ios::out);
	fp.seekg(0, ios::beg);
	while (fp.read((char *)&m1, sizeof(m1)))
	{
		if (m1.getmem() != num)
		{
			fp2.write((char *)&m1, sizeof(m1));
		}
	}
	fp2.close();
	fp.close();
	remove("list_of_members.txt");
	rename("Temp.txt", "list_of_members.txt");
	cout << endl
		 << endl
		 << "\tRecord Deleted...";
	getchar();
}
void fnmanage()
{
	for (;;)
	{
	
		int option;
		cout << "\t***********************************************";
		cout << "\n\tPress 1 to CREATE MEMBER";
		cout << "\n\tPress 2 to DISPLAY ALL RECORDS";
		cout << "\n\tPress 3 to SEARCH FOR A PARTICULAR RECORD ";
		cout << "\n\tPress 4 to EDIT MEMBER DETAILS";
		cout << "\n\tPress 5 to DELETE MEMBER";
		cout << "\n\tPress 6 to GO BACK TO MAIN MENU";
		cout << "\n\t**********************************************";

		cout << "\n\n\tOption: ";
		cin >> option;
		switch (option)
		{
		case 1:
			system("cls");
			save_member();
			break;

		case 2:
			show_all();
			break;

		case 3:
			int num;
			system("cls");
			cout << "\n\n\tPlease Enter The member Number: ";
			cin >> num;
			display_record(num);
			break;

		case 4:
			edit_member();
			break;

		case 5:
			delete_member();
			break;

		case 6:
			system("cls");
			break;

		default:
			fnmanage();
		}
	}
}

void fnuser()
{
    for (;;)
    {
        int m;
        cout<<"\n";
        cout << "1.SIGN UP(join gym)\n2.QUIT GYM\n3.LOG IN(edit profile)\n";
        cout << endl
             << "enter your choice" << endl;
        cin >> m;
        switch (m)
        {
        case 1:
            system("cls");
            save_member();
            break;
        case 2:
            delete_member();
            break;

        case 3:
            edit_member();
            break;
        }
    }
}
void fntrainer()
{
	ifstream t1;
	ifstream t2;
	for (;;)
	{
		int tom;
		
		cout << endl<<"1.trainer1\n2.trainer2\n";
		cout << endl
			 << "enter your trainer number" << endl;
		cin >> tom;
		switch(tom)
		{
		case 1: cout<<"You are alloted to the ones who choosen gold membership"<<endl;
				   t1.open("trainer1.txt",ios::in);
				   if(t1.is_open()){
				string tr;
				while(getline(t1,tr)){
					cout<<tr<<"\n";
				}
			}
				  // cout<<mem_name;
				   break;
		case 2: cout<<"You are alloted to the ones who choosen silver membership"<<endl;
			t2.open("trainer2.txt",ios::in);
			if(t2.is_open()){
				string tr2;
				while(getline(t2,tr2)){
					cout<<tr2<<"\n";
				}
			}
			//cout<<mem_name;
			break;
			t1.close();
			t2.close();




		}
	}
}
int main()
{

    int i, k;
    string name, code;
    cout << " ************ SRM GYM MANAGEMENT SYSTEM************ " << endl;
    cout<<"\n";
    cout << endl
         << "SELECT MODE" << endl
         << "1.User" << endl
         << "2.Admin" << endl
         << "3.Trainer" << endl;
    cin >> i;

    if (i == 1)
    {
        cout << endl
             << "you're in USER MODE" << endl;
        fnuser();
    }
    if (i == 2)
    {
        cout << endl
             << "you're in ADMIN MODE" << endl;

        alogin ad;
        k = ad.adlogin();
        if (k == 1)
        {
            fnmanage();
        }
        else
        {
            cout << "you cannot access manageral details!";
        }
    }
    if (i == 3)
    {
        cout << endl
             << "you're in TRAINERS MODE" << endl;
        fntrainer();
    }

    return 0;
}
