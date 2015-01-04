#include <iostream>
#include "functions.h"

using namespace std;

bool assert(int a, int b)
{
	return a == b;
}

bool assert(Date a, Date b)
{
	return compareDates(a, b) == 0;
}

bool assert(Duration a, Duration b)
{
	return 	a.days == b.days &&
			a.weeks == b.weeks &&
			a.months == b.months &&
			a.years == b.years;
}

void testCalcEaster()
{
	cout << "calcEaster()" << endl;
	cout << assert(calcEaster(1995).day, 16);
	cout << assert(calcEaster(1996).day, 7);
	cout << assert(calcEaster(1997).day, 30);
	cout << assert(calcEaster(1998).day, 12);
	cout << assert(calcEaster(1999).day, 4);
	cout << assert(calcEaster(2000).day, 23);
	cout << assert(calcEaster(2001).day, 15);
	cout << assert(calcEaster(2002).day, 31);
	cout << assert(calcEaster(2003).day, 20);
	cout << assert(calcEaster(2004).day, 11);
	cout << assert(calcEaster(2005).day, 27);
	cout << assert(calcEaster(2006).day, 16);
	cout << assert(calcEaster(2007).day, 8);
	cout << assert(calcEaster(2008).day, 23);
	cout << assert(calcEaster(2009).day, 12);
	cout << assert(calcEaster(2010).day, 4);
	cout << assert(calcEaster(2011).day, 24);
	cout << assert(calcEaster(2012).day, 8);
	cout << assert(calcEaster(2013).day, 31);
	cout << assert(calcEaster(2014).day, 20);
	cout << assert(calcEaster(2015).day, 5);
	cout << endl;
	cout << assert(calcEaster(1995).month, 4);
	cout << assert(calcEaster(1996).month, 4);
	cout << assert(calcEaster(1997).month, 3);
	cout << assert(calcEaster(1998).month, 4);
	cout << assert(calcEaster(1999).month, 4);
	cout << assert(calcEaster(2000).month, 4);
	cout << assert(calcEaster(2001).month, 4);
	cout << assert(calcEaster(2002).month, 3);
	cout << assert(calcEaster(2003).month, 4);
	cout << assert(calcEaster(2004).month, 4);
	cout << assert(calcEaster(2005).month, 3);
	cout << assert(calcEaster(2006).month, 4);
	cout << assert(calcEaster(2007).month, 4);
	cout << assert(calcEaster(2008).month, 3);
	cout << assert(calcEaster(2009).month, 4);
	cout << assert(calcEaster(2010).month, 4);
	cout << assert(calcEaster(2011).month, 4);
	cout << assert(calcEaster(2012).month, 4);
	cout << assert(calcEaster(2013).month, 3);
	cout << assert(calcEaster(2014).month, 4);
	cout << assert(calcEaster(2015).month, 4);
	cout << endl;
}

void testAddDays()
{
	cout << "addDays()" << endl;
	Date beginDate, endDate;
	beginDate.day = 4;
	beginDate.month = 1;
	beginDate.year = 2015;

	endDate.day = 14;
	endDate.month = 1;
	endDate.year = 2015;
	cout << assert(addDays(beginDate, 10), endDate);
	// printDate(addDays(beginDate, 10));

	endDate.day = 3;
	endDate.month = 2;
	endDate.year = 2015;
	cout << assert(addDays(beginDate, 30), endDate);
	// printDate(addDays(beginDate, 30));

	endDate.day = 14;
	endDate.month = 4;
	endDate.year = 2015;
	cout << assert(addDays(beginDate, 100), endDate);
	// printDate(addDays(beginDate, 100));

	endDate.day = 18;
	endDate.month = 5;
	endDate.year = 2016;
	cout << assert(addDays(beginDate, 500), endDate);
	// printDate(addDays(beginDate, 500));

	endDate.day = 12;
	endDate.month = 2;
	endDate.year = 2019;
	cout << assert(addDays(beginDate, 1500), endDate);
	// printDate(addDays(beginDate, 1500));

	endDate.day = 25;
	endDate.month = 1;
	endDate.year = 2030;
	cout << assert(addDays(beginDate, 5500), endDate);
	// printDate(addDays(beginDate, 5500));

	endDate.day = 31;
	endDate.month = 1;
	endDate.year = 2030;
	cout << assert(addDays(beginDate, 5506), endDate);
	// printDate(addDays(beginDate, 5506));

	endDate.day = 1;
	endDate.month = 2;
	endDate.year = 2030;
	cout << assert(addDays(beginDate, 5507), endDate);
	// printDate(addDays(beginDate, 5507));

	endDate.day = 31;
	endDate.month = 12;
	endDate.year = 2029;
	cout << assert(addDays(beginDate, 5475), endDate);
	// printDate(addDays(beginDate, 5475));

	cout << endl;
}

