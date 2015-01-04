#include <iostream>
#include "functions.h"
#include "screens.h"

using namespace std;

void descriptionScreen()
{
	clearScreen();

	char q;
	int dayCode;
	Date date;
	cout << "Example: " << endl << "(format: which day month year)" << endl;
	cout << "Enter : 2 6 10 2014" << endl;
	cout << "for the second Saturday in October 2014" << endl;
	cout << "Enter: l 1 11 2015" << endl;
	cout << "for the last Monday in November 2015" << endl << endl;

	cin >> q >> dayCode >> date.month >> date.year;

	date.day = 1;
	int firstDayOfWeek = dayOfWeek(date);
	int firstSeekedDay = (7 - firstDayOfWeek + 1 + dayCode) % 7;
	if (firstSeekedDay == 0)
	{
		firstSeekedDay = 7;
	}

	if (q != 'l')
	{
		int seekedDay = firstSeekedDay + 7 * (charToInt(q) - 1);
		if (seekedDay <= daysInMonthCount(date))
		{
			cout << "The date you are looking for is:" << endl;
			cout << seekedDay;
			cout << " " << date.month << " " << date.year << endl;
		}
		else
		{
			cout << "No such date" << endl;
		}
	}
	else
	{
		cout << "The date you are looking for is:" << endl;
		cout << firstSeekedDay + 7 * ((daysInMonthCount(date) - firstSeekedDay) / 7);
		cout << " " << date.month << " " << date.year << endl;
	}

	waitUntilEnter();

	homeScreen();
}