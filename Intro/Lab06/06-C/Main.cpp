/*Christopher King
Section 1023
Create a program that averages a judges score dropping the highest and 
lowest scores.
03/01/12 14:09 - 14:39 Started program, created getJudgeData, calcScore, 
findHighest, findLowest, and Main.*/
#include<iostream>
#include<iomanip>
using namespace std;

//prototypes
void vGetJudgeData(double& dScore);
double dCalcScore(double, double, double, double, double);
int iFindLowest(double, double, double, double, double);
int iFindHighest(double, double, double, double, double);

int main()
{
	//declare variables
	double dScore1, dScore2, dScore3, dScore4, dScore5, dAvg;
	
	//function calls to get the judge scores
	vGetJudgeData(dScore1);
	vGetJudgeData(dScore2);
	vGetJudgeData(dScore3);
	vGetJudgeData(dScore4);
	vGetJudgeData(dScore5);

	//function call for dCalcScore
	dAvg = dCalcScore(dScore1, dScore2, dScore3, dScore4, dScore5);

	//display contestant's score
	cout << fixed << setprecision(3);
	cout << "The contestant scored a:\n\t\t\t" << dAvg << endl;
	system("pause");
	return 0;
}

//getJudgeData function definition
void vGetJudgeData(double &dScore)
{
	//accumulator
	static int siJudge = 1;
	//prompt
	cout << "PLease enter judge number " << siJudge <<"\'s score:\n\t";
	cin >> dScore;
	//validate
	while (dScore > 10 || dScore < 0)
	{
		cout << "Invalid entry! PLease enter a number between 1 and 10!\n";
		cin >> dScore;
	}
	//increment
	siJudge++;
}

double dCalcScore(double d1, double d2, double d3, double d4, double d5)
{
	//declare local avg
	double dAvg;
	int iHigh, iLow;

	//call for highest and lowest
	iHigh = iFindHighest(d1, d2, d3, d4, d5);
	iLow = iFindLowest(d1, d2, d3, d4, d5);

	//does proper calculations depending on the highest and lowest
	if ((iHigh == 1 || iLow == 1) && (iLow == 2 || iHigh == 2))
		dAvg = (d3 + d4 + d5) / 3;
	else if ((iHigh == 1 || iLow == 1) && (iLow == 3 || iHigh == 3))
		dAvg = (d2 + d4 + d5) / 3;
	else if ((iHigh == 1 || iLow == 1) && (iLow == 4 || iHigh == 4))
		dAvg = (d2 + d3 + d5) / 3;
	else if ((iHigh == 1 || iLow == 1) && (iLow == 5 || iHigh == 5))
		dAvg = (d2 + d3 + d4) / 3;
	else if ((iHigh == 2 || iLow == 2) && (iLow == 3 || iHigh == 3))
		dAvg = (d1 + d4 + d5) / 3;
	else if ((iHigh == 2 || iLow == 2) && (iLow == 4 || iHigh == 4))
		dAvg = (d1 + d3 + d5) / 3;
	else if ((iHigh == 2 || iLow == 2) && (iLow == 5 || iHigh == 5))
		dAvg = (d1 + d3 + d4) / 3;
	else if ((iHigh == 3 || iLow == 3) && (iLow == 4 || iHigh == 4))
		dAvg = (d1 + d2 + d5) / 3;
	else if ((iHigh == 3 || iLow == 3) && (iLow == 5 || iHigh == 5))
		dAvg = (d1 + d2 + d4) / 3;
	else if ((iHigh == 4 || iLow == 4) && (iLow == 5 || iHigh == 5))
		dAvg = (d1 + d2 + d3) / 3;
	else
		dAvg = d1;

	//return the avg
	return dAvg;
}

int iFindHighest(double d1, double d2, double d3, double d4, double d5)
{
	//declare the variable to be returned
	int iReturn;

	//find the highest number
	if (d1 >= d2 && d1 >= d3 && d1 >= d4 && d1 >= d5)
		iReturn = 1;
	else if (d2 >= d1 && d2 >= d3 && d2 >= d4 && d2 >= d5)
		iReturn = 2;
	else if (d3 >= d1 && d3 >= d2 && d3 >= d4 && d3 >= d5)
		iReturn = 3;
	else if (d4 >= d1 && d4 >= d2 && d4 >= d3 && d4 >= d5)
		iReturn = 4;
	else //(d5 >= d1 && d5 >= d2 && d5 >= d3 && d5 >= d4)
		iReturn = 5;
	
	//return the highest
	return iReturn;
}

int iFindLowest(double d1, double d2, double d3, double d4, double d5)
{
	//declare the variable to be returned
	int iReturn;

	//find the lowest
	if (d1 <= d2 && d1 <= d3 && d1 <= d4 && d1 <= d5)
		iReturn = 1;
	else if (d2 <= d1 && d2 <= d3 && d2 <= d4 && d2 <= d5)
		iReturn = 2;
	else if (d3 <= d1 && d3 <= d2 && d3 <= d4 && d3 <= d5)
		iReturn = 3;
	else if (d4 <= d1 && d4 <= d2 && d4 <= d3 && d4 <= d5)
		iReturn = 4;
	else //(d5 <= d1 && d5 <= d2 && d5 <= d3 && d5 <= d4)
		iReturn = 5;
	
	//return the lowest
	return iReturn;
}