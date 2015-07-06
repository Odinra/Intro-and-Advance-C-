/*Christopher King
Section 1031
Started 05/24/12 1310 ended - */
#ifndef DAYOFYEAR_
#define DAYOFYEAR_

#include <string>
#include <iostream>
using namespace std;


class DayOfYear
{
private:
	int iDayNumber;
	string sMonth;
	int iDate;
public:
	DayOfYear(int iDay)
	{
		iDayNumber = iDay;
	}
	void FindDate();
	
};
#endif