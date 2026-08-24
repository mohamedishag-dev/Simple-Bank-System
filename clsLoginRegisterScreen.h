#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsString.h"
#include "clsUser.h"
using namespace std;

class clsLoginRegisterScreen :protected clsScreen
{


private:

	static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord& LoginRegisterRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(40) << left << LoginRegisterRecord.Date_Time;
		cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
		cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
		cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;

	}

public:


	static void ShowLoginRegisterScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pShowLoginRegister))
		{
			return;
		}

		vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterRecord();

		string Title = "\t Login Register List Screen";
		string SubTitle = "\t\t  (" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t______________________________________________________________";
		cout << "___________________________________________\n\n";

		cout << setw(8) << left << "" << "| " << setw(40) << left << "Dtae/Time";
		cout << "| " << setw(20) << left << "UserName";
		cout << "| " << setw(20) << left << "Password";
		cout << "| " << setw(12) << left << "Permissions";
		cout << setw(8) << left << "\n\t______________________________________________________________";
		cout << "___________________________________________\n\n";

		if (vLoginRegisterRecord.size() == 0)
			cout << "\t\t\t\tNo Logins Available In the System!";
		else

		{
			for (clsUser::stLoginRegisterRecord LoginRegisterRecord : vLoginRegisterRecord)
			{
				_PrintLoginRegisterRecordLine(LoginRegisterRecord);
				cout << endl;
			}
		}

		cout << setw(8) << left << "\n\t______________________________________________________________";
		cout << "___________________________________________\n\n";

	}

};