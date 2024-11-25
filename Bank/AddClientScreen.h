#pragma once
#include "Screen.h";
#include <iostream>
#include <iomanip>
#include "BankClient.h";
#include "InputValidation.h";
using namespace std;
class AddClientScreen : protected Screen
{
private:
	static void _AddNewClient()
	{
		string AccountNumber = "";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		AccountNumber = InputValidation::ReadString("\n\n\t\t\t\t\tPlease Enter Account Number:");
		while (BankClient::IsClientExist(AccountNumber))
		{
			cout << "\n\t\t\t\t\tAccount Number Is Already Used ,choose another one: ";
			AccountNumber = InputValidation::ReadString();
		}
		BankClient client = BankClient::GetAddNewClient(AccountNumber);
		_ReadClientInfo(client);
		BankClient::SaveResults SaveResult = client.Save();
		switch (SaveResult)
		{
		case BankClient::SaveResults::svFaild:
			cout << "\nError acount was already exist ";
			break;
		case BankClient::SaveResults::svSucceeded:
			_PrintClientInfo(client);
			cout << "\n\t\t\t\t\tAccount Added Successfully :-)\n";
			break;
		}
	}
public:
	static void ShowAddClient()
	{
		_DrawScreenHeader("Add Client Screen");
		_AddNewClient();
	}

};