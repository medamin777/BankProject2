#pragma once
#include "Screen.h"
#include "User.h"
#include <iostream>
using namespace std;
class ShowUsersScreen : protected Screen
{
private:
	static void _PrintUserLine(User user)
	{
		cout << "|" << setw(15) << left << user.UserName;
		cout << "|" << setw(20) << left << user.FullName();
		cout << "|" << setw(12) << left << user.Phone;
		cout << "|" << setw(40) << left << user.Email;
		cout << "|" << setw(20) << left << user.Password;
		cout << "|" << setw(18) << left << user.Permession;
	}
public:
	static void ShowUsersList()
	{
		vector<User> Users = User::GetAllUsers();
		string Title = "Users List";
		string SubTitle = "\t\t (" + to_string(Users.size()) + ") Users";
		_DrawScreenHeader(Title, SubTitle);
		cout << "\n___________________________________________________________";
		cout << "______________________________________________________________\n" << endl;
		cout << "|" << left << setw(15) << "User Name";
		cout << "|" << left << setw(20) << "Full Name";
		cout << "|" << left << setw(12) << "Phone";
		cout << "|" << left << setw(40) << "Email";
		cout << "|" << left << setw(20) << "Password";
		cout << "|" << left << setw(18) << "Permession";
		cout << "\n___________________________________________________________";
		cout << "______________________________________________________________\n" << endl;
		if (Users.size() == 0)
		{
			cout << "\t\t\t\t No Users Available in the System";
		}
		else
		{
			for (User user : Users)
			{
				_PrintUserLine(user);
				cout << endl;
			}

		}
		cout << "\n___________________________________________________________";
		cout << "______________________________________________________________\n" << endl;
	}

};
