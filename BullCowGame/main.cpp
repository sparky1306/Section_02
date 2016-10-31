/*  Console executable that uses the BullCow class
This is responsible for user interaction
*/

#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

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
	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n\n";

	return;
}

// Call Get Guess 5 times
void PlayGame()
{
	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();
	FText Guess = "";

	// loop asking for guesses while game is NOT won and still tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		Guess = GetValidGuess(); 

		// Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ", Cows = " << BullCowCount.Cows;

		std::cout << std::endl << std::endl;
	}

	PrintGameSummary();

	return;
}

// Get a guess from the user and print it
FText GetValidGuess() 
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";

	do {
		int32 CurrentTry = BCGame.GetCurrentTry();

		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries() << ". Enter a guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValid(Guess);
		switch (Status)
		{
		case EGuessStatus::OK:
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters (aka an isogram).\n\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter your guess in all lowercase letters.\n\n";
			break;
		default:
			break;
		}

	} while (Status != EGuessStatus::OK);

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

	std::cout << std::endl;

	return bResult;
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon()) {
		std::cout << "CONGRATULATIONS!  You guessed it!!!\n\n";
	}
	else {
		std::cout << "Sorry, you've run out of tries.\n\n";
	}

	return;
}
