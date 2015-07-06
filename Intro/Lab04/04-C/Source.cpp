/*Christopher King
Section 1023
A Program that calculates the fat content of items*/
#include <iostream>
using namespace std;

int main()
{
	//declare variables
	double dCalories, dFatGrams, dFatCalories, dTotal, dPercent;

	//prompt for and store the data
	cout << "Please enter the number of calories in your food\n";
	cin >> dCalories;
	cout << "Please enter the number of fat grams in your food\n";
	cin >> dFatGrams;

	//validate the data
	if (dCalories <= 0 || dFatGrams < 0)
	{
		cout << "Error: Invalid Data\n";
		exit(0);
	}

	//do the calculations
	dFatCalories = dFatGrams * 9;

	dTotal = dFatCalories + dCalories;

	dPercent = (dFatCalories / dTotal) * 10;

	//validate the data is correct
	if (dTotal < dFatCalories)
	{
		cout << "Error: either calories or far grams were enterted incorrectly";
		exit(0);
	}

	//display the answer
	cout << dPercent << "% of calories come from fat in the food\n";

	//test to see if the food is low in fat
	if (dPercent < 30)
		cout << "The food is low in fat\n";

	system("pause");
	return 0;
}