#pragma once
#include <iostream>

using namespace std;

class AbstractSeq
{
public:
	virtual int fun(int k) = 0;
	void printSeq(int k, int m);
	int sumSeq(int k, int m);

};

class OddSeq: public AbstractSeq
{
public:
	int fun(int k)
	{
		return (2*k + 1);
	}
};

class CubeSeq : public AbstractSeq
{
	int fun(int k)
	{
		return (k*k*k);
	}
};