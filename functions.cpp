#include <iostream>
#include <cstdlib>
#include <climits>
#include "functions.h"

using namespace std;

void clearScreen()
{
	// prints 100 newlines
	for (int i = 0; i < 10; i++)
		cout << "\n\n\n\n\n\n\n\n\n\n";
}

void waitUntilEnter()
{
	cout << endl << "press enter to continue...";
	// wait until enter is pressed
	cin.ignore();
	while (cin.get() != '\n');
}

int charToInt(char c)
{
	return c - '0';
}

int daysInMonthCount(int month, int year)
{
	switch (month)
	{
		case 2:
			if (isLeapYear(year))
			{
				// leap year
				return 29;
			}
			else
			{
				return 28;
			}
			break;

		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
			break;

		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
			break;

		// if the month is invalid return 0
		default:
			return 0;
	}
}

int daysInMonthCount(Date date)
{
	return daysInMonthCount(date.month, date.year);
}

int daysInYearCount(int year)
{
	return 365 + isLeapYear(year);
}

int daysUpToNowThisYear(Date date)
{
	int m = 1, daysCnt = 0;
	while (m < date.month)
	{
		daysCnt += daysInMonthCount(m, date.year);
		m++;
	}
	daysCnt += date.day;
	return daysCnt;
}

void swapDates(Date& date1, Date& date2)
{
	Date temp = date1;
	date1 = date2;
	date2 = temp;
}

// returns <0 if date1 is before date2
// 			0 if date1 is the same as date2
// 		   >0 if date1 is after date2
int compareDates(Date date1, Date date2)
{
	if (date1.year == date2.year)
	{
		if (date1.month == date2.month)
		{
			if (date1.day == date2.day)
			{
				return 0;
			}
			else
			{
				return date1.day - date2.day;
			}
		}
		else
		{
			return date1.month - date2.month;
		}
	}
	else
	{
		return date1.year - date2.year;
	}
}

bool isFirstDateEarlier(Date date1, Date date2)
{
	return compareDates(date1, date2) < 0;
}

bool isDateCorrect(Date date)
{
	if (date.day < 1 || date.month < 1 || date.month > 12)
		return false;

	return date.day <= daysInMonthCount(date);
}

Date addDays(Date date, int days)
{
	if (days <= 0)
	{
		return date;
	}

	if (days >= daysInYearCount(date.year) - daysUpToNowThisYear(date) + 1)
	{
		days -= (daysInYearCount(date.year) - daysUpToNowThisYear(date) + 1);
		date.day = 1;
		date.month = 1;
		date.year++;
		while (days >= daysInYearCount(date.year))
		{
			days -= daysInYearCount(date.year);
			date.day = 1;
			date.month = 1;
			date.year++;
		}
	}
	else if (days >= daysInMonthCount(date) - date.day + 1)
	{
		days -= (daysInMonthCount(date) - date.day + 1);
		date.day = 1;
		date.month++;
		if (date.month > 12)
		{
			date.year = date.month / 12;
			date.month %= 12;
		}
	}
	while (days >= daysInMonthCount(date))
	{
		days -= daysInMonthCount(date);
		date.day = 1;
		date.month++;
		if (date.month > 12)
		{
			date.year += date.month / 12;
			date.month %= 12;
		}
	}
	date.day += days;

	return date;
}

Date subtractDays(Date date, int days)
{
	if (days <= 0)
	{
		return date;
	}

	if (days >= daysUpToNowThisYear(date))
	{
		days -= daysUpToNowThisYear(date);
		date.day = 31;
		date.month = 12;
		date.year--;
		while (days >= daysInYearCount(date.year))
		{
			days -= daysInYearCount(date.year);
			date.day = 31;
			date.month = 12;
			date.year--;
		}
	}
	else if (days >= date.day)
	{
		days -= date.day;
		date.month--;
		if (date.month == 0)
		{
			date.year--;
			date.month = 12;
		}
		date.day = daysInMonthCount(date);
	}
	while (days >= daysInMonthCount(date))
	{
		days -= daysInMonthCount(date);
		date.month--;
		if (date.month == 0)
		{
			date.year--;
			date.month = 12;
		}
		date.day = daysInMonthCount(date);
	}
	date.day -= days;

	return date;
}

