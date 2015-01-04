#include <iostream>
#include <algorithm>
#include "functions.h"
#include "screens.h"

using namespace std;

const int MAX_HOLIDAY_CNT = 10000;
Date holidays[MAX_HOLIDAY_CNT], workOffDays[MAX_HOLIDAY_CNT];

void advancedModeScreen()
{
	clearScreen();

	int n;
	cout << "How many holidays do you want to type in?" << endl;
	cin >> n;

	int i, j = 0;
	bool workoff;
	for (i = 0; i < n; i++)
	{
		cout << "Enter holiday date " << i + 1 << " (day month year workoff(0/1))" << endl;
		cin >> holidays[i].day >> holidays[i].month >> holidays[i].year >> workoff;
		while (!isDateCorrect(holidays[i]))
		{
			cout << "Incorrect date" << endl;
			cout << "Enter holiday date " << i + 1 << " (day month year workoff(0/1))" << endl;
			cin >> holidays[i].day >> holidays[i].month >> holidays[i].year >> workoff;
		}
		if (workoff)
		{
			cout << "Enter work off date (day month year)" << endl;
			cin >> workOffDays[j].day >> workOffDays[j].month >> workOffDays[j].year;
			while (!isDateCorrect(workOffDays[j]))
			{
				cout << "Incorrect date" << endl;
				cout << "Enter work off date (day month year)" << endl;
				cin >> workOffDays[i].day >> workOffDays[i].month >> workOffDays[i].year >> workoff;
			}
			j++;
		}
	}

	sort(holidays, holidays+i, isFirstDateEarlier);

	sort(workOffDays, workOffDays+j, isFirstDateEarlier);

	char choice;
	int days;
	do
	{
		cout << "1 - add/subtract days" << endl;
		cout << "2 - duration" << endl;
		cout << "e - exit back to home screen" << endl;
		cin >> choice;
		switch (choice)
		{
			case '1':
				Date date, endDate;
				cout << "Enter day, month, year separated by a space" << endl;
				cin >> date.day >> date.month >> date.year;
				if (isDateCorrect(date))
				{
					cout << "Enter days to add (subtract with -)" << endl;
					cin >> days;
					if (days > 0)
					{
						endDate = date;
						while (days > 0)
						{
							endDate = addDays(endDate, 1);
							if (!dateExists(holidays, i, endDate) &&
								((dayOfWeek(endDate) != 0 && dayOfWeek(endDate) != 6)
									|| dateExists(workOffDays, j, endDate)))
							{
								days--;
							}
						}
					}
					else
					{
						days = -days;
						endDate = date;
						while (days > 0)
						{
							endDate = subtractDays(endDate, 1);
							if (!dateExists(holidays, i, endDate) &&
								((dayOfWeek(endDate) != 0 && dayOfWeek(endDate) != 6)
									|| dateExists(workOffDays, j, endDate)))
							{
								days--;
							}
						}
					}
					printDate(endDate);
				}
				break;
			case '2':

				Date date1, date2;
				cout << "Enter day, month, year separated by a space for the first date" << endl;
				cin >> date1.day >> date1.month >> date1.year;
				if (isDateCorrect(date1))
				{
					cout << "Enter day, month, year separated by a space for the first date" << endl;
					cin >> date2.day >> date2.month >> date2.year;
					if (isDateCorrect(date2))
					{
						days = calcDurationDays(date1, date2);
						days -= datesInIntervalCount(holidays, i, date1, date2);
						days += datesInIntervalCount(workOffDays, j, date1, date2);
						days -= weekendDaysInIntervalCount(date1, date2);

						cout << days << " days" << endl;
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
				break;
			case 'e':
				// break loop
				break;
			default:
				cout << "No such option" << endl;
		}
	} while (choice != 'e');

	homeScreen();
}