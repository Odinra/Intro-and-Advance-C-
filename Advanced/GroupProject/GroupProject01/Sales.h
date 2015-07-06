#ifndef SALES_H_
#define SALES_H_
/* Sales Portion of group Project*/
//includes
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Inventory.h"
#include "HumanResources.h"
#include "CashFlow.h"
//namespace
using namespace std;
//inventory struct

#define TAX .0825

struct inventory
{
public:
	string name;
	string Description;
	string Vendor;
	string PackType;
	string PackSize;
	double cost;
	double markUp;
	double price;
	int quantity;
	string OrderPoint;
	string filename;
};
struct Test : public inventory
{
public:
	int count;

};
class Sales
{
private:
		string Password;
public:
	void sale(int size);
	void CloseDown(int size);
	void salesinit(string prefix, int size);
	void Report(string password);
	int dateRecognitionSoftware();
	int salesMain();
	
	void ReadPassword();
	string GetPassword() {return Password;}
	void UpdatePassword(string value);

	int runningMonth;
	int runningYear;
	int monthNo;
	string currentDayOfWeek;

	string Year;
	string Month;
	string Day;
	fstream* files;
	Test test;
	inventory* inv;


	int daynumber;
	int weeknumber;
	fstream reportdate;
	fstream weekreport;
	fstream quarterreport;
	fstream annualreport;
	fstream report;
	fstream index;
	string datestring;
	string weekstring;
	string quarterstring;
	string annualstring;
	string reportDate;
	string reportWeek;
	string reportQuarter;
	string annualString;
};

/**************Encryption Class***************************start**************/
class Encryption
{
protected:
	fstream inFile;
	fstream outFile;
	string inFileName;
	string outFileName;
	int key;
public:
	Encryption(char *inFileNames, char *outFileNames);
	Encryption();
	~Encryption();

	virtual char transform(char ch) = 0;

	void encrypt();
};

//***************SimpleEncryption Class*****************
class Encrypt : public Encryption
{
public:
	char transform(char ch)
	{
		return (ch + 3);
	}
	Encrypt(char *inFileName, char *outFileName)
		: Encryption(inFileName, outFileName)
	{
	}
	Encrypt();
};
//**************SimpleDecryption Class*******************
class Decrypt : public Encryption
{
public:
	char transform(char ch)
	{
		return (ch - 3);
	}
	Decrypt(char *inFileName, char *outFileName)
		: Encryption(inFileName, outFileName)
	{
	}
	Decrypt();
	/* *******example of use*******
	SimpleEncryption obfuscate(inFileName, outFileName);
	obfuscate.encrypt();

	SimpleDecryption obfuscate(inFileName, outFileName);
	obfuscate.encrypt();*/
	
};
/*****************Encryption**************************************end**********/
#endif