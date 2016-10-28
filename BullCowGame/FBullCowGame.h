#pragma once
#include <string>

class FBullCowGame {
public:
	void Reset(); // TODO richer return.
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValid(std::string); // TODO richer return.

private:
	int MyCurrentTry;
	int MyMaxTries;
};