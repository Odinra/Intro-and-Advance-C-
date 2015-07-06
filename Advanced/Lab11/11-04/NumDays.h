/*Christopher King
Section 1031
Started  05/29/12 1317 ended -*/
#ifndef NUMDAYS_
#define NUMDAYS_

//classification
class NumDays
{
private:
	//class varimables
	int iHours;
	double iDays;
public:
	//Functions
	NumDays(int iH)
	{
		iHours = iH; iDays = iH / 8.0;
	}
	void setDays()
	{
		iDays = iHours /8.0;
	}
	double getDays()
	{
		return iDays;
	}
	//friendimification
	friend double operator+(NumDays ndA, NumDays ndB);
	friend double operator-(NumDays ndA, NumDays ndB);
	//incrementation and decrementation function
	double operator++();
	double operator--();
};
#endif NUMDAYS_