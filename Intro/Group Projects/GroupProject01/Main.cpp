/* Christopher King, , 
Section 1023 (T,TH 2-5)
Create a Group project that allows the user to build a computer to their specifications using
everything from chapters 1-4. */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;

int main()
{
	/*Declare variables for all data used. Name - email hold the customer
	information, sCpu - sVid hold the data from the files, sPlease, sLastTry
	sCancelled, and sChange hold the shortcuts for the longer sentances,
	sOutFile holds the name of the outputfile created by the program, 
	sTemp1 - sTemp6 hold the information from the file that is only used 
	temporarily */
	string sFirstName, sLastName, sAddress, sCity, sState, sZip, sPhone,
		sEmail, sCpu, sRam, sHd, sOd, sMon, sVid, sPlease, sChanges, sType,
		sLastTry, sCancelled, sOutFile, sTemp1, sTemp2, sTemp3, sTemp4,
		sTemp5, sTemp6, sLogo;
	/*dCpu - dVid hold the prices of the items, dTemp1 - dTemp4 hold the 
	excess values from the files */
	double dCpu, dRam, dHd, dOd, dMon, dVid, dTemp1, dTemp2, dTemp3, dTemp4,
		dDiscounted, dSubtotal, dDiscountAmt, dSubtotalDiscAmt, dSubtotalDisc,
		dShipping, dTax, dGrandTotal, dTotalShip;
	//char for the if statements
	char cCPU, cRam, cHd, cOd, cMon, cVid, cIf;
	//sets a value to hold the length of the string, and the menu.
	int iSLength, iMenu;
	ifstream ifCPU, ifRam, ifHard, ifOptical, ifMonitor, ifVideo;
	ofstream outPutFile;
	system("cls");

	//set up "shortcuts" for repeated statements to be displayed
	sPlease = "Please enter your ";
	sLastTry = "That data is incorrect you have ONE (1) more attempt to enter "
		"the correct data\n";
	sLastTry += "If the correct data is not entered the program will close\n\n";
	sCancelled = "\t   Your Order has been cancelled due to invalid information"
		"\n";
	sChanges = "Would wou like to make any changes ";
	sType = "Choose which component you wish to purchase.\n\n";

	//Store the logo in the logo string
	sLogo = "_____                          _____\n"
            "|    |  |             ^       |       |  /\n"
            "|    |  |            / \\      |       | /\n"
            "|____|  |           /   \\     |       |/\n" 
            "|    |  |          /_____\\    |       |\\ \n"
            "|    |  |         /       \\   |       | \\ \n"
            "|____|  |______  /         \\  |_____  |  \\ \n\n"
			"_____       ______   _____             ______\n"
            "|           |     | |     |   |     |  |     |\n"
            "|           |     | |     |   |     |  |     |\n"
            "|    ____   |_____| |     |   |     |  |_____| \n"
            "|      |\\   | \\     |     |   |     |  |\n"
            "|      | \\  |  \\    |     |   |     |  |\n"
            "|______|  \\ |   \\   |_____|   |_____|  |\n";
	

	//Display the logo and prompt the user to start the program
	cout << sLogo <<"\nPress any key to begin your order...\n";
	_getch();

	system("cls");

	cout << sPlease << "First Name\n\t";
	getline(cin, sFirstName);
	
	//store the number of characters stored in sFirstname
	iSLength = sFirstName.length();
	//test that there is at least 2 characters stored in the string varaible
	//if there is less than 2 characters it gives the user one more chance
	if ( iSLength < 1)
	{
		cout << sLastTry << sPlease << "First Name\n\t";
		getline(cin, sFirstName);
		iSLength = sFirstName.length();

		//again tests that there are at least 2 characters stored
		if ( iSLength < 1)
		{
			//if there are still less than 2 characters the program will clear
			//the screen and close
			system("cls");
			cout << sCancelled;
			exit(0);
		}
	}
	//does the same thing for all other strings as sFirstName through Email 
	
	cout << sPlease << "Last Name\n\t";
	getline(cin, sLastName);
	iSLength = sLastName.length();
	if (iSLength < 1)
	{
		cout << sLastTry << sPlease << "Last Name\n\t";
		getline(cin, sLastName);
		iSLength = sLastName.length();
		if (iSLength < 1)
		{
			system("cls");
			cout << sCancelled;
			exit(0);
		}
	}
	cout << sPlease << "Address\n\t";
	getline(cin, sAddress);
	iSLength = sAddress.length();
	if (iSLength < 1)
	{
		cout << sLastTry << sPlease << "Address\n\t";
		getline(cin, sAddress);
		iSLength = sAddress.length();
		if (iSLength < 1)
		{
			system("cls");
			cout << sCancelled;
			exit(0);
		}
	}
	cout << sPlease << "City\n\t";
	getline(cin, sCity);
	iSLength = sCity.length();
	if (iSLength < 1)
	{
		cout << sLastTry << sPlease << "City\n\t";
		getline(cin, sCity);
		iSLength = sCity.length();
		if (iSLength < 1)
		{
			system("cls");
			cout << sCancelled;
			exit(0);
		}
	}
	cout << sPlease << "State\n\t";
	getline(cin, sState);
	iSLength = sState.length();
	if (iSLength < 1)
	{
		cout << sLastTry << sPlease << "State\n\t";
		getline(cin, sState);
		iSLength = sState.length();
		if (iSLength < 1)
		{
			system("cls");
			cout << sCancelled;
			exit(0);
		}
	}
	cout << sPlease << "Zip Code\n\t";
	getline(cin, sZip);
	iSLength = sZip.length();
	if (iSLength < 1 )
	{
		cout << sLastTry << sPlease << "Zip Code\n\t";
		getline(cin, sZip);
		iSLength = sZip.length();
		if (iSLength < 1)
		{
			system("cls");
			cout << sCancelled;
			exit(0);
		}
	}
	cout << sPlease << "Phone Number\n\t";
	getline(cin, sPhone);
	iSLength = sPhone.length();
	if (iSLength < 1 )
	{
		cout << sLastTry << sPlease << "Phone Number\n\t";
		getline(cin, sPhone);
		iSLength = sPhone.length();
		if (iSLength < 1 )
		{
			system("cls");
			cout << sCancelled;
			exit(0);
		}
	}
	cout << sPlease << "Email Address\n\t";
	getline(cin, sEmail);
	iSLength = sEmail.length();
	if (iSLength < 1 )
	{
		cout << sLastTry << sPlease << "Email Address\n\t";
		if (iSLength < 1 )
		{
			system("cls");
			cout << sCancelled;
			exit(0);
		}
	}
	


	system("cls");

	//open each of the 6 input files
	ifCPU.open("cpu.dat");
	ifRam.open("ram.dat");
	ifHard.open("harddrive.dat");
	ifOptical.open("opticaldrive.dat");
	ifMonitor.open("monitor.dat");
	ifVideo.open("video.dat");

	//store the data from the files in the appropriate variable
	ifCPU >> sCpu >> sTemp1 >> dCpu;
	// uses the 2 seperate string variables to show the data as it is in the 
	// files
	sCpu = sCpu + " " + sTemp1;

	ifRam >> sRam >> sTemp1 >> dRam;
	sRam = sRam + " " + sTemp1;

	ifHard >> sHd >> sTemp1 >> dHd;
	sHd = sHd + " " + sTemp1;

	ifOptical >> sOd >> dOd;

	ifMonitor >> sMon >> sTemp1 >> sTemp2 >> sTemp3 >> dMon;
	sMon = sMon + " " + sTemp1 + " " + sTemp2 + " " + sTemp3;

	ifVideo >> sVid >> sTemp1 >> dVid;
	sVid = sVid + " " + sTemp1;


	cout << fixed << setprecision(2);
	cout << left << setw(25) << sCpu << "$" << right << setw(10) << dCpu <<endl
		<< left << setw(25) << sRam << "$" << right << setw(10) << dRam << endl
		<< left << setw(25) << sHd<< "$" << right << setw(10) << dHd << endl 
		<< left << setw(25) << sOd << "$" << right << setw(10) << dOd << endl 
		<< left << setw(25) << sMon << "$" << right << setw(10) << dMon << endl
		<< left << setw(25) << sVid << "$" << right << setw(10) << dVid <<endl;
	
	cIf = cCPU = cRam = cHd = cOd = cMon = cVid = 'n';
	//prompt and recieve input on wheteher the user would like to change any of
	//the deafault values
	cout << "This is the default configuration. " << sChanges << "? Y/N?\n";
	cin >> cIf;
	
	//if statement for storing which values need to be changed
	if (cIf  == 'Y' || cIf == 'y')
	{
		cout << sChanges << "to the CPU? Y/N?\n";
		cin >> cCPU;
		cout << sChanges << "to the Ram? Y/N?\n";
		cin >> cRam;
		cout << sChanges << "to the Hard Drive? Y/N?\n";
		cin >> cHd;
		cout << sChanges << "to the Optical Drive? Y/N?\n";
		cin >> cOd;
		cout << sChanges << "to the Monitor? Y/N?\n";
		cin >> cMon;
		cout << sChanges << "to the Video Card? Y/N?\n";
		cin >> cVid;
	}

	system("cls");

	//Test to see if the file needs any more extraction
	if (cCPU == 'Y' || cCPU == 'y')
	{
		//Extract the data from the file
		ifCPU >> sTemp1 >> sTemp2 >> dTemp1;
		sTemp1 = sTemp1 + " " + sTemp2;
		ifCPU >> sTemp2 >> sTemp3 >> dTemp2;
		sTemp2 = sTemp2 + " " + sTemp3;
		ifCPU >> sTemp3 >> sTemp4 >> dTemp3;
		sTemp3 = sTemp3 + " " + sTemp4;

		//Print the Menu to the user
		cout << sType <<  "1. " << left << setw(25) << sCpu 
			<< "$" << right << setw(10) << dCpu;
		cout << "\n2. " << left << setw(25) << sTemp1 
			<< "$" << right << setw(10) << dTemp1;
		cout << "\n3. " << left << setw(25) << sTemp2 
			<< "$" << right << setw(10) << dTemp2;
		cout << "\n4. " << left << setw(25) << sTemp3
			<< "$" << right << setw(10) << dTemp3 << endl;
		cin >> iMenu;

		//takes the users selection and assigns it as the prefered choice
		if (iMenu == 1)
		{
			sCpu = sCpu;
			dCpu = dCpu;
		}
		else if (iMenu == 2)
		{
			sCpu = sTemp1;
			dCpu = dTemp1;
		}
		else if (iMenu == 3)
		{
			sCpu = sTemp2;
			dCpu = dTemp2;
		}
		else if (iMenu == 4)
		{
			sCpu = sTemp3;
			dCpu = dTemp3;
		}
	}

	if (cRam == 'Y' || cRam == 'y')
	{
		ifRam >> sTemp1 >> sTemp2 >> dTemp1;
		sTemp1 = sTemp1 + " " + sTemp2;
		ifRam >> sTemp2 >> sTemp3 >> dTemp2;
		sTemp2 = sTemp2 + " " + sTemp3;
		ifRam >> sTemp3 >> sTemp4 >> dTemp3;
		sTemp3 = sTemp3 + " " + sTemp4;

		cout << sType << "1. " << left << setw(25) << sRam 
			<< "$" << right << setw(10) << dRam;
		cout << "\n2. " << left << setw(25) << sTemp1 
			<< "$" << right << setw(10) << dTemp1;
		cout << "\n3. " << left << setw(25) << sTemp2 
			<< "$" << right << setw(10) << dTemp2;
		cout << "\n4. " << left << setw(25) << sTemp3 
			<< "$" << right << setw(10) << dTemp3 << endl;
		cin >> iMenu;

		if (iMenu == 1)
		{
			sRam = sRam;
			dRam = dRam;
		}
		else if (iMenu == 2)
		{
			sRam = sTemp1;
			dRam = dTemp1;
		}
		else if (iMenu == 3)
		{
			sRam = sTemp2;
			dRam = dTemp2;
		}
		else if (iMenu == 4)
		{
			sRam = sTemp3;
			dRam = dTemp3;
		}
	}
	
	if (cHd == 'Y' || cHd == 'y')
	{
		ifHard >> sTemp1 >> sTemp2 >> dTemp1;
		sTemp1 = sTemp1 + " " + sTemp2;
		ifHard >> sTemp2 >> sTemp3 >> dTemp2;
		sTemp2 = sTemp2 + " " + sTemp3;
		ifHard >> sTemp3 >> sTemp4 >> dTemp3;
		sTemp3 = sTemp3 + " " + sTemp4;

		cout << sType << "1. " << left << setw(25) << sHd 
			<< "$" << right << setw(10) << dHd;
		cout << "\n2. " << left << setw(25) << sTemp1 
			<< "$" << right << setw(10) << dTemp1;
		cout << "\n3. " << left << setw(25) << sTemp2 
			<< "$" << right << setw(10) << dTemp2;
		cout << "\n4. " << left << setw(25) << sTemp3 
			<< "$" << right << setw(10) << dTemp3 << endl;
		cin >> iMenu;

		if (iMenu == 1)
		{
			sHd = sHd;
			dHd = dHd;
		}
		else if (iMenu == 2)
		{
			sHd = sTemp1;
			dHd = dTemp1;
		}
		else if (iMenu == 3)
		{
			sHd = sTemp2;
			dHd = dTemp2;
		}
		else if (iMenu == 4)
		{
			sHd = sTemp3;
			dHd = dTemp3;
		}
	}

	if (cOd == 'Y' || cOd == 'y')
	{
		ifOptical >> sTemp1 >> sTemp2 >> dTemp1;
		sTemp1 = sTemp1 + " " + sTemp2;
		ifOptical >> sTemp2 >> sTemp3 >> sTemp4 >> sTemp5 >> dTemp2;
		sTemp2 = sTemp2 + " " + sTemp3 + " " + sTemp4 + " " + sTemp5;
		ifOptical >> sTemp3 >> sTemp4 >> sTemp5 >> sTemp6 >> dTemp3;
		sTemp3 = sTemp3 + " " + sTemp4 + " " + sTemp5 + " " + sTemp6;

		cout << sType << "1. " << left << setw(25) << sOd 
			<< "$" << right << setw(10) << dOd;
		cout << "\n2. " << left << setw(25) << sTemp1 
			<< "$" << right << setw(10) << dTemp1;
		cout << "\n3. " << left << setw(25) << sTemp2 
			<< "$" << right << setw(10) << dTemp2;
		cout << "\n4. " << left << setw(25) << sTemp3 
			<< "$" << right << setw(10) << dTemp3 << endl;
		cin >> iMenu;

		if (iMenu == 1)
		{
			sOd = sOd;
			dOd = dOd;
		}
		else if (iMenu == 2)
		{
			sOd = sTemp1;
			dOd = dTemp1;
		}
		else if (iMenu == 3)
		{
			sOd = sTemp2;
			dOd = dTemp2;
		}
		else if (iMenu == 4)
		{
			sOd = sTemp3;
			dOd = dTemp3;
		}
	}
	
	if (cMon == 'Y' || cMon == 'y')
	{
		ifMonitor >> sTemp1 >> sTemp2 >> sTemp3 >> sTemp4 >> dTemp1;
		sTemp1 = sTemp1 + " " + sTemp2 + " " + sTemp3 + " " + sTemp4;
		ifMonitor >> sTemp2 >> sTemp3 >> sTemp4 >> sTemp5 >> dTemp2;
		sTemp2 = sTemp2 + " " + sTemp3 + " " + sTemp4 + " " + sTemp5;

		cout << sType << "1. " << left << setw(25) << sMon 
			<< "$" << right << setw(10) << dMon;
		cout << "\n2. " << left << setw(25) << sTemp1 
			<< "$" << right << setw(10) << dTemp1;
		cout << "\n3. " << left << setw(25) << sTemp2 
			<< "$" << right << setw(10) << dTemp2 << endl;
		cin >> iMenu;

		if (iMenu == 1)
		{
			sMon = sMon;
			dMon = dMon;
		}
		else if (iMenu == 2)
		{
			sMon = sTemp1;
			dMon = dTemp1;
		}
		else if (iMenu == 3)
		{
			sMon = sTemp2;
			dMon = dTemp2;
		}
	}

	if (cVid == 'Y' || cVid == 'y')
	{
		ifVideo >> sTemp1 >> sTemp2 >> dTemp1;
		sTemp1 = sTemp1 + " " + sTemp2;
		ifVideo >> sTemp2 >> sTemp3 >> dTemp2;
		sTemp2 = sTemp2 + " " + sTemp3;
		ifVideo >> sTemp3 >> sTemp4 >> dTemp3;
		sTemp3 = sTemp3 + " " + sTemp4;

		cout << sType << "1. " << left << setw(25) << sVid 
			<< "$" << right << setw(10) << dVid;
		cout << "\n2. " << left << setw(25) << sTemp1 
			<< "$" << right << setw(10) << dTemp1;
		cout << "\n3. " << left << setw(25) << sTemp2 
			<< "$" << right << setw(10) << dTemp2;
		cout << "\n4. " << left << setw(25) << sTemp3 
			<< "$" << right << setw(10) << dTemp3 << endl;
		cin >> iMenu;

		if (iMenu == 1)
		{
			sVid = sVid;
			dVid = dVid;
		}
		else if (iMenu == 2)
		{
			sVid = sTemp1;
			dVid = dTemp1;
		}
		else if (iMenu == 3)
		{
			sVid = sTemp2;
			dVid = dTemp2;
		}
		else if (iMenu == 4)
		{
			sVid = sTemp3;
			dVid = dTemp3;
		}
	}
	//close each of the 6 input files
	ifCPU.close();
	ifRam.close();
	ifHard.close();
	ifOptical.close();
	ifMonitor.close();
	ifVideo.close();

	//check if elligible for a discount and if so which one.
	dDiscountAmt = 0;

	cout << "You may qualify for a discount \nAre you a student? Y/N?\n";
	cin >> cIf;

	if (cIf == 'y' || cIf == 'Y')
		dDiscountAmt = .12;

	cout << "Are you a Senior Citizen? Y/N?\n";
	cin >> cIf;

	if (cIf == 'y' || cIf == 'Y')
		dDiscountAmt = .15;

	//Perform calculations neccessary for data used by the program

	dSubtotal = dCpu + dRam + dHd + dOd + dMon + dVid;

	if (dDiscountAmt > 0)
		dSubtotalDisc = dSubtotal * dDiscountAmt;
	else 
		dSubtotalDisc = 0;

	dSubtotalDiscAmt = dSubtotal - dSubtotalDisc;

	dShipping = dSubtotalDiscAmt * .08;

	dTotalShip = dSubtotalDiscAmt + dShipping;

	dTax = dTotalShip *.0825;

	dGrandTotal = dTax + dTotalShip;

	system("cls");

	//display the final customization and prices and confirm the order
	cout << "Your final customization is:\n" << left << setw(25) << sCpu 
		<< "$" << right << setw(10) << dCpu << endl 
		<< left << setw(25) << sRam << "$" << right << setw(10) << dRam << endl
		<< left << setw(25) << sHd << "$" << right << setw(10) << dHd << endl 
		<< left << setw(25) << sOd << "$" << right << setw(10) << dOd << endl 
		<< left << setw(25) << sMon << "$" << right << setw(10) << dMon << endl
		<< left << setw(25) << sVid << "$" << right << setw(10) << dVid 
		<< "\n\nSubtotal:\n$" << right << setw(10) << dSubtotal 
		<< "\nDiscount Amount:\n$" << right << setw(10) << dSubtotalDisc 
		<< "\nDiscounted Subtotal:\n$" << right << setw(10) << dSubtotalDiscAmt
		<< "\nShipping charge:\n$" << right << setw(10) << dShipping 
		<< "\nSales tax:\n$" << right << setw(10) << dTax 
		<< "\nYour Grand Total is:\n$" << right << setw(10) << dGrandTotal;

	cout << "\nWould you like to confirm your order? Y/N?\n";
	cin >> cIf;

	//if order is not confirmed closes program
	if (cIf == 'N' || cIf == 'n')
	{
		system("cls");
		cout << "Your order has been cancelled.\n";
		exit(0);
	}

	

	//Use the sOutFile to store the requested name for the output file
	sOutFile = sLastName + "," + sFirstName + ".dat";

	//open the ouputfile with the correct name
	outPutFile.open(sOutFile);

	//output the information into the created file
	outPutFile << fixed << setprecision(2) << sFirstName << " " << sLastName 
		<< "\n" << sAddress << "\n" << sCity << ",\t" << sState << "\t" << sZip
		<< "\n" << sPhone << "\n" << sEmail << "\n" 
		<< "\n\nSubtotal:\n$" << right << setw(10) << dSubtotal 
		<< "\nDiscount Amount:\n$" << right << setw(10) << dSubtotalDisc 
		<< "\nDiscounted Subtotal:\n$" << right << setw(10) << dSubtotalDiscAmt 
		<< "\nShipping charge:\n$" << right << setw(10) << dShipping 
		<< "\nSales tax:\n$" << right << setw(10) << dTax 
		<< "\nYour Grand Total is:\n$" << right << setw(10) << dGrandTotal 
		<< "\n\nYour final customization is:\n" 
		<< left << setw(25) << sCpu << "$" << right << setw(10) << dCpu << endl
		<< left << setw(25) << sRam << "$" << right << setw(10) << dRam << endl
		<< left << setw(25) << sHd << "$" << right << setw(10) << dHd << endl
		<< left << setw(25) << sOd << "$" << right << setw(10) << dOd << endl
		<< left << setw(25) << sMon << "$" << right << setw(10) << dMon << endl
		<< left << setw(25) << sVid << "$" << right << setw(10) << dVid;
	
	//close the outputfile
	outPutFile.close();

	return 0;
}