#pragma once

#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;

class clsUpdateCurrencyRateScreen :protected clsScreen
{

	static float _ReadRate()
	{
		float Amount = 0;

		cout << "\nEnter New Rate: ";
		cin >> Amount;
		return Amount;
	}

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n___________________";
		cout << "\nCountry  : " << Currency.Country();
		cout << "\nCode     : " << Currency.CurrencyCode();
		cout << "\nName     : " << Currency.CurrencyName();
		cout << "\nRate(1$) = " << Currency.Rate();
		cout << "\n___________________\n";

	}

public:

	static void ShowUpdateCurrencyRateScreen()
	{

		clsScreen::_DrawScreenHeader("\t Update Currency Screen");

		string CurrencyCode = "";

		cout << "\nPlease Enter CurrencyCode: ";
		CurrencyCode = clsInputValidate<string>::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{

			cout << "\nCurrency is not found,choose another one: ";
			CurrencyCode = clsInputValidate<string>::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);

		cout << "\n\nAre you sure you want update the rate of this Currency? y/n ? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			cout << "\nCurrency Card:";
			cout << "\n___________________\n";

			Currency.UpdateRate(_ReadRate());

			cout << "\nCurrency Rate Update Successfully :-)\n";
			_PrintCurrency(Currency);

		}


	}

};