#include <iostream>
#include "functions.h"
#include "screens.h"

using namespace std;

void addSubtractScreen()
{
	clearScreen();

	Date date;
	cout << "Enter day, month and year separated by a space" << endl;
	cin >> date.day >> date.month >> date.year;

	if (isDateCorrect(date))
	{
		int daysToAdd, weeksToAdd, monthsToAdd, yearsToAdd;
		cout << "Enter years, months, weeks and days to add (subtract with -)" << endl;
		cin >> yearsToAdd >> monthsToAdd >> weeksToAdd >> daysToAdd;

		// normalize
		daysToAdd += (weeksToAdd * 7);
		yearsToAdd += (monthsToAdd / 12);
		monthsToAdd %= 12;

		// order: years, months, days
		date.year += yearsToAdd;
		date.month += monthsToAdd;
		if (date.month > 12)
		{
			date.year++;
			date.month %= 12;
		}
		else if (date.month < 1)
		{
			date.year--;
			date.month = (12 + date.month) % 12;
		}
		int daysInMonth = daysInMonthCount(date);
		if (date.day > daysInMonth)
		{
			date.day = daysInMonth;
		}

		if (daysToAdd > 0)
		{
			date = addDays(date, daysToAdd);
		}
		else
		{
			date = subtractDays(date, -daysToAdd);
		}

		printDate(date);
	}
	else
	{
		cout << "Incorrect date" << endl;
	}

	waitUntilEnter();

	homeScreen();
}