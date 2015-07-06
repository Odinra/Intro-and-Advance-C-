/* Christopher King
Section 1031
Snow condition Structure Header
CK 05/08/12 - 12:55-01:42 Started Program
CK 05/10/12 - 11:00ish - 11:37 Finished product
*/
#ifndef SLOPES_H
#define SLOPES_H
#include <string>
using namespace std;

struct Slopes
{
	string sMonth;
	int iDate[7];
	double dBase[7];
	void setDates(int startDate);
};
#endif
