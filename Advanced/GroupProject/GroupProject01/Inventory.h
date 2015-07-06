#ifndef INVENTORY_H_
#define INVENTORY_H_

//inventory

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<direct.h>
#include<stdio.h>
#include <windows.h>
#include "Sales.h"
#include "HumanResources.h"
#include "CashFlow.h"

using namespace std;

//*********Item Class*********
class Item
{
private:
	string itemID;           //ID number of item
	string item;             //item name
	string itemDescription;  //description of the item
	string itemPackType;     //the package type of the item
	string vendor;           //item vendor
	string itemPackSize;     //psck size of item
	double itemPrice;        //price of item
	double markUp;           //item mark up percentage
	int numberOfItem;        //number of items in inventory
	int orderPoint;          //order point
	
public:
	//set
	void setItemID(string id)
	{	itemID = id;	}
	void setItem(string i)
	{	item = i;	}
	void setItemDes(string iDes)
	{	itemDescription = iDes;	}
	void setVendor(string iv)
	{	vendor = iv;	}
	void setPackType(string pt)
	{	itemPackType = pt;	}
	void setPackSize(string ps)
	{	itemPackSize = ps;	}
	void setItemPrice(double p)
	{	itemPrice = p;	}
	void setMarkUp(double mUp)
	{	markUp = mUp;	}
	void setNumberOfItem(int n)
	{	numberOfItem = n;	}
	void setOrderPoint(int op)
	{	orderPoint = op;	}

	//get
	string getItemID()
	{	return itemID;	}
	string getItem()
	{	return item;	}
	string getItemDes()
	{	return itemDescription;	}
	string getVendor()
	{	return vendor;	}
	string getPackType()
	{	return itemPackType;	}
	string getPackSize()
	{	return itemPackSize;	}
	double getItemPrice()
	{	return itemPrice;	}
	double getMarkUp()
	{	return markUp;	}
	int getNumberOfItem()
	{	return numberOfItem;	}
	double getOrderPoint()
	{	return orderPoint;	}

};
class Vendor
{
private:
	string vName;
	string vStreet;
	string vCity;
	string vState;
	string vZip;
	string vPhone;
public:
	//set
	void setVName(string vN)
	{ vName = vN; }
	void setVStreet(string vS)
	{ vStreet = vS; }
	void setVCity(string vC)
	{ vCity = vC; }
	void setVState(string vSt)
	{ vState = vSt; }
	void setVZip(string vZ)
	{ vZip = vZ; }
	void setVPhone(string vP)
	{ vPhone = vP; }

	//get
	string getVName()
	{ return vName; }
	string getVStreet()
	{ return vStreet; }
	string getVCity()
	{ return vCity; }
	string getVState()
	{ return vState; }
	string getVZip()
	{ return vZip; }
	string getVPhone()
	{ return vPhone; }
};

class Inventory
{
private:
		string Password;
public:
	void AddInventory();
	void UpdateInventory();
	void AddVendor();
	void UpdateVendor();
	void InventoryReport();
	void GenerateOrder();
	void ReadPassword();
	string GetPassword() {return Password;}
	void UpdatePassword(string value);
	//Main Function
	void InventoryManagement();
};

#endif