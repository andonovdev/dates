#include <iostream>
#include "functions.h"
#include "screens.h"

using namespace std;

void printFormattedScreen()
{
	clearScreen();

	Date date;
	cout << "Enter date, month and year separated by a space" << endl;
	cin >> date.day >> date.month >> date.year;

	if (isDateCorrect(date))
	{
		int formatCode;
		cout << "Choose format: (for the example we use 14 March 2015)" << endl;
		cout << "0 - 14 March 2015" << endl;
		cout << "1 - March 14, 2015" << endl;
		cout << "2 - 14/3/2015" << endl;
		cout << "3 - 14.3.2015" << endl;
		cout << "4 - 14/03/15" << endl;
		cout << "5 - 14-03-15" << endl;
		cout << "6 - 3/14/2015" << endl;
		cout << "7 - 3.14.2015" << endl;
		cout << "8 - 03/14/15" << endl;
		cout << "9 - 03-14-15" << endl;
		cin >> formatCode;

		if (formatCode < 0 || formatCode > 9)
		{
			cout << "No such format" << endl;
		}
		else
		{
			printDate(date, formatCode);
		}
	}
	else
	{
		cout << "Incorrect date" << endl;
	}

	waitUntilEnter();

	homeScreen();
}