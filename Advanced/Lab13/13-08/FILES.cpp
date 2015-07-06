#include "FILES.h"

//constructionator
FILES::FILES( string s)
{
	//set the filename
	sFileName = s;
	//open the file
	file.open(sFileName);
}
//find customer function
int FILES::findCust(string name)
{
	//variables
	int position;
	//loop
	while(!file.eof())
	{
		//set the position
		position = file.tellp();
		//read the current record
		file.read(reinterpret_cast<char *>(&customer), sizeof(customer));
		//if this is the correct record return the position
		if (customer.sName == name)
		{
			return position;
		}
	}
	//if not, tell the user it doesnt exist		
	cout << "/n/n/t/tThat record was not foud. Please check spelling and case./n/n";
	//if record doesn't exist return -1(sentinel)
	return (-1);
}

//display customer function
void FILES::displayCust(string name)
{
	//variables
	int position;
	//call the findcust function
	position = findCust(name);
	//if the customer is valid display it
	if (position != -1)
	{
		file.seekg(position, ios::beg);
		file.read(reinterpret_cast<char *>(&customer), sizeof(customer));
		cout << customer.sName << '/n' << customer.sAddress << '/n' 
			<< customer.sCity_State << '/n' << customer.sPhone << '/n'
			<< customer.dAccountBalance << '/n' << customer.sLastPayment << '/n/n';
	}

}
//delete customer function
void FILES::deleteCust(string name)
{
	//variables
	int position;
	//call the findcust function
	position = findCust(name);
	//if the customer is valid delete it
	if (position != -1)
	{
		file.seekp(position, ios::beg);
		for (int spot = 0; spot < sizeof(customer); spot++)
			file.put(127);
		cout << "/n/n/t/tThe Record was deleted./n/n";
	}

}
//delete customer function (overloaded because location is already known)
void FILES::deleteCust(int position)
{
	//if the customer is valid delete it
	if (position != -1)
	{
		file.seekp(position, ios::beg);
		for (int spot = 0; spot < sizeof(customer); spot++)
			file.put(127);
		cout << "/n/n/t/tThe Record was deleted./n/n";
	}

}
//change customer function
void FILES::changeCust(char Name[], char Address[], char City_State[], char Phone[], double AccountBalance, char LastPayment[])
{
	//variable stuffs
	int position;
	strcpy_s(customer.sName, Name);
	strcpy_s(customer.sAddress,  Address);
	strcpy_s(customer.sCity_State, City_State);
	strcpy_s(customer.sPhone, Phone);
	customer.dAccountBalance = AccountBalance;
	strcpy_s(customer.sLastPayment, LastPayment);
	position = findCust(customer.sName);

	//if the file exists delete then replace it
	if (position != -1)	
	{
		deleteCust(position);
		file.seekp(position, ios::beg);
		file.write(reinterpret_cast<char *>(&customer), sizeof(customer));
	}
}
//display all function
void FILES::displayAll()
{
	//read the first record
	file.read(reinterpret_cast<char *>(&customer), sizeof(customer));
	do
	{
		//display the read information
		cout << customer.sName << '/n' << customer.sAddress << '/n' 
			<< customer.sCity_State << '/n' << customer.sPhone << '/n'
			<< customer.dAccountBalance << '/n' << customer.sLastPayment << '/n/n';
		file.read(reinterpret_cast<char *>(&customer), sizeof(customer));
	}while (!file.eof());
}
//add customer function
void FILES::addCust(char Name[], char Address[], char City_State[], char Phone[], double AccountBalance, char LastPayment[])
{
	//variable stuffs
	int position;
	strcpy_s(customer.sName, Name);
	strcpy_s(customer.sAddress,  Address);
	strcpy_s(customer.sCity_State, City_State);
	strcpy_s(customer.sPhone, Phone);
	customer.dAccountBalance = AccountBalance;
	strcpy_s(customer.sLastPayment, LastPayment);
	//set the write point to the end of the file
	file.seekp(0, ios::end);
	position = file.tellp();
	//write to the file
	file.write(reinterpret_cast<char *>(&customer), sizeof(customer));

}
string FILES::LastLines(int iNoLines)
{
	//variables
	string sLines, sAdder;
	int iNoNewLines = 0;
	long int iFileLocation = 0;
	char ch;
	//for loop ( for some reason it was counting every \n twice so I doubled noLines)
	for (int ibyte = 0; iNoNewLines < iNoLines * 2 && iFileLocation != -1; ibyte--)
	{
		//seek from the end ( it would not work if it started at 0 for some reason)
		file.seekg((/*sizeof(char) * */ibyte - 1), ios::end);
		//set the current location
		iFileLocation = file.tellg();
		//get the character
		file.get(ch);
		//test if that character is /n
		if (ch == '\n')
		{
			//if so incrementation occurs
			iNoNewLines++;
		}

	}
	//do loop
	do
	{
		//manipulation of the returned string
		getline(file, sAdder);
		sLines.append(sAdder + '\n');
		iNoNewLines--;
	}while (iNoNewLines > iNoLines);
	//return the last 10 lines of the file in 1 large string.
	return sLines;
}
//encrypt function
void FILES::encrypt()
{
	//open the file to be outputed to
	fstream eFile;
	eFile.open("(encrypted)" + sFileName, ios::out);
	//encrypt
	while (!file.eof())
	{
		char ch;
		file.get(ch);
		ch += 10;
		eFile.put(ch);
	}
	eFile.close();
}
//decrypt function
void FILES::decrypt()
{
	//open the file to be outputed to
	fstream eFile;
	eFile.open("(decrypted)" + sFileName, ios::out);
	//decrypt
	while (!file.eof())
	{
		char ch;
		file.get(ch);
		ch -= 10;
		eFile.put(ch);
	}
	eFile.close();
}