Duration calcDuration(Date date1, Date date2)
{
	// if date2 is before date1
	if (compareDates(date1, date2) > 0)
	{
		swapDates(date1, date2);
	}

	Duration duration;
	duration.years = date2.year - date1.year;
	if (date2.month < date1.month)
	{
		duration.years--;
		date2.year--;
		duration.months = 12 + date2.month - date1.month;
	}
	else
	{
		duration.months = date2.month - date1.month;
	}
	if (date2.day < date1.day)
	{
		duration.months--;
		date2.month--;
		duration.days = daysInMonthCount(date2) + date2.day - date1.day; 
	}
	else
	{
		duration.days = date2.day - date1.day;
	}

	duration.weeks = duration.days / 7;
	duration.days %= 7;

	return duration;
}

int calcDurationDays(Date date1, Date date2)
{
	// if date2 is before date1
	if (compareDates(date1, date2) > 0)
	{
		swapDates(date1, date2);
	}

	int days = 0;

	// years
	days += (365 * (date2.year - 1) + pastLeapYearsCount(date2.year - 1));
	days += daysUpToNowThisYear(date2);
	days -= (365 * (date1.year - 1) + pastLeapYearsCount(date1.year - 1));
	days -= daysUpToNowThisYear(date1);

	return days;
}

bool isLeapYear(int year)
{
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int pastLeapYearsCount(int year)
{
	return year / 4 - year / 100 + year / 400;
}

int dayOfWeek(Date date)
{
	Date baseDate;
	baseDate.day = 1;
	baseDate.month = 1;
	baseDate.year = 2000;
	int base = 6, res;

	if (compareDates(baseDate, date) < 0)
	{
		res = (base + calcDurationDays(baseDate, date)) % 7;
	}
	else
	{
		res = (base - calcDurationDays(baseDate, date)) % 7;
		if (res < 0)
		{
			res += 7;
		}
	}

	// Sunday to Saturday -> 0 to 6
	return res;
}

const char* getWeekdayName(int dayCode)
{
	switch (dayCode)
	{
		case 0:
			return "Sunday";
		case 1:
			return "Monday";
		case 2:
			return "Tuesday";
		case 3:
			return "Wednesday";
		case 4:
			return "Thursday";
		case 5:
			return "Friday";
		case 6:
			return "Saturday";
		default:
			return "No such day of the week";
	}
}

const char* getMonthName(int month)
{
	switch (month)
	{
		case 1:
			return "January";
			break;
		case 2:
			return "February";
			break;
		case 3:
			return "March";
			break;
		case 4:
			return "April";
			break;
		case 5:
			return "May";
			break;
		case 6:
			return "June";
			break;
		case 7:
			return "July";
			break;
		case 8:
			return "August";
			break;
		case 9:
			return "September";
			break;
		case 10:
			return "October";
			break;
		case 11:
			return "November";
			break;
		case 12:
			return "December";
			break;

		default:
			return "No such month";
			break;
	}
}

void printDate(Date date, int formatCode /* = 0 */)
{
	switch (formatCode)
	{
		case 1:
			cout << getMonthName(date.month) << " " << date.day << ", " << date.year << endl;
			break;
		case 2:
			cout << date.day << "/" << date.month << "/" << date.year << endl;
			break;
		case 3:
			cout << date.day << "." << date.month << "." << date.year << endl;
			break;
		case 4:
			if (date.day < 10)
			{
				cout << '0';
			}
			cout << date.day << "/";
			if (date.month < 10)
			{
				cout << '0';
			}
			cout << date.month << "/" << date.year % 100 << endl;
			break;
		case 5:
			if (date.day < 10)
			{
				cout << '0';
			}
			cout << date.day << "-";
			if (date.month < 10)
			{
				cout << '0';
			}
			cout << date.month << "-" << date.year % 100 << endl;
			break;
		case 6:
			cout << date.month << "/" << date.day << "/" << date.year << endl;
			break;
		case 7:
			cout << date.month << "." << date.day << "." << date.year << endl;
			break;
		case 8:
			if (date.month < 10)
			{
				cout << '0';
			}
			cout << date.month << "/";
			if (date.day < 10)
			{
				cout << '0';
			}
			cout << date.day << "/" << date.year % 100 << endl;
			break;
		case 9:
			if (date.month < 10)
			{
				cout << '0';
			}
			cout << date.month << "-";
			if (date.day < 10)
			{
				cout << '0';
			}
			cout << date.day << "-" << date.year % 100 << endl;
			break;

		default:
			cout << date.day << " " << getMonthName(date.month) << " " << date.year << endl;;
			break;
	}
}

Date calcEaster(int year)
{
	Date date;
	date.year = year;

	int a, b, c, k, p, q, m, n, d, e;
	a = year % 19;
	b = year % 4;
	c = year % 7;
	k = year / 100;
	p = (13 + 8*k) / 25;
	q = k / 4;
	m = (15 - p + k - q) % 30;
	n = (4 + k - q) % 7;
	d = (19*a + m) % 30;
	e = (2*b + 4*c + 6*d + n) % 7;

	int dayOfMarch = 22 + d + e;
	if (dayOfMarch > 31)
	{
		if (d == 29 && e == 6)
		{
			date.day = 19;
		}
		else if (d == 28 && e == 6 && (11*m+11) % 30 < 19)
		{
			date.day = 18;
		}
		else
		{
			date.day = dayOfMarch - 31;
		}
		date.month = 4;
	}
	else
	{
		date.day = dayOfMarch;
		date.month = 3;
	}

	return date;
}

bool dateExists(Date dates[], int cnt, Date date)
{
	int l = 0, r = cnt - 1, mid;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (compareDates(date, dates[mid]) == 0)
		{
			return true;
		}
		else if (compareDates(date, dates[mid]) < 0)
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}

	return false;
}

int datesInIntervalCount(Date dates[], int cnt, Date date1, Date date2)
{
	if (cnt == 0)
	{
		return 0;
	}

	int leftLimit, rightLimit;
	int l = -1, r = cnt - 1, mid;
	while (r - l > 1)
	{
		mid = (l + r) / 2;
		if (compareDates(date1, dates[mid]) == 0)
		{
			r = mid;
			break;
		}
		else if (compareDates(date1, dates[mid]) < 0)
		{
			r = mid;
		}
		else
		{
			l = mid;
		}
	}
	leftLimit = r;

	l = 0;
	r = cnt;
	while (r - l > 1)
	{
		mid = (l + r) / 2;
		if (compareDates(date2, dates[mid]) == 0)
		{
			l = mid;
			break;
		}
		else if (compareDates(date2, dates[mid]) < 0)
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	rightLimit = l;

	return rightLimit - leftLimit + 1;
}

int weekendDaysInIntervalCount(Date date1, Date date2)
{
	if (compareDates(date1, date2) > 0)
	{
		swapDates(date1, date2);
	}

	int totalDays = calcDurationDays(date1, date2);
	int dow = dayOfWeek(date1);

	int saturdayCnt;
	if (dow == 0)
	{
		saturdayCnt = totalDays / 7;
		dow = 7;
	}
	else
	{
		saturdayCnt = (totalDays - (7 - dow)) / 7 + 1;
	}
	int sundayCnt = (totalDays - (8 - dow)) / 7 + 1;

	return saturdayCnt + sundayCnt;
}

// 5 1 2015 0 7 1 2015 0 9 1 2015 0