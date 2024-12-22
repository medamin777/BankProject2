#pragma once
#include <iostream>
#include "BankClient.h";
#include "Screen.h";
#include "InputValidation.h";
class FindClientScreen :protected Screen
{
public:
    static void ShowFindClient()
    {
        if (!(_AccesRights(User::ePermession::FindClient)))
        {
            return;
        }
        _DrawScreenHeader("Find Client Screen");
        string AccountNumber;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        AccountNumber = InputValidation::ReadString("\n\n\t\t\t\t\tPlease Enter Account Number: ");
        while (!BankClient::IsClientExist(AccountNumber))
        {
            cout << "\n\t\t\t\t\tAccount number is not found, choose another one: ";
            AccountNumber = InputValidation::ReadString();
        }

        BankClient Client1 = BankClient::Find(AccountNumber);

        if (!Client1.IsEmpty())
        {
            cout << "\n\t\t\t\t\tClient Found :-)\n";
        }
        else
        {
            cout << "\n\t\t\t\t\tClient Was not Found :-(\n";
        }

        _PrintClientInfo(Client1);

    }
};

