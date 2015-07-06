/* CK King
section 1031
Start Time 07/12/12 2208 End Time 07/12/12*/

#include <iostream>
#include <fstream>

using namespace std;

class Encryption
{
protected:
	ifstream inFile;
	ofstream outFile;
	int key;
public:
	Encryption(char *inFileName, char *outFileName);
	~Encryption();
	virtual char transform(char ch, int i) = 0;
	void encrypt();
	void setKey(int i)
	{ key = i;}
};

Encryption::Encryption(char *inFileName, char *outFileName)
{
	inFile.open(inFileName);
	outFile.open(outFileName);
	if (!inFile)
	{
		cout << "The file " << inFileName << " cannot be opened.";
		exit(1);
	}
	if (!outFile)
	{
		cout << "The file " << outFileName << " cannot be opened.";
		exit(1);
	}
}

Encryption::~Encryption()
{
	inFile.close();
	outFile.close();
}

void Encryption::encrypt()
{
	char ch;
	char transCh;
	inFile.get(ch);
	while (!inFile.fail())
	{
		transCh = transform(ch, key);
		outFile.put(transCh);
		inFile.get(ch);
	}
}

class LessSimpleEncryption : public Encryption
{
public:
	virtual char transform(char ch, int i)
	{
		return ch + i;
	}
	LessSimpleEncryption(char *inFileName, char *outFileName)
		: Encryption(inFileName, outFileName)
	{
	}
};

int main()
{
	char inFileName[80], outFileName[80];
	cout << "Enter name of file to encrypt\n";
	cin >> inFileName;
	cout << "Enter the name of the file to recieve the encrypted text:\n";
	cin >> outFileName;
	LessSimpleEncryption obfuscate(inFileName, outFileName);
	obfuscate.setKey(15);
	obfuscate.encrypt();
	system("pause");
	return 0;
}