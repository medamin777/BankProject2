#pragma once
#include <iostream>
#include "Screen.h"
#include "InputValidation.h"
#include "AddUserScreen.h"
#include "ShowUsersScreen.h"
#include "DeleteUserScreen.h"
#include "UpdateUserScreen.h"
#include "FindUserScreen.h"
class ManageUserScreen : protected Screen
{
private:
	enum ManageUsersOption { ShowUsersList = 1, AddUser = 2, DeleteUser = 3, UpdateUser = 4, FindUser = 5, MainMenue = 6 };
	static short _ReadOption()
	{
		short Option = 0;
		Option = InputValidation::readintegerNumberBetween(1, 6, "\n\t\t\t\t\tPlease choose what do you want to do  [1 to 6]: ");
		return Option;
	}
	static void _GoBacktoManageUsersMenue()
	{
		cout << "\n\t\t\t\t\tPress any key to go back to main menue.....";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _ShowAddUserScreen()
	{
		system("cls");
		AddUserScreen::AddUser();
		_GoBacktoManageUsersMenue();
	}
	static void _ShowDeleteUserScreen()
	{
		system("cls");
		DeleteUserScreen::ShowDeleteUser();
		_GoBacktoManageUsersMenue();
	}
	static void _ShowUpdateScreen()
	{
		system("cls");
		UpdateUserScreen::ShowUpdateUser();
		_GoBacktoManageUsersMenue();
	}
	static void _ShowFindUserScreen()
	{
		system("cls");
		FindUserScreen::ShowFindUser();
		_GoBacktoManageUsersMenue();
	}
	static void _ShowMainMenueScreen()
	{

	}
	static void _ShowUserScreen()
	{
		system("cls");
		ShowUsersScreen::ShowUsersList();
		_GoBacktoManageUsersMenue();
	}
	static void _PerformManageUsersMenue(ManageUsersOption Option)
	{
		switch (Option)
		{
		case ManageUsersOption::AddUser:
			_ShowAddUserScreen();
			break;
		case ManageUsersOption::DeleteUser:
			_ShowDeleteUserScreen();
			break;
		case ManageUsersOption::FindUser:
			_ShowFindUserScreen();
			break;
		case ManageUsersOption::UpdateUser:
			_ShowUpdateScreen();
			break;
		case ManageUsersOption::MainMenue:
			_ShowMainMenueScreen();
			break;
		case ManageUsersOption::ShowUsersList:
			_ShowUserScreen();
			break;
		}
	}
public:
	static void ShowManageUsersMenue()
	{
		system("cls");
		if (!(_AccesRights(User::ePermession::ManageUsers)))
		{
			return;
		}
		cout << "\n\n\t\t\t\t\t========================================\n";
		cout << "\t\t\t\t\t\t\tManage Users Menue";
		cout << "\n\t\t\t\t\t========================================";
		cout << "\n\t\t\t\t\t[1] Show Users List";
		cout << "\n\t\t\t\t\t[2] Add User";
		cout << "\n\t\t\t\t\t[3] Delete User";
		cout << "\n\t\t\t\t\t[4] Update User";
		cout << "\n\t\t\t\t\t[5] Find User";
		cout << "\n\t\t\t\t\t[6] Main Menue";
		cout << "\n\t\t\t\t\t========================================";
		_PerformManageUsersMenue((ManageUsersOption)_ReadOption());

	}
};
