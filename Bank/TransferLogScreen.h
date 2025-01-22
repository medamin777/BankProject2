#pragma once
#include "Screen.h"
#include <vector>
class TransferLogScreen :public Screen
{
private:
	void static _PrintTransferLogLine(BankClient::TransferLog transferlog)
	{
		cout << "|" << setw(20) << left << transferlog.date;
		cout << "|" << setw(20) << left << transferlog.SourceAccount;
		cout << "|" << setw(20) << left << transferlog.DestinationAccount;
		cout << "|" << setw(10) << left << transferlog.Amount;
		cout << "|" << setw(20) << left << transferlog.SourceBalance;
		cout << "|" << setw(20) << left << transferlog.DestinationBalance;
		cout << "|" << setw(20) << left << transferlog.UserName;
	}





public:
	static void ShowTransferLog()
	{
		vector<BankClient::TransferLog> transferlogs = BankClient::getAllTransfer("TransferLog.txt");
		string Title = "Transfer Log Screen";
		string SubTitle = "\t\t(" + to_string(transferlogs.size()) + ") Record(s)";
		_DrawScreenHeader(Title, SubTitle);
		cout << "\n___________________________________________________________";
		cout << "___________________________________________________________________\n" << endl;
		cout << "|" << left << setw(20) << "Date/Time";
		cout << "|" << left << setw(20) << "Source Account";
		cout << "|" << left << setw(20) << "Destination Account";
		cout << "|" << left << setw(10) << "Amount";
		cout << "|" << left << setw(20) << "Balance Source";
		cout << "|" << left << setw(20) << "Balance Destination";
		cout << "|" << left << setw(20) << "User Name";
		cout << "\n___________________________________________________________";
		cout << "___________________________________________________________________\n" << endl;
		if (!transferlogs.size())
		{
			cout << "\t\t\t\t\tNo Transfer Log in System";
			return;
		}
		for (BankClient::TransferLog transferlog : transferlogs)
		{
			_PrintTransferLogLine(transferlog);
		}
		cout << "\n___________________________________________________________";
		cout << "___________________________________________________________________\n" << endl;
	}
		

	
	
	
};