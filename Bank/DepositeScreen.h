#pragma once
#pragma once
#include <iostream>
#include "BankClient.h"
#include "Screen.h"
#include "InputValidation.h"

class DepositeScreen :protected Screen
{
public:
	static void ShowDepositeScreen()
	{
		_DrawScreenHeader("Deposite Screen");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string AccountNumber = InputValidation::ReadString("\n\t\t\t\t\tPlease Enter an Account Number: ");

		while (!BankClient::IsClientExist(AccountNumber))
		{

			cout << "\t\t\t\t\tClient with [" << AccountNumber << "] does not exist , Please Enter an Account Number : ";
			AccountNumber = InputValidation::ReadString();
		}
		BankClient Client = BankClient::Find(AccountNumber);
		_PrintClientInfo(Client);
		float Amount = InputValidation::ReadFloat("\n\t\t\t\t\tPlease Enter an Amount: ");
		char Answer = 'n';
		cout << "\nDo you want to add this amount to your Account: ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			Client.Deposite(Amount);
			cout << "Amount Deposited successfuly";
			cout << "\nNew Acount Balance:" << Client.AccountBalance;
		}

	}

};

