#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;

class clsListCurrenciesScreen :protected clsScreen
{


	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{

		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(40) << left << Currency.CurrencyName();
		cout << "| " << setw(12) << left << Currency.Rate();

	}

public:

	static void ShowListCurrenciesScreen()
	{
		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string Title = "\tCurrencies List Screen";
		string SubTitle = "\t  (" + to_string(vCurrencies.size()) + ") Currency(s).";

		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t______________________________________________________________";
		cout << "___________________________________________\n\n";

		cout << setw(8) << left << "" << "| " << setw(30) << left << "Country";
		cout << "| " << setw(8) << left << "code";
		cout << "| " << setw(40) << left << "Name";
		cout << "| " << setw(12) << left << "Rate/(1$)";
		cout << setw(8) << left << "\n\t______________________________________________________________";
		cout << "___________________________________________\n\n";

		if (vCurrencies.size() == 0)
			cout << "\t\t\t\tNo Currencies Available In the System!";
		else

		{
			for (clsCurrency Currency : vCurrencies)
			{
				_PrintCurrencyRecordLine(Currency);
				cout << endl;
			}
		}

		cout << setw(8) << left << "\n\t______________________________________________________________";
		cout << "___________________________________________\n\n";

	}

};