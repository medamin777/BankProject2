#pragma once
#include "Screen.h"
#include "User.h"
#include "Global.h"
#include "MainScreen.h"
class LoginScreen :protected Screen
{
private:
	void static _Login()
	{
		string Username = "";
		string Password = "";
		bool FaildLogin = false;
		do{
			if (FaildLogin) 
			{
				cout << "\n\t\t\t\t\tInvalid User !";
			}
			cout << "\n\t\t\t\t\tEnter User Name: ";
			cin >> Username;
			cin.ignore();
			cout << "\n\t\t\t\t\tEnter Password: "; 
			getline(cin, Password);
			CurrentUser = User::Find(Username, Password);
			FaildLogin = CurrentUser.IsEmpty();
		} while (FaildLogin);
		
	}
public :
	void static ShowLogin()
	{
		_DrawScreenHeader("Login Screen");
		_Login();
		MainScreen::ShowMainMenue();
		
	}
};

