// Calculator480.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<string>
#include<vector>
#include "stdafx.h"

using namespace std;

string input();
void calculate(string input);
vector<string> splitter(string input);
double addition(double num1, double num2);
double subtraction(double num1, double num2);
double multiplication(double num1, double num2);
double division(double num1, double num2);
double exponent(double num1, double num2);



int main()
{
	input();
	return 0;
}

void input()
{
	cout << "input what you want to calculate: ";
	char input = cin.get();
}

void calculate(string input)
{
	//split string into the vector
	vector<string> splitter;


}

vector<string> splitter(string input)
{
	vector<string> splitter;
	vector<int> tempInt;
	int count = 0;
	int max = input.length();

	for(int i = 0; i < max; i++)
	{
		char tempString = input.substr(i,1);
		if(tempString.compare("+"))
			splitter.push_back(tempString);
		else if (tempString.compare("-"))
			splitter.push_back(tempString);
		else if (tempString.compare("*"))
			splitter.push_back(tempString);
		else if (tempString.compare("/"))
			splitter.push_back(tempString);
		else if ()


	}


}

double addition(double num1, double num2)
{
	return num1 + num2;
}
double subtraction(double num1, double num2)
{
	return num1 - num2;
}
double multiplication(double num1, double num2)
{
	return num1 * num2;
}
double division(double num1, double num2)
{
	//will check before this function to ensure num2 != 0
	return num1 / num2;
}
double exponent(double num1, double num2)
{

}
