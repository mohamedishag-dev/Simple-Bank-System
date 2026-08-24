#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsInputValidate.h"
#include "clsTotalBalances.h"
#include "clsDepositScreen.h"
#include "clsTransfarScreen.h"
#include "clsWithDrawScreen.h"
#include "clsTransfarLogScreen.h"

using namespace std;

class clsTransactionsScreen :protected clsScreen
{
private:

    enum enTransactionsMenueOptions { eDeposit = 1, eWithdraw = 2, eShowTotalBalance = 3, eTransfar = 4, eTransfarLog = 5, eShowMainMenue = 6 };

    static short _ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";

        short Choice = clsInputValidate<short>::ReadNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _ShowDepositScreen()
    {
        // cout << "\nDeposit Screen Will be here...\n";
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithDrawScreen()
    {
        // cout << "\nWithDraw Screen Will be here...\n";
        clsWithDrawScreen::ShowWithDrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        // cout << "\nTotal Balances Screen Will be here...\n";
        clsTotalBalances::ShowTotalBalances();
    }

    static void _ShowTransfarScreen()
    {
        // cout << "\nTransfar Screen Will be here...\n";
        clsTransfarScreen::ShowTransfarScreen();
    }

    static void _ShowTransfarLogScreen()
    {
        // cout << "\nTransfar Log Screen Will be here...\n";
        clsTransfarLogScreen::ShowTransfarLogScreen();
    }

    static void _ShowMainMenue()
    {
        // cout << "\nMain Menue Screen Will be here...\n";

    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionsMenue();
    }

    static void PerfromTranactionsMenueOption(enTransactionsMenueOptions TransactionMenueOption)
    {
        switch (TransactionMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithDrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eTransfar:
        {
            system("cls");
            _ShowTransfarScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eTransfarLog:
        {
            system("cls");
            _ShowTransfarLogScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowMainMenue:
        {

            _ShowMainMenue();

        }
        }

    }

public:

    static void ShowTransactionsMenue()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return;
        }

        system("cls");
        clsScreen::_DrawScreenHeader("\t Transactions Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tTransactions Menue Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfar.\n";
        cout << setw(37) << left << "" << "\t[5] Transfar Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        PerfromTranactionsMenueOption((enTransactionsMenueOptions)_ReadTransactionsMenueOption());
    }

};