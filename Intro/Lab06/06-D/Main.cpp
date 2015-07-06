/*Christopher King, Derek
Section 1023
Create a program that calculates a travel expense for a company.
03/01/12 16:01 - 16:55 started program created iDays, iDepart.
03/01/12 20:45 - 22:03 created iArrive, dAir, dRent, dPrivate, dPark,
						dTaxi, dReg, dHotel, dMeal
03/02/12 12:00 - 12:35 started the report function
03/05/12 16:00 - finished report funcion and created main*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int Days();
double Depart();
double Arrive();
double Air();
double Rent();
double Private();
double Park(int iDays);
double Taxi(int iDays);
double Reg();
double Hotel(int iDays);
double Meal(double dDepart, double dArrive, int iDays);
void Report(int, double, double, double, double, double, double, double, 
	double,	double, double, ofstream&);


//main function
int main()
{
	//declare variables
	int iDays = 0;
	double dDepart = 0, dArrive = 0, dAir = 0, dRent = 0, dPrivate = 0, 
		dPark = 0, dTaxi = 0, dReg = 0, dHotel = 0, dMeal = 0;
	ofstream ofReport;

	//function calls and clear screens
	system("cls");
	iDays = Days();
	system("cls");
	dDepart = Depart();
	system("cls");
	dArrive = Arrive();
	system("cls");
	dAir = Air();
	system("cls");
	dRent = Rent();
	system("cls");
	dPrivate = Private();
	system("cls");
	dPark = Park(iDays);
	system("cls");
	dTaxi = Taxi(iDays);
	system("cls");
	dReg = Reg();
	system("cls");
	dHotel = Hotel(iDays);
	system("cls");
	dMeal = Meal(dDepart, dArrive, iDays);
	system("cls");

	ofReport.open("ExpenseReport.txt");
	if (ofReport.fail())
	{
		cout << "Error opening file!\n";
		exit(0);
	}
	else
	{
		Report(iDays, dDepart, dArrive, dAir, dRent, dPrivate, dPark, dTaxi, dReg,
		dHotel, dMeal, ofReport);
	}
	system("pause");
	return 0;
}

//days spent on trip
int Days()
{
	//declare
	int iDays = 0;

	//prompt
	cout << "How many days does the trip last\n";
	cin >> iDays;
	
	//validate
	while (iDays < 1)
	{
		cout << "Invalid Entry! You must enter a non-negative number greater"
			"than 0!\n";
		cin >>  iDays;
	}

	//return
	return iDays;
}

//time of departure
double Depart()
{
	//declare
	double dDepart = 0;
	
	//prompt
	cout << "What is your departure time (in military time) with a decimal "
		"between hours and minutes:\n\t";
	cin >> dDepart;

	while (dDepart > 23.59 || dDepart < 0)
	{
		cout << "Invalid Entry! You must enter a Valid time!";
		cin >> dDepart;
	}

	//return
	return dDepart;
}

//time of arrival
double Arrive()
{
	//declare
	double dArrive = 0;
	
	//prompt
	cout << "What is your arrival home time (in military time) with a decimal "
		"between hours and minutes:\n\t";
	cin >> dArrive;

	while (dArrive > 23.59 || dArrive < 0)
	{
		cout << "Invalid Entry! You must enter a Valid time!";
		cin >> dArrive;
	}

	//return
	return dArrive;
} 

//spent on airfare
double Air()
{
	//declare
	double dAir = 0;
	
	//prompt
	cout << "How much was spent on all airfare?\n\t";
	cin >> dAir;

	while (dAir < 0)
	{
		cout << "Invalid Entry! You must enter a Valid Dollar Amount!";
		cin >> dAir;
	}

	//return
	return dAir;
}

//amount spent on rent
double Rent()
{
	//declare
	double dRent = 0;
	
	//prompt
	cout << "How much was spent on a Vehicle Rental?\n\t";
	cin >> dRent;

	while (dRent < 0)
	{
		cout << "Invalid Entry! You must enter a Valid Dollar Amount!";
		cin >> dRent;
	}

	//return
	return dRent;
}

//private vehicle allowance
double Private()
{
	//declare
	double dMiles = 0, dAllowance;
	
	//prompt
	cout << "How many miles were driven?\n\t";
	cin >> dMiles;

	while (dMiles < 0)
	{
		cout << "Invalid Entry! You must enter a Valid Amount of miles!";
		cin >> dMiles;
	}

	//convert to allowance
	dAllowance = dMiles * .58;

	//return
	return dAllowance;
}

//parking spent
double Park(int iDays)
{
	//declare
	double dPark = 0, dAccume = 0;

	//for loop to add up values
	for(int iCount = 1; iCount <= iDays; iCount++)
	{
		//prompt
		cout << "How much was spent on parking for day " << iCount << ":\n\t";
		cin >> dPark;

		//validate
		while (dPark < 0)
		{
			cout << "Invalid Entry! You must enter a Valid Dollar Amount!";
			cin >> dPark;
		}

		//Make sure value is not greater than 12
		if (dPark > 12)
		{
			cout << "Only $12 per day allowed. Anything else will paid by the employee";
			dPark = 12;
		}

		//Accumulator
		dAccume += dPark;
	}

	return dAccume;
}

//taxi spent
double Taxi(int iDays)
{
	//declare
	double dTaxi = 0, dAccume = 0;

	//for loop to add up values
	for(int iCount = 1; iCount <= iDays; iCount++)
	{
		//prompt
		cout << "How much was spent on taxi fees for day " << iCount << ":\n\t";
		cin >> dTaxi;

		//validate
		while (dTaxi < 0)
		{
			cout << "Invalid Entry! You must enter a Valid Dollar Amount!";
			cin >> dTaxi;
		}

		//Make sure value is not greater than 40
		if (dTaxi > 40)
		{
			cout << "Only $40 per day allowed. Anything else will paid by the employee";
			dTaxi = 40;
		}

		//Accumulator
		dAccume += dTaxi;
	}

	return dAccume;
}

//registration spent
double Reg()
{
	//declare
	double dReg = 0;
	
	//prompt
	cout << "How much was spent on Conference or Seminar Registration?\n\t";
	cin >> dReg;

	while (dReg < 0)
	{
		cout << "Invalid Entry! You must enter a Valid Dollar Amount!";
		cin >> dReg;
	}

	//return
	return dReg;
}

//hotel spent
double Hotel(int iDays)
{
	//declare
	double dHotel = 0, dAccume = 0;

	//Get number of nights
	iDays--;

	//Don't break the loop
	if (iDays > 0)
	{
		//for loop to add up values
		for(int iCount = 1; iCount <= iDays; iCount++)
		{
			//prompt
			cout << "How much was spent on hotel expenditures for Night " 
				<< iCount << ":\n\t";
			cin >> dHotel;
	
			//validate
			while (dHotel < 0)
			{
				cout << "Invalid Entry! You must enter a Valid Dollar Amount!";
				cin >> dHotel;
			}
	
			//Make sure value is not greater than 40
			if (dHotel > 90)
			{
				cout << "Only $90 per day allowed. Anything else will paid by"
					" the employee";
				dHotel = 90;
			}
	
			//Accumulator
			dAccume += dHotel;
		}
	}
	else
	{
		dAccume = 0;
	}

	return dAccume;
}

//meals spent
double Meal(double dDepart, double dArrive, int iDays)
{
	//declare
	double dMeals = 0, dAccume = 0;
	int iCount = 1;

	//Departure breakfast
	if (iCount == 1 && dDepart <= 7)
	{
		//prompt
		cout << "How much was spent on Breakfast for morning " << iCount
			<< ":\n\t";
		cin >> dMeals;

		//validate
		while (dMeals < 0)
		{
			cout << "Invalid Entry! You must enter a Valid Dollar Amount!";
			cin >> dMeals;
		}

		//Make sure value is not greater than 40
		if (dMeals > 18)
		{
			cout <<"Only $18 per breakfast allowed. Anything else will paid by"
				" the employee";
			dMeals = 18;
		}
	
	
		dAccume += dMeals;
	}

	iCount ++;
	
	//for loop to add up values for breakfast
	for(; iCount <= iDays; iCount++)
	{
		//prompt
		cout << "How much was spent on Breakfast for morning " << iCount
			<< ":\n\t";
		cin >> dMeals;
		
		//validate
		while (dMeals < 0)
		{
			cout << "Invalid Entry! You must enter a Valid Dollar Amount!";
			cin >> dMeals;
		}
	
		//Make sure value is not greater than 18
		if (dMeals > 18)
		{
			cout <<"Only $18 per breakfast allowed. Anything else will paid by"
				" the employee";
			dMeals = 18;
		}
	
		//Accumulator
		dAccume += dMeals;
	}

	//reinitialize
	iCount = 1;

	//departure lunch
	if (iCount == 1 && dDepart <= 12)
	{
		//prompt
		cout << "How much was spent on Lunch for day " << iCount
			<< ":\n\t";
		cin >> dMeals;

		//validate
		while (dMeals < 0)
		{
			cout << "Invalid Entry! You must enter a Valid Dollar Amount!";
			cin >> dMeals;
		}

		//Make sure value is not greater than 12
		if (dMeals > 12)
		{
			cout <<"Only $12 per lunch allowed. Anything else will paid by"
				" the employee";
			dMeals = 12;
		}
	
	
		dAccume += dMeals;
	}

	iCount ++;
	
	//for loop to add up values for lunch
	for(; iCount <= iDays; iCount++)
	{
		//prompt
		cout << "How much was spent on Lunch for day " << iCount
			<< ":\n\t";
		cin >> dMeals;
		
		//validate
		while (dMeals < 0)
		{
			cout << "Invalid Entry! You must enter a Valid Dollar Amount!";
			cin >> dMeals;
		}
	
		//Make sure value is not greater than 12
		if (dMeals > 12)
		{
			cout <<"Only $12 per Lunch allowed. Anything else will paid by"
				" the employee";
			dMeals = 12;
		}
	
		//Accumulator
		dAccume += dMeals;
	}

	//reinitialize
	iCount = 1;

	//departure dinner 
	if (iCount == 1 && dDepart <= 18)
	{
		//prompt
		cout << "How much was spent on dinner for night " << iCount
			<< ":\n\t";
		cin >> dMeals;

		//validate
		while (dMeals < 0)
		{
			cout << "Invalid Entry! You must enter a Valid Dollar Amount!";
			cin >> dMeals;
		}

		//Make sure value is not greater than 20
		if (dMeals > 20)
		{
			cout <<"Only $20 per lunch allowed. Anything else will paid by"
				" the employee";
			dMeals = 20;
		}
	
	
		dAccume += dMeals;
	}

	iCount ++;
	
	//for loop to add up values for dinner
	for(; iCount <= iDays; iCount++)
	{
		//prompt
		cout << "How much was spent on dinner for night " << iCount
			<< ":\n\t";
		cin >> dMeals;
		
		//validate
		while (dMeals < 0)
		{
			cout << "Invalid Entry! You must enter a Valid Dollar Amount!";
			cin >> dMeals;
		}
	
		//Make sure value is not greater than 20
		if (dMeals > 20)
		{
			cout <<"Only $20 per Lunch allowed. Anything else will paid by"
				" the employee";
			dMeals = 20;
		}
	
		//Accumulator
		dAccume += dMeals;
	}

	//arrival breakfast
	if (dArrive <= 8)
	{
		//prompt
		cout << "How much was spent on Breakfast for morning " << iCount
			<< ":\n\t";
		cin >> dMeals;

		//validate
		while (dMeals < 0)
		{
			cout << "Invalid Entry! You must enter a Valid Dollar Amount!";
			cin >> dMeals;
		}

		//Make sure value is not greater than 40
		if (dMeals > 18)
		{
			cout <<"Only $18 per breakfast allowed. Anything else will paid by"
				" the employee";
			dMeals = 18;
		}
	
	
		dAccume += dMeals;
	}

	//arrival lunch
	if (dArrive <= 13)
	{
		//prompt
		cout << "How much was spent on Lunch for day " << iCount
			<< ":\n\t";
		cin >> dMeals;

		//validate
		while (dMeals < 0)
		{
			cout << "Invalid Entry! You must enter a Valid Dollar Amount!";
			cin >> dMeals;
		}

		//Make sure value is not greater than 12
		if (dMeals > 12)
		{
			cout <<"Only $12 per lunch allowed. Anything else will paid by"
				" the employee";
			dMeals = 12;
		}
	
	
		dAccume += dMeals;
	}

	//arrival dinner
	if (dArrive <= 19)
	{
		//prompt
		cout << "How much was spent on dinner for night " << iCount
			<< ":\n\t";
		cin >> dMeals;

		//validate
		while (dMeals < 0)
		{
			cout << "Invalid Entry! You must enter a Valid Dollar Amount!";
			cin >> dMeals;
		}

		//Make sure value is not greater than 20
		if (dMeals > 20)
		{
			cout <<"Only $20 per lunch allowed. Anything else will paid by"
				" the employee";
			dMeals = 20;
		}
	
	
		dAccume += dMeals;
	}

		return dAccume;
}

//report 
void Report(int iDays, double dDepart, double dArrive, double dAir, 
	double dRent, double dPrivate, double dPark, double dTaxi, double dReg,
	double dHotel, double dMeal, ofstream &ofReport)
{
	//declare a variable to get the correct maximum meals allowed
	double dMaxMeal = 0, dTotal = 0, dMaxTotal = 0;

	//if statements to adjust for departure and arrival times
	if (dDepart <= 7)
		dMaxMeal += 50;
	else if (dDepart <= 12)
		dMaxMeal += 32;
	else if (dDepart <= 18)
		dMaxMeal += 20;
	else
		dMaxMeal +=0;

	if (dArrive >= 8)
		dMaxMeal += 18;
	else if (dArrive >= 13)
		dMaxMeal += 30;
	else if (dArrive >= 19)
		dMaxMeal += 50;
	else
		dMaxMeal += 0;

	//calculate totals
	dTotal = dAir + dRent + dPrivate + dPark + dTaxi + dHotel + dMeal;
	dMaxTotal = ((12.00 * iDays) + (40.00 * iDays) + (90.00 * (iDays - 1)) + 
		(dMaxMeal + ((iDays-1) * iDays)));

	//display the report to the screen
	cout << "Total Number of days spent on the trip:\n\t\t" << iDays
		<< fixed << setprecision(2)
		<< "\nDeparture Time of the first day:\n\t\t" << dDepart
		<< "\nArral Home Time:\n\t\t" << dArrive
		<< "\nTotal Spent on AirFare:\n\t\t$" << dAir
		<< "\nTotal Spent on car Rentals:\n\t\t$" << dRent
		<< "\nTotal Spent on Private Vehicle Allowance:\n\t\t$" << dPrivate
		<< "\nTotal Spent on Parking:\n\t\t$" << dPark
		<< "\nMaximum Allowed on Parking:\n\t\t$" << (12.00 * iDays)
		<< "\nTotal Spent on Taxi Fees:\n\t\t$" << dTaxi
		<< "\nMaximum Allowed on Taxi Fees:\n\t\t$" << (40.00 * iDays)
		<< "\nTotal spent on Registration Fees:\n\t\t$" << dReg
		<< "\nTotal Spent on Hotel Expenses:\n\t\t$" << dHotel
		<< "\nMaximum Allowed on Hotel Expenses:\n\t\t$"<<(90.00 * (iDays - 1))
		<< "\nTotal Spent on Meals:\n\t\t$" << dMeal
		<< "\nMaximum Allowed on Meals:\n\t\t$" << (dMaxMeal + ((iDays-1) * iDays))
		<< "\nTotal Expenditures:\n\t\t$" << dTotal
		<< "\nMaximum Total Expenditures Allowed (only including expenditures "
		"with a cap)" << dMaxTotal
		<< endl;



	//send report to the file
	ofReport << "Total Number of days spent on the trip:\n\t\t" << iDays
		<< fixed << setprecision(2)
		<< "\nDeparture Time of the first day:\n\t\t" << dDepart
		<< "\nArral Home Time:\n\t\t" << dArrive
		<< "\nTotal Spent on AirFare:\n\t\t$" << dAir
		<< "\nTotal Spent on car Rentals:\n\t\t$" << dRent
		<< "\nTotal Spent on Private Vehicle Allowance:\n\t\t$" << dPrivate
		<< "\nTotal Spent on Parking:\n\t\t$" << dPark
		<< "\nMaximum Allowed on Parking:\n\t\t$" << (12.00 * iDays)
		<< "\nTotal Spent on Taxi Fees:\n\t\t$" << dTaxi
		<< "\nMaximum Allowed on Taxi Fees:\n\t\t$" << (40.00 * iDays)
		<< "\nTotal spent on Registration Fees:\n\t\t$" << dReg
		<< "\nTotal Spent on Hotel Expenses:\n\t\t$" << dHotel
		<< "\nMaximum Allowed on Hotel Expenses:\n\t\t$" << (90 * (iDays - 1))
		<< "\nTotal Spent on Meals:\n\t\t$" << dMeal
		<< "\nMaximum Allowed on Meals:\n\t\t$" << (dMaxMeal + ((iDays-1) * iDays))
		<< "\nTotal Expenditures:\n\t\t$" << dTotal
		<< "\nMaximum Total Expenditures Allowed (only including expenditures "
		"with a cap)" << dMaxTotal
		<< endl;
}