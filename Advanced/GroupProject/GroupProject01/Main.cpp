/*Christopher King
Angel Rios
Tony Alexander
Philip Bowers*/

#include "Inventory.h"
#include "Sales.h"
#include "HumanResources.h"
#include "CashFlow.h"

Inventory inventory;
Sales sales;
HumanResources hr;
CashFlow cf;

int main()
{
	int menu = 0;
	do
	{
		do
		{
			system("cls");
			cout << "Please select a system from the following menu\n"
				<< "1)\tInventory Subsystem\n"
				<< "2)\tSales Subsytem\n"
				<< "3)\tHuman Resources Subsystem\n"
				<< "4)\tCash Flow Subsystem\n"
				<< "5)\tExit Program\n";
			cin >> menu;
		} while (menu < 0 || menu > 5);

		if ( menu == 1)
		{
			inventory.InventoryManagement();
		}
		else if ( menu == 2)
		{
			sales.salesMain();
		}
		else if (menu == 3)
		{
			hr.hrMain();
		}
		else if(menu == 4)
		{
			cf.Menu();
		}

	}while(menu !=5);

}