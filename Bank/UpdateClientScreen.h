#pragma once
#include <iostream>
#include "InputValidation.h";
#include "BankClient.h";
#include "Screen.h";
#include "BankClient.h";
class UpdateClientScreen : protected Screen
{
public:
	static void ShowUpdateClients()
	{
		_DrawScreenHeader("Update Client Screen");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string AccountNumber = InputValidation::ReadString("\n\n\t\t\t\t\tPlease Enter client Account Number");
		while (!BankClient::IsClientExist(AccountNumber))
		{
			cout << "\n\t\t\t\t\tAccount number is not found, choose another one: ";
			AccountNumber = InputValidation::ReadString();
		}
		BankClient Client1 = BankClient::Find(AccountNumber);
		_PrintClientInfo(Client1);
		_ReadClientInfo(Client1);
		BankClient::SaveResults SaveResult;
		SaveResult = Client1.Save();
		switch (SaveResult)
		{
		case BankClient::SaveResults::svFaild:
			cout << "\n\t\t\t\t\tError account was not saved becuase it's Empy";
			break;
		case BankClient::SaveResults::svSucceeded:
			cout << "\n\t\t\t\t\tAccount Updated Successfully :-)\n";
			break;
		}
	}
};

