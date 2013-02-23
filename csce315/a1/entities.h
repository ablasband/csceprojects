// entities.h

using namespace std;	

#ifndef ENTITIES_H
#define ENTITIES_H

class Student
{
private:
	int num;
	Name name;
	string major;
public:
	Student(int n, Name na, string m) : num(n), 
	name(na), major(m) { }
	
	int getNum() { return num; }
	Name getName() { return name; }
	string getMajor() { return major; }
	
	string toString()
	{
		stringstream ss;
		ss << "Student: " << name.toString() << "(" << num << "): " << major; 
		return ss.str();
	}
};

class Department
{
private:
	int id;
	string name;
public:
	Department(int i, string n) : id(i), name(n) { }
	
	int getID() { return id; }
	string getName() { return name; }
	
	string toString()
	{
		stringstream ss;
		ss << "Department: " << name << "(" << id << ")";
		return ss.str();
	}
};

class Fine
{
private:
	int studentNumber;
	int departmentID;
	float amount;
	Date date;
	string fineType;
public:
	Fine(int s, int d, float a, Date da, string f) : 
	studentNumber(s), departmentID(d), amount(a), 
	date(da), fineType(f) { }
	
	int getStudentNumber() { return studentNumber; }
	int getDepartmentID() { return departmentID; }
	float getAmount() { return amount; }
	Date getDate() { return date; }
	string getFineType() { return fineType; }
	
	string toString()
	{
		stringstream ss;
		ss << "Fine: type " << fineType << "(" << studentNumber << ") in (" << departmentID << ") for " << amount << " on " << date.toString();
		return ss.str();
	}
};

class Payment
{
private:
	int studentNumber;
	float amount;
	Date date;
public:
	Payment(int s, float a, Date d) : studentNumber(s), 
	amount(a), date(d) { }

	int getStudentNumber() { return studentNumber; }
	float getAmount() { return amount; }
	Date getDate() { return date; }
	
	string toString()
	{
		stringstream ss;
		ss << "Payment: (" << studentNumber << ") for " << amount << " on " << date.toString();
		return ss.str();
	}
};

#endif
