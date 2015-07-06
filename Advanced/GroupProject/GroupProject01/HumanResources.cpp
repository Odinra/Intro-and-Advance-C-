#include "HumanResources.h"

void HumanResources::dateRecognitionSoftware()
{
	string currentMonth;
	//For user purposes
	string currentMonthName;
	string currentDay;
	string currentYear;
	string Choice;
	fstream File;
	File.open("Date.txt");
	File >> Month >> Day;
	
	File.close();
	cout << "                 DATE RECOGNITION SOFTWARE ACTIVATING                 \n\n"; 
	cout << "Enter the current Month (Format: 1, 3, 12): ";
	cin >> currentMonth;
	cout << "Enter the current Day of the Month (Format: 1, 15, 20, 31): ";
	cin >> currentDay;
	cout << "Enter the current Year (Format: 1, 5, 11, 12, 13): 20";
	cin >> currentYear;
	cout << "Enter the current Day of the Week (Format: Monday, Tuesday, etc.): ";
	cin >> currentDayOfWeek;
	if(currentMonth == "1")
	{
		currentMonthName = "January";
	}
	else if(currentMonth == "2")
	{
		currentMonthName = "February";
	}
	else if(currentMonth == "3")
	{
		currentMonthName = "March";
	}
	else if(currentMonth == "4")
	{
		currentMonthName = "April";
	}
	else if(currentMonth == "5")
	{
		currentMonthName = "May";
	}
	else if(currentMonth == "6")
	{
		currentMonthName = "June";
	}
	else if(currentMonth == "7")
	{
		currentMonthName = "July";
	}
	else if(currentMonth == "8")
	{
		currentMonthName = "August";
	}
	else if(currentMonth == "9")
	{
		currentMonthName = "September";
	}
	else if(currentMonth == "10")
	{
		currentMonthName = "October";
	}
	else if(currentMonth == "11")
	{
		currentMonthName = "November";
	}
	else if(currentMonth == "12")
	{
		currentMonthName = "December";
	}

	cout << currentMonthName << " " << currentDay << ", 20" << currentYear;
	cout << endl << "Is this the current date? Enter yes or no: ";
	cin >> Choice;
	if(Choice == "yes" || Choice == "Yes")
	{
		if(Month == "" && Day == "")
		{
			runningMonth = stoi(currentMonth);
			runningYear = 1;
		}
		else if(Month != "" || Day != "")
		{
			
		if(currentYear > Year)
		{
			//Year advancment equation
			runningYear += 1;
			//Month advancement equation
			runningMonth =  stoi(currentMonth) - (stoi(Month) + 12);
		}
		else
		{
			runningMonth = stoi(currentMonth) - stoi(Month);
		}

		}

	}
	else
	{
		dateRecognitionSoftware();
	}
	


}

//MAIN///////////////////////////
int HumanResources::hrMain()
{
	int menu;
	bool exit = false;
	ReadPassword();
	/*dateRecognitionSoftware();	*/
	cout << "\n----------Simulating Menu Selection---------- \n\n";
	do
	{
	cout << "Select a menu option: \n" << "(1) Human Resources \n" << "(2) Start the Date Recognition Software \n" <<
		"(3) Exit Program \n";
	cin >> menu;
	switch(menu)
	{
	case 1:
		humanResources();
		break;
	case 2:
		dateRecognitionSoftware();
		break;
	case 3:
		exit = true;
		break;
	default:
		break;
	}
	}
	while(exit != true);
	return(0);
}

