#include <iostream>
#include "functions.h"
#include "screens.h"

using namespace std;

void homeScreen()
{
	clearScreen();
	
	char choice;
	bool tryAgain = false;

	cout << "1 date correctness check" << endl;
	cout << "2 print date in chosen format" << endl;
	cout << "3 day of week" << endl;
	cout << "4 description to date" << endl;
	cout << "5 print calendar" << endl;
	cout << "6 add/subtract from date" << endl;
	cout << "7 time between dates" << endl;
	cout << "8 calculate Easter date" << endl;
	cout << "9 enter advanced mode" << endl;
	cout << "e for exit" << endl;
	
	cout << endl;
	do
	{
		cout << "Your choice: ";
		cin >> choice;
		switch (choice)
		{
			case '1':
				correctnessCheckScreen();
				break;

			case '2':
				printFormattedScreen();
				break;

			case '3':
				dayOfWeekScreen();
				break;

			case '4':
				descriptionScreen();
				break;

			case '5':
				printCalendarScreen();
				break;

			case '6':
				addSubtractScreen();
				break;

			case '7':
				durationScreen();
				break;

			case '8':
				easterScreen();
				break;

			case '9':
				advancedModeScreen();
				break;

			// exit
			case 'e':
				tryAgain = false;
				break;

			// try choosing again
			default:
				cout << "no such option" << endl;
				tryAgain = true;
				break;
		}
	}
	while (tryAgain);
}