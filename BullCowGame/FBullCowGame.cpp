#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset();}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
bool FBullCowGame::IsGameWon() const { return false; }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;

	return;
}

bool FBullCowGame::CheckGuessValid(FString)
{
	// TODO implement a guess validation method
	return false;
}

// provide a method for counting bulls and cows, and incrementing try #
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment turn number
	MyCurrentTry++;

	// setup return variable
	FBullCowCount BullCowCount;

	// loop through all letters in guess
	int32 HiddenWordLength = MyHiddenWord.length();
	int32 GuessLength = Guess.length();

	for (int32 i = 0; i < HiddenWordLength; i++) {
		// compare letters against hidden word
		for (int32 j = 0; j < HiddenWordLength; j++)
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

	return BullCowCount;
}
