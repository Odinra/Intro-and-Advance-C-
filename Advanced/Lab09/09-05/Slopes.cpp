/* Christopher King
Section 1031
Snow condition Structure Source
CK 05/08/12 - 12:55-01:42 Started Program
CK 05/10/12 - 11:00ish - 11:37 Finished product
*/
#include "Slopes.h"

void Slopes::setDates(int startDate)
{
	for (int index = 0; index < 7; index++)
	{
		iDate[index] = startDate++;
	}
}