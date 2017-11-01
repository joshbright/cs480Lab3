// Calculator480.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<string>
#include<vector> //needed for vector
#include<sstream> //needed for ostringstream
#include<cctype> //needed for isdigit

using namespace std;


void calculate();
vector<string> split();
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
	 //vector that will contain split up characters
	vector<string> splitter = split();
	

}

vector<string> split() //split the input into an array
{
	vector<string> splitter;
	cout << "input what you want to calculate: ";
	while(char input = cin.get())
	{
		ostringstream convert;
		if(input == '\n')
			break;
		else if( ((input >= '0') && (input <= '9')) || (input == '.') )
		{
			double n;
			cin.putback(input);
			cin >> n;
			convert << n;
			cout << "num is: " << n << endl;
			splitter.push_back(convert.str());
		}
		else
		{
			char c;
			cin.putback(input);
			cin >> c;
			convert << c;
			cout << "char is: " << c << endl;
			splitter.push_back(convert.str());
		}
	}
	return splitter;
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
	return 0.0;
}
