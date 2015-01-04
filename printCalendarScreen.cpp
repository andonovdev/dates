#include <iostream>
#include <iomanip>
#include "functions.h"
#include "screens.h"

using namespace std;

void printCalendarScreen()
{
	clearScreen();

	Date date;
	cout << "Enter month and year separated by a space" << endl;
	cin >> date.month >> date.year;

	if (date.month < 1 || date.month > 12)
	{
		cout << "No such month" << endl;
	}
	else
	{
		int curDate = 1;
		
		int totalDays = daysInMonthCount(date);

		date.day = 1;
		int firstDayOfWeek = dayOfWeek(date);

		// print day labels
		cout << endl << "Mo Tu We Th Fr Sa Su" << endl;

		if (firstDayOfWeek == 0)
		{
			cout << setw(20);
		}
		else
		{
			cout << setw(firstDayOfWeek * 3 - 1);
		}
		while (curDate <= totalDays)
		{
			cout << curDate;
			if ((curDate + firstDayOfWeek - 1) % 7 == 0)
			{
				cout << endl << setw(2);
			}
			else
			{
				cout << setw(3);
			}
			curDate++;
		}
		cout << endl;
	}

	waitUntilEnter();

	homeScreen();
}