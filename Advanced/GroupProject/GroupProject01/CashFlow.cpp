#include "CashFlow.h"

int CashFlow::Menu()
{
	//Declaration
	string password;
	bool exit = false;
	bool back = false;
	char input;
	double value;

	//Read from files
	ReadPassword();
	ReadCashFlowData();

	//Login
	cout << "TSTC Snack Shop Cash Flow System\n"
		 << "Enter Password: (DEFAULT PASSWORD: password1) ";
	cin >> password;

	//Validation
	if(password == GetPassword())
	{
		system("CLS");

		//Valid-Begin
		do
		{
			cout << "TSTC Snack Shop Cash Flow System\n"
				 << "--------------------------------\n"
				 << "1. Cash on hand\n"
				 << "2. Value of inventory\n"
				 << "3. Sales Tax collected\n"
				 << "4. Commission\n"
				 << "5. Reporting\n"
				 << "6. Change Password\n"
				 << "0. Exit\n"
				 << "--------------------------------\n"
				 << "Make a selection:\n";
			cin >> input;

			switch (input)
			{
			case '1': //Cash On Hand
				system("CLS");

				back = false;
				do
				{
					cout << "TSTC Snack Shop Cash Flow System\n"
						 << "--------------------------------\n"
						 << "1. View Cash On Hand\n"
						 << "2. Add/Deduct Revenue\n"		 
						 << "0. Back\n"
						 << "--------------------------------\n"
						 << "Make a selection:\n";
					cin >> input;

					switch (input)
					{
					case '1':
						system("CLS");
						cout << "Cash On Hand: " << CashOnHand << endl;
						system("PAUSE");
						system("CLS");
						break;
					case '2':
						system("CLS");
						cout << "Add/Deduct Revenue\n"
							 << "Enter a value: (negative for deduction)\n";
						cin >> value;
						UpdateCashOnHand(value);

						cout << "Value Updated\n";
						system("PAUSE");
						system("CLS");
						break;
					case '0':
						back = true;
						system("CLS");
						break;
					default:
						system("CLS");
						cout << "Invalid Input";
						system("PAUSE");
						system("CLS");
						break;
					}
				}while(!back);

				system("CLS");
				break;
			case '2': //Value of Inventory
				system("CLS");

				back = false;
				do
				{
					cout << "TSTC Snack Shop Cash Flow System\n"
						 << "--------------------------------\n"
						 << "1. View Value of Inventory\n"
						 << "2. Add/Deduct Value of Inventory\n"		 
						 << "0. Back\n"
						 << "--------------------------------\n"
						 << "Make a selection:\n";
					cin >> input;

					switch (input)
					{
					case '1':
						system("CLS");
						cout << "Value of Inventory: " << InventoryValue << endl;
						system("PAUSE");
						system("CLS");
						break;
					case '2':
						system("CLS");
						cout << "Add/Deduct Value of Inventory\n"
							 << "Enter a value: (negative for deduction)\n";
						cin >> value;
						UpdateInventoryValue(value);

						cout << "Value Updated\n";
						system("PAUSE");
						system("CLS");
						break;
					case '0':
						back = true;
						system("CLS");
						break;
					default:
						system("CLS");
						cout << "Invalid Input";
						system("PAUSE");
						system("CLS");
						break;
					}
				}while(!back);

				system("CLS");
				break;
			case '3': //Sales Tax
				system("CLS");

				back = false;
				do
				{
					cout << "TSTC Snack Shop Cash Flow System\n"
						 << "--------------------------------\n"
						 << "1. View Sales Tax\n"
						 << "2. Add/Deduct Sales Tax\n"		 
						 << "0. Back\n"
						 << "--------------------------------\n"
						 << "Make a selection:\n";
					cin >> input;

					switch (input)
					{
					case '1':
						system("CLS");
						cout << "Sales Tax: " << SalesTaxCollected << endl;
						system("PAUSE");
						system("CLS");
						break;
					case '2':
						system("CLS");
						cout << "Add/Deduct Sales Tax\n"
							 << "Enter a value: (negative for deduction)\n";
						cin >> value;
						UpdateSalesTaxCollected(value);

						cout << "Value Updated\n";
						system("PAUSE");
						system("CLS");
						break;
					case '0':
						back = true;
						system("CLS");
						break;
					default:
						system("CLS");
						cout << "Invalid Input";
						system("PAUSE");
						system("CLS");
						break;
					}
				}while(!back);

				system("CLS");
				break;
			case '4': //Commission
				system("CLS");

				back = false;
				do
				{
					cout << "TSTC Snack Shop Cash Flow System\n"
						 << "--------------------------------\n"
						 << "1. View TSTC Commission\n"
						 << "2. Add/Deduct TSTC Commission\n"		 
						 << "0. Back\n"
						 << "--------------------------------\n"
						 << "Make a selection:\n";
					cin >> input;

					switch (input)
					{
					case '1':
						system("CLS");
						cout << "TSTC Commission: " << Commission << endl;
						system("PAUSE");
						system("CLS");
						break;
					case '2':
						system("CLS");
						cout << "Add/Deduct TSTC Commission\n"
							 << "Enter a value: (negative for deduction)\n";
						cin >> value;
						UpdateCommission(value);

						cout << "Value Updated\n";
						system("PAUSE");
						system("CLS");
						break;
					case '0':
						back = true;
						system("CLS");
						break;
					default:
						system("CLS");
						cout << "Invalid Input";
						system("PAUSE");
						system("CLS");
						break;
					}
				}while(!back);

				system("CLS");
				break;
			case '5': //TODO: Reporting
				system("CLS");
					
				back = false;
				do
				{
					cout << "TSTC Snack Shop Cash Flow System\n"
						 << "--------------------------------\n"
						 << "1. Print Daily Detail Journal Report\n"
						 << "2. Print Weekly Detail Journal Report\n"
						 << "3. Print Quarterly Summary Report\n"
						 << "4. Print Annual Summary Report\n"
						 << "0. Back\n"
						 << "--------------------------------\n"
						 << "Make a selection:\n";
					cin >> input;

					switch (input)
					{
					case '1':
						system("CLS");


						PrintDaily();
						cout << "Nothing to Report\n";


						system("PAUSE");
						system("CLS");
						break;
					case '2':
						system("CLS");


						PrintWeekly();
						cout << "Nothing to Report\n";
						
						
						system("PAUSE");
						system("CLS");
						break;
					case '3':
						system("CLS");


						PrintQuarterly();
						cout << "Nothing to Report\n";
						
						
						system("PAUSE");
						system("CLS");
						break;
					case '4':
						system("CLS");

						
						PrintAnnual();
						cout << "Nothing to Report\n";
						
						
						system("PAUSE");
						system("CLS");
						break;
					case '0':
						back = true;
						system("CLS");
						break;
					default:
						system("CLS");
						cout << "Invalid Input";
						system("PAUSE");
						system("CLS");
						break;
					}
				}while(!back);

				system("PAUSE");
				system("CLS");
				break;
			case '6': //Password
				system("CLS");

				cout << "Enter Current Password: ";
				cin >> password;

				if(password == GetPassword())
				{
					cout << "Enter New Password: ";
					cin >> password;

					UpdatePassword(password);

					cout << "Password Updated.\n";
				}
				else
				{	
					cout << "Invalid Password";
				}

				system("PAUSE");
				system("CLS");
				break;
			case '0': //Exit
				exit = true;
				break;
			default: //Invalid Input
				system("CLS");
				
				cout << "Invalid Input\n";
				system("PAUSE");
				system("CLS");
				break;
			}
		}while(!exit);
		system("CLS");
		return 1;
	}
	else
	{
		//Invalid
		cout << "Invalid Password\n";
		system("PAUSE");
		system("CLS");
		return 0;
	}
	return -1;
}

