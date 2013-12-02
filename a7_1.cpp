//Nathan Mueller, 10/29/13, Harden
//This program creates three sets of math problems for a user to solve. Each set involves two numbers either added,
//subtracted or multiplied. The user gets to define how many problems are in each set and the maximum
// number that will be used in the problems. The program provides feedback on whether the problem was correct
//or not and also gives a report at the end telling the user how they did overall with percentages correct.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "conio.h"

int getProbsPerSet(int &probsPerSet);
void doOneSet(char ch, int probsPerSet, double &numCorrect);
void doOneProblem(char ch, int maxNum, double &numCorrect);
void printHeader(char ch);
int getMaxNum(int &maxNum);
void generateOperands(int num1, int num2, char ch);
int calculateCorrectAnswer(int num1, int num2, char ch);
void checkAnswer(int answer, int correctAnswer, double &numCorrect); 
void printReport(double set1Correct, double set2Correct, double set3Correct, int probsPerSet);



int main()
{
	int probsPerSet;
	double set1Correct = 0.0;
	double set2Correct = 0.0;
	double set3Correct = 0.0;

	getProbsPerSet(probsPerSet);	//user enters the number of problems they want in each set
	srand(time(0)); 
	doOneSet('+', probsPerSet, set1Correct);    //three sets of problems are created
    doOneSet('-', probsPerSet, set2Correct);
    doOneSet('*', probsPerSet, set3Correct);
	printReport(set1Correct, set2Correct, set3Correct, probsPerSet);	//a report is generated for the user
																		//telling them how they did

	_getch();
}






//User enters the number of problems they want per set
int getProbsPerSet(int &probsPerSet)
{
	cout << "Enter problems per set: ";
	cin >> probsPerSet;
	return probsPerSet;
}






//creates on set of problems with the current operand
void doOneSet(char ch, int probsPerSet, double &numCorrect) 
{

	int maxNum;

	printHeader(ch);
	getMaxNum(maxNum);

	for (int i = 1; i <= probsPerSet; i++)
	{
		doOneProblem(ch, maxNum, numCorrect);
	}

}




//prints out the header at the top of each set denoting the number
void printHeader(char ch)
{
	int setNumber;

	if (ch == '+')
		setNumber = 1;
	if (ch == '-')
		setNumber = 2;
	if (ch == '*')
		setNumber = 3;

	cout << endl << "Set #" << setNumber << endl << "----------" << endl;
}




//allows the user to enter the highest number that can be used in one of the problems
int getMaxNum(int &maxNum)
{
	cout << "What is the maximum number for this set? ";
	cin >> maxNum;
	return maxNum;
}





//creates a single problem with two random numbers and the desired operand,
//collects the user's answer, checks it and passes the number that they
//got correct up to the main function
void doOneProblem(char ch, int maxNum, double &numCorrect)
{
	int num1 = rand() % maxNum + 1;
	int num2 = rand() % maxNum + 1;
	int answer;
	int correctAnswer;
	generateOperands(num1, num2, ch);
	cin >> answer;
	correctAnswer = calculateCorrectAnswer(num1, num2, ch);
	checkAnswer(answer, correctAnswer, numCorrect);
}







//prints out the problem for the user to solve
void generateOperands(int num1, int num2, char ch)
{
	cout << num1 << " " << ch << " " << num2 << " = ";
}






//calculates what the correct answer for the problem should be
int calculateCorrectAnswer(int num1, int num2, char ch)
{
	if (ch == '+')
		return num1 + num2;
	if (ch == '-')
		return num1 - num2;
	if (ch == '*')
		return num1 * num2;
}







//checks the user's answer and prints out feedback and increases the count of correct answers for the 
//report that is printed at the end
void checkAnswer(int answer, int correctAnswer, double &numCorrect)
{
	if (answer == correctAnswer)
	{
		cout << "correct" << endl;
		numCorrect++;
	}
	else
		cout << "incorrect" << endl;
}





//prints out a report telling the user how many problems they got correct out of the total for each set
// and the percentage correct that that equals, and also a total and percentage for all the problems
void printReport(double set1Correct, double set2Correct, double set3Correct, int probsPerSet)
{
	double totalCorrect = set1Correct + set2Correct + set3Correct;
	double total = probsPerSet * 3.0;

	cout.precision(0); 
	cout.setf(ios::fixed); 

	cout << endl << endl;
	cout << "Set#1: You got " << set1Correct << " out of " << probsPerSet << " for " 
		 << (set1Correct / probsPerSet) * 100 << "%" << endl;

	cout << "Set#2: You got " << set2Correct << " out of " << probsPerSet << " for " 
		 << (set2Correct / probsPerSet) * 100 << "%" << endl;

	cout << "Set#3: You got " << set3Correct << " out of " << probsPerSet << " for " 
		 << (set3Correct / probsPerSet) * 100 << "%" << endl;

	cout << "Overall you got " << totalCorrect << " correct out of " << total << " for " 
		 << (totalCorrect / total) * 100 << "%" << endl;
}
