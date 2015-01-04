#include <iostream>
#include "functions.h"
#include "screens.h"

using namespace std;

void easterScreen()
{
	clearScreen();

	int year;
	cout << "Enter year to calculate Easter date" << endl;
	cin >> year;

	Date easterDate = calcEaster(year);
	printDate(easterDate);

	waitUntilEnter();

	homeScreen();
}