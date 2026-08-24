#pragma once
#include <iomanip>
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
using namespace std;

class clsListUsersScreen :protected clsScreen
{

private:

	static void _PrintUserRecordLine(clsUser User)
	{

		cout << setw(8) << left << "" << "| " << setw(12) << left << User.UserName;
		cout << "| " << setw(25) << left << User.FullName();
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permissions;

	}

public:

	static void ShowClientsList()
	{
		vector <clsUser> vUsers = clsUser::GetUsersList();

		string Title = "\tUsers List Screen";
		string SubTitle = "\t  (" + to_string(vUsers.size()) + ") User(s).";

		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t______________________________________________________________";
		cout << "___________________________________________\n\n";

		cout << setw(8) << left << "" << "| " << setw(12) << left << "User Name";
		cout << "| " << setw(25) << left << "full Name";
		cout << "| " << setw(12) << left << "Phone";
		cout << "| " << setw(20) << left << "Email";
		cout << "| " << setw(10) << left << "Password";
		cout << "| " << setw(12) << left << "Permissions";
		cout << setw(8) << left << "\n\t______________________________________________________________";
		cout << "___________________________________________\n\n";

		if (vUsers.size() == 0)
			cout << "\t\t\t\tNo Users Available In the System!";
		else

		{
			for (clsUser User : vUsers)
			{
				_PrintUserRecordLine(User);
				cout << endl;
			}
		}

		cout << setw(8) << left << "\n\t______________________________________________________________";
		cout << "___________________________________________\n\n";

	}

};