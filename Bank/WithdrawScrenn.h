#pragma once
#include <iostream>
#include "BankClient.h"
#include "Screen.h"
#include "InputValidation.h"
class WithdrawScrenn : protected Screen
{
public:
	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("Wirhdraw Screen");
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
		cout << "\n\t\t\t\t\tDo you want to perform this transaction: ";
		cin >> Answer;
		if (tolower(Answer) == 'y')
		{
			if (Client.Withdraw(Amount))
			{
				cout << "\t\t\t\t\tAmount Withdrawed successfuly";
				cout << "\n\t\t\t\t\tNew Acount Balance:" << Client.AccountBalance;
			}
			else
				cout << "\n\t\t\t\t\tyour account balance is insufficient to cover this amount";

		}

	}
};

