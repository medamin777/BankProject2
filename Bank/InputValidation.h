#pragma once
#include <iostream>
#include "Date.h"
using namespace std;
class InputValidation
{
public:
	static bool IsNumberBetween(int number, int number1, int number2)
	{
		return number >= number2 && number <= number1;
	}
	static bool IsNumberBetween(float number, float number1, float number2)
	{
		return number >= number2 && number <= number1;
	}
	static bool isDateBetween(date Date, date dateFrom, date dateTo)
	{
		if (dateFrom.CompareDates(dateTo) == date::After)
			date::SwapDates(dateFrom, dateTo);

		if (Date.CompareDates(dateFrom) == date::Before
			||
			Date.CompareDates(dateTo) == date::After
			)
			return false;

		return true;
	}
	static int readintegerNumber(string message)
	{
		int number = 0;
		cin >> number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << message << endl;
			cin >> number;
		}
		return number;
	}
	static int readintegerNumberBetween(int Number1, int Number2)
	{
		int number = 0;
		cin >> number;
		while (cin.fail() || (number<Number1 || number>Number2))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> number;
		}
		return number;
	}
	static int readintegerNumberBetween(int Number1, int Number2, string Message)
	{
		int number = 0;
		cout << Message;
		cin >> number;
		while (cin.fail() || (number<Number1 || number>Number2))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Message;
			cin >> number;
		}
		return number;
	}
	static string ReadString()
	{
		string mystring = "";
		getline(cin, mystring);
		return mystring;
	}
	static string ReadString(string Message)
	{
		cout << Message;
		string mystring = "";
		getline(cin, mystring);
		cin.ignore();
		return mystring;
	}
	static char ReadChar(string message)
	{
		cout << message;
		char Char;
		cin >> Char;
		cin.ignore();
		return Char;
	}
	static float ReadFloat(string message)
	{

		float Number = 0;
		cout << message;
		cin >> Number;
		return Number;
	}
	static float ReadFloat()
	{
		float Number = 0;
		cin >> Number;
		return Number;

	}
	static double readDoubleNumberBetween(double from, double to, string message)
	{
		double number = 0;


		while (number < from || number > to)
		{
			cout << message << endl;
			cin >> number;
		}

		return number;
	}


	static bool isValidDate(date Date)
	{
		return date::IsValidDate(Date);
	}


};

