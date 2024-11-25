#pragma once
using namespace std;
#include <iostream>                            
#include <iomanip>
#include "InputValidation.h";
#include "BankClient.h"
#include "User.h"
class Screen
{
private:
	static int _ReadPermession()
	{
		int Permession = 0;
		char Answer1 = InputValidation::ReadChar("n\t\t\t\t\tDo yout want to give it Full Acces Y/N");
		if (tolower(Answer1) == 'y')
			return User::ePermession::All;
		cout << "n\t\t\t\t\tDo you want to give access to :";
		char Answer = InputValidation::ReadChar("n\t\t\t\t\tShow Clients List Y/N:");
		if (tolower(Answer == 'y'))
			Permession += User::ePermession::ClientList;
		char Answer2 = InputValidation::ReadChar("n\t\t\t\t\tAdd Client");
		if (tolower(Answer2 == 'y'))
			Permession += User::ePermession::AddClient;
		char Answer3 = InputValidation::ReadChar("n\t\t\t\t\tDelete Client");
		if (tolower(Answer3 == 'y'))
			Permession += User::ePermession::DeleteClient;
		char Answer4 = InputValidation::ReadChar("n\t\t\t\t\tUpdate Client");
		if (tolower(Answer4 == 'y'))
			Permession += User::ePermession::UpdateClient;
		char Answer5 = InputValidation::ReadChar("n\t\t\t\t\tFind Client");
		if (tolower(Answer5) == 'y')
			Permession += User::ePermession::FindClient;
		char Answer6 = InputValidation::ReadChar("n\t\t\t\t\tTransaction Menue");
		if (tolower(Answer6) == 'y')
			Permession += User::ePermession::TransactionMenue;
		char Answer7 = InputValidation::ReadChar("n\t\t\t\t\tManage Users Menue");
		if (tolower(Answer7 == 'y'))
			Permession = +User::ePermession::ManageUsers;
		return Permession;

	}
protected:
	static void _DrawScreenHeader(string Title, string Subtitle = "")
	{
		cout << "\t\t\t\t\t====================================================" << endl;
		cout << "\t\t\t\t\t\t\t";
		cout << Title;
		if (Subtitle != "")
		{
			cout << "\n\n\t\t\t\t\t " << Subtitle;
		}
		cout << "\n\t\t\t\t\t====================================================";
	}
	static void _ReadClientInfo(BankClient& Client)
	{
		cout << "\n\t\t\t\t\tEnter FirstName :";
		Client.FirstName = InputValidation::ReadString();
		cout << "\n\t\t\t\t\tEnter LastName :";
		Client.LastName = InputValidation::ReadString();
		cout << "\n\t\t\t\t\tEnter Email: ";
		Client.Email = InputValidation::ReadString();
		cout << "\n\t\t\t\t\tEnter Phone: ";
		Client.Phone = InputValidation::ReadString();
		cout << "\n\t\t\t\t\tEnter PinCode: ";
		Client.PinCode = InputValidation::ReadString();
		cout << "\n\t\t\t\t\tEnter Account Balance: ";
		Client.AccountBalance = InputValidation::ReadFloat();
	}
	static void _PrintClientInfo(BankClient Client)
	{
		cout << "\n\t\t\t\t\tClient Card:";
		cout << "\n\t\t\t\t\t___________________";
		cout << "\n\t\t\t\t\tFirstName     : " << Client.FirstName;
		cout << "\n\t\t\t\t\tLastName      : " << Client.LastName;
		cout << "\n\t\t\t\t\tFull Name     : " << Client.FullName();
		cout << "\n\t\t\t\t\tEmail         : " << Client.Email;
		cout << "\n\t\t\t\t\tPhone         : " << Client.Phone;
		cout << "\n\t\t\t\t\tAccountNumber : " << Client.AccountNumber();
		cout << "\n\t\t\t\t\tPinCode       : " << Client.PinCode;
		cout << "\n\t\t\t\t\tBalance       : " << Client.AccountBalance;
		cout << "\n\t\t\t\t\t___________________\n";
	}
	static void _ReadUserInfo(User& user)
	{
		user.FirstName = InputValidation::ReadString("\n\t\t\t\t\tEnter  FirstName:");
		user.LastName = InputValidation::ReadString("\n\t\t\t\t\tEnter  LastName:");
		user.Email = InputValidation::ReadString("\n\t\t\t\t\tEnter  Email:");
		user.Phone = InputValidation::ReadString("\n\t\t\t\t\tEnter  Phone Number:");
		user.Password = InputValidation::ReadString("\n\t\t\t\t\tEnter  Password:");
		user.Permession = _ReadPermession();
	}
	static void _PrintUserInfo(User user)
	{
		cout << "\n\t\t\t\t\tUser Card:";
		cout << "\n\t\t\t\t\t___________________";
		cout << "\n\t\t\t\t\tFirstName     : " << user.FirstName;
		cout << "\n\t\t\t\t\tLastName      : " << user.LastName;
		cout << "\n\t\t\t\t\tFull Name     : " << user.FullName();
		cout << "\n\t\t\t\t\tEmail         : " << user.Email;
		cout << "\n\t\t\t\t\tPhone         : " << user.Phone;
		cout << "\n\t\t\t\t\tUser          : " << user.UserName;
		cout << "\n\t\t\t\t\tPassword      : " << user.Password;
		cout << "\n\t\t\t\t\tPermession    :" << user.Permession;
		cout << "\n\t\t\t\t\t___________________\n";

	}
};

