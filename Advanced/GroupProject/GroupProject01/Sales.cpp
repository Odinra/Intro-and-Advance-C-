#include "Sales.h"

int Sales::salesMain()
{
	cout << fixed << setprecision(2);
	test.count = -1;
	string name;
	char buffer[33];
	ReadPassword();
	daynumber = dateRecognitionSoftware();

	if (monthNo == 1)
		daynumber += 0;
	else if (monthNo == 2)
		daynumber += 31;
	else if (monthNo == 3)
		daynumber += 59;
	else if (monthNo == 4)
		daynumber += 90;
	else if (monthNo == 5)
		daynumber += 120;
	else if (monthNo == 6)
		daynumber += 151;
		else if (monthNo == 7)
		daynumber += 181;
	else if (monthNo == 8)
		daynumber += 212;
	else if (monthNo == 9)
		daynumber += 243;
	else if (monthNo == 10)
		daynumber += 273;
	else if (monthNo == 11)
		daynumber += 304;
	else if (monthNo == 12)
		daynumber += 334;

	datestring = "BusinessDay-";
	datestring.append(_itoa((daynumber), buffer, 10));

	weekstring = "WeekNumber-";
	weekstring.append(_itoa(((daynumber/7) + 1), buffer, 10));

	quarterstring = "QuarterNumber-";
	quarterstring.append(_itoa((daynumber/91 + 1), buffer, 10));

	annualstring = "AnnualReport";

	reportdate.open(datestring + ".dat", ios::app);
	weekreport.open(weekstring + ".dat", ios::app);
	quarterreport.open(quarterstring + ".dat", ios::app);
	annualreport.open(annualstring + ".dat", ios::app);

	reportdate << fixed << setprecision(2) <<"\n\nDay Number:" << daynumber;
	weekreport << fixed << setprecision(2) <<"\n\nDay Number:" << daynumber;
	quarterreport << fixed << setprecision(2) <<"\n\nDay Number:" << daynumber;
	annualreport << fixed << setprecision(2) <<"\n\nDay Number:" << daynumber;


	index.open("IndexFile.txt");

	while (!index.eof())
	{	test.count++;
		getline(index, test.filename);
		
	}

	index.close();
	index.open("IndexFile.txt");

	
	int choice;

	salesinit(name, test.count);

	do{
		do{
			system("cls");
			cout << "Please make a selection from one of the following menu items:\n"
				"1. Conduct a Sales Transaction.\n"
				"\n2. Close down for the day\n"
				"\n3. Report Subsystem\n";
			cin >> choice;
		}while (choice < 1 || choice > 3);

		if (choice == 1)
		{
			sale(test.count);
		}
		else if (choice == 3)
		{
			system("cls");
			cout << "Please enter the manager password";
			cin >> Password;
			Report(Password);
		}

		
	}while(choice != 2);

	

	CloseDown(test.count);
	return 0;
}

void Sales::sale(int size)
{
	int choice;
	int quant;
	inventory sold[25];
	int salenum = -1;


	double subtotal = 0, total = 0, taxamt = 0;

	char cont = 'a';
	do{
		salenum++;

		do{
			cout << "Please make a selection from the following available items:\n";
			for (int i = 0; i < size; i++)
			{
				cout << i + 1 << "\t" << inv[i].name << "\t" << inv[i].Description << "\t" << inv[i].quantity << "\t$" << inv[i].price << "\n";
			}
			cin >> choice;
		}while( choice < 1 || choice > size);

		choice--;

		sold[salenum] = inv[choice];

		do{
			cout << "How much of " << sold[salenum].name << " would you like to purchase?\n"
				"(Maximum of " << sold[salenum].quantity << ")\n";
			cin >> quant;
		}while( quant < 0 || quant > sold[salenum].quantity);

		sold[salenum].quantity = quant;

		inv[choice].quantity -= quant;


		subtotal += inv[choice].price * quant;

		cout << "Would you like to add more items to the cart? y or Y for yes";
		cin >> cont;


	}while((cont == 'y' || cont == 'Y') && salenum < 24);

	for(int i = 0; i < salenum + 1; i++)
	{
		cout << "\n" << sold[i].name << "\t" << sold[i].quantity << "\t" << sold[i].price << "\n";

		reportdate << "\n" << sold[i].name << "\t" << sold[i].quantity << "\t" << sold[i].price;

		weekreport << "\n" << sold[i].name << "\t" << sold[i].quantity << "\t" << sold[i].price;

		quarterreport << "\n" << sold[i].name << "\t" << sold[i].quantity << "\t" << sold[i].price;

		annualreport << "\n" << sold[i].name << "\t" << sold[i].quantity << "\t" << sold[i].price;

		//subtotal += sold[i].price;
	}

	taxamt = subtotal * TAX;
	total = taxamt + subtotal;

	cout << "\nSubtotal:\n\t\t$" << subtotal << "\nTax:\n\t\t$" << taxamt << "\nTotal:\n\t\t$" << total << "\n";

	reportdate << "\nSubtotal:\n\t\t$" << subtotal << "\nTax:\n\t\t$" << taxamt << "\nTotal:\n\t\t$" << total;

	weekreport << "\nSubtotal:\n\t\t$" << subtotal << "\nTax:\n\t\t$" << taxamt << "\nTotal:\n\t\t$" << total;

	quarterreport << "\nSubtotal:\n\t\t$" << subtotal << "\nTax:\n\t\t$" << taxamt << "\nTotal:\n\t\t$" << total;

	annualreport << "\nSubtotal:\n\t\t$" << subtotal << "\nTax:\n\t\t$" << taxamt << "\nTotal:\n\t\t$" << total;

	system("pause");


}

