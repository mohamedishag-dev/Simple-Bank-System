#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsFindUserScreen.h"
#include "clsListUsersScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"

using namespace std;

class clsManageUsersScreen :protected clsScreen
{
private:

    enum enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static short ReadManageUsersMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";

        short Choice = clsInputValidate<short>::ReadNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static void _ShowListUsersScreen()
    {
        // cout << "\nUsers List Screen Will be here...\n";
        clsListUsersScreen::ShowClientsList();
    }

    static void _ShowAddNewUserScreen()
    {
        // cout << "\nAdd New User Screen Will be here...\n";
        clsAddNewUserScreen::ShowAddNewUsersScreen();
    }

    static void _ShowDeleteUserScreen()
    {
        //  cout << "\nDelete User Screen Will be here...\n";
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        //cout << "\nUpdate User Screen Will be here...\n";
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        // cout << "\nFind User Screen Will be here...\n";
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _ShowMainMenue()
    {


    }

    static void _GoBackToManageUsersMenue()
    {
        cout << "\nPress any key to go back to Main Menue...";
        system("pause>0");
        ShowManageUsersMenue();
    }

    static void PerfromManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
    {
        switch (ManageUsersMenueOption)
        {
        case enManageUsersMenueOptions::eListUsers:
        {
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eFindUser:
        {
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;
        }

        case enManageUsersMenueOptions::eMainMenue:
        {
            _ShowMainMenue();
        }
        }

    }

public:

    static void ShowManageUsersMenue()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;
        }

        system("cls");
        clsScreen::_DrawScreenHeader("\t Manage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tManage Users Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Users.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Users.\n";
        cout << setw(37) << left << "" << "\t[4] Update Users.\n";
        cout << setw(37) << left << "" << "\t[5] Find Users.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        PerfromManageUsersMenueOption((enManageUsersMenueOptions)ReadManageUsersMenueOption());
    }

};