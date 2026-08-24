#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsTransfarLogScreen :protected clsScreen
{

	static void _PrintTransfarRegisterRecordLine(clsBankClient::stTransfarRegisterRecord& TransfarRegisterRecord)
	{

		cout << setw(8) << left << "" << "| " << setw(30) << left << TransfarRegisterRecord.Date_Time;
		cout << "| " << setw(8) << left << TransfarRegisterRecord.s_Acct;
		cout << "| " << setw(8) << left << TransfarRegisterRecord.d_Acct;
		cout << "| " << setw(8) << left << TransfarRegisterRecord.Amount;
		cout << "| " << setw(10) << left << TransfarRegisterRecord.s_Balance;
		cout << "| " << setw(10) << left << TransfarRegisterRecord.d_Balance;
		cout << "| " << setw(8) << left << TransfarRegisterRecord.UserName;

	}

public:

	static void ShowTransfarLogScreen()
	{

		vector <clsBankClient::stTransfarRegisterRecord> vTransfarRegisterRecords = clsBankClient::GetTransfarRegisterRecord();

		string Title = "\tTransfar Log List Screen";
		string SubTitle = "\t   (" + to_string(vTransfarRegisterRecords.size()) + ") Record(s).";

		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t______________________________________________________________";
		cout << "___________________________________________\n\n";

		cout << setw(8) << left << "" << "| " << setw(30) << left << "Date/Time";
		cout << "| " << setw(8) << left << "s.Acct";
		cout << "| " << setw(8) << left << "d.Acct";
		cout << "| " << setw(8) << left << "Amount";
		cout << "| " << setw(10) << left << "s.Balance";
		cout << "| " << setw(10) << left << "d.Balance";
		cout << "| " << setw(8) << left << "User";
		cout << setw(8) << left << "\n\t______________________________________________________________";
		cout << "___________________________________________\n\n";

		if (vTransfarRegisterRecords.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

		{
			for (clsBankClient::stTransfarRegisterRecord TransfarRegisterRecord : vTransfarRegisterRecords)
			{
				_PrintTransfarRegisterRecordLine(TransfarRegisterRecord);
				cout << endl;
			}
		}

		cout << setw(8) << left << "\n\t______________________________________________________________";
		cout << "___________________________________________\n\n";

	}
};