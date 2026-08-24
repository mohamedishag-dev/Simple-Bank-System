#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsDeleteUserScreen :protected clsScreen
{
private:

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

	static void ShowDeleteUserScreen()
	{
		clsScreen::_DrawScreenHeader("\t Delete User Screen");


		string UserName = "";

		cout << "\nPlease Enter UserName: ";
		UserName = clsInputValidate<string>::ReadString();

		while (!clsUser::IsUserExist(UserName))

		{
			cout << "\nUserName is not found, choose another one: ";
			UserName = clsInputValidate<string>::ReadString();
		}

		clsUser DeleteUser = clsUser::Find(UserName);
		_PrintUser(DeleteUser);

		char Answer = 'n';

		cout << "\nAre you sure you want delete this User? y/n ? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (DeleteUser.Delete())
			{
				cout << "\nUser Deleted Successfully.";
				_PrintUser(DeleteUser);

			}
			else
			{
				cout << "\n\nError User was not Deleted\n";
			}
		}
	}

};