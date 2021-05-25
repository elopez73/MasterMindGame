//Esau Lopez
//This is my work
#ifndef MASTERMIND_H
#define MASTERMIND_H
#include<string>
#include<ostream>
#include<sstream>
#include<iostream>
#include<cmath>
#include<ctime>
using namespace std; 
class Ball
{
public:
	string input;
	string kill;
	void inputColor()
	{
		cout << "Please enter a color " << endl;
		cin >> input;
		while (!(input == "red" || input == "blue" || input == "green" || input == "yellow" ||
			input == "brown" || input == "orange" || input == "black" || input == "white"))
		{
			cout << "Invalid color: Please enter a color " << endl;
			cin >> input;		
		}	
	}
	string getColor()
	{
		return input;
	}
};

class SolutionBall
{
public:
	string color;
	int value;
	void setran(int value)
	{
		switch (value) {
		case 0:
			color = "red";
			break;
		case 1:
			color = "green";
			break;
		case 2:
			color = "blue";
			break;
		case 3:
			color = "yellow";
			break;
		case 4:
			color = "orange";
			break;
		case 5:
			color = "brown";
			break;
		case 6:
			color = "black";
			break;
		case 7:
			color = "white";
			break;
		}
	}
	string getColor()
	{	
		return color;
	}
};
#endif