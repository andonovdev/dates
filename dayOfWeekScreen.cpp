#include <iostream>
#include "functions.h"
#include "screens.h"

using namespace std;

void dayOfWeekScreen()
{
	clearScreen();

	Date date;
	cout << "Enter date, month and year separated by a space" << endl;
	cin >> date.day >> date.month >> date.year;

	if (isDateCorrect(date))
	{
		cout << getWeekdayName(dayOfWeek(date)) << endl;
	}
	else
	{
		cout << "Incorrect date" << endl;
	}

	waitUntilEnter();

	homeScreen();
}