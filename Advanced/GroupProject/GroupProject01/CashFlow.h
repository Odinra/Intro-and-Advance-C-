#ifndef CASHFLOW_H_
#define CASHFLOW_H_

#include <iostream>
#include <fstream>
#include <string>
#include "Inventory.h"
#include "Sales.h"
#include "HumanResources.h"
using namespace std;

class CashFlow
{
private:
	string Password;
public:
	double CashOnHand;
	double InventoryValue;
	double SalesTaxCollected;
	double Commission;

	//Password
	void ReadPassword();
	string GetPassword() {return Password;}
	void UpdatePassword(string value);

	//Read Values
	void ReadCashFlowData();

	//Update Values	
	void UpdateCashOnHand(double value);
	void UpdateInventoryValue(double value);
	void UpdateSalesTaxCollected(double value);
	void UpdateCommission(double value); 

	//Reports
	void PrintDaily();
	void PrintWeekly();
	void PrintQuarterly();
	void PrintAnnual();

	//Menu
	int Menu();
};

#endif