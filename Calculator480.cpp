// Calculator480.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<string>
#include<vector> //needed for vector
#include<sstream> //needed for ostringstream
#include<cstdlib>
#include<float.h>

using namespace std;


void parser();
vector<string> split();
vector<string> twoCharacterChecker(vector<string> splitter);
vector<string> doubleNeg(vector<string> splitter, int i);
int operatorPriority(string operation);
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

void parser()
{
	 //vector that will contain split up characters
	vector<string> splitter = split(); //the input vector
	vector<string> reversePolish; //The vector to store the postfix
	vector<string> stack; //The stack to keep track of parens

	int sizeOfSplitter = splitter.size();

	int parenCount = 0;
	for(int i = 0; i < sizeOfSplitter; i++)
	{
		//if the element at j is a number push to the reversePolish array
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
				while(!stack.empty() && operatorPriority(tempString) <= operatorPriority(stack.back()))
				{
					reversePolish.push_back(stack.back());
					stack.pop_back();
				}
				stack.push_back(splitter[i]);
				break;
			case '-':
				while(!stack.empty() && operatorPriority(tempString) <= operatorPriority(stack.back()))
				{
					reversePolish.push_back(stack.back());
					stack.pop_back();
				}
				stack.push_back(splitter[i]);
				break;
			case '/':
				while(!stack.empty() && operatorPriority(tempString) <= operatorPriority(stack.back()))
				{
					reversePolish.push_back(stack.back());
					stack.pop_back();
				}
				stack.push_back(splitter[i]);
				break;
			case '*':
				while(!stack.empty() && operatorPriority(tempString) <= operatorPriority(stack.back()))
				{
					reversePolish.push_back(stack.back());
					stack.pop_back();
				}
				stack.push_back(splitter[i]);
				break;
			case '^':
				while(!stack.empty() && operatorPriority(tempString) <= operatorPriority(stack.back()))
				{
					reversePolish.push_back(stack.back());
					stack.pop_back();
				}
				stack.push_back(splitter[i]);
				break;
			case '(':
				stack.push_back(splitter[i]); //insert ( onto stack
				parenCount++;
				break;
			case ')':
				while(stack.back() != "(" && !stack.empty())
				{
					reversePolish.push_back(stack.back()); //add top element of stack to reverse polish
					stack.pop_back(); //pop element off the stack
				}
				parenCount--;
				stack.pop_back();
				break;
			default:
				cout << "There is an incorrect symbol entered" << endl;
				return;
			}
		}
	}

	if(parenCount != 0)
	{
		cout <<" ERROR: Parenthesis aren't balanced"<<endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}

	while(!stack.empty())
	{
		reversePolish.push_back(stack.back());
		stack.pop_back();
	}



	//This is after the reverse polish
	//Start of actual calculator

	vector<double> calc;
	for(int i = 0; i< reversePolish.size(); i++)
	{
		string temp = reversePolish[i];
		if(isNumber(reversePolish[i]))
		{
			calc.push_back(stod(reversePolish[i]));
		}
		else
		{
			double num2 = calc.back();
			calc.pop_back();
			double num1 = calc.back();
			calc.pop_back();
			
			char test = temp[0];
			switch(test)
			{
			case '+':
				calc.push_back(addition(num1, num2));
				break;
			case '-':
				calc.push_back(subtraction(num1,num2));
				break;
			case '*':
				calc.push_back(multiplication(num1,num2));
				break;
			case '/':
				calc.push_back(division(num1,num2));
				break;
			case '^':
				calc.push_back(exponent(num1,num2));
				break;
			default:
				cout << "An unknown character has been encountered" << endl;
				return;
			}
		}
	}


	cout << "The answer is: " << calc.back() << endl;

}


