#pragma once
using namespace std;
#include <iostream>
#include "LoginUser.h"
#include "Screen.h"
#include "User.h"
class RegistLoginScreen : public Screen
{
private:
	static void _PrintLoginUserRecord(LoginUser loginuser)
	{
		cout << "|" << setw(20) << left << loginuser.getTime();
		
		cout << "|" << setw(12) << left << loginuser.getUserName();
		cout << "|" << setw(12) << left << loginuser.GetPassword();
		cout << "|" << setw(12) << left << loginuser.getPermession();
	}

public :
	static void ShowLoginUsers()
	{
		if (!(_AccesRights(User::ePermession::LoginRegistration)))
		{
			return;
		}
		vector<LoginUser> LoginUsers = LoginUser::GetAllLoginUsers();
		string Title = "Login Register List Screen";
		string SubTitle = "\t\t(" + to_string(LoginUsers.size()) + ") Record(s)";
		_DrawScreenHeader(Title, SubTitle);
		cout << "\n___________________________________________________________";
		cout << "______________________________________________________________\n" << endl;
		cout << "|" << left << setw(20) << "Date/Time";
		cout << "|" << left << setw(12) << "User Name";
		cout << "|" << left << setw(12) << "Password";
		cout << "|" << left << setw(12) << "Permession";
		cout << "\n___________________________________________________________";
		cout << "______________________________________________________________\n" << endl;
		if (LoginUsers.size() == 0)
		{
			cout << "\t\t\t\tNo Users Loged in System!";
		}
		else
		{
			for (LoginUser loginuser : LoginUsers)
			{
				_PrintLoginUserRecord(loginuser);
				cout << endl;
			}
		}
		cout << "\n___________________________________________________________";
		cout << "______________________________________________________________\n" << endl;

	}
	
};