//HUMAN RESOURCES//////////////////////
void HumanResources::humanResources()
{
	int menu;
	bool exit = false;
	do
	{
	cout << "\nHuman Resources: \n" << "(1) Employee Subsystem \n" << "(2) Payroll Subsystem \n" <<
		"(3) Reports Subsystem \n" << "(4) Exit Human Resources \n";
	cin >> menu;
	switch(menu)
	{
	case 1:
		cout << "Enter the password for this system: ";
		cin >> password;
		if(password == GetPassword())
			employeeSubsystem();
		else
			cout << "Password is incorrect. \n";
		break;
	case 2: 
		cout << "Enter the password for this system: ";
		cin >> password;
		if(password == GetPassword())
			payrollSubsystem();
		else
			cout << "Password is incorrect. \n";
		break;
	case 3:
		cout << "Enter the password for this system: ";
		cin >> password;
		if(password == GetPassword())
			reportsSubsystem();
		else
			cout << "Password is incorrect. \n";
		break;
	case 4: 
		exit = true;
		break;
	default:
		break;
	}
	}
	while(exit != true);
}

//SUBSYSTEMS FOR HUMAN RESOURCES//////////////////////
void HumanResources::employeeSubsystem()
{
	int menu;
	bool exit = false;
	cout << "\n-----------Employee Subsystem-----------\n";

	do
	{
	cout << "Subsystem Commands: \n" << "(1) Add Employee \n" << "(2) Update Employee Information \n" << "(3) Exit Subsystem \n";
	cin >> menu;
	switch(menu)
	{
	case 1:
		addEmployee();
		break;
	case 2: 
		updateEmployee();
		break;
	case 3: 
		exit = true;
		break;
	default:	
		break;
	}
	}
	while(exit != true);
}

//EMPLOYEE SUBSYSTEM ROUTES////////////////////////////////////////////////////////////////////////////
void HumanResources::addEmployee()
{
	fstream File;
	string Choice;
	string fileName;
	//VARIABLES///////////////
	//Full Name
	string nameLine;
	string First, Middle, Last, Maiden;
	//ID
	string ID;
	//Address///////
	string Address;
	//Phone Number
	string Phone;
	//Dependents
	string Dependents;
	//Pay Type
	string payType;
	//Pay Rate
	string payRate;
	//Add new employee number
	string Employees;
	int employeeNumber;
	//Enter the information into a new file using the last name
	cout << "Enter the first name: ";
	cin >> First;
	cout << "\nEnter the middle name: ";
	cin >> Middle;
	cout << "\nEnter the last name: ";
	cin >> Last;
	cout << "\nIs there a maiden name? (yes or no): ";
	cin >> Choice;
	if(Choice == "yes" || Choice == "Yes")
	{
	cout << "\nEnter the maiden name: ";
	cin >> Maiden;
	}
	cout << "\nEnter an ID number: ";
	cin >> ID;
	cin.ignore();
	cout << "\nEnter the full address (Street, City, State, Zip): \n";
	getline(cin, Address);
	cout << "\nEnter a Phone number: ";
	cin >> Phone;
	cin.ignore();
	cout << "\nEnter number of dependents: ";
	getline(cin, Dependents);
	//
	//Some Issues have been known here:
	cout << "\nEnter the pay type (Salary, Hourly): ";
	cin >> payType;
	cin.ignore();		
	//
	//
	cout << "\nEnter the pay rate (For salary enter the weekly rate, no commas): $";
	getline(cin, payRate);
	//Create the file
	fileName = Last;
	fileName.append(".txt");
	File.open(fileName, ios::out);
	//Name line
	File << First + " " + Middle + " " + Last + " " + Maiden << endl
		//ID line
		<< ID  << endl
		//Address Line
		<< Address << endl
		//Phone line
		<< Phone << endl
		//Dependents
		<< Dependents << endl 
		//Pay Type line
		<< payType << endl
		//Pay rate line
		<< payRate;
	File.close();
	//Now update the Employee index file(ei)
	File.open("ei.txt", ios::in);	
	if(File.fail())
	{
		employeeNumber = 0;
	}
	else
	{
		File >> Employees;
		employeeNumber = stoi(Employees);
		
	}
	File.close();
	
	employeeNumber++;
	
	File.open("ei.txt", ios::out);
	File << employeeNumber;
	File.seekp(0L, ios::end);
	File << endl << Last;
	File.close();
	cout << "\n\nFile saved successfully.\n\n";
}

