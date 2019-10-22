/*
Austin Meadowcroft
10/15/2019
Keywords02
*/

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <windows.h>
#include <ctime>
#include <algorithm>

using namespace std;

// Display directions to the recruit on how to use Keywords

int wordInitializer()
{
	// gives a seed to random number generator
	srand(time(NULL));
	int wordPicks = rand() % 10;
	return wordPicks;
}

int letterCheck(string targetWord, string guess)
{
	int wordLength = targetWord.size();
	int numLetters = 0;

	// Checks number of letters in correct place
	for (int i = 0; i < wordLength; i++)
	{
		if (guess[i] == targetWord[i])
		{
			numLetters++;
		}
	}
	return numLetters;
}

bool wordDisplay()
{
	bool isFinish = false;
	bool isNumTooSmall = false;
	int wrongCounter = 0;
	int numLetters;
	// Creating and populating an array with previously declared values
	int word01 = wordInitializer();
	int word02 = wordInitializer();
	int word03 = wordInitializer();
	int words[] = { word01, word02, word03 };
	int wordPicks[3];
	for (int i = 0; i < 3; i++)
	{
		wordPicks[i] = words[i];
	}

	// Create a collection of 10 words you had written down manually
	string foo[] = { "BOOKER", "DRIVER", "GIBSON", "WHEATLEY", "SUNDOWN", "CAMBRIDGE", "STUDIO", "SODUS", "RAPIDS", "COMANCHE" };
	
	// Initializes variables
	bool isGuessing = true;
	bool isUnlocked = true;
	int wordLength;
	int wordCounter = 0;
	int attemptCounter = 1;
	string jumble;
	string guess;

	while (wordCounter != 3 && isUnlocked)
	{
		// Resets variable
		attemptCounter = 1;
		isGuessing = true;
		while (attemptCounter != 3 && isGuessing) 
		{
			// Clears screen
			system("CLS");
			// Jumbles word
			jumble = foo[wordPicks[wordCounter]];
			wordLength = jumble.size();
			for (int i = 0; i < wordLength; i++)
			{
				int index01 = (rand() % wordLength);
				int index02 = (rand() % wordLength);
				char temp = jumble[index01];

				jumble[index01] = jumble[index02];
				jumble[index02] = temp;
			}
			// Tell recruit how many incorrect guesses he or she has left
			cout << "YOU HAVE " << 4 - attemptCounter << " ATTEMPTS REMAINING" << endl;
			cout << "KEYWORD #" << wordCounter + 1 << ": " << jumble << endl << endl;
			cout << "ENTER KEYWORD: ";
			cin >> guess;
			cout << endl << endl;
			transform(guess.begin(), guess.end(), guess.begin(), toupper);
			// If the guess is in the secret word
			if (guess == foo[wordPicks[wordCounter]])
			{
				// Tell the recruit the guess is correct
				cout << "CORRECT" << endl;
				system("PAUSE");
				isGuessing = false;
			}
			else
			{
				cout << "INCORRECT" << endl;
				// Checks if guess is too short
				if (guess.size() < foo[wordPicks[wordCounter]].size())
				{
					cout << "NOT ENOUGH LETTERS IN GUESS" << endl;
					isNumTooSmall = true;
				}
				if (!isNumTooSmall)
				{
					numLetters = letterCheck(foo[wordPicks[wordCounter]], guess);
					// Tell the recruit the guess is incorrect
					cout << numLetters << " LETTERS IN CORRECT POSITION" << endl;
				}
				wrongCounter++;
				system("PAUSE");
			}
			// Increment the number of incorrect guesses the recruit has made
			attemptCounter++;
		}
		// Tell the recruit that he or she has failed the Keywords II course.
		if (wrongCounter == 3)
		{
			cout << "*** INVALID KEYWORD ***" << endl;
			cout << "*** TERMINAL LOCKED ***" << endl;
			system("PAUSE");
			isUnlocked = false;
		}
		wordCounter++;
	}
	if (isUnlocked)
	{
		isFinish = true;
	}
	if (isFinish)
	{
		//     Congratulate the recruit on guessing the secret words 
		cout << "GOOD SOLDIER SOLDIER" << endl;
	}
	return isUnlocked;
}

void initialDisplay()
{
	string username;
	// Display Title of the program to the user
	cout << "*** PROTOCAL KEYWORDS 02 ***" << endl;
	// Ask the recruit to log in using their name
	cout << "PLEASE ENTER YOUR USERNAME: " << endl;
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	cin >> username;
	system("CLS");
	// simulates work
	for (int i = 0; i < 2; i++)
	{
		cout << "LOADING";
		this_thread::sleep_for(chrono::milliseconds(333));
		system("CLS");
		cout << "LOADING.";
		this_thread::sleep_for(chrono::milliseconds(333));
		system("CLS");
		cout << "LOADING..";
		this_thread::sleep_for(chrono::milliseconds(333));
		system("CLS");
		cout << "LOADING...";
		this_thread::sleep_for(chrono::milliseconds(333));
		system("CLS");
	}
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	cout << "Welcome: " << username << endl << endl;
	// Display an overview of what Keywords II is to the recruit 
	cout << "KEYWORDS 02 IS A TRAINING PROGRAM" << endl;
	cout << "DEVELOPED TO IMPROVE CODEBREAKING" << endl;
	cout << "ABILITIES OF NEW RECRUITS" << endl << endl;
	system("PAUSE");
}

int main()
{
	bool isSimulation = true;
	bool isntLocked = false;
	string intent;
	// changes text size
	_CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 24;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	// changes console color
	system("COLOR 02");

	// Create an int var to count the number of simulations being run starting at 1
	int simulationCount = 1;

	// Calls seperate functions
	initialDisplay();
	while (isSimulation)
	{
		// Display the simulation # is starting to the recruit. 
		cout << "SIMULATION # " << simulationCount << endl << endl;
		isntLocked = wordDisplay();
		if (isntLocked)
		{
			// Ask the recruit if they would like to run the simulation again
			cout << "ENTER 'YES' TO RUN ANOTHER SIMULATION" << endl;
			cout << "ENTER 'NO' TO EXIT TRAINING PROGRAM" << endl;
			cin >> intent;
			transform(intent.begin(), intent.end(), intent.begin(), toupper);
			// Display End of Simulations to the recruit
			if (intent == "NO")
			{
				isSimulation = false;
			}
			else
			{
				//     Increment the number of simulations ran counter
				simulationCount++;
			}
		}
	}
	// resetting console color
	system("COLOR");
	return 0;
}

//     Show player how much of the secret word he or she has guessed



