#pragma once
#include <iostream>
#include "BankClient.h";
#include "Screen.h";
#include "InputValidation.h";
class DeleteClientScreen : protected Screen
{
public:

	static void ShowDeleteClient()
	{
		_DrawScreenHeader("Delete Client Screen");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string AccountNumber = InputValidation::ReadString("\n\n\t\t\t\t\tEnter Account Number ");
		while (!BankClient::IsClientExist(AccountNumber))
		{
			cout << "\n\t\t\t\t\tClient doesn't Exist , Enter Account Number: ";
			AccountNumber = InputValidation::ReadString();
		}
		BankClient client = BankClient::Find(AccountNumber);
		_PrintClientInfo(client);
		cout << "\n\t\t\t\t\tDo you want to Delete this client Y/N ";
		char Answer = 'n';
		cin >> Answer;
		if (tolower(Answer == 'y'))
		{
			if (client.Delete())
			{
				cout << "\n\t\t\t\t\tClient Deleted Successfully ";
				_PrintClientInfo(client);
			}
			else
				cout << "\n\t\t\t\t\tFaild Delete Operation";
		}
	}
};

