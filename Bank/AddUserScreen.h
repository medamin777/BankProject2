#pragma once
#include <iostream>
#include "Screen.h"
#include "User.h"
using namespace std;
class AddUserScreen :protected Screen
{
private:
	static void _AddNewUser()
	{
		string UserName = "";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		UserName = InputValidation::ReadString("\n\t\t\t\t\tEnter a User Name: ");
		while (User::IsUserExist(UserName))
		{
			UserName = InputValidation::ReadString("\n\t\t\t\t\tUser is already Exist , Please Enter another Username: ");

		}
		User user = User::GetAddNewUser(UserName);
		_ReadUserInfo(user);
		User::SaveResults saveresults;
		saveresults = user.Save();
		switch (saveresults)
		{
		case User::SaveResults::SaveSucced:
			_PrintUserInfo(user);
			cout << "\n\t\t\t\t\tUser Added Successfly";
			break;
		case User::SaveResults::SaveFaild:
			cout << "\n\t\t\t\t\tFaild to Add a New User";
			break;
		}
	}
public:
	static void AddUser()
	{
		_DrawScreenHeader("Add User Screen");
		_AddNewUser();
	}
};

