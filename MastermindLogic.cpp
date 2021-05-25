// This is my work
// Esua Lopez
#include<iostream>
#include<string.h>
#include"Mastermind.h"
#include<stdlib.h>
#include<cmath>
#include<ctime>
#include<sstream>
#include <conio.h>
using namespace std;
//Creates int to minimize the amount of checking code
//Checks color against one solution with three guesses
int checkColor(string g1, string g2, string g3, string s1)
{
	int Wp = 0;
	if (g1 == s1||g2==s1||g3==s1)
	{
		Wp = Wp + 1;
	}
	else
	{
		Wp = Wp;
	}
	return Wp;
}
//checks the color but of equal position, since that would generate a Black Peg
int Blackpeg(string c1, string c2)
{
	int Bp = 0;
	if (c1 == c2)
	{
		Bp += 1;
	}
	else
	{
		Bp = 0;
	}
	return Bp;
}
int main(void)
{
	//Cration of 4 random numbers//
	srand(time(NULL));
	int value = rand() % 8;
	int value2 = rand() % 8;
	int value3 = rand() % 8;
	int value4 = rand() % 8;
	//I decided to start my rounds before the loop//
	int rounds = 0;
	///////////////////////////
	//Creation of the Objects//
	Ball guess1;
	Ball guess2;
	Ball guess3;
	Ball guess4;
	SolutionBall solution1;
	SolutionBall solution2;
	SolutionBall solution3;
	SolutionBall solution4;
	//Creation of the solution colors//
	solution1.setran(value);
	solution2.setran(value2);
	solution3.setran(value3);
	solution4.setran(value4);
	//Start of the Game//
	cout << "              NOW THAT THE SOLUTION IS IN YOU MAY START WITH YOUR FIRST GUESS      " <<endl;
	for (rounds = 0; rounds <= 10; rounds++)
	{	
		int Black;//My Black Pegs
		int White;//My White Pegs
		//Now the user is prompted to input there colors
		guess1.inputColor();
		guess2.inputColor();
		guess3.inputColor();
		guess4.inputColor();
		//I do color checks on each position and color except the same postion
		White = checkColor(guess1.getColor(), guess2.getColor(), guess3.getColor(), solution4.getColor());
		White += checkColor(guess2.getColor(), guess3.getColor(), guess4.getColor(), solution1.getColor());
		White += checkColor(guess3.getColor(), guess4.getColor(), guess1.getColor(), solution2.getColor());
		White += checkColor(guess4.getColor(), guess1.getColor(), guess2.getColor(), solution3.getColor());
		//Its implied if im checking the same position i can check the color and if its true then they get a black peg
		Black = Blackpeg(guess1.getColor(), solution1.getColor());
		Black += Blackpeg(guess2.getColor(), solution2.getColor());
		Black += Blackpeg(guess3.getColor(), solution3.getColor());
		Black += Blackpeg(guess4.getColor(), solution4.getColor());
		cout << "Black Pegs: "<< Black << endl;
		cout << "White Pegs: "<< White << endl;
		cout << "Hit enter to start your next guess" << endl;
		//Create a backdoor door access the game answer by pressing k twice
		if (_getch() == 13)
		{
			Black = Black;
		}
		else if(_getch() == 'k')
		{
			Black = 4;
		}
		//If the 4 black pegs are aquired//
		if (Black == 4)
			{
			cout << flush;
			system("CLS");
			cout << "" << endl;
			cout << "                       YOUR SKILLS HAVE GOTTEN THE WIN, THIS IS TRULY FEAT UNLIKE ANY OTHER                   " << endl;
			cout <<	"                                                The Solution was: "<< endl;
			rounds = 11;
			cout << solution1.getColor() << endl;
			cout << solution2.getColor() << endl;
			cout << solution3.getColor() << endl;
			cout << solution4.getColor() << endl;
			cout << "                                           ";
			return 0;
			}
		if (Black != 4)
			{
				cout << "                              Just Keep Trying...                    " << endl;
				Ball* guess1 = new Ball;
				Ball* guess2 = new Ball;
				Ball* guess3 = new Ball;
				Ball* guess4 = new Ball;
			}
	}
	cout << flush;
	system("CLS");	
	cout << "                                You lost, better luck next time";
	cout << "                                The Solution was: " << endl;
	cout << solution1.getColor() << endl;
	cout << solution2.getColor() << endl;
	cout << solution3.getColor() << endl;
	cout << solution4.getColor() << endl;
	cout << "                                           ";
	return 0;
}
	