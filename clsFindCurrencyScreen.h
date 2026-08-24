#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;

class clsFindCurrencyScreen :protected clsScreen
{

	static void _ShowResult(clsCurrency Currency)
	{

		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}

		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
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

	static void ShowFindCurrencyScreen()
	{

		clsScreen::_DrawScreenHeader("\t Find Currency Screen");

		cout << "Find By: [1] Code or [2] Country? ";
		short Answer = 1;
		cin >> Answer;

		if (Answer == 1)
		{

			cout << "\nPlease Enter CurrencyCode: ";
			string CurrencyCode = clsInputValidate<string>::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResult(Currency);
		}

		else
		{

			cout << "\nPlease Enter Country Name: ";
			string CurrencyCode = clsInputValidate<string>::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(CurrencyCode);
			_ShowResult(Currency);
		}

	}

};