//Password
void CashFlow::ReadPassword()
{
	fstream File;
	string password;

	File.open("Password.txt");
	getline(File, password);
	File.close();

	UpdatePassword(password);
}
void CashFlow::UpdatePassword(string value)
{
	Password = value;
	fstream File;

	File.open("Password.txt", ios::out);	
	File << Password;
	File.close();
}

//Read Values
void CashFlow::ReadCashFlowData()
{
	fstream File;
	string cash, inventory, sales, commission;

	File.open("CashOnHand.txt");
	getline(File, cash);
	File.close();

	File.open("InventoryValue.txt");
	getline(File, inventory);
	File.close();

	File.open("SalesTaxCollected.txt");
	getline(File, sales);
	File.close();

	File.open("Commission.txt");
	getline(File, commission);
	File.close();

	CashOnHand = stod(cash);
	InventoryValue = stod(inventory);
	SalesTaxCollected = stod(sales);
	Commission = stod(commission);
}

//Update Values
void CashFlow::UpdateCashOnHand(double value)
{
	fstream File;
	CashOnHand += value;

	File.open("CashOnHand.txt", ios::out);
	File << CashOnHand;
	File.close();	
}
void CashFlow::UpdateInventoryValue(double value)
{
	fstream File;
	InventoryValue += value;

	File.open("InventoryValue.txt", ios::out);
	File << InventoryValue;
	File.close();	
}
void CashFlow::UpdateSalesTaxCollected(double value)
{
	fstream File;
	SalesTaxCollected += value;

	File.open("SalesTaxCollected.txt", ios::out);
	File << SalesTaxCollected;
	File.close();	
}
void CashFlow::UpdateCommission(double value)
{
	fstream File;
	Commission += value;

	File.open("Commission.txt", ios::out);
	File << Commission;
	File.close();	
}

//TODO: Reports 
void CashFlow::PrintDaily()
{

}
void CashFlow::PrintWeekly()
{

}
void CashFlow::PrintQuarterly()
{

}
void CashFlow::PrintAnnual()
{

}
