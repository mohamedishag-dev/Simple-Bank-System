
#pragma once
#include <iomanip>
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateUserScreen :protected clsScreen
{
private:

	static int ReadPermissionsToSet()
	{

		int Permissions = 0;
		char Answer = 'n';


		cout << "\nDo you want to give full access? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}

		cout << "\nDo you want to give access to : \n ";

		cout << "\nShow Client List? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClients;
		}

		cout << "\nFind Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTranactions;
		}

		cout << "\nManage Users? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		cout << "\nShow Login Register? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pShowLoginRegister;
		}

		cout << "\nShow Currency Exchange? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pShowCurrencyExchange;
		}

		return Permissions;

	}

	static clsUser _ReadUserInfo(clsUser& User)
	{

		cout << "\nEnter First Name? ";
		User.FirstName = clsInputValidate<string>::ReadString();

		cout << "\nEnter Last Name? ";
		User.LastName = clsInputValidate<string>::ReadString();

		cout << "\nEnter Email? ";
		User.Email = clsInputValidate<string>::ReadString();

		cout << "\nEnter Phone? ";
		User.Phone = clsInputValidate<string>::ReadString();

		cout << "\nEnter Password? ";
		User.Password = clsInputValidate<string>::ReadString();

		cout << "\nEnter Permissions? ";
		User.Permissions = ReadPermissionsToSet();

		return User;
	}

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName  : " << User.FirstName;
		cout << "\nLastName   : " << User.LastName;
		cout << "\nFull Name  : " << User.FullName();
		cout << "\nEmail      : " << User.Email;
		cout << "\nPhone      : " << User.Phone;
		cout << "\nUserName   : " << User.UserName;
		cout << "\nPassword   : " << User.Password;
		cout << "\nPermissions: " << User.Permissions;
		cout << "\n___________________\n";

	}

public:

	static void ShowUpdateUserScreen()
	{
		clsScreen::_DrawScreenHeader("\t Update User Screen");

		string Username = "";

		cout << "Enter Username? ";
		Username = clsInputValidate<string>::ReadString();

		while (!clsUser::IsUserExist(Username))

		{
			cout << "\nUsername is not found, choose another one: ";
			Username = clsInputValidate<string>::ReadString();
		}

		clsUser User1 = clsUser::Find(Username);
		_PrintUser(User1);

		cout << "\nUpdate User:";
		cout << "\n___________________";
		_ReadUserInfo(User1);

		clsUser::enSaveResults SaveResult;
		SaveResult = User1.Save();

		switch (SaveResult)
		{
		case clsUser::enSaveResults::svSucceeded:
		{

			cout << "\nAccount Update Successfully :-)\n";
			_PrintUser(User1);
			break;
		}
		case clsUser::enSaveResults::svFaildEmptyObject:
		{

			cout << "\nError account was not saved because is's Empty.\n";
			break;
		}
		}


	}

};