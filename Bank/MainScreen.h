#pragma once
#include <iostream>
#include "Screen.h"
#include "InputValidation.h"
#include "ShowClientScreen.h"
#include "AddClientScreen.h"
#include "DeleteClientScreen.h"
#include "UpdateClientScreen.h"
#include "FindClientScreen.h"
#include "TransactionScreen.h"
#include "ManageUserScreen.h"
#include "Global.h"
#include "LoginScreen.h"
#include <iomanip>
using namespace std;
class MainScreen :protected Screen
{
private:
	enum MainMenuOptions { ListClients = 1, AddNewClient = 2, DeleteClient = 3, UpdateClient = 4, FindClient = 5, ShowTransactionMenue = 6, ManageUsers = 7, Exit = 8 };
	static short _ReadMenueOption()
	{
		short choice = InputValidation::readintegerNumberBetween(1, 8, "\n\t\t\t\t\tChoose what do you want to do ? [1 to 8] ");
		return choice;
	}
	static void _GoBackToMainMenue()
	{
		std::cout << setw(37) << left << "" << "\nPress any key to go back to Main Menue....\n";
		system("pause>0");
		ShowMainMenue();
	}
	static void _ShowAllClientsScreen()
	{
		system("cls");
		ShowClientScreen::ShowClientList();
		_GoBackToMainMenue();
	}
	static void _ShowAddClientScreen()
	{
		system("cls");
		//cout << "\nClient Add Screen will be here...\n";
		AddClientScreen::ShowAddClient();
		_GoBackToMainMenue();
	}
	static void _ShowUpdateClientScree()
	{
		system("cls");
		//cout << "\nClient Update Screen will be here...\n";
		UpdateClientScreen::ShowUpdateClients();
		_GoBackToMainMenue();
	}
	static void _ShowDeleteClientScreen()
	{
		system("cls");
		//cout << "\nClient Delete Screen will be here...\n";
		DeleteClientScreen::ShowDeleteClient();
		_GoBackToMainMenue();
	}
	static void _ShowFindClientScreen()
	{
		system("cls");
		//cout << "\nClient Find Screen will be here...\n";
		FindClientScreen::ShowFindClient();
		_GoBackToMainMenue();
	}
	static void _ShowTransactionScreen()
	{
		system("cls");
		TransactionScreen::ShowTransactionMenue();
		_GoBackToMainMenue();
	}
	static void _ShowManageUsersScreen()
	{
		system("cls");
		ManageUserScreen::ShowManageUsersMenue();
		_GoBackToMainMenue();
	}
	static void _Logout()
	{
		CurrentUser = User::_GetEmpyObject();

		system("cls");

		
		
	}
	static void _PerformMainMenueOption(MainMenuOptions MainOption)
	{
		switch (MainOption)
		{
		case MainMenuOptions::AddNewClient:

			_ShowAddClientScreen();
			break;
		case MainMenuOptions::DeleteClient:

			_ShowDeleteClientScreen();
			break;
		case MainMenuOptions::FindClient:
			_ShowFindClientScreen();
			break;
		case MainMenuOptions::ListClients:
			_ShowAllClientsScreen();
			break;
		case MainMenuOptions::ManageUsers:
			_ShowManageUsersScreen();
			break;
		case MainMenuOptions::ShowTransactionMenue:
			_ShowTransactionScreen();

			break;
		case MainMenuOptions::UpdateClient:
			_ShowUpdateClientScree();
			break;
		case MainMenuOptions::Exit:
			_Logout();
			
			break;
		}
	}
public:
	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("Main Screen");
		cout << "\n\n\t\t\t\t\t========================================\n";
		cout << "\t\t\t\t\t\t\tMain Menue";
		cout << "\n\t\t\t\t\t========================================";
		cout << "\n\t\t\t\t\t[1] Show Client List";
		cout << "\n\t\t\t\t\t[2] Add Client";
		cout << "\n\t\t\t\t\t[3] Delete Client";
		cout << "\n\t\t\t\t\t[4] Update Client";
		cout << "\n\t\t\t\t\t[5] Find Client";
		cout << "\n\t\t\t\t\t[6] Transaction Menu";
		cout << "\n\t\t\t\t\t[7] Manage Users";
		cout << "\n\t\t\t\t\t[8] Logout";
		cout << "\n\t\t\t\t\t========================================";
		_PerformMainMenueOption((MainMenuOptions)_ReadMenueOption());
	}
};

