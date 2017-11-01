// Calculator480.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<string>
#include<vector> //needed for vector
#include<sstream> //needed for ostringstream
#include<cstdlib>

using namespace std;



void calculate();
vector<string> parser();
vector<string> split();
bool isNumber(string s);
double addition(double num1, double num2);
double subtraction(double num1, double num2);
double multiplication(double num1, double num2);
double division(double num1, double num2);
double exponent(double num1, double num2);



int main()
{
	parser();
	system("PAUSE");
	return 0;
}

void calculate()
{
	vector<string> parsedVector = parser();
}

vector<string> parser()
{
	 //vector that will contain split up characters
	vector<string> splitter = split();
	vector<string> reversePolish;
	for(int i = 0; i < splitter.size(); i++)
	{
		if(isNumber(splitter[i]))
		{
			reversePolish.push_back(splitter[i]);
		}
		else
		{
			string tempString = splitter[i];
			char test = tempString[0]; //this converts the string to char
			switch(test)
			{
			case '+':
				cout << "The ouput is +" << endl;
				break;
			case '-':
				cout << "The ouput is -" << endl;
				break;
			case '/':
				cout << "The ouput is /" << endl;
				break;
			case '*':
				cout << "The ouput is *" << endl;
				break;
			case '^':
				cout << "The ouput is ^" << endl;
				break;
			case '(':
				cout << "The ouput is (" << endl;
				break;
			case ')':
				cout << "The ouput is )" << endl;
				break;
			}
		}
	}
	return reversePolish;
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
			cout << "is the num: " << n << endl;
			splitter.push_back(convert.str());
		}
		else
		{
			char c;
			cin.putback(input);
			cin >> c;
			convert << c;
			cout << "not num: " << c << endl;
			splitter.push_back(convert.str());
		}
	}
	return splitter;
}

bool isNumber(string s)
{
	try
	{
		stod(s.c_str());
	}	
	catch(...)
	{
		return false;
	}
	return true;
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
