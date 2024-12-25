#pragma once
#include "Screen.h"
#include "User.h"
#include "Global.h"
#include "MainScreen.h"
class LoginScreen :protected Screen
{
private:
	bool static _Login()
	{
		string Username = "";
		string Password = "";
		bool LoginFaild = false;
		short FaildLoginCount = 0;
		do {
			if (LoginFaild)
			{
				FaildLoginCount++;
				cout << "\n\t\t\t\t\tInvalid UserName/Password! you have " << 3-FaildLoginCount << " trials to login\n";
				
			}
			if (FaildLoginCount==3)
			{
				cout << "\n\t\t\t\t\tYour are Locked after 3 faild trails \n\n";
				return false;
			}
			cout << "\n\t\t\t\t\tEnter Username :";
			cin >> Username;
			cin.ignore();
			cout << "\n\t\t\t\t\tEnter Password :";
			cin >> Password;
			CurrentUser = User::Find(Username, Password);
			LoginFaild = CurrentUser.IsEmpty();


		} while (LoginFaild);
		MainScreen::ShowMainMenue();
		return true;
	}
public :
	bool static ShowLogin()
	{
		system("cls");
		_DrawScreenHeader("Login Screen");
		return _Login();
	}
};

