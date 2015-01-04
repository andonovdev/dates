#include <iostream>
#include "functions.h"
#include "screens.h"

using namespace std;

void correctnessCheckScreen()
{
	clearScreen();

	Date date;
	cout << "Enter date, month and year separated by a space" << endl;
	cin >> date.day >> date.month >> date.year;

	if (isDateCorrect(date))
	{
		cout << "Date is correct" << endl;
	}
	else
	{
		cout << "Date is incorrect" << endl;
	}

	waitUntilEnter();

	homeScreen();
}