#pragma once
#include "Screen.h"
#include "BankClient.h"
#include "InputValidation.h"
class TransferScreen :protected Screen
{
private:
	static void _PrintClientCard(BankClient client)
	{
		cout << "\n\t\t\t\t\t******************************";
		cout << "\n\t\t\t\t\tFull Name: " << client.FullName();
		cout << "\n\t\t\t\t\tAccount Number: " << client.AccountNumber();
		cout << "\n\t\t\t\t\tBalance: " << client.AccountBalance;
		cout << "\n\t\t\t\t\t******************************\n";
	}
public:

	 static void ShowTransfer()
	{
		_DrawScreenHeader("Transfer Screen");
		string SenderAccount;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\n\t\t\t\t\tPlease enter Account Number to transfer From: ";
		getline(cin, SenderAccount);
		
		while (!BankClient::IsClientExist(SenderAccount))
		{
			
			cout << "\n\t\t\t\t\tInvalid Account,Please enter Account Number to transfer From:";
			getline(cin, SenderAccount);
		  
		}
		
		BankClient Sender = BankClient::Find(SenderAccount);
		_PrintClientCard(Sender);
		string ReceiverAccount;
		cout<<"\n\t\t\t\t\tPlease enter Account Number to transfer to : ";
		getline(cin, ReceiverAccount);
	
		while (!BankClient::IsClientExist(ReceiverAccount) || ReceiverAccount==SenderAccount)
		{
			cout << "\n\t\t\t\t\tInvalid Account,Please enter Account Number to transfer to: ";
			ReceiverAccount = InputValidation::ReadString();
		}
		BankClient Receiver = BankClient::Find(ReceiverAccount);
		_PrintClientCard(Receiver);
		float Amount = InputValidation::ReadFloat("\n\t\t\t\t\tEnter transfer Amount: ");
		cin.ignore();
		while(Amount>Sender.AccountBalance)
		{
			Amount= InputValidation::ReadFloat("\n\t\t\t\t\tAmount Exceeds the available Balance ,Enter transfer Amount: ");
		}
		char Answer;
		cout << "\n\t\t\t\t\tDo you want to perform this operation? Y/N?: ";
		cin >> Answer;
		if (Answer)
		{
			if (Sender.Transfer(Receiver, Amount))
			{
				cout << "\n\t\t\t\t\tTransfer Done Successfully";
				_PrintClientCard(Sender);
				_PrintClientCard(Receiver);
			}
		
		}


	}
	
};

