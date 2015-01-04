#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "date.h"
#include "duration.h"

void clearScreen();

void waitUntilEnter();

int charToInt(char c);

int daysInMonthCount(int month, int year);

int daysInMonthCount(Date);

int daysInYearCount(int);

int daysUpToNowThisYear(Date);

void swapDates(Date&, Date&);

int compareDates(Date, Date);

bool isFirstDateEarlier(Date, Date);

// check if date is in month
bool isDateCorrect(Date);

Date addDays(Date, int);

Date subtractDays(Date, int);

Duration calcDuration(Date, Date);

int calcDurationDays(Date, Date);

bool isLeapYear(int year);

int pastLeapYearsCount(int year);

int dayOfWeek(Date);

const char* getWeekdayName(int dayCode);

const char* getMonthName(int month);

void printDate(Date, int formatCode = 0);

void printCalendar(int firstDayOfWeek);

Date addDays(Date date, int days);

Date calcEaster(int year);

int holidayCountInInterval(Date, Date, Date holidays[], int, Date workOffDays[], int);

bool dateExists(Date[], int, Date);

int datesInIntervalCount(Date[], int, Date, Date);

int weekendDaysInIntervalCount(Date, Date);

#endif /* FUNCTIONS_H_ */
