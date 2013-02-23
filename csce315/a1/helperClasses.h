// helperClasses.h

using namespace std;	

#ifndef HELPERCLASSES_H
#define HELPERCLASSES_H

class Date
{
private:
	int month;
	int day;
	int year;
public:
	Date(int m, int d, int y) : month(m), day(d), year(y) { }
	string toString()
	{
		stringstream ss;
		ss << "[" << month << "/" << day << "/" << year << "]";
		return ss.str(); 
	}
	
	int differenceInMonths(Date &otherDate)
	{	
		return abs(otherDate.getMonth() - month) + abs(otherDate.getYear() - year)*12;
	}
	
	int getMonth() { return month; }
	int getDay() { return day; }
	int getYear() { return year; }
};

class Name
{
private:
	string first;
	string last;
public:
	Name(string f, string l) : first(f), last(l) { }
	string toString()
	{
		stringstream ss;
		ss << first << " " << last;
		return ss.str();
	}
};

#endif