void Sales::CloseDown(int size)
{
	for (int i = 0; i < size; i++)
	{
		files[i].close();

		files[i].open(inv[i].filename + ".txt", ios::out);

		files[i] << fixed << setprecision(2)
			<<inv[i].filename<< "\n" 
			<< inv[i].name << "\n" 
			<< inv[i].Description << "\n" 
			<< inv[i].Vendor << "\n" 
			<< inv[i].PackType << "\n" 
			<< inv[i].PackSize << "\n";
		files[i] << inv[i].cost; files[i] << "\n";
		files[i] << inv[i].markUp; files[i] << "\n";
		files[i] << inv[i].quantity; files[i] << "\n";
		files[i] << inv[i].OrderPoint;

		files[i].close();


	}

	delete [] files;
	
}

void Sales::salesinit(string prefix, int size)
{
	files = new fstream[size];
	inv = new inventory[size];

	for(int i = 0; !index.eof() && i < size; i++)
	{
		getline(index, inv[i].filename);
	}

	for (int i = 0; i < size; i++)
	{
		files[i].open(inv[i].filename + ".txt" );
		
		getline(files[i], inv[i].filename);
		getline(files[i], inv[i].name);
		getline(files[i], inv[i].Description);
		getline(files[i], inv[i].Vendor);
		getline(files[i], inv[i].PackType);
		getline(files[i], inv[i].PackSize);
		files[i] >> inv[i].cost;
		files[i] >> inv[i].markUp;
		files[i] >> inv[i].quantity;
		files[i].ignore();
		getline(files[i], inv[i].OrderPoint);

		inv[i].price = inv[i].cost + (inv[i].cost * (inv[i].markUp / 100));

	}
}

void Sales::Report(string password)
{
	if(password == GetPassword())
	{
		cout << "incorrect password";
		system("pause");
		return;
	}
	int choice;
	reportdate.close();
	weekreport.close();
	quarterreport.close();
	annualreport.close();

	string reports;
	char buffer[33];

	do{
	cout << "Please make a selection from the following menu:\n"
		"1. Report on a specific date\n"
		"2. Report on a specific week\n"
		"3. Report on a specific quarter\n"
		"4. The annual Report\n"
		"5. Exit Report Subsytem\n";
	cin >> choice;
	}while(choice < 1 || choice > 5);

	dateRecognitionSoftware();

		if (monthNo == 1)
		daynumber += 0;
	else if (monthNo == 2)
		daynumber += 31;
	else if (monthNo == 3)
		daynumber += 59;
	else if (monthNo == 4)
		daynumber += 90;
	else if (monthNo == 5)
		daynumber += 120;
	else if (monthNo == 6)
		daynumber += 151;
	else if (monthNo == 7)
		daynumber += 181;
	else if (monthNo == 8)
		daynumber += 212;
	else if (monthNo == 9)
		daynumber += 243;
	else if (monthNo == 10)
		daynumber += 273;
	else if (monthNo == 11)
		daynumber += 304;
	else if (monthNo == 12)
		daynumber += 334;
	
	if ( choice == 1)
	{
	reportDate = "BusinessDay-";
	reportDate.append(itoa((daynumber), buffer, 10));
		report.open(reportDate + ".dat");
	}

	else if ( choice == 2)
	{
	reportWeek = "WeekNumber-";
	reportWeek.append(itoa(((daynumber/7) + 1), buffer, 10));
	report.open(reportWeek + ".dat");
	}

	else if ( choice == 3)
	{
	reportQuarter = "QuarterNumber-";
	reportQuarter.append(itoa((daynumber/91 + 1), buffer, 10));
	report.open(reportQuarter + ".dat");
	}
	
	else if (choice == 4)
	{
	annualstring = "AnnualReport";
	report.open(annualstring + ".dat");
	}

	while (!report.eof())
	{
		getline(report, reports);
		cout << reports << "\n";
	}

	system("pause");

	report.close();
	reportdate.open(datestring + ".dat");
	weekreport.open(weekstring + ".dat", ios::app);
	quarterreport.open(quarterstring + ".dat", ios::app);
	annualreport.open(annualstring + ".dat", ios::app);
}

