// Calculator480.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<string>
#include<vector>
#include "stdafx.h"

using namespace std;

void calculate();
vector<string> splitter(string input);
double addition(double num1, double num2);
double subtraction(double num1, double num2);
double multiplication(double num1, double num2);
double division(double num1, double num2);
double exponent(double num1, double num2);



int main()
{
	calculate();
	return 0;
}

void calculate()
{
	vector<string> splitter; //vector that will contain split up characters
	cout << "input what you want to calculate: ";
	char input = cin.get();

	if( (input >= '0') && (input <= '9'))
	{
		int n;
		cin.putback(input);
		cin >> n;
		cout << "you input: " << n << endl;
	}
	else
	{

		//switch()
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
