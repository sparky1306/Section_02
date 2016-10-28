/*  Console executable that uses the BullCow class
This is responsible for user interaction
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

// Main Application
int main()
{
	do {
		PrintIntro();
		PlayGame();
	}
	while (AskToPlayAgain());

	std::cout << std::endl;
	return 0;
}


// Introduce the game
void PrintIntro()
{
	constexpr int32 WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows!" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << std::endl << std::endl;

	return;
}

// Call Get Guess 5 times
void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();
	FText Guess = "";

	//TODO change to While loop when validation implemented
	for (int32 i = 0; i < MaxTries; i++) {
		Guess = GetGuess(); // TODO Make loop checking valid

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

		// Print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ", Cows = " << BullCowCount.Cows;

		std::cout << std::endl;
	}

	// TODO Summarize game

	return;
}

// Get a guess from the user and print it
FText GetGuess()
{
	FText Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try " << CurrentTry << ". Enter a guess: ";
	std::getline(std::cin, Guess);

	return Guess;
}

// Ask user if they want to play again
bool AskToPlayAgain()
{
	FText Answer = "";
	bool bResult = false;

	std::cout << "Do you want to play again (y/n)? ";

	std::getline(std::cin, Answer);

	bResult = (Answer[0] == 'y') || (Answer[0] == 'Y');

	return bResult;
}