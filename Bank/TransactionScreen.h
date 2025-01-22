#pragma once
#include <iostream>
#include "BankClient.h"
#include "Screen.h"
#include "MainScreen.h"
#include "InputValidation.h"
#include "DepositeScreen.h"
#include "WithdrawScrenn.h"
#include "TotalBalancesScreen.h"
#include "TransferScreen.h"
#include "TransferLogScreen.h"
using namespace std;
class TransactionScreen :protected Screen
{
private:
	enum TransactionOption { Depostie = 1, Withdraw = 2, TotalBalance = 3,Transfert = 4,TransferLog=5,MainMenue=6 };
	static short _ReadTransactionMenue()
	{
		short choice = 0;
		choice = InputValidation::readintegerNumberBetween(1, 6, "\n\t\t\t\t\tChoose what do you want to do ? [1 to 6]");
		return choice;
	}
	static void _GoBackToTransactionMenue()
	{
		std::cout << setw(37) << left << "" << "\nPress any key to go back to Main Menue....\n";
		system("pause>0");
		ShowTransactionMenue();
	}
	static void _ShowDpositeScreen()
	{
		system("cls");
		DepositeScreen::ShowDepositeScreen();

		_GoBackToTransactionMenue();
	}
	static void _ShowWithdrawScreen()
	{
		system("cls");
		WithdrawScrenn::ShowWithdrawScreen();
		_GoBackToTransactionMenue();
	}
	static void _ShowTotalBalanceScreen()
	{
		system("cls");
		TotalBalancesScreen::ShowTotalBalances();
		_GoBackToTransactionMenue();
	}
	
	static void _ShowTransferScreen()
	{
		system("cls");
		TransferScreen::ShowTransfer();
		_GoBackToTransactionMenue();
	}
	static void _ShowTransferLogScreen()
	{
		system("cls");
		TransferLogScreen::ShowTransferLog();
		_GoBackToTransactionMenue();

	}
	static void _ShowMainMenueScreen()
	{
		
	}
	static void _PerformTransactionMenue(TransactionOption Choice)
	{
		switch (Choice)
		{
		case TransactionOption::Depostie:
			_ShowDpositeScreen();
			break;
		case TransactionOption::Withdraw:
			_ShowWithdrawScreen();
			break;
		case TransactionOption::MainMenue:
			_ShowMainMenueScreen();
			break;
		case TransactionOption::TotalBalance:
			_ShowTotalBalanceScreen();
				break;
		case TransactionOption::Transfert:
			_ShowTransferScreen();
			break;
	
		case TransactionOption::TransferLog:
			_ShowTransferLogScreen();
			break;
			
		}
	}
public:
	static void ShowTransactionMenue()
	{
		system("cls");
		if (!(_AccesRights(User::ePermession::TransactionMenue)))
		{
			return;
		}
		_DrawScreenHeader("Transaction Screen");
		cout << "\n\n\t\t\t\t\t========================================\n";
		cout << "\t\t\t\t\t\t\tTransaction Main Menue";
		cout << "\n\t\t\t\t\t========================================";
		cout << "\n\t\t\t\t\t[1] Deposite";
		cout << "\n\t\t\t\t\t[2] Withdraw";
		cout << "\n\t\t\t\t\t[3] Totale Balances";
		cout << "\n\t\t\t\t\t[4] Transfer";
		cout << "\n\t\t\t\t\t[5] Transfer Log";
		cout << "\n\t\t\t\t\t[6] Main Menue";
		cout << "\n\t\t\t\t\t========================================";
		_PerformTransactionMenue(TransactionOption(_ReadTransactionMenue()));
	}
};
