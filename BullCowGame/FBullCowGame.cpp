#pragma once

#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset();}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameWon; }

int32 FBullCowGame::GetMaxTries() const { 
	TMap<int32, int32> WordLengthToMaxTries{ {2,3}, {3,4}, {4,7}, {5,10}, {6,16} };

	return WordLengthToMaxTries[GetHiddenWordLength()]; 
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet";

	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameWon = false;

	return;
}

EGuessStatus FBullCowGame::CheckGuessValid(FString Guess) const
{
	// if guess isn't isogram
	if (!IsIsogram(Guess)) { return EGuessStatus::Not_Isogram; }
	else if (!IsLowercase(Guess)) { return EGuessStatus::Not_Lowercase; }
	else if (Guess.length() != GetHiddenWordLength()) { return EGuessStatus::Wrong_Length; }
	else { return EGuessStatus::OK; }
}

// provide a method for counting bulls and cows, and incrementing try #
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = GetHiddenWordLength();

	// loop through all letters in Hidden Word
	for (int32 i = 0; i < WordLength; i++) {
		// compare letters against hidden word
		for (int32 j = 0; j < WordLength; j++)
		{
			// if match
			if (Guess[i] == MyHiddenWord[j]) {
				// increment bulls if in same place
				if (i == j) { BullCowCount.Bulls++; }
				// increment cows if not
				else { BullCowCount.Cows++; }
			}
			
		}
	}
	
	if (BullCowCount.Bulls == GetHiddenWordLength()) { bGameWon = true; }

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
	if (Guess.length() <= 1) { return true; }

	// map Guess using loop
	TMap<char, bool> LetterSeen;

	for (auto Letter : Guess) {
		Letter = tolower(Letter);

		if (LetterSeen[Letter]) { return false; }
		else { LetterSeen[Letter] = true; }
	}

	return true;
}

bool FBullCowGame::IsLowercase(FString Guess) const
{
	if (Guess.length() == 0) { return true; }

	for (auto Letter : Guess) {
		if (!islower(Letter)) {
			return false;
		}
	}
	return true;
}
