#pragma once
#include <iostream>
#include "Person.h"
#include <string>
#include "String.h"
#include <vector>
#include <fstream>
using namespace std;
class BankClient :public Person
{
private:
	enum Mode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	Mode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool MarkForDelete = false;
	static BankClient _ConvertLinetoClientObject(string Line, string separator = "#//#")
	{
		vector<string> ClientData = String::Split(Line, separator);
		return BankClient(Mode::UpdateMode, ClientData[0], ClientData[1], ClientData[2], ClientData[3], ClientData[4], ClientData[5], stof(ClientData[6]));
	}
	static string _ConvertClientObjecttoLine(BankClient Client, string Sep = "#//#")
	{
		string Line = "";
		Line += Client.FirstName + Sep;
		Line += Client.LastName + Sep;
		Line += Client.Email + Sep;
		Line += Client.Phone + Sep;
		Line += Client.AccountNumber() + Sep;
		Line += Client.PinCode + Sep;
		Line += to_string(Client.AccountBalance);
		return Line;
	}
	static BankClient _GetEmptyClientObject()
	{
		return BankClient(Mode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static vector<BankClient> _LoadClientsDataFromFile()
	{
		fstream Myfile;
		vector<BankClient> Clients;
		Myfile.open("Clients.txt", ios::in);
		if (Myfile.is_open())
		{
			string Line = "";
			while (getline(Myfile, Line))
			{
				BankClient Client = _ConvertLinetoClientObject(Line);
				Clients.push_back(Client);
			}
			Myfile.close();
		}
		return Clients;
	}
	static void _SaveClientsDataToFile(vector<BankClient> Clients)
	{
		fstream Myfile;
		Myfile.open("Clients.txt", ios::out);
		if (Myfile.is_open())
		{
			for (BankClient client : Clients)
			{
				if (client.MarkForDelete == false)
				{
					Myfile << _ConvertClientObjecttoLine(client) << endl;
				}
			}
			Myfile.close();
		}
	}
	void _Update()
	{
		vector<BankClient> Clients = _LoadClientsDataFromFile();
		for (BankClient& Client : Clients)
		{
			if (Client.AccountNumber() == AccountNumber())
			{
				Client = *this;
				break;
			}
		}
		_SaveClientsDataToFile(Clients);
	}
	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjecttoLine(*this));
	}
	void _AddDataLineToFile(string DataLine)
	{
		fstream Myfile;
		Myfile.open("Clients.txt", ios::out | ios::app);
		if (Myfile.is_open())
		{
			Myfile << DataLine << endl;
			Myfile.close();
		}
	}
public:
	BankClient(Mode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) : Person(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_AccountBalance = AccountBalance;
		_PinCode = PinCode;
	}
	bool IsEmpty()
	{
		return (_Mode == Mode::EmptyMode);
	}
	string AccountNumber()
	{
		return _AccountNumber;
	}
	static bool IsClientExist(string AccountNumber)
	{
		return (!BankClient::Find(AccountNumber).IsEmpty());
	}
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property (get = GetPinCode, put = SetPinCode)) string PinCode;
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(put = SetAccountBalance, get = GetAccountBalance)) float AccountBalance;
	static BankClient Find(string AccountNumber)
	{
		fstream Myfile;
		Myfile.open("Clients.txt", ios::in);  // read only 
		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line))
			{
				BankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					Myfile.close();
					return Client;
				}
			}
			Myfile.close();
		}
		return _GetEmptyClientObject();
	}
	static BankClient Find(string AccountNumber, string PinCode)
	{
		fstream Myfile;
		Myfile.open("Clients.txt", ios::in);
		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line))
			{
				BankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					Myfile.close();
					return Client;
				}
			}
			Myfile.close();
		}
		return _GetEmptyClientObject();
	}
	enum SaveResults { svFaild = 0, svSucceeded = 1 };
	SaveResults Save()
	{
		switch (_Mode)
		{
		case Mode::EmptyMode:
			return SaveResults::svFaild;
		case Mode::UpdateMode:
			_Update();
			return SaveResults::svSucceeded;
		case Mode::AddNewMode:
			_AddNew();
			_Mode = Mode::UpdateMode;
			return SaveResults::svSucceeded;
		default:
			break;
		}
	}
	void Deposite(float Amount)
	{
		AccountBalance += Amount;
		Save();
	}
	bool Withdraw(float Amount)
	{
		if (Amount <= AccountBalance)
		{
			AccountBalance -= Amount;
			Save();
			return true;
		}
		return false;
	}
	static BankClient GetAddNewClient(string AccountNumber)
	{
		return BankClient(Mode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	bool Delete()
	{
		vector<BankClient> Clients = _LoadClientsDataFromFile();
		for (BankClient& client : Clients)
		{
			if (client.AccountNumber() == this->_AccountNumber)
			{
				client.MarkForDelete = true;
			}
		}
		_SaveClientsDataToFile(Clients);
		*this = _GetEmptyClientObject();
		return true;
	}
	static vector<BankClient> GetClientLists()
	{
		return _LoadClientsDataFromFile();
	}
	static float GetTotalBalances()
	{
		vector<BankClient> clients = _LoadClientsDataFromFile();
		float TotalBalance = 0;
		for (BankClient client : clients)
		{
			TotalBalance += client.AccountBalance;
		}
		return TotalBalance;
	}
};

