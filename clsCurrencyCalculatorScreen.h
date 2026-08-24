#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

class clsCurrencyCalculatorScreen :protected clsScreen
{

	static float _ReadAmount()
	{
		float Amount = 0;

		cout << "\nEnter Amount to Exchange: ";
		cin >> Amount;
		return Amount;
	}

	static clsCurrency GetCurrency(string Title)
	{
		cout << Title;
		string CurrencyCode = clsInputValidate<string>::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{

			cout << "\nCurrency is not found,choose another one: ";
			CurrencyCode = clsInputValidate<string>::ReadString();
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;
	}

	static void _PrintCurrencyCard(clsCurrency Currency, string Title)
	{
		cout << Title;
		cout << "\n___________________";
		cout << "\nCountry  : " << Currency.Country();
		cout << "\nCode     : " << Currency.CurrencyCode();
		cout << "\nName     : " << Currency.CurrencyName();
		cout << "\nRate(1$) = " << Currency.Rate();
		cout << "\n___________________\n";

	}

	static void _PrintCurrencyCalculationsResult(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
	{

		_PrintCurrencyCard(CurrencyFrom, "\nConvert From:");

		float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);

		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = "
			<< AmountInUSD << " USD\n";

		if (CurrencyTo.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting From USD to:";
		_PrintCurrencyCard(CurrencyTo, "\nTo:");

		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = "
			<< CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo) << " " << CurrencyTo.CurrencyCode();
	}

public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'y';

		while (Continue == 'y' || Continue == 'Y')
		{
			system("cls");
			clsScreen::_DrawScreenHeader("\t Currency Calculator Screen");

			clsCurrency CurrencyFrom = GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency CurrencyTo = GetCurrency("\nPlease Enter Currency2 Code: ");
			float Amount = _ReadAmount();

			_PrintCurrencyCalculationsResult(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo you want to perform another calculation? y/n ?";
			cin >> Continue;

		}


	}

};