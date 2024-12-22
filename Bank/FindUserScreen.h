#pragma once
#include "Screen.h"
#include "User.h"
#include <vector>
class FindUserScreen: public Screen
{
public :
	void static  ShowFindUser()
	{
		_AccesRights(User::ePermession::FindClient);
		_DrawScreenHeader("Find User Screen");
		cin.ignore();
		cout << "\n\t\t\t\t\t\Enter User Name :";
		string UserName = InputValidation::ReadString();
		while (!(User::IsUserExist(UserName)))
		{
			cout <<"\n\t\t\t\t\t\ User doesn't Exist/Enter User Name :";
			UserName = InputValidation::ReadString();
		}
		User user = User::Find(UserName);
		_PrintUserInfo(user);
	}
};

