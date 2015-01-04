#include <iostream>
#include "functions.h"
#include "screens.h"

using namespace std;

void durationScreen()
{
	clearScreen();

	Date date1, date2;
	cout << "Enter day, month and year separated by a space for the first date" << endl;
	cin >> date1.day >> date1.month >> date1.year;

	if (isDateCorrect(date1))
	{
		cout << "Enter day, month and year separated by a space for the second date" << endl;
		cin >> date2.day >> date2.month >> date2.year;

		if (isDateCorrect(date2))
		{
			Duration duration = calcDuration(date1, date2);
			cout << "Including the first, not including the last date:" << endl;
			cout << duration.days << " days, ";
			cout << duration.weeks << " weeks, ";
			cout << duration.months << " months and ";
			cout << duration.years << " years" << endl;
		}
		else
		{
			cout << "Incorrect date" << endl;
		}
	}
	else
	{
		cout << "Incorrect date" << endl;
	}	

	waitUntilEnter();

	homeScreen();
}