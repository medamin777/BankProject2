#pragma once
#include <iostream>
#include "Screen.h"
#include "User.h"
using namespace std;
class DeleteUserScreen : protected Screen
{
public:
	static void ShowDeleteUser()
	{
		_DrawScreenHeader("Delete Screen");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string UserName = InputValidation::ReadString("\n\t\t\t\t\t\Enter a User Name:");
		while (!User::IsUserExist(UserName))
		{
			UserName = InputValidation::ReadString("\t\t\t\t\tUser doesn't Exist , Enter a User Name:");
		}
		User user = User::Find(UserName);
		_PrintUserInfo(user);
		cout << "\n\t\t\t\t\tDo you want to Delete this User Y/N ";
		char Answer = 'n';
		cin >> Answer;
		if (tolower(Answer == 'y'))
		{
			if (user.Delete())
			{
				cout << "\n\t\t\t\t\tUser Deleted Successfully";
				_PrintUserInfo(user);
			}
			else
				cout << "\n\t\t\t\t\tFaild Delete Operation";
		}

	}
};

