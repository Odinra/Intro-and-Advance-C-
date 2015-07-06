/* Christopher King
Section 1023
A program that determines which division has the greatest sales
02/28/12 19:28 - 20:47 create main, dGetSales, and vFindHighest functions*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//prototypes
double dGetSales(string);
void vFindHighest(double, double, double, double);

int main()
{
	//declare variables
	double dNE, dSE, dNW, dSW;

	//function calls
	dNE = dGetSales("Northeast");
	dSE = dGetSales("Southeast");
	dNW = dGetSales("Northwest");
	dSW = dGetSales("Southwest");

	vFindHighest(dNE, dSE, dNW, dSW);
	system("pause");
	return 0;
}

//function to get the sales
double dGetSales(string sDivision)
{
	//declare
	double dSales = 0;

	//prompt
	cout << "Please enter the sales for " << sDivision << endl;
	cin >> dSales;
	
	//validate
	while (dSales < 0)
	{
		cout << "Invalid Input, sales cannot be negative"
			<< "Please enter the sales for " << sDivision;
		cin >> dSales;
	}

	//return
	return dSales;
}

// function to find the best division
void vFindHighest (double dNE, double dSE, double dNW, double dSW)
{
	//set the precision to 2 to set the price
	cout << fixed << setprecision(2);

	//several if statements to find the correct highest price since 
	//we havent gone over sorting functions 
	if (dNE > dSE && dNE > dNW && dNE > dSW)
	{
		cout << "Northeast division had the highest sales figure of\n\t\t\t\t$"
			<< dNE << endl;
	}
	else if (dSE > dNE && dSE > dNW && dSE > dSW)
	{
		cout << "Southeast division had the highest sales figure of\n\t\t\t\t$"
			<< dSE << endl;
	}
	else if (dNW > dNE && dNW > dSE && dNW > dSW)
	{
		cout << "Northwest division had the highest sales figure of\n\t\t\t\t$"
			<< dNW << endl;
	}
	else if (dSW > dNE && dSW > dSE && dSW > dNW)
	{
		cout << "Southwest division had the highest sales figure of\n\t\t\t\t$"
			<< dSW << endl;
	}
	else if ( dNE == dSE && dNE == dNW && dNE == dSW)
	{
		cout << "All divisions had equal sales figures of\n\t\t\t\t$"
			<< dNE << endl;
	}
	else if (dNE == dSE && dNE == dNW && dNE > dSW)
	{
		cout << "Northeast, Southeast and Northwest each had the highest sales"
			"figures of \n\t\t\t\t$" << dNE << endl;
	}
	else if (dNE == dSE && dNE == dSW && dNE > dNW)
	{
		cout << "Northeast, Southeast, and Southwest each had the highest sales"
			"figures of \n\t\t\t\t$" << dNE << endl;
	}
	else if (dNE == dNW && dNE == dSW && dNW > dSE)
	{
		cout << "Northeast, SouthWest, and NorthWest each had the highest sales"
			"figures of \n\t\t\t\t$" << dNE << endl;
	}
	else if (dSE == dNW && dSE == dSW && dSE > dNE)
	{
		cout << "Southeast, Northwest, and SouthWest each had the highest sales"
			"figures of \n\t\t\t\t$" << dSE << endl;
	}
	else if (dNE == dSE && dNE > dNW && dNE > dSW)
	{
		cout << "Northeast and Southeast each had the highest sales figures of"
			"\n\t\t\t\t$" << dNE << endl;
	}
	else if (dNE == dNW && dNE > dSE && dNE > dSW)
	{
		cout << "Northeast and Northwest each had the highest sales figures of"
			"\n\t\t\t\t$" << dNE << endl;
	}
	else if (dNE == dSW && dNE > dSE && dNE > dNW)
	{
		cout << "Northeast and Southwest each had the highest sales figures of"
			"\n\t\t\t\t$" << dNE << endl;
	}
	else if (dSE == dNW && dSE > dNE && dSE > dSW)
	{
		cout << "Southeast and Northwest each had the highest sales figures of"
			"\n\t\t\t\t$" << dSE << endl;
	}
	else
	{
		cout << "Southeast and Northwest each had the highest sales figures of"
			"\n\t\t\t\t$" << dSE << endl;
	}
}