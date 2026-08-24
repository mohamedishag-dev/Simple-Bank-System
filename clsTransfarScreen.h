#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsTransfarScreen :protected clsScreen
{

    static clsBankClient _GetClient()
    {
        string AccountNumber = "";

        cout << "\nPlease Enter Account Number to Transfar 1 From: ";
        AccountNumber = clsInputValidate<string>::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))

        {
            cout << "\nAccount Number with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = clsInputValidate<string>::ReadString();
        }

        return clsBankClient::Find(AccountNumber);
    }

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

public:

    static void ShowTransfarScreen()
    {
        system("cls");
        clsScreen::_DrawScreenHeader("\t Transfar Screen");

        clsBankClient SourceClient = _GetClient();
        _PrintClient(SourceClient);

        clsBankClient DestinationClient = _GetClient();
        _PrintClient(DestinationClient);


        double Amount = 0;
        cout << "\nEnter Transfar amount? ";
        cin >> Amount;

        while (Amount > SourceClient.AccountBalance)
        {
            cout << "\nAmount Exceeds the available balance!, Enter another amount: ";
            cin >> Amount;
        }

        char Answer = 'n';
        cout << "\n\nAre you sure you want perfrom this operation? y/n ? ";
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (SourceClient.Transfar(Amount, DestinationClient))
            {
                cout << "\n\nTransfar done Successfully.\n";
            }
            else
            {
                cout << "\nTransfar Faild!\n";
            }
        }

        _PrintClient(SourceClient);
        _PrintClient(DestinationClient);

    }

};