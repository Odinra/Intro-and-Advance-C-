#ifndef FILES_H_
#define FILES_H_
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

//files class
class FILES
{
	//private variables
private:
	fstream file;
	string sFileName;
	//public functions
public:
	//constructionator prototype
	FILES(string s);
	//destructor
	~FILES()
	{
		//close
		file.close();
	}
	//prototype
	string LastLines(int iNoLines);
};

#endif