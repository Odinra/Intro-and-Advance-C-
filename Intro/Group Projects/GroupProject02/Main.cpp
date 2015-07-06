/*CK King, Jennifer Perry, Bradley Ward
Group 1 Group Project 2
Section 1023
Creat a Sales and Payroll System
03/08/12 14:13 - 16:24 Create Program started main, added structure and AddNew
03/14/12 17:30 - 18:00 (CK) Added the menu loop, switch, and verification
03/14/12 18:15 - 19:28 (CK) Added the Paycheck and commision functions
03/18/12			   (BW) Added Payroll section, added decision statement for
							APT number, and fixed clerical issues
							Cannot go any further with PayrollEntry function, 
							encountering Linker errors
03/19/12 08:00 - 08:20 (CK & BW) Fixed Linker errors, fixed variables used by
						   multiple functions also cleared the screen as needed
Note for CK - Remember to work on cin statements, errors still occurring with
			the cin statements 
			DONE.
			  Also, need to change position and pay type from chars to ints, 
			  when encountered with the
			  cin statement for them, cannot continue through.
			DONE. Just changed it from || to && and fixed it.
03/19/12 17:50 - 20:06 (CK) did the neccessary loop statement used on the Email 
							Address, made the menu increment for the addNew, 
							changed the functions that recieve an employee
							parameter to recieve the whole array
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//Employee Structure
struct Emp
{
	//int variables
	int iId,
		iZip,
		iDep,
		iTotalHours;
	//string variables
	string sFirst,
		sLast,
		sAddress1,
		sAddress2,
		sCity,
		sState;	
	//double variables
	double dAmt,
		dCom,
		dBase,
		iPhone,
		dGross,
		dNet,
		dSales,
		iTotalSales;
	//char variables
	char cPos, //'s' or 'o'
		cPay, //'h' or 's'
		cEmail[101],//A Char array to search for a @;
		cApartmentChoice; //'Y', 'y', or 'N', 'n'
};

//prototypes for functions
Emp AddNew();
bool ExitSystem();
void Paycheck(Emp& );
double Commission(Emp);
void PayrollEntry(Emp eEmployee[]);

int main()
{
	//count to see which Employee is being used
	int iCount= 0, iMenu = 0, iPay = 0;

	//Exit break
	bool bExit = 0;

	//Employee structure array
	Emp Employee[9];

	//menu
	do
	{
		system("cls");
		//prompt
		cout << "Please select a menu option:\n\n"
			"1.\tAdd New Employee:\n"
			"2.\tSales Transaction Entry:\n"
			"3.\tPayroll Entry:\n"
			"4.\tGenerate Paycheck:\n"
			"5.\tExit System:\n\n";
		cin >> iMenu;
		
		//while loop
		while (iMenu < 0 || iMenu > 5)
		{
			system("cls");
			cout << "ERROR! INCORRECT ENTRY SELECTION!\n";
			cout << "Please select a menu option:\n\n"
				"1.\tAdd New Employee:\n"
				"2.\tSales Transaction Entry:\n"
				"3.\tPayroll Entry:\n"
				"4.\tGenerate Paycheck:\n"
				"5.\tExit System:\n\n";
			cin >> iMenu;
		}

		//menu switch
		switch (iMenu)
		{
			//set the Employee using the AddNew function
			case 1:system("cls");
				if (iCount < 10)
				   {
					   Employee[iCount] = AddNew();
					   iCount++;
				   }
				else
				   {
					   cout << "Error! Can only enter 10 employees!";
				   }
				break;
			//Jennifer's Sales Transaction Entry
			case 2:system("cls");
				break;
			//Brad's Payroll Entry
			case 3:system("cls");
				PayrollEntry(Employee);
				break;
		//CK's Paycheck function
			case 4:system("cls");
				if (iPay <= iCount)
				   {
					   Paycheck(Employee[iPay]);
					   cout << "\nPaycheck file for Employee Entry #" << iPay
						 << "\nEmployee ID #:" << Employee[iPay].iId
						 <<"\nEmployee Last Name:\n\t\t"<<Employee[iPay].sLast
						 << endl;
					   iPay++;
				   }
				   else
				   {
					   cout << "ERROR! Cannot create more Paychecks than "
						   "Employees Entered!\n Please either enter more "
						   "Employees.\nRemember, no more than 10 allowed!\n";
				   }
				break;
			//exit statement
			case 5:system("cls");
				ExitSystem();
				break;
		}

	} while (!bExit);
	return 0;

}

Emp AddNew()
{
	//Create an Employee sturct to be returned
	Emp eEmployee;
	//boolian variable to set the email value
	bool bEmail = 0;

	cout << "Please enter the the Employee's ID Number:\n";
	cin >> eEmployee.iId;
	cout << "Please enter the Employee's First Name:\n";
	cin.ignore();
	getline(cin, eEmployee.sFirst);
	cout << "Please enter the Employee's Last Name:\n";
	//cin.ignore();
	getline(cin, eEmployee.sLast);
	cout << "Please enter the Employee's Address (minus Apt. number)\n";
	//cin.ignore();
	getline(cin, eEmployee.sAddress1);
	cout << "Is your current residence at an apartment complex?\n";
	cin >> eEmployee.cApartmentChoice;
	if (eEmployee.cApartmentChoice == 'Y'|| eEmployee.cApartmentChoice == 'y')
	{
		cout << "Please enter the Employee's Apt. Number:\n";
		cin.ignore();
		getline(cin, eEmployee.sAddress2);
	}
	cout << "Please enter the Employee's City:\n";
	cin.ignore();
	getline(cin, eEmployee.sCity);
	cout << "PLease enter the Employee's State:\n";
	//cin.ignore();
	getline(cin, eEmployee.sState);
	cout << "Please enter the Employee's Zip Code:\n";
	//cin.ignore();
	cin >> eEmployee.iZip;
	while (eEmployee.iZip > 99999 || eEmployee.iZip < 10000)
	{
		cout << "Invalid Entry! Must contain 5 digits and cannot"
		"be negative";
		cout << "Please enter the Employee's Zip Code:\n";
		//cin.ignore();
		cin >> eEmployee.iZip;
	}
	cout << "Please enter the Employee's Home Phone Number:\n";
	//cin.ignore();
	cin >> eEmployee.iPhone;
	while (eEmployee.iPhone > 9999999999 || eEmployee.iPhone < 1000000000)
	{
		cout << "Invalid Entry! Must contain 10 digits and cannot"
		"be negative\n";
		cout << "Please enter the Employee's Phone Number:\n";
		//cin.ignore();
		cin >> eEmployee.iPhone;
	}
	cout << "Please enter the Employee's Email Address:\n";
	//cin.ignore();
	cin >> eEmployee.cEmail;
		
	for (int iEmail = 0; iEmail < 102; iEmail++)
	{
		if (eEmployee.cEmail[iEmail] == '@')
		{
			bEmail = 1;
		}
	}
	
	while(!bEmail)
	{
		cout << "Invalid Entry! Email must contain @ symbol.\n";
		cout << "Please enter the Employee's Email Address:\n";
		cin >> eEmployee.cEmail;
		
		for (int iEmail = 0; iEmail < 102; iEmail++)
		{
			if (eEmployee.cEmail[iEmail] == '@')
			{
				bEmail = 1;
			}
		}
	}

	cout << "Please enter the Employee's Number of Dependents:\n";
	//cin.ignore();
	cin >> eEmployee.iDep;
	while (eEmployee.iDep < 1)
	{
		cout << "Invalid Entry! Please enter a positive number";
		//cin.ignore();
		cin >> eEmployee.iDep;
	}
	cout << "Please enter the Employee's Position:\n"
		"(Enter s for Sales, and o for Office)\n";
	//cin.ignore();
	cin >> eEmployee.cPos;
	//eEmployee.cPos = 's';
	while (eEmployee.cPos != 's' && eEmployee.cPos != 'o')
	{
		//cout << endl << eEmployee.cPos << endl;
		cout << "INVALID ENTRY:\n";
		cout << "Please enter the Employee's Position:\n"
		"(Enter s for Sales, and o for Office)\n";
		cin >> eEmployee.cPos;
	}
	cout << "Please enter the Employee's Pay Type:\n"
		"(Enter h for Hourly and s for Salary)\n";
	cin >> eEmployee.cPay;
	while (eEmployee.cPay != 'h' && eEmployee.cPay != 's')
	{
		cout << "INVALID ENTRY:\n";
		cout << "Please enter the Employee's Pay Type:\n"
		"(Enter h for Hourly and s for Salary)\n";
		cin >> eEmployee.cPay;
	}
	cout << "Please enter the Employee's Pay Amount:\n";
	cin >> eEmployee.dBase;

	if (eEmployee.cPay == 's')
	{
		//to get it to a weekly amount
		eEmployee.dAmt = eEmployee.dBase / 52;
	}

	if (eEmployee.cPos == 's')
	{
		cout << "Please enter the Employee's Commission Percentage:\n"
			"(in Deicmal point form)\n";
		cin >> eEmployee.dCom;
	}
	else
		eEmployee.dCom = 1;


	return eEmployee;
}

bool ExitSystem()
{
       char cChoice = {0};

       cout << "Are you ready to exit the program? Y or N" << endl;
       cin >> cChoice;

       if(cChoice == 'Y' || cChoice == 'y')
       {
               cout << "Are your sure? Y or N" << endl;
               cin >> cChoice;

               if(cChoice == 'Y' || cChoice == 'y')
               {
                       return true;
               }
               else
               {
                       return false;
               }
       }else
       {
               return false;
       }
}

void Paycheck(Emp& Employee)
{

	const double FICAHI = .0145;
	const double OASDI = .042;
	double dFed;
	ofstream ofCheck;
	string sFileName, sName;
	sName = Employee.sLast;
	sFileName = sName + ".dat";

	//hourly hours
	int iHours;

	//calculate gross pay depending on salary or hourly
	if (Employee.cPay = 's')
	{
		Employee.dGross = Employee.dBase / 52;
	}
	else 
	{
		cout << "How many hours did the employee work this week?";
		cin >> iHours;
		Employee.dGross = Employee.dBase * iHours;
	}

	//determine whether sales or not, if so go to commision function
	if (Employee.cPos = 's')
	{
		Employee.dGross += Commission(Employee);
	}

	//determine net pay
	Employee.dNet = Employee.dGross;

	Employee.dNet -= (Employee.dGross * FICAHI);

	Employee.dNet -= (Employee.dGross * OASDI);

	//determine Fed Tax
	if (Employee.iDep == 1)
	{
		dFed = .35;
	}
	else if (Employee.iDep == 2)
	{
		dFed = .28;
	}
	else if (Employee.iDep == 3)
	{
		dFed = .24;
	}
	else
	{
		dFed = .18;
	}

	Employee.dNet -= (Employee.dGross *dFed);

	ofCheck.open(sFileName);

	ofCheck << fixed << setprecision(0) << Employee.iId << endl
		<< Employee.sFirst << " " << Employee.sLast << endl
		<< Employee.sAddress1 << "\n" << Employee.sAddress2 << endl;
	//commission if Sales Employee
	if (Employee.cPos == 's')
	{
		ofCheck << "Commision Amount:\n\t\t$" << Employee.dCom << endl;
	}
	
	ofCheck << "Gross Pay:\n\t\t$" << Employee.dGross
		<< "\nFICA HI Tax:\n\t\t$" << (Employee.dGross * FICAHI)
		<< "\nFICA OASDI Tax:\n\t\t$" << (Employee.dGross * OASDI)
		<< "\nFED Tax:\n\t\t$" << (Employee.dGross * dFed)
		<< "\nNet Pay:\n\t\t$" << Employee.dNet;


}

double Commission(Emp Employee)
{
	return (Employee.iTotalSales * Employee.dCom);
}

void PayrollEntry(Emp eEmployee[])
{
	int iEmpID = -1;
		//iTotalHours,
		//iTotalSales;

	//prompt
	cout << "Please enter the Employee's ID Number:\n";
	cin >> iEmpID;
	
	for (int iCount = 0; iCount < 9; iCount++)
	{
		if(iEmpID == eEmployee[iCount].iId)
		{
			if (eEmployee[iCount].cPay == 'h')
			{
				cout << "Please enter the amount of hours worked for the week:\n";
				cin >> eEmployee[iCount].iTotalHours;
				cout << "\n";
			}
			else if (eEmployee[iCount].cPay == 's')
			{
				cout << "Please enter the total amount of sales for the week:\n";
				cin >> eEmployee[iCount].iTotalSales;
				cout << "\n";
			}
		}	
	}
}