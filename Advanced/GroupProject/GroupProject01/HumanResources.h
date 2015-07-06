//Rex Bowers HUMAN RESOURCES
#ifndef HUMANRESOURCES_H_
#define HUMANRESOURCES_H_
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>
#include "Inventory.h"
#include "Sales.h"
#include "CashFlow.h"

using namespace std;

class HumanResources 
{
private:
	string password;
public:
	//PROTOTYPES//////////////
	void humanResources();
	void employeeSubsystem();
	void addEmployee();
	void updateEmployee();
	void payrollSubsystem();
	void generatePaycheck();
	void reportsSubsystem();
	void weeklyReport();
	void quarterlyReport(int runningMonth);
	void annualReport(int runningYear);
	void dateRecognitionSoftware();
	int hrMain();
	void ReadPassword();
	string GetPassword() {return password;}
	void UpdatePassword(string value);

	//DATE RECOGNITION SOFTWARE///////////////////////////
	/*To use this software you must first input the current month, day, and the day of the week.
	* After the current information is input it will then store the information into the file.
	* The next run of the program or a user defined call point the software will ask for the information again
	*  only a calculation will occur between the two different dates.
	*/

	//GLOBALS/////////////////////////////////////////////
	//For files
	string Year;
	string Month;
	string Day;
	int runningMonth;
	int runningYear;
	string currentDayOfWeek;
};

#endif