void HumanResources::updateEmployee()
{
	fstream File;

	//VARIABLES///////////////
	//Full Name
	string nameLine;
	string First, Middle, Last, Maiden;
	//ID
	string ID;
	//Address
	string Address;
	//Phone Number
	string Phone;
	//Dependents
	string Dependents;
	//Pay Type
	string payType;
	//Pay Rate
	string payRate;
	string fileName;
	string Update;
	string bufferLine;
	string Choice;
	//Used for the employee index
	string Employees;
	int employeeNumber;
	//Search for certain file and update it
	cout << "Enter a file name to update it (The file name is the employee's last name): \n";
	cin >> fileName;
	fileName.append(".txt");
	File.open(fileName);
	if(!File)
	{
		cout << "ERROR! FILE NOT FOUND!";
	}
	else
	{
	//Store File information into the variables as strings
	//No calculations can be made with said string variables as they are
	getline(File, nameLine);
	File >> ID;
	File.ignore();
	getline(File, Address);
	getline(File, Phone);
	
	File >> Dependents >> payType >> payRate;
	//Display the information
	cout << nameLine << endl
		//ID line
		<< ID << endl
		//Address Line
		<< Address << endl
		//Phone line
		<< Phone << endl 
		//Dependents
		<< Dependents << endl 
		//Pay Type line
		<< payType << endl
		//Pay rate line
		<< payRate << endl;
	File.close();
	cout << "Is this the employee information you want to update? Enter yes or no:";
	cin >> Update;
	//If yes then update the employee
	if(Update == "yes" || Update == "Yes")
	{
	cout << "Please note that a different last name will result in a different file being written. \n";
	cout << "Enter the first name: ";
	cin >> First;
	cout << "\nEnter the middle name: ";
	cin >> Middle;
	cout << "\nEnter the last name: ";
	cin >> Last;
	cout << "\nIs there a maiden name? (yes or no): ";
	cin >> Choice;
	if(Choice == "yes" || Choice == "Yes")
	{
	cout << "\nEnter the maiden name: ";
	cin >> Maiden;
	}
	cout << "\nEnter an ID number: ";
	cin >> ID;
	cout << "\nEnter an Address (Street, City, State, Zip): ";
	getline(cin, Address);
	cout << "\nEnter a Phone number: ";
	cin >> Phone;
	cout << "\nEnter number of dependents: ";
	cin >> Dependents;

		cout << "\nEnter the pay type (Salary or Hourly): ";
		cin >> payType;

	cout << "\nEnter the pay rate (For salary enter the weekly rate, no commas): $";
	cin >> payRate;
	//Write Information to a file
	File.open(Last);
	//Name line
	File << nameLine << endl
		//ID line
		<< ID << endl
		//Address Line
		<< Address << endl
		//Phone line
		<< Phone << endl
		//Dependents
		<< Dependents << endl
		//Pay Type line
		<< payType << endl
		//Pay rate line
		<< payRate;
	File.close();

	cout << "\n\nFile updated successfully.\n\n";
	}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//PAYROLL SUBSYSTEM ROUTES////////////////////////////////////////////////////////////////////////////
void HumanResources::payrollSubsystem()
{
	int menu;
	bool exit = false;
	cout << "\n-----------Employee Subsystem-----------\n";

	do
	{
	cout << "Subsystem Commands: \n" << "(1) Generate Weekly Paycheck \n" << "(2) Exit Subsystem \n";
	cin >> menu;
	switch(menu)
	{
	case 1:
		generatePaycheck();
		break;
	case 2: 
		exit = true;
		break;
	default:	
		break;
	}
	}
	while(exit != true);
}
void HumanResources::generatePaycheck()
{
	fstream File;
	string employeeName;
	string employeeFileName;
	//Employee Information file Variables
	string Dependents;
	string payType;
	string payRate;
	//Loop Variables
	double Pay = 0;
	int numberOfEmployees = 0;
	string Employees;
	int workTime = 0;
	int Index = 0;
	double overtime = 0;
	string Worked;
	string Overtime;
	//Payroll employee file variables
	double grossPay;
	double overtimePay;
	double ficaHi;
	double ficaOasdi;
	double fedTax;
	double netPay;
	//Pointer to string array for adding employee Names
	string *totalEmployees;

	//EMPLOYEE INDEX
	File.open("ei.txt");
	File >> Employees;
	numberOfEmployees = stoi(Employees);
	totalEmployees = new string[numberOfEmployees];
	//Insert the employee names from the employee index file
	for(Index = 0; Index < numberOfEmployees; Index++)
	{
		File >> *(totalEmployees + Index);
	}
	File.close();


	for(Index = 0; Index < numberOfEmployees; Index++)
	{
		//Open the EmployeeFile using lastnames
		employeeName = *(totalEmployees + Index);
		employeeFileName = *(totalEmployees + Index);
		employeeFileName.append(".txt");
		File.open(employeeFileName);
		//Ignore name, ID, Address, number
		// and take dependents, paytype, and payrate
		File.ignore();
		File.ignore();
		File.ignore();
		File.ignore();
		File >> Dependents >> payType >> payRate;
		File.close();
		Pay = stod(payRate);
		//Open the employeePayroll file using lastname with payroll
		employeeFileName = *(totalEmployees + Index);
	employeeFileName.append("Payroll.txt");
	//Open the payroll file for the employee
	File.open(employeeFileName, ios::in);
	if(File.is_open())
	{
	File.ignore();
	File >> grossPay;
	File.ignore();
	File >> overtimePay; 
	File.ignore();
	File >> ficaHi;
	File.ignore();
	File >> ficaOasdi;
	File.ignore();
	File >> fedTax;
	File.ignore();
	File >> netPay;
	}
	File.close();
	if(payType == "Hourly" || payType == "hourly")
	{
		while(workTime < 0 || workTime > 65)
		{
		cout << "Enter the number of hours worked during the week for " << employeeName << ": ";
		cin >> workTime;
		if(workTime > 65)
		{
			cout << "Number of hours worked cannot exceed 5 days for a week.";
		}
		}
		cout << "Did " << employeeName << " work overtime? (Yes or No)";
		cin >> Overtime;
		if(Overtime == "Yes" || Overtime == "yes")
		{
			cout << "How many hours of overtime were worked?";
			cin >> overtime;
		}
		//Days times number of hours in the work days
		//Amount of time multiplied by the pay rate
		Pay *= workTime;
		
		grossPay += Pay;
		overtimePay = overtime * Pay;
		//Gross is now complete

	}
	else if(payType == "Salary" || payType == "salary")
	{
		overtimePay = 0;
		cout << "Did the salary employee " << employeeName << " work this week? (Yes or No): ";
		cin >> Worked;
		if(Worked == "yes" || Worked == "Yes")
		{
			break;
		}
		else
		{
			Pay = 0;
		}
		grossPay += Pay;
	}
	//Fica-Hi Tax
	ficaHi = 0.0145 * grossPay;
	//Fica-Oasdi Tax
	ficaOasdi = 0.042 * grossPay;
	//Federal Tax
	if(Dependents == "1")
	{
		fedTax = .35 * grossPay;
	}
	else if(Dependents == "2")
	{
		fedTax = .28 * grossPay;
	}
	else if(Dependents == "3")
	{
		fedTax = .24 * grossPay;
	}
	else if(Dependents == "4")
	{
		fedTax = .18 * grossPay;
	}
	else
	{
		fedTax = .13 * grossPay;
	}
	//Net Pay
	netPay = grossPay - (ficaHi + ficaOasdi + fedTax);
	netPay += overtimePay;
	//
	//Output all the information to the file
	//
	//
	File.open(employeeFileName);
	File.clear();
	File << "Gross Pay: " << endl << grossPay << endl << "Overtime Pay: " << endl << overtimePay << endl << "Fica-Hi Tax: " << endl << ficaHi << endl << "Fica-Oasdi Tax: " << endl
		<< ficaOasdi << endl << "Federal Tax: " << fedTax << endl << "Net Pay: " << netPay;
	File.close();

	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//REPORTS SUBSYSTEM ROUTES////////////////////////////////////////////////////////////////////////////
void HumanResources::reportsSubsystem()
{
	fstream File;
	string employeeName;
	string employeeFileName;
	double weeklyPay;
	int Choice;
	bool exit = false;
	cout << "\n-----------Reports Subsystem-----------\n";
	do
	{
		cout << "Subsystem Commands: " << endl << "(1) Create or View Weekly Report " << endl << "(2) Create or View Quarterly Report " << endl
		<< "(3) Create or View Annual Report " << endl << "(4) Exit Subsystem";
	cin >> Choice;
	switch(Choice)
	{
	case 1:
		weeklyReport();
		break;
	case 2:
		quarterlyReport(runningMonth);
		break;
	case 3:
		annualReport(runningYear);
		break;
	case 4:
		exit = true;
		break;
	default:
		continue;
	}
	}
	while(exit != true);

}

void HumanResources::weeklyReport()
{
	fstream File;
	int numberOfEmployees=0;
	string *totalEmployees;
	string *employeePay;
	string employeeFileName;
	string employeePayType;
	string Employees;
	string netPay;
	double Pay;
	File.open("ei.txt");
	File >> Employees;
	totalEmployees = new string[numberOfEmployees];
	employeePay = new string[numberOfEmployees];
	//Insert the employee names from the employee index file
	for(int Index = 0; Index < numberOfEmployees; Index++)
	{
		File >> *(totalEmployees + Index);
	}
	File.close();
	for(int Index = 0; Index < numberOfEmployees; Index++)
		{
		employeeFileName = *(totalEmployees + Index);
		employeeFileName.append("Payroll.txt");
		File.open(employeeFileName);
		File.ignore();
		File.ignore();
		File.ignore();
		File.ignore();
		File.ignore();
		File >> netPay;
		File.close();
		Pay = stod(netPay);
		//Get the pay type
		employeeFileName = *(totalEmployees + Index);
		employeeFileName.append(".txt");
		File.open(employeeFileName);
		File.ignore();
		File.ignore();
		File.ignore();
		File.ignore();
		File.ignore();
		File >> employeePayType;
		File.close();

		if(employeePayType == "Hourly" || employeePayType == "hourly")
		{
			Pay *= 5;
		}
		*(employeePay + Index) = Pay;
		
		}
}

void HumanResources::quarterlyReport(int runningMonth)
{
	fstream File;
	int numberOfEmployees=0;
	double Pay;
	string Employees;
	string *totalEmployees;
	string *employeePay;
	string employeeFileName;
	string netPay;
	string bufferLine;
	string employeePayType;
	//If time since last run is greater than 2 months
	// Then create/update the report
	File.open("ei.txt");
	File >> Employees;
	totalEmployees = new string[numberOfEmployees];
	employeePay = new string[numberOfEmployees];
	//Insert the employee names from the employee index file
	for(int Index = 0; Index < numberOfEmployees; Index++)
	{
		File >> *(totalEmployees + Index);
	}
	File.close();
	if(runningMonth >= 2)
	{
		
		for(int Index = 0; Index < numberOfEmployees; Index++)
		{
		employeeFileName = *(totalEmployees + Index);
		employeeFileName.append("Payroll.txt");
		File.open(employeeFileName);
		File.ignore();
		File.ignore();
		File.ignore();
		File.ignore();
		File.ignore();
		File >> netPay;
		File.close();
		Pay = stod(netPay);
		employeeFileName = *(totalEmployees + Index);
		employeeFileName.append(".txt");
		File.open(employeeFileName);
		File.ignore();
		File.ignore();
		File.ignore();
		File.ignore();
		File.ignore();
		File >> employeePayType;
		File.close();

		//Multiply by three to indicate three months have passed
		//
		if(employeePayType == "Hourly" || employeePayType == "hourly")
		{
			Pay *= 5;
			Pay *= 4;
			Pay *= 3;
		}
		//Weeks in one month;
		else if(employeePayType == "Salary" || employeePayType == "salary")
		{
		Pay *= 4;
		//3 months
		Pay *= 3;
		}
		*(employeePay + Index) = Pay;
		
		}

		File.open("QuarterlyHumanReport");
		File.clear();
		for(int Index = 0; Index < numberOfEmployees; Index++)
		{
		//Name1
		//Pay1
		//Name2
		//Pay2 
		File << *(totalEmployees + Index) << endl << *(employeePay + Index);	
		}
		File.close();
		cout << "Now displaying the quarterly report file: " << endl;
		File.open("QuarterlyHumanReport");
		while(!File.eof())
		{
			File >> bufferLine;
			cout << bufferLine;
		}
		File.close();
	}
	else
	{
		cout << "There has not been a long enough time to create another quarterlyReport. " << endl;
	}
}

void HumanResources::annualReport(int runningYear)
{
	fstream File;
	int numberOfEmployees=0;
	double Pay;
	string Employees;
	string *totalEmployees;
	string *employeePay;
	string employeeFileName;
	string netPay;
	string bufferLine;
	string employeePayType;
	//If time since last run is greater than 2 months
	// Then create/update the report
	File.open("ei.txt");
	File >> Employees;
	totalEmployees = new string[numberOfEmployees];
	employeePay = new string[numberOfEmployees];
	//Insert the employee names from the employee index file
	for(int Index = 0; Index < numberOfEmployees; Index++)
	{
		File >> *(totalEmployees + Index);
	}
	File.close();
	if(runningYear > 1)
	{
		
		for(int Index = 0; Index < numberOfEmployees; Index++)
		{
		employeeFileName = *(totalEmployees + Index);
		employeeFileName.append("Payroll.txt");
		File.open(employeeFileName);
		File.ignore();
		File.ignore();
		File.ignore();
		File.ignore();
		File.ignore();
		File >> netPay;
		File.close();
		Pay = stod(netPay);
		employeeFileName = *(totalEmployees + Index);
		employeeFileName.append(".txt");
		File.open(employeeFileName);
		File.ignore();
		File.ignore();
		File.ignore();
		File.ignore();
		File.ignore();
		File >> employeePayType;
		File.close();

		//Multiply by three to indicate three months have passed
		//
		if(employeePayType == "Hourly" || employeePayType == "hourly")
		{
			Pay *= 5;
			Pay *= 4;
			Pay *= 12;
		}
		//Weeks in one month;
		else if(employeePayType == "Salary" || employeePayType == "salary")
		{
		Pay *= 4;
		//3 months
		Pay *= 12;
		}
		*(employeePay + Index) = Pay;
		
		}
		File.open("AnnuallyHumanReport");
		File.clear();
		for(int Index = 0; Index < numberOfEmployees; Index++)
		{
		//Name1
		//Pay1
		//Name2
		//Pay2 
		File << *(totalEmployees + Index) << endl << *(employeePay + Index);	
		}
		File.close();
		cout << "Now displaying the annual report file: " << endl;
		File.open("AnnuallyHumanReport");
		while(!File.eof())
		{
			File >> bufferLine;
			cout << bufferLine;
		}
		File.close();
	}
	else
	{
		cout << "There has not been a long enough time to create another annuallyReport. " << endl;
	}
}

void HumanResources::ReadPassword()
{
	fstream File;
	string password;

	File.open("Password.txt");
	getline(File, password);
	File.close();

	UpdatePassword(password);
}
void HumanResources::UpdatePassword(string value)
{
	password = value;
	fstream File;

	File.open("Password.txt", ios::out);	
	File << password;
	File.close();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////