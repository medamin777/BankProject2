#pragma once
#include <iostream>
#include <iomanip>
#include "Screen.h";
#include "BankClient.h";
using namespace std;
class ShowClientScreen : protected Screen
{
private:
	static void PrintClientREcordLine(BankClient Client)
	{
		cout << "|" << setw(15) << left << Client.AccountNumber();
		cout << "|" << setw(20) << left << Client.FullName();
		cout << "|" << setw(12) << left << Client.Phone;
		cout << "|" << setw(30) << left << Client.Email;
		cout << "|" << setw(10) << left << Client.PinCode;
		cout << "|" << setw(12) << left << Client.AccountBalance;
	}
public:
	static void ShowClientList()
	{
		if (!(_AccesRights(User::ePermession::ClientList)))
		{
			return;
		}
		vector<BankClient> Clients = BankClient::GetClientLists();
		string Title = "Client List Screen";
		string SubTitle = "\t\t(" + to_string(Clients.size()) + ") Client(s)";
		_DrawScreenHeader(Title, SubTitle);
		cout << "\n___________________________________________________________";
		cout << "______________________________________________________________\n" << endl;
		cout << "|" << left << setw(15) << "Account Number";
		cout << "|" << left << setw(20) << "Client Name";
		cout << "|" << left << setw(12) << "Phone";
		cout << "|" << left << setw(30) << "Email";
		cout << "|" << left << setw(10) << "Pin Code";
		cout << "|" << left << setw(12) << "Account Balance";
		cout << "\n___________________________________________________________";
		cout << "______________________________________________________________\n" << endl;
		if (Clients.size() == 0)
			cout << "\t\t\t\tNo Clients Available in the System!";
		else
		{
			for (BankClient client : Clients)
			{
				PrintClientREcordLine(client);
				cout << endl;
			}

		}
		cout << "\n___________________________________________________________";
		cout << "______________________________________________________________\n" << endl;
	}

};



