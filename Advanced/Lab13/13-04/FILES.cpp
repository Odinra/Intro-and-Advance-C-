#include "FILES.h"

//constructionator
FILES::FILES( string s)
{
	//set the filename
	sFileName = s;
	//open the file
	file.open(sFileName);
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