int Sales::dateRecognitionSoftware()
{
	string currentMonth;
	//For user purposes
	string currentMonthName;
	string currentDay;
	string currentYear;
	string Choice;
	fstream File;
	File.open("Date.txt");
	File >> Month >> Day;
	
	File.close();
	cout << "                 DATE RECOGNITION SOFTWARE ACTIVATING                 \n\n"; 
	cout << "Enter the current Month (Format: 1, 3, 12): ";
	cin >> currentMonth;
	cout << "Enter the current Day of the Month (Format: 1, 15, 20, 31): ";
	cin >> currentDay;
	cout << "Enter the current Year (Format: 1, 5, 11, 12, 13): ";
	cin >> currentYear;
	cout << "Enter the current Day of the Week (Format: Monday, Tuesday, etc.): ";
	cin >> currentDayOfWeek;
	if(currentMonth == "1")
	{
		currentMonthName = "January";
	}
	else if(currentMonth == "2")
	{
		currentMonthName = "February";
	}
	else if(currentMonth == "3")
	{
		currentMonthName = "March";
	}
	else if(currentMonth == "4")
	{
		currentMonthName = "April";
	}
	else if(currentMonth == "5")
	{
		currentMonthName = "May";
	}
	else if(currentMonth == "6")
	{
		currentMonthName = "June";
	}
	else if(currentMonth == "7")
	{
		currentMonthName = "July";
	}
	else if(currentMonth == "8")
	{
		currentMonthName = "August";
	}
	else if(currentMonth == "9")
	{
		currentMonthName = "September";
	}
	else if(currentMonth == "10")
	{
		currentMonthName = "October";
	}
	else if(currentMonth == "11")
	{
		currentMonthName = "November";
	}
	else if(currentMonth == "12")
	{
		currentMonthName = "December";
	}

	cout << currentMonthName << " " << currentDay << ", " << currentYear;
	cout << endl << "Is this the current date? Enter yes or no: ";
	cin >> Choice;
	if(Choice == "yes" || Choice == "Yes")
	{
		if(Month == "" && Day == "")
		{
			runningMonth = stoi(currentMonth);
			runningYear = 1;
		}
		else if(Month != "" || Day != "")
		{
			
		if(currentYear > Year)
		{
			//Year advancment equation
			runningYear += 1;
			//Month advancement equation
			runningMonth =  stoi(currentMonth) - (stoi(Month) + 12);
		}
		else
		{
			runningMonth = stoi(currentMonth) - stoi(Month);
		}

		}

	}
	else
	{
		dateRecognitionSoftware();
	}
	
	monthNo = stoi(currentMonth);

	return (stoi(currentDay));

}

void Sales::ReadPassword()
{
	fstream File;
	string password;

	File.open("Password.txt");
	getline(File, password);
	File.close();

	UpdatePassword(password);
}
void Sales::UpdatePassword(string value)
{
	Password = value;
	fstream File;

	File.open("Password.txt", ios::out);	
	File << Password;
	File.close();
}

///////Encryption Constructor
Encryption::Encryption(char *inFileNames, char *outFileNames)
{
	inFileName = inFileName;
	outFileName = outFileNames;
	inFile.open(inFileName);
	outFile.open(outFileName);
	if (!inFile)
	{
		cout<< "Cannot open file\n\n";
		exit(1);
	}
	if (!outFile)
	{
		cout<< "Cannot open file\n\n";
		exit(1);
	}
}
///////Encryption Destructor
Encryption::~Encryption()
{
	inFile.close();
	outFile.close();
}
///////encrypt function
void Encryption::encrypt()
{
	char ch;
	char transCh;
	inFile.get(ch);

	while (!inFile.fail())
	{
		transCh = transform(ch);
		outFile.put(transCh);
		inFile.get(ch);
	}

	if (remove(inFileName.c_str()) != 0)
    {
        perror("Error deleting file");
    }
}

