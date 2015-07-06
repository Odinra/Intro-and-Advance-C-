#ifndef FILES_H_
#define FILES_H_
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

//person struct
struct PERSON
{
	char sName[101];
	char sAddress[101];
	char sCity_State[101];
	char sPhone[101];
	double dAccountBalance;
	char sLastPayment[101];
};

//files class
class FILES
{
	//private variables
private:
	fstream file;
	string sFileName;
	PERSON customer;
	//public functions
public:
	//constructionator prototype
	FILES(string s);
	//destructor
	~FILES()
	{
		//close
		file.close();
	}
	//prototypes
	string LastLines(int iNoLines);
	void encrypt();
	void decrypt();
	void enterNew();
	//delet is 127
	void displayCust(string name);
	void deleteCust(string name);
	void deleteCust(int position);
	void changeCust(char Name[], char Address[], char City_State[], char Phone[], double AccountBalance, char LastPayment[]);
	void displayAll();
	void addCust(char Name[], char Address[], char City_State[], char Phone[], double AccountBalance, char LastPayment[]);
	int findCust(string name);
};

#endif