void testSubtractDays()
{
	cout << "subtractDays()" << endl;
	Date beginDate, endDate;
	beginDate.day = 4;
	beginDate.month = 1;
	beginDate.year = 2015;

	endDate.day = 14;
	endDate.month = 1;
	endDate.year = 2015;
	cout << assert(subtractDays(endDate, 10), beginDate);
	// printDate(subtractDays(endDate, 10));

	endDate.day = 3;
	endDate.month = 2;
	endDate.year = 2015;
	cout << assert(subtractDays(endDate, 30), beginDate);
	// printDate(subtractDays(endDate, 30));

	endDate.day = 14;
	endDate.month = 4;
	endDate.year = 2015;
	cout << assert(subtractDays(endDate, 100), beginDate);
	// printDate(subtractDays(endDate, 100));

	endDate.day = 18;
	endDate.month = 5;
	endDate.year = 2016;
	cout << assert(subtractDays(endDate, 500), beginDate);
	// printDate(subtractDays(endDate, 500));

	endDate.day = 12;
	endDate.month = 2;
	endDate.year = 2019;
	cout << assert(subtractDays(endDate, 1500), beginDate);
	// printDate(subtractDays(endDate, 1500));

	endDate.day = 25;
	endDate.month = 1;
	endDate.year = 2030;
	cout << assert(subtractDays(endDate, 5500), beginDate);
	// printDate(subtractDays(endDate, 5500));

	endDate.day = 31;
	endDate.month = 1;
	endDate.year = 2030;
	cout << assert(subtractDays(endDate, 5506), beginDate);
	// printDate(subtractDays(endDate, 5506));

	endDate.day = 1;
	endDate.month = 2;
	endDate.year = 2030;
	cout << assert(subtractDays(endDate, 5507), beginDate);
	// printDate(subtractDays(endDate, 5507));

	endDate.day = 31;
	endDate.month = 12;
	endDate.year = 2029;
	cout << assert(subtractDays(endDate, 5475), beginDate);
	// printDate(subtractDays(endDate, 5475));

	cout << endl;
}

void testCalcDuration()
{
	cout << "calcDuration()" << endl;
	Date beginDate, endDate;
	Duration duration;

	beginDate.day = 4;
	beginDate.month = 1;
	beginDate.year = 2015;
	endDate.day = 14;
	endDate.month = 1;
	endDate.year = 2015;
	duration.days = 3;
	duration.weeks = 1;
	duration.months = 0;
	duration.years = 0;
	cout << assert(calcDuration(beginDate, endDate), duration);

	beginDate.day = 29;
	beginDate.month = 2;
	beginDate.year = 2012;
	endDate.day = 3;
	endDate.month = 4;
	endDate.year = 2013;
	duration.days = 5;
	duration.weeks = 0;
	duration.months = 1;
	duration.years = 1;
	cout << assert(calcDuration(beginDate, endDate), duration);

	beginDate.day = 14;
	beginDate.month = 1;
	beginDate.year = 2015;
	endDate.day = 4;
	endDate.month = 1;
	endDate.year = 2015;
	duration.days = 3;
	duration.weeks = 1;
	duration.months = 0;
	duration.years = 0;
	cout << assert(calcDuration(beginDate, endDate), duration);

	beginDate.day = 3;
	beginDate.month = 4;
	beginDate.year = 2013;
	endDate.day = 29;
	endDate.month = 2;
	endDate.year = 2012;
	duration.days = 5;
	duration.weeks = 0;
	duration.months = 1;
	duration.years = 1;
	cout << assert(calcDuration(beginDate, endDate), duration);

	beginDate.day = 4;
	beginDate.month = 1;
	beginDate.year = 2012;
	endDate.day = 6;
	endDate.month = 1;
	endDate.year = 2015;
	duration.days = 2;
	duration.weeks = 0;
	duration.months = 0;
	duration.years = 3;
	cout << assert(calcDuration(beginDate, endDate), duration);

	beginDate.day = 31;
	beginDate.month = 10;
	beginDate.year = 2012;
	endDate.day = 21;
	endDate.month = 4;
	endDate.year = 2015;
	duration.days = 0;
	duration.weeks = 3;
	duration.months = 5;
	duration.years = 2;
	cout << assert(calcDuration(beginDate, endDate), duration);

	beginDate.day = 2;
	beginDate.month = 6;
	beginDate.year = 2012;
	endDate.day = 1;
	endDate.month = 9;
	endDate.year = 2020;
	duration.days = 2;
	duration.weeks = 4;
	duration.months = 2;
	duration.years = 8;
	cout << assert(calcDuration(beginDate, endDate), duration);

	beginDate.day = 12;
	beginDate.month = 5;
	beginDate.year = 2013;
	endDate.day = 6;
	endDate.month = 9;
	endDate.year = 2019;
	duration.days = 4;
	duration.weeks = 3;
	duration.months = 3;
	duration.years = 6;
	cout << assert(calcDuration(beginDate, endDate), duration);
	// cout << calcDuration(beginDate, endDate).days << endl;
	// cout << calcDuration(beginDate, endDate).weeks << endl;
	// cout << calcDuration(beginDate, endDate).months << endl;
	// cout << calcDuration(beginDate, endDate).years << endl;

	cout << endl;
}

void testCalcDurationDays()
{
	cout << "calcDurationDays()" << endl;
	Date beginDate, endDate;

	beginDate.day = 1;
	beginDate.month = 6;
	beginDate.year = 2012;
	endDate.day = 1;
	endDate.month = 9;
	endDate.year = 2020;
	cout << assert(calcDurationDays(beginDate, endDate), 3014);

	beginDate.day = 1;
	beginDate.month = 9;
	beginDate.year = 2020;
	endDate.day = 1;
	endDate.month = 6;
	endDate.year = 2012;
	cout << assert(calcDurationDays(beginDate, endDate), 3014);

	beginDate.day = 25;
	beginDate.month = 6;
	beginDate.year = 2012;
	endDate.day = 1;
	endDate.month = 8;
	endDate.year = 2020;
	cout << assert(calcDurationDays(beginDate, endDate), 2959);

	beginDate.day = 25;
	beginDate.month = 3;
	beginDate.year = 1999;
	endDate.day = 3;
	endDate.month = 8;
	endDate.year = 2023;
	cout << assert(calcDurationDays(beginDate, endDate), 8897);

	beginDate.day = 15;
	beginDate.month = 7;
	beginDate.year = 1998;
	endDate.day = 28;
	endDate.month = 2;
	endDate.year = 2022;
	cout << assert(calcDurationDays(beginDate, endDate), 8629);

	cout << endl;
}

void testDayOfWeek()
{
	cout << "dayOfWeek()" << endl;
	Date date;

	date.day = 1;
	date.month = 1;
	date.year = 2000;
	cout << assert(dayOfWeek(date), 6);

	date.day = 4;
	date.month = 1;
	date.year = 2015;
	cout << assert(dayOfWeek(date), 0);

	date.day = 7;
	date.month = 11;
	date.year = 2018;
	cout << assert(dayOfWeek(date), 3);

	date.day = 4;
	date.month = 9;
	date.year = 1997;
	cout << assert(dayOfWeek(date), 4);

	date.day = 18;
	date.month = 1;
	date.year = 1989;
	cout << assert(dayOfWeek(date), 3);

	date.day = 31;
	date.month = 3;
	date.year = 2001;
	cout << assert(dayOfWeek(date), 6);

	cout << endl;
}

int main()
{
	testCalcEaster();
	testAddDays();
	testSubtractDays();
	testCalcDuration();
	testCalcDurationDays();
	testDayOfWeek();

	return 0;
}