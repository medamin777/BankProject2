#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include "String.h"
#include <string>
using namespace std;
class date {
private:
	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;
public:
	date()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}
	date(string sDate)
	{
		vector<string> vDate;
		vDate = String::Split(sDate, "/");
		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}
	date(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}
	date(short DateOrderInYear, short Year)
	{
		date Date1(DateOrderInYear, Year);
		_Day = Date1._Day;
		_Month = Date1._Month;
		_Year = Date1._Year;
	}
	void SetDay(short Day)
	{
		_Day = Day;
	}
	short GetDay()
	{
		return _Day;
	}
	_declspec(property(put = SetDay, get = GetDay)) short Day;
	void SetMonth(short Month)
	{
		_Month = Month;
	}
	short GetMonth()
	{
		return _Month;
	}
	__declspec(property (get = GetMonth, put = SetMonth)) short Month;
	void SetYear(short Year)
	{
		_Year = Year;
	}
	short GetYear()
	{
		return _Year;
	}
	__declspec(property (get = GetYear, put = SetYear)) short Year;
	static string DateToString(date date)
	{
		return to_string(date.Day) + "/" + to_string(date.Month) + "/" + to_string(date.Year);
	}
	string DateToString()
	{
		return DateToString(*this);
	}
	static date GetSystemDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		short Day, Month, Year;
		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		return date(Day, Month, Year);
	}
	static string GetSystemAll()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		short Day, Mounth, Year, Hour, Minutes, Seconds;
		Year = now->tm_year + 1900;
		Mounth = now->tm_mon;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minutes = now->tm_min;
		Seconds = now->tm_sec;
		return to_string(Day) + "/" + to_string(Mounth) + "/" + to_string(Year) + "-" + to_string(Hour) + ":" + to_string(Minutes) + ":" + to_string(Seconds);

		
	}
	static bool IsValidDate(date date)
	{

		if (date.Day < 1 || date.Day>31)
			return false;

		if (date.Month < 1 || date.Month>12)
			return false;

		if (date.Month == 2)
		{
			if (isLeapYear(date.Year))
			{
				if (date.Day > 29)
					return false;
			}
			else
			{
				if (date.Day > 28)
					return false;
			}
		}

		short DaysInMonth = NumberOfDaysInMonth(date.Month, date.Year);

		if (date.Day > DaysInMonth)
			return false;

		return true;

	}
	static bool isLeapYear(short Year)
	{
		return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
	}
	bool isLeapYear()
	{
		return isLeapYear(this->Year);
	}
	static short NumberOfDaysInYear(short Year)
	{
		return isLeapYear(Year) ? 365 : 364;
	}
	short NumberOfDaysInYear()
	{
		return NumberOfDaysInYear(_Year);
	}
	static short NumberOfHoursInYear(short Year)
	{
		return  NumberOfDaysInYear(Year) * 24;
	}

	short NumberOfHoursInYear()
	{
		return  NumberOfHoursInYear(_Year);
	}
	static int NumberOfMinutesInYear(short Year)
	{
		return  NumberOfHoursInYear(Year) * 60;
	}
	int NumberOfMinutesInYear()
	{
		return  NumberOfMinutesInYear(_Year);
	}
	static int NumberOfSecondsInYear(short Year)
	{
		return  NumberOfMinutesInYear(Year) * 60;
	}
	int NumberOfSecondsInYear()
	{
		return  NumberOfSecondsInYear();
	}
	static short NumberOfDaysInMonth(short Month, short Year)
	{

		if (Month < 1 || Month>12)
			return  0;

		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : days[Month - 1];

	}
	short NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(_Month, _Year);
	}
	static short NumberOfHoursInMonth(short Month, short Day)
	{
		return NumberOfDaysInMonth(Month, Day) * 24;
	}
	short NumberOfHoursInMonth()
	{
		return NumberOfHoursInMonth(_Month, _Year);
	}
	static short NumberOfMinutesInMonth(short Month, short Year)
	{
		return NumberOfHoursInMonth(Month, Year) * 60;
	}
	short NumberOfMinutesInMonth()
	{
		return NumberOfMinutesInMonth(_Month, _Year);
	}
	static short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	short DaysOfWeekOrder()
	{
		return DayOfWeekOrder(_Day, _Month, _Year);
	}
	static string DayShortName(short DayOfWeekOrder)
	{
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayNames[DayOfWeekOrder - 1];
	}
	string DayShortName()
	{
		string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayNames[DayOfWeekOrder(_Day, _Month, _Year) - 1];
	}
	static string MonthShortName(short MonthNumber)
	{
		string Months[12] = { "Jan", "Feb", "Mar",
						   "Apr", "May", "Jun",
						   "Jul", "Aug", "Sep",
						   "Oct", "Nov", "Dec"
		};
		return (Months[MonthNumber - 1]);

	}
	string MonthShortName()
	{
		return MonthShortName(_Month);
	}
	static void PrintMonthCalendar(short Month, short Year)
	{
		int NumberOfDays;
		int current = DayOfWeekOrder(1, Month, Year);
		NumberOfDays = NumberOfDaysInMonth(Month, Year);
		printf("\n  _______________%s_______________\n\n",
			MonthShortName(Month).c_str());
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
		int i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);


			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n  _________________________________\n");

	}
	void PrintMonthCalendar()
	{
		PrintMonthCalendar(_Month, _Year);
	}

	static void PrintYearCalendar(int Year)
	{
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", Year);
		printf("  _________________________________\n");


		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}

		return;
	}

	void PrintYearCalendar()
	{
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", _Year);
		printf("  _________________________________\n");


		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, _Year);
		}

		return;
	}
	static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;

		for (int i = 1; i <= Month; i++)
		{
			TotalDays += NumberOfDaysInMonth(i, Year);
		}

		TotalDays += Day;

		return TotalDays;
	}
	static date GetDateFromOrderInYear(short DateOrderInYear, short Year)
	{
		date date;
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;
		date.Year = Year;
		date.Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInMonth(date.Month, Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				date.Month++;
			}
			else
			{
				date.Day = RemainingDays;
				break;
			}

		}

		return date;
	}
	void AddDays(short Days)
	{
		short RemainingDays = Days + DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
		short MonthDays = 0;
		_Month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInMonth(_Month, _Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				_Month++;

				if (_Month > 12)
				{
					_Month = 1;
					_Year++;

				}
			}
			else
			{
				_Day = RemainingDays;
				break;
			}

		}
	}
	static bool IsDate1BeforeDate2(date Date1, date Date2)
	{
		return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}

	bool IsDateBeforeDate2(date Date2)
	{
		//note: *this sends the current object :-) 
		return  IsDate1BeforeDate2(*this, Date2);

	}
	static bool IsDate1EqualDate2(date date1, date date2)
	{
		return  (date1.Year == date2.Year) ? ((date1.Month == date2.Month) ? ((date1.Day == date2.Day) ? true : false) : false) : false;
	}

	bool IsDateEqualDate2(date date2)
	{
		return  IsDate1EqualDate2(*this, date2);
	}
	static bool IsLastDayInMonth(date date1)
	{

		return (date1.Day == NumberOfDaysInMonth(date1.Month, date1.Year));
	}
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}
	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}

	static date AddOneDay(date Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{
				Date.Month = 1;
				Date.Day = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
		{
			Date.Day++;
		}

		return Date;
	}
	void AddOneDay()

	{
		*this = AddOneDay(*this);
	}
	static void  SwapDates(date& Date1, date& Date2)
	{
		date TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}
	static int GetDifferenceInDays(date Date1, date Date2, bool IncludeEndDay = false)
	{
		//this will take care of negative diff
		int Days = 0;
		short SawpFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			//Swap Dates 
			SwapDates(Date1, Date2);
			SawpFlagValue = -1;

		}
	}
	int GetDifferenceInDays(date Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}
	static short CalculateMyAgeInDays(date DateOfBirth)
	{
		return GetDifferenceInDays(DateOfBirth, date::GetSystemDate(), true);
	}
	static date IncreaseDateByOneWeek(date& Date)
	{

		for (int i = 1; i <= 7; i++)
		{
			Date = AddOneDay(Date);
		}

		return Date;
	}

	void IncreaseDateByOneWeek()
	{
		IncreaseDateByOneWeek(*this);
	}

	date IncreaseDateByXWeeks(short Weeks, date& Date)
	{

		for (short i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void IncreaseDateByXWeeks(short Weeks)
	{
		IncreaseDateByXWeeks(Weeks, *this);
	}

	date IncreaseDateByOneMonth(date& Date)
	{

		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}

		//last check day in date should not exceed max days in the current month
		// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
		// be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}

		return Date;
	}

	void IncreaseDateByOneMonth()
	{

		IncreaseDateByOneMonth(*this);

	}

	date IncreaseDateByXDays(short Days, date& Date)
	{

		for (short i = 1; i <= Days; i++)
		{
			Date = AddOneDay(Date);
		}
		return Date;
	}

	void IncreaseDateByXDays(short Days)
	{

		IncreaseDateByXDays(Days, *this);
	}

	date IncreaseDateByXMonths(short Months, date& Date)
	{

		for (short i = 1; i <= Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void IncreaseDateByXMonths(short Months)
	{
		IncreaseDateByXMonths(Months, *this);
	}

	static date IncreaseDateByOneYear(date& Date)
	{
		Date.Year++;
		return Date;
	}

	void IncreaseDateByOneYear()
	{
		IncreaseDateByOneYear(*this);
	}

	date IncreaseDateByXYears(short Years, date& Date)
	{
		Date.Year += Years;
		return Date;

	}

	void IncreaseDateByXYears(short Years)
	{
		IncreaseDateByXYears(Years);
	}

	date IncreaseDateByOneDecade(date& Date)
	{
		//Period of 10 years
		Date.Year += 10;
		return Date;
	}

	void IncreaseDateByOneDecade()
	{
		IncreaseDateByOneDecade(*this);
	}

	date IncreaseDateByXDecades(short Decade, date& Date)
	{
		Date.Year += Decade * 10;
		return Date;
	}

	void IncreaseDateByXDecades(short Decade)
	{
		IncreaseDateByXDecades(Decade, *this);
	}

	date IncreaseDateByOneCentury(date& Date)
	{
		//Period of 100 years
		Date.Year += 100;
		return Date;
	}

	void IncreaseDateByOneCentury()
	{
		IncreaseDateByOneCentury(*this);
	}

	date IncreaseDateByOneMillennium(date& Date)
	{
		//Period of 1000 years
		Date.Year += 1000;
		return Date;
	}

	date IncreaseDateByOneMillennium()
	{
		IncreaseDateByOneMillennium(*this);
	}

	static date DecreaseDateByOneDay(date Date)
	{
		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Month = 12;
				Date.Day = 31;
				Date.Year--;
			}
			else
			{

				Date.Month--;
				Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
			}
		}
		else
		{
			Date.Day--;
		}

		return Date;
	}

	void DecreaseDateByOneDay()
	{
		DecreaseDateByOneDay(*this);
	}

	static date DecreaseDateByOneWeek(date& Date)
	{

		for (int i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	void DecreaseDateByOneWeek()
	{
		DecreaseDateByOneWeek(*this);
	}

	static date DecreaseDateByXWeeks(short Weeks, date& Date)
	{

		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void DecreaseDateByXWeeks(short Weeks)
	{
		DecreaseDateByXWeeks(Weeks, *this);
	}

	static date DecreaseDateByOneMonth(date& Date)
	{

		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
			Date.Month--;


		//last check day in date should not exceed max days in the current month
	   // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
	   // be 28/2/2022
		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}


		return Date;
	}

	void DecreaseDateByOneMonth()
	{
		DecreaseDateByOneMonth(*this);
	}

	static date DecreaseDateByXDays(short Days, date& Date)
	{

		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	void DecreaseDateByXDays(short Days)
	{
		DecreaseDateByXDays(Days, *this);
	}

	static date DecreaseDateByXMonths(short Months, date& Date)
	{

		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void DecreaseDateByXMonths(short Months)
	{
		DecreaseDateByXMonths(Months, *this);
	}

	static date DecreaseDateByOneYear(date& Date)
	{

		Date.Year--;
		return Date;
	}

	void DecreaseDateByOneYear()
	{
		DecreaseDateByOneYear(*this);
	}

	static date DecreaseDateByXYears(short Years, date& Date)
	{

		Date.Year -= Years;
		return Date;
	}

	void DecreaseDateByXYears(short Years)
	{
		DecreaseDateByXYears(Years, *this);
	}

	static date DecreaseDateByOneDecade(date& Date)
	{
		//Period of 10 years
		Date.Year -= 10;
		return Date;
	}

	void DecreaseDateByOneDecade()
	{
		DecreaseDateByOneDecade(*this);
	}

	static date DecreaseDateByXDecades(short Decades, date& Date)
	{

		Date.Year -= Decades * 10;
		return Date;
	}

	void DecreaseDateByXDecades(short Decades)
	{
		DecreaseDateByXDecades(Decades, *this);
	}

	static date DecreaseDateByOneCentury(date& Date)
	{
		//Period of 100 years
		Date.Year -= 100;
		return Date;
	}

	void DecreaseDateByOneCentury()
	{
		DecreaseDateByOneCentury(*this);
	}

	static date DecreaseDateByOneMillennium(date& Date)
	{
		//Period of 1000 years
		Date.Year -= 1000;
		return Date;
	}

	void DecreaseDateByOneMillennium()
	{
		DecreaseDateByOneMillennium(*this);
	}


	static short IsEndOfWeek(date Date)
	{
		return  DayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 6;
	}

	short IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(date Date)
	{
		//Weekends are Fri and Sat
		short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
		return  (DayIndex == 5 || DayIndex == 6);
	}

	bool IsWeekEnd()
	{
		return  IsWeekEnd(*this);
	}

	static bool IsBusinessDay(date Date)
	{
		//Weekends are Sun,Mon,Tue,Wed and Thur

	   /*
		short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
		return  (DayIndex >= 5 && DayIndex <= 4);
	   */

	   //shorter method is to invert the IsWeekEnd: this will save updating code.
		return !IsWeekEnd(Date);

	}

	bool IsBusinessDay()
	{
		return  IsBusinessDay(*this);
	}

	static short DaysUntilTheEndOfWeek(date Date)
	{
		return 6 - DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	}

	short DaysUntilTheEndOfWeek()
	{
		return  DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(date Date1)
	{

		date EndOfMontDate;
		EndOfMontDate.Day = NumberOfDaysInMonth(Date1.Month, Date1.Year);
		EndOfMontDate.Month = Date1.Month;
		EndOfMontDate.Year = Date1.Year;

		return GetDifferenceInDays(Date1, EndOfMontDate, true);

	}

	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(date Date1)
	{

		date EndOfYearDate;
		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date1.Year;

		return GetDifferenceInDays(Date1, EndOfYearDate, true);

	}

	short DaysUntilTheEndOfYear()
	{
		return  DaysUntilTheEndOfYear(*this);
	}

	//i added this method to calculate business days between 2 days
	static short CalculateBusinessDays(date DateFrom, date DateTo)
	{

		short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = AddOneDay(DateFrom);
		}

		return Days;

	}

	static short CalculateVacationDays(date DateFrom, date DateTo)
	{
		/*short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = AddOneDay(DateFrom);
		}*/

		return CalculateBusinessDays(DateFrom, DateTo);

	}
	//above method is eough , no need to have method for the object

	static date CalculateVacationReturnDate(date DateFrom, short VacationDays)
	{

		short WeekEndCounter = 0;

		for (short i = 1; i <= VacationDays; i++)
		{

			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = AddOneDay(DateFrom);
		}
		//to add weekends 
		for (short i = 1; i <= WeekEndCounter; i++)
			DateFrom = AddOneDay(DateFrom);

		return DateFrom;
	}

	static bool IsDate1AfterDate2(date Date1, date Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));

	}

	bool IsDateAfterDate2(date Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(date Date1, date Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;
		return enDateCompare::After;

	}
	enDateCompare CompareDates(date Date2)
	{
		return CompareDates(*this, Date2);
	}
};