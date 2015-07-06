#include "Inventory.h"

//**********Add Inventory Function************
void Inventory::AddInventory()
{
	Item *instance;
	int num;
	string newId;
	string newItem;
	string newDescription;
	string newVendor;
	string newPackType;
	string newPackSize;
	double newPrice;
	double newMarkUp;
	int newNumOfItem;
	int newOrderPoint;
	fstream file;
	fstream file2;

	cout<< "How many items to add to inventory? :";
	cin>> num;

	instance = new Item[num];

	for (int i = 0; i < num; i++)
	{
		system("cls");

		cout<< "Enter item " << i + 1 << "s ID number :";
		cin>> newId;
		instance[i].setItemID(newId);
		cout<< endl;

		cout<< "Enter the name of item " << i + 1 << "  :";
		cin.get();
		getline(cin, newItem);
		instance[i].setItem(newItem);
		cout<< endl;

		cout<< "Enter the description of item" << i + 1 << "  :";
		getline(cin, newDescription);
		instance[i].setItemDes(newDescription);
		cout<< endl;

		cout<< "Enter the name of the vendor for item " << i + 1 << "  :";
		getline(cin, newVendor);
		instance[i].setVendor(newVendor);
		cout<< endl;

		cout<< "Enter the package type of item " << i + 1 << " :";
		getline(cin, newPackType);
		instance[i].setPackType(newPackType);
		cout<< endl;

		cout<< "Enter the package size of item " << i + 1 << " :";
		getline(cin, newPackSize);
		instance[i].setPackSize(newPackSize);
		cout<< endl;

		cout<< "Enter the price of item " << i + 1 << " :$";
		cin.ignore();
		cin>> newPrice;
	    instance[i].setItemPrice(newPrice);
		cout<< endl;

		cout<< "Enter the mark up percentage of item " << i + 1 << " :%";
		cin>> newMarkUp;
	    instance[i].setMarkUp(newMarkUp);
		cout<< endl;

		cout<< "Enter the starting amount of item " << i + 1 << " in inventory :";
		cin>> newNumOfItem;
		instance[i].setNumberOfItem(newNumOfItem);
		cout<< endl;

		cout<< "Enter the order point for item " << i + 1 << " :";
		cin>> newOrderPoint;
	    instance[i].setOrderPoint(newOrderPoint);
		cout<< endl;
	
		file.open(instance[i].getItemID() + ".txt", ios::out|ios::app);

		file<< instance[i].getItemID() << endl;
		file<< instance[i].getItem() << endl;
		file<< instance[i].getItemDes() << endl;
		file<< instance[i].getVendor() << endl;
		file<< instance[i].getPackType() << endl;
		file<< instance[i].getPackSize() << endl;
		file<< instance[i].getItemPrice() << endl;
		file<< instance[i].getMarkUp() << endl;
		file<< instance[i].getNumberOfItem() << endl;
		file<< instance[i].getOrderPoint() << endl;

		file2.open("IndexFile.txt", ios::out|ios::app);
		file2<< instance[i].getItemID() << endl;

		file.close();
		file2.close();
	}

	cout<< "Saving..." << endl;
	cout<< "Done" << endl;
	system("pause");
	    
}

//**************Update Inventory Function*****************
void Inventory::UpdateInventory()
{
	fstream file;
	fstream file2;
	string changeID;
	const int num = 10;
	const int num2 = 200;
	char buffer[num] [num2];
	int choice = 0;
	char change[num2];
	string fileName;

	system("cls");

	cout<< "What is the item ID of the product to change? :";
	cin.get();
	getline(cin, changeID);

	fileName = changeID + ".txt";
	

	file.open(fileName, ios::in | ios::out);   

	for (int i = 0; i < num; i++)
	{
		file.getline(buffer[i], num2);
	}
	
	for (int a = 0; a < num; a++)
	{
		cout<< a + 1 << ".  " << buffer[a] << endl;
	}

	cout<< "Select the nummber of the line you want to change.  :";
	cin>> choice;
	choice = choice - 1;
	cout<< "Change to what? : ";
	cin.get();
	cin.getline(change, num2);

	for (int c = 0; c < num2; c++)
	{
		buffer[choice] [c] = change[c];
	}

	file.close();

	if (remove(fileName.c_str()) != 0)
    {
        perror("Error deleting file");
    }

	file2.open(fileName, ios::out);  

	for (int s = 0; s < num; s++)  
	{
		file2<< buffer[s] << endl;    
	}

	file2.close();

	system("pause");
}

//*************Add Vendor Function***************
void Inventory::AddVendor()
{
	Vendor *instance;
	int num;
	string newVName;
	string newVStreet;
	string newVCity;
	string newVState;
	string newVZip;
	string newVPhone;
	fstream file;

	cout<< "How many vedors to add to files? :";
	cin>> num;

	instance = new Vendor[num];

	system("cls");

	for (int i = 0; i < num; i++)
	{
		cout<< "Enter vendor " << i + 1 << "s name :";
		cin.get();
		getline(cin, newVName);
		instance[i].setVName(newVName);
		cout<< endl;

		cout<< "Enter vendor " << i + 1 <<"s address" << endl;
		cout<< "Street  :";
		//cin.get();
		getline(cin, newVStreet);
		instance[i].setVStreet(newVStreet);
		cout<< endl;

		cout<< "City  :";
		//cin.get();
		getline(cin, newVCity);
		instance[i].setVCity(newVCity);
		cout<< endl;

		cout<< "State  :";
		//cin.get();
		getline(cin, newVState);
		instance[i].setVState(newVState);
		cout<< endl;

		cout<< "Zip :";
		getline(cin, newVZip);
		instance[i].setVZip(newVZip);
		cout<< endl;

		cout<< "Enter the phone number of vendor " << i + 1 << " :";
		getline(cin, newVPhone);
		instance[i].setVPhone(newVPhone);
		cout<< endl;
	}

	cout<< "Saving..." << endl << endl;

	for (int a = 0; a < num; a++)
	{
		file.open(instance[a].getVName() + ".txt", ios::out|ios::app);

		file<< instance[a].getVName() << endl;
		file<< instance[a].getVStreet() << endl;
		file<< instance[a].getVCity() << endl;
		file<< instance[a].getVState() << endl;
		file<< instance[a].getVZip() << endl;
		file<< instance[a].getVPhone() << endl;
	}

	file.close();

	cout<< "Done" << endl;
	system("pause");
	    
}

//**************Update Vendor Function*****************
void Inventory::UpdateVendor()
{
	fstream file;
	fstream file2;
	string changeID;
	const int num = 6;
	const int num2 = 200;
	char buffer[num] [num2];
	int choice = 0;
	char change[num2];
	string fileName;

	system("cls");

	cout<< "What is the name of the vendor to change? :";
	cin.get();
	getline(cin, changeID);

	fileName = changeID + ".txt";

	file.open(fileName, ios::in | ios::out);   

	for (int i = 0; i < num; i++)
	{
		file.getline(buffer[i], num2);
	}
	
	for (int a = 0; a < num; a++)
	{
		cout<< a + 1 << ".  " << buffer[a] << endl;
	}

	cout<< "Select the nummber of the line you want to change.  :";
	cin>> choice;
	choice = choice - 1;
	cout<< "Change to what? : ";
	cin.get();
	cin.getline(change, num2);

	for (int c = 0; c < num2; c++)
	{
		buffer[choice] [c] = change[c];
	}

	file.close();

	if (remove(fileName.c_str()) != 0)
    {
        perror("Error deleting file");
    }

	file2.open(fileName, ios::out);   

	for (int s = 0; s < num; s++)  
	{
		file2<< buffer[s] << endl;  
	}

	file2.close();

	system("pause");
}

//*****************Inventory Report Function*******************
void Inventory::InventoryReport()
{
	fstream file;
	fstream file2[300];
	string changeID;
	const int num = 300;
	const int num2 = 200;
	const int num3 = 5;
	char buffer1[num] [num2];
	char buffer2[num] [num2];
	int choice = 0;
    int i = 0;
	string fileName;

	system("cls");

	file.open("IndexFile.txt");

	while (!(file.eof()))
	{
		file.getline(buffer1[i], num2);
		i++;
	}
	
	for (int a = 0; a < i; a++)
	{
		string str(buffer1[a]);

		file2[a].open(str + ".txt");  

		for (int s = 0; s < 10; s++)                
		{
			file2[a].getline(buffer2[s], num2);	 
		}
		cout<< buffer2[0] << endl;
		cout<< buffer2[1] << endl;
		cout<< buffer2[8] << endl << endl;
	}

	file.close();
	for (int z = 0; z < i; z++)
	{
		file2[z].close();
	}
	system("pause");
}

//***************Generate Product Order Function******************
void Inventory::GenerateOrder()
{
	string orderID;
	string fileName1;
	double cost;
	fstream fileO;
	fstream fileO2;
	const int num = 10;
	const int num2 = 200;
	char buffer[num] [num2];
	char change[num2];

	cout<< "What is the product ID of the item to order? :";
	cin>> orderID;
	cout<< "How many to order? :";
	cin.get();
	cin.getline(change, num2);
	cout<< "What is the cost per item? :";
	cin>> cost;

	fileName1 = orderID + ".txt";
	
	fileO.open(fileName1, ios::in | ios::out);   

	for (int i = 0; i < num; i++)
	{
		fileO.getline(buffer[i], num2);
	}

	stringstream ss( buffer[8]);
	stringstream ss2( change);
	int order = 0, o;

	ss >> o;
	order += o;
	ss2 >> o;
	order += o;

	_itoa_s(order, change, 10);

	for (int c = 0; c < num2; c++)
	{
		buffer[8] [c] = change[c];  //prob!!!!!!!!!!
	}

	fileO.close();

	if (remove(fileName1.c_str()) != 0)
    {
        perror("Error deleting file");
    }

	fileO2.open(fileName1, ios::out);  

	for (int s = 0; s < num; s++)  
	{
		fileO2<< buffer[s] << endl;    
	}

	fileO2.close();

	system("pause");
	
}

//****************Password Function**********************
void Inventory::ReadPassword()
{
	fstream File;
	string password;

	File.open("Password.txt");
	getline(File, password);
	File.close();

	UpdatePassword(password);
}
void Inventory::UpdatePassword(string value)
{
	Password = value;
	fstream File;

	File.open("Password.txt", ios::out);	
	File << Password;
	File.close();
}

//**************Inventory Management System Function***************
void Inventory::InventoryManagement()
{
	int choice = 0,
		choice2 = 0,
		choice3 = 0,
		choice4 = 0;
		ReadPassword();
	while (choice != 5)
	{
		choice = 0;
		system("cls");
		cout<< "1. Product Subsystem" << endl << endl;
		cout<< "2. Vendor Subsystem" << endl << endl;
		cout<< "3. Order Subsystem" << endl << endl;
		cout<< "4. Inventory Report" << endl << endl;
		cout<< "5. Exit" << endl << endl;
		cout<< "Enter number of choice :";
		cin>> choice;

		cout <<"Enter Password: (DEFAULT PASSWORD: password1) ";
		cin >> Password;

		if(choice == 1)
		{
			if (Password == GetPassword())
			{

				while (choice2 != 3)
				{
					choice2 = 0;
					system("cls");
					cout<< "1. Add Product" << endl << endl;
					cout<< "2. Update Product" << endl << endl;
					cout<< "3. Exit" << endl << endl;
					cout<< "Enter number of choice :";
					cin>> choice2;

					if (choice2 == 1)
					{
						AddInventory();
					}

					if (choice2 == 2)
					{
						UpdateInventory();
					}
				}
			}
		}

		if(choice == 2)
		{
			if(Password == GetPassword())
			{
				while (choice3 != 3)
				{
					choice3 = 0;
					system("cls");
					cout<< "1. Add Vendor" << endl << endl;
					cout<< "2. Update Vendor" << endl << endl;
					cout<< "3. Exit" << endl << endl;
					cout<< "Enter number of choice :";
					cin>> choice3;

					if (choice3 == 1)
					{
						AddVendor();
					}

					if (choice3 == 2)
					{
						UpdateVendor();
					}
				}
			}
		}

		if(choice == 3)
		{
			if(Password == GetPassword())
			{
				while (choice4 != 2)
				{
					choice4 = 0;
					system("cls");
					cout<< "1. Generate Product Order" << endl << endl;
					cout<< "2. Exit" << endl << endl;
					cout<< "Enter number of choice :";
					cin>> choice4;

					if (choice4 == 1)
					{
						GenerateOrder();
					}
				}
			}
		}

		if(choice == 4)
		{
			InventoryReport();
		}
	}
}

//***************Encryption Function**************************
