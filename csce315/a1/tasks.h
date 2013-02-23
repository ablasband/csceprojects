// tasks.h

using namespace std;	

#ifndef TASKS_H
#define TASKS_H

// function declarations

// printing functions
void printStudent(int studentNumber, vector<Student>& students, vector<Department>& departments, vector<Fine>& fines, vector<Payment>& payments);
void printDepartment(int departmentID, vector<Student>& students, vector<Department>& departments, vector<Fine>& fines, vector<Payment>& payments);
void printMajor(char major, vector<Student>& students, vector<Department>& departments, vector<Fine>& fines, vector<Payment>& payments);
void printInputLines(vector<string> inputLines);

// reading functions
vector<string> readInFile(string file);

// executing functions
void parseAndDo(vector<string> input, vector<Student>& students, vector<Department>& departments, vector<Fine>& fines, vector<Payment>& payments);

// extraneous functions
int identifyLine(string line); // gives an int value to the type of input
float adjustForInterest(float value, Date date, Date CURRENT_DATE);
float roundToHundreths(float value);


// function definitions

// printing functions
void printStudent(int studentNumber, vector<Student>& students, vector<Department>& departments, vector<Fine>& fines, vector<Payment>& payments)
{
	cout << "REPORT ON STUDENT # " << studentNumber << ":" << endl;
	
	float paid = 0;
	float owes = 0;
	float withInterest;
	
	// print student with matching id
	for (int i = 0; i < students.size(); i ++)
	{
		if (students.at(i).getNum() == studentNumber)
		{
			cout << students.at(i).toString() << endl;
		}
	}
	
	// print fines with matching id, calculate what student owes with interest
	for (int i = 0; i < fines.size(); i ++)
	{
		if (fines.at(i).getStudentNumber() == studentNumber)
		{
			withInterest = adjustForInterest(fines.at(i).getAmount(),fines.at(i).getDate(), Date(1,24,2013));
			cout << fines.at(i).toString() << " - " << withInterest << " with interest" << endl;
			owes += withInterest;
		}
	}
	
	// print payments with matching id
	for (int i = 0; i < payments.size(); i ++)
	{
		if (payments.at(i).getStudentNumber() == studentNumber)
		{
			cout << payments.at(i).toString() << endl;
			paid += payments.at(i).getAmount();
		}
	}
	
	// subtract paid from owed to get current balance
	cout << "Current balance: $" << owes - paid << " owed!" << endl;
	cout << endl;
}

void printDepartment(int departmentID, vector<Student>& students, vector<Department>& departments, 
				vector<Fine>& fines, vector<Payment>& payments)
{
	cout << "REPORT ON FINED STUDENTS IN DEPARTMENT # " << departmentID << ":" << endl;
	
	// collect list of studentNumbers from fines with same departmentID
	vector<int> studentNumbersFined;
	for (int i = 0; i < fines.size(); i ++)
	{
		if (fines.at(i).getDepartmentID() == departmentID)
		{
			studentNumbersFined.push_back(fines.at(i).getStudentNumber());
		}
	}
	
	for (int i = 0; i < studentNumbersFined.size(); i ++)
	{
		// print student with matching id
		for (int j = 0; j < students.size(); j ++)
		{
			if (students.at(j).getNum() == studentNumbersFined.at(i))
			{
				cout << students.at(j).toString() << endl;
			}
		}
	}
	
	cout << endl;
}

void printMajor(string major, vector<Student>& students, vector<Department>& departments, 
				vector<Fine>& fines, vector<Payment>& payments)
{
	cout << "REPORT ON STUDENTS WITH OUTSTANDING BALANCES IN " << major << ":" << endl;
	
	float paid = 0;
	float owes = 0;
	float withInterest;
	int studentNumber;
	
	// iterate through all students
	for (int i = 0; i < students.size(); i ++)
	{
		if (students.at(i).getMajor() == major)
		{
			paid = 0;
			owes = 0;
			studentNumber = students.at(i).getNum();
			
			for (int j = 0; j < fines.size(); j ++)
			{
				// tally up the students fines adjusted for interest in owes
				if (fines.at(j).getStudentNumber() == studentNumber)
				{
					withInterest = adjustForInterest(fines.at(j).getAmount(),fines.at(j).getDate(), Date(1,24,2013));
					owes += withInterest;
				}
			}
			
			// tally up the students payments in paid
			for (int j = 0; j < payments.size(); j ++)
			{
				if (payments.at(j).getStudentNumber() == studentNumber)
				{
					paid += payments.at(j).getAmount();
				}
			}
			
			// show student owes money if they have an outstanding total balance
			if (owes - paid > 0)
			{
				cout << students.at(i).toString() << " owes " << owes - paid << endl;
			}
		}
	}
	
	cout << endl;
}

void printInputLines(vector<string> inputLines)
{
	if (!inputLines.empty())
	{
		for (int i = 0; i < inputLines.size(); i ++)
		{
			cout << i << " " << inputLines.at(i) << endl;
		}
	}
	else
	{
		cout << "nothing here..." << endl;
	}
}

// reading functions
vector<string> readInFile(string file)
{
	string line;
  	ifstream inFile(file.c_str());
  
  	vector<string> input;
  
  	if (inFile.is_open())
  	{
    	while (inFile.good())
    	{
      		getline(inFile,line);
      		if (line.substr(0,1) != "#") input.push_back(line); // ignore comments indicated by '#'
    	}
    	inFile.close();
    	
    	return input;
  	}
  	else 
  	{
  		cerr << "Error: unable to open file" << endl; 
	}
}

// executing functions
void parseAndDo(vector<string> input, vector<Student>& students, vector<Department>& departments, 
				vector<Fine>& fines, vector<Payment>& payments)
{
	string line;
	
	while(!input.empty())
	{
		string dummy; // to catch the first 1 or 2 characters for line identification
		line = input.front();
		input.erase(input.begin());
			
		switch(identifyLine(line))
		{
			case 0: // add a student
			{
				int name;
				string firstName, lastName, major;
				stringstream ss;
				
				ss << line;
				ss >> dummy >> name >> firstName >> lastName >> major;
				
				students.push_back(Student(name,Name(firstName,lastName),major));
			}
			break;
			case 1: // add a department
			{
				int id;
				string name;
				stringstream ss;
				
				ss << line;
				ss >> dummy >> id >> name;
				
				departments.push_back(Department(id,name));
			}
			break;
			case 2: // add a fine
			{
				int studentNumber;
				int departmentID;
				float amount;
				int month;
				int day;
				int year;
				string fineType;
				stringstream ss;
				
				ss << line;
				ss >> dummy >> studentNumber >> departmentID >> amount >> month >> day >> year >> fineType;
				
				fines.push_back(Fine(studentNumber, departmentID, amount, Date(month, day, year), fineType));
			} 
			break;
			case 3: // add a payment
			{
				int studentNumber;
				float amount;
				int month;
				int day;
				int year;
				stringstream ss;
				
				ss << line;
				ss >> dummy >> studentNumber >> amount >> month >> day >> year;
				
				payments.push_back(Payment(studentNumber, amount, Date(month, day, year)));
			}
			break;
			case 4: // print student information
			{
				int studentNumber;
				stringstream ss;
				
				ss << line;
				ss >> dummy >> studentNumber;
				
				printStudent(studentNumber, students, departments, fines, payments);
			}
			break;
			case 5: // print department information
			{
				int departmentID;
				stringstream ss;
				
				ss << line;
				ss >> dummy >> departmentID;
				
				printDepartment(departmentID, students, departments, fines, payments);
			}
			break;
			case 6: // print major information
			{
				string major;
				stringstream ss;
				
				ss << line;
				ss >> dummy >> major;
				
				printMajor(major, students, departments, fines, payments);
			}
			break;
		}
	}
}

// extraneous functions
int identifyLine(string line)
{
	if (line.find("S",0) == 0) 			return 0; // student
	else if (line.find("D",0) == 0) 	return 1; // department
	else if (line.find("F",0) == 0) 	return 2; // fine
	else if (line.find("PS",0) == 0) 	return 4; // print student
	else if (line.find("PD",0) == 0) 	return 5; // print department
	else if (line.find("PM",0) == 0) 	return 6; // print major
	else if (line.find("P",0) == 0) 	return 3; // payment (do last so P* doesn't register as P_)
	else
	{
		cerr << "Error: unidentified input" << endl;
	}
}

float adjustForInterest(float value, Date date, Date CURRENT_DATE)
{
	return roundToHundreths(value*(float)pow(1.01,CURRENT_DATE.differenceInMonths(date)));
}

float roundToHundreths(float value)
{
	// reference: http://faculty.salisbury.edu/~dxdefino/RoundOff.htm
	return floor(value*100+0.5)/100;
}

#endif
