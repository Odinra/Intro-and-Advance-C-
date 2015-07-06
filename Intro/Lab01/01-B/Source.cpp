// This program calculaed the amount of money spent on basebalss last year
#include <iostream>
using namespace std;

int main()
{
	//created the variables to store the number of balls bought, price per ball, and total spent.
	double dballs, dcostEach, dcostTotal;

	//get the number of balls purchased.
	cout << "How many baseballs were purchased?" << endl;
	cin >> dballs;

	//get the price spent on each ball.
	cout << "How much did each baseball cost?" << endl;
	cin >> dcostEach;

	//calulate the total amount spent on baseballs.
	dcostTotal = dballs * dcostEach;

	//Display the amount spent.
	cout << "The total amount spent on baseballs was $" << dcostTotal << endl;
	return 0;
}