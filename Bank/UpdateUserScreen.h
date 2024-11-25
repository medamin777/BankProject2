#pragma once
#include "User.h"
#include "Screen.h"
#include <iomanip>
using namespace std;
class UpdateUserScreen :protected Screen
{
public:
	static void ShowUpdateUser()
	{
		_DrawScreenHeader("Update User Screen");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string UserName = InputValidation::ReadString("\n\t\t\t\t\t\Enter a User Name:");
		while (!User::IsUserExist(UserName))
		{
			UserName = InputValidation::ReadString("\t\t\t\t\tUser doesn't Exist , Enter a User Name:");
		}
		User user = User::Find(UserName);
		_PrintUserInfo(user);
		cout << "\n\t\t\t\t\tDo you want to update this User Y/N ";
		char Answer = 'n';
		cin >> Answer;
		if (tolower(Answer == 'y'))
		{
			User user = User::Find(UserName);
			_ReadUserInfo(user);
			User::SaveResults saveresults = user.Save();

			switch (saveresults)
			{
			case User::SaveResults::SaveSucced:
				cout << "\n\t\t\t\t\tAccount Updated Successfully : -)\n";
				break;
			case User::SaveResults::SaveFaild:
				cout << "\n\t\t\t\t\tFaild Operation ";
				break;
			}

		}
	}
};

