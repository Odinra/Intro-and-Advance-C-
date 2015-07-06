/*Christopher King
Section 1031
Started  05/29/12 1317 ended -*/
#include "NumDays.h"

//operation overlodification
double operator+(NumDays ndA, NumDays ndB)
{
	return (ndA.iHours + ndB.iHours);
}
double operator-(NumDays ndA, NumDays ndB)
{
	return (ndA.iHours - ndB.iHours);
}
double NumDays::operator++()
{	
	iHours++;
	setDays();
	return (iDays);
}
double NumDays::operator--()
{
	iHours--;
	setDays();
	return (iDays);
}