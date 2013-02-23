//trackerMain.cpp

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <math.h>
#include "helperClasses.h"
#include "entities.h"
#include "tasks.h"

using namespace std;	
 
int main()
{
	vector<Student> students;
	vector<Department> departments;
	vector<Fine> fines;
	vector<Payment> payments;
	vector<string> inputLines;
	
	// input variables	
	int in = -1;
	string inLine = "";
	
	while (in != 0)
	{
		cout << "------------MEMORY------------" << endl;
		printInputLines(inputLines);
		cout << "------------PROMPT------------" << endl
			 << "Hello, what do you want to do?" << endl
		     << "1. enter a line" << endl
		     << "2. enter a file" << endl
		     << "3. execute" << endl
		     << "4. clear memory" << endl
		     << "0. exit" << endl
		     << "------------INPUT-------------" << endl;
		     
		cout << "> ";
		cin >> in;
		cin.ignore();
		cout << endl;
		
		switch(in)
		{
			case 0: // exit
				return 0;
				break;
			case 1: // manually add instructions to the queue
				cout << "enter a line to add:" << endl;
				getline(cin,inLine);
				inputLines.push_back(inLine);
				break;
			case 2: // read instructions from a file to the queue
				cout << "enter a filename: ";
				getline(cin,inLine);
				inputLines = readInFile(inLine);
				break;
			case 3: // execute the stored instructions
				cout << "-----------RESPONSE-----------" << endl;
				parseAndDo(inputLines, students, departments, fines, payments);
				break;
			case 4: // erase the stored instructions
				inputLines.erase(inputLines.begin(),inputLines.end());
				break;
			default: // wrong input
				cerr << "Error: unidentified option" << endl;
		}
	}
	
    
    return 0;
}