vector<string> split() //split the input into an array
{
	vector<string> splitter;
	cout << "input what you want to calculate: ";
	while(char input = cin.get())
	{
		ostringstream convert;
		if((input == '\n') && splitter.size() == 0)
		{
			cout << "No input" << endl;
			break;
		}
		else if(input == '\n')
			break;
		else if( ((input >= '0') && (input <= '9')) || (input == '.') )
		{
			double n;
			cin.putback(input);
			cin >> n;
			convert << n;
			//cout << "is the num: " << n << endl;
			splitter.push_back(convert.str());
		}
		else
		{
			char c;
			cin.putback(input);
			cin >> c;
			convert << c;
			//cout << "not num: " << c << endl;
			splitter.push_back(convert.str());
		}
	}

	//TODO: call twoCharacterChecker to check characters
	if(!isNumber(splitter.front()) && splitter.front() != "-" && splitter.front() != "(")
	{
		cout <<" ERROR: You have entered an incorrect character in the front of your expression"<<endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
	splitter = twoCharacterChecker(splitter);
	return splitter;
}

vector<string> twoCharacterChecker(vector<string> splitter)
{
	//This checks if there are two characters in a row
	
	int negCount = 0;
	vector<string> fixed = splitter;
	for(int i=1; i < splitter.size(); i++)
	{
		string temp1 = splitter[i-1];
		string temp2 = splitter[i];

		if(isNumber(temp1))
		{
			double checked1 = stod(temp1);
			negCount = 0;
		}
		else
		{
			char checked1 = temp1[0];
			if(splitter[i-1] == "-")
			{
				negCount ++;
			}
		}

		if(isNumber(temp2))
		{
			double checked2 = stod(temp2);
		}
		else
		{
			char checked2 = temp2[0];
		}

		
		//checks if there are two numbers only seperated by a paraenthesis
		if(i+1 < splitter.size())
		{
			if(isNumber(splitter[i-1]) && isNumber(splitter[i+1]) && (splitter[i] != "+" && splitter[i] != "-" && splitter[i] != "/" && splitter[i] != "*" && splitter[i] != "^"))
			{
				cout <<" ERROR: There are two numbers in a row. Please use the operator * for multiplication"<<endl;
				system("PAUSE");
				exit(EXIT_FAILURE);
			}
		}

		if(!isNumber(temp2) && !isNumber(temp2))
		{
			if( (splitter[i-1] == "-") && (splitter[i] == "-") && negCount >= 2 )
			{
				cout <<" ERROR: There are too many -'s in a row"<<endl;
				system("PAUSE");
				exit(EXIT_FAILURE);
			}
			else if((splitter[i-1] == "-") && ( splitter[i] != "(" && splitter[i] != ")" && splitter[i] != "-") )
			{
				cout <<" ERROR: You have input a - before another character"<<endl;
				system("PAUSE");
				exit(EXIT_FAILURE);
			}
			else if((splitter[i-1] == "+") && (splitter[i] == "+"))
			{
				cout <<" ERROR: There are too many +'s in a row"<<endl;
				system("PAUSE");
				exit(EXIT_FAILURE);
			}
			else if((splitter[i-1] == "/") && (splitter[i] == "/"))
			{
				cout <<" ERROR: There are too many /'s in a row"<<endl;
				system("PAUSE");
				exit(EXIT_FAILURE);
			}
			else if((splitter[i-1] == "*") && (splitter[i] == "*"))
			{
				cout <<" ERROR: There are too many *'s in a row"<<endl;
				system("PAUSE");
				exit(EXIT_FAILURE);
			}
			else if((splitter[i-1] == "^") && (splitter[i] == "^"))
			{
				cout <<" ERROR: There are too many ^'s in a row"<<endl;
				system("PAUSE");
				exit(EXIT_FAILURE);
			}
			else if(i+1 < splitter.size())
			{
				string temp3 = splitter[i+1];
				char checked3 = temp3[0];
				
				if(splitter[i-1] == "-" && splitter[i] == "-" && !ispunct(checked3))
				{
					fixed = doubleNeg(splitter, i-1);
					splitter = fixed;
					negCount = 0;
				}
			}

			else if(splitter[i-1] == "-")
			{
				//do nothing
			}
			else 
			{
				/*
				cout <<" ERROR: random error"<<endl;
				system("PAUSE");
				exit(EXIT_FAILURE);*/
			}
		}
		if(splitter.front() == "-" && i == 1 && isNumber(splitter[1]))
		{
			double makeNeg = stod(splitter[1]);
			splitter.erase(splitter.begin());
			splitter.erase(splitter.begin());
			makeNeg = makeNeg * -1;
			ostringstream convert;
			convert << makeNeg;
			string str = convert.str();
			splitter.insert(splitter.begin(), str);
		}

		else if(i > 2 && (splitter[i-2] == "+" || splitter[i-2] == "/" || splitter[i-2] == "*" || splitter[i-2] == "^") && splitter[i-1] == "-" && isNumber(splitter[i]))
		{
			double makeNeg = stod(splitter[i]);
			splitter.erase(splitter.begin()+i-1);
			splitter.erase(splitter.begin()+i-1);
			makeNeg = makeNeg * -1;
			ostringstream convert;
			convert << makeNeg;
			string str = convert.str();
			if(i <= 3)
				splitter.push_back(str);
			else
				splitter.insert(splitter.begin()+i-1, str);
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

vector<string> doubleNeg(vector<string> splitter, int i)
{
	double temp = stod(splitter[i+2]);
	temp *= -1;
	splitter.erase(splitter.begin()+i);
	splitter.erase(splitter.begin()+i+1);
	ostringstream convert;
	convert << temp;
	string str = convert.str();
	i=i++;
	splitter.insert(splitter.begin()+i, str);
	return splitter;
}
int operatorPriority(string operation)
{
	char op = operation[0];
	switch(op)
	{
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	case '^':
		return 3;
	default:
		return 0;
	}
	
}
double addition(double num1, double num2)
{
	if(_finite(num1+num2))
		return num1 + num2;
	else
	{
		cout <<" ERROR: The solution of the equation is not finite"<<endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
}
double subtraction(double num1, double num2)
{
	if(_finite(num1-num2))
		return num1 - num2;
	else
	{
		cout <<" ERROR: The solution of the equation is not finite"<<endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
}
double multiplication(double num1, double num2)
{
	if(_finite(num1*num2))
		return num1*num2;
	else
	{
		cout <<" ERROR: The solution of the equation is not finite"<<endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
}
double division(double num1, double num2)
{
	//will check before this function to ensure num2 != 0
	if(num2 == 0)
	{
		cout <<" ERROR: You attempted to divide by divide by zero"<<endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}

	return num1 / num2;
}
double exponent(double num1, double num2)
{
	if(_finite((double)pow(num1,num2)))
		return pow(num1,num2);
	else
	{
		cout <<" ERROR: The solution of the equation is not finite"<<endl;
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
}
