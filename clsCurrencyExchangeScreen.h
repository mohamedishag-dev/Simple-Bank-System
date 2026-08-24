#pragma once
#include <iomanip>
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsFindCurrencyScreen.h"
#include "clsListCurrenciesScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std;

class clsCurrencyExchangeScreen :protected clsScreen
{

	enum enCurrencyExchangeOptions { eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrency = 3, eCurrencyCalculator = 4, eExit = 5 };

	static void _ShowMainMenue()
	{


	}

	static void _ShowFindCurrencyScreen()
	{
		// cout << "\nFind Currencies Screen Will be here...\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyRateScreen()
	{
		//cout << "\nUpdate Currencies Screen Will be here...\n";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowListCurrenciesScreen()
	{
		//cout << "\nList Currencies Screen Will be here...\n";
		clsListCurrenciesScreen::ShowListCurrenciesScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\nCurrency Calculator Screen Will be here...\n";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static short _ReadCurrencyExchangeOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";

		short Choice = clsInputValidate<short>::ReadNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}

	static void _GoBackToCurrencyExchangeMenue()
	{
		cout << "\nPress any key to go back to Currency Exchange Menue...";
		system("pause>0");
		ShowCurrencyExchangeScreen();
	}

	static void _PerfromenCurrencyExchangeMenueOption(enCurrencyExchangeOptions CurrencyExchangeOption)
	{
		switch (CurrencyExchangeOption)
		{
		case enCurrencyExchangeOptions::eListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}
		case enCurrencyExchangeOptions::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}

		case enCurrencyExchangeOptions::eUpdateCurrency:
		{
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}

		case enCurrencyExchangeOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenue();
			break;
		}

		case enCurrencyExchangeOptions::eExit:
		{
			system("cls");
			_ShowMainMenue();
			break;
		}

		}

	}

public:

	static void ShowCurrencyExchangeScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pShowCurrencyExchange))
		{
			return;
		}

		system("cls");
		clsScreen::_DrawScreenHeader("\t Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerfromenCurrencyExchangeMenueOption((enCurrencyExchangeOptions)_ReadCurrencyExchangeOption());

	}

};