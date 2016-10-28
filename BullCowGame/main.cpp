#include <iostream>
#include <string>


void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();


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
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows!" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << std::endl << std::endl;

	return;
}

// Call Get Guess 5 times
void PlayGame()
{
	const int TRIES = 5;
	std::string Guess = "";

	for (int i = 0; i < TRIES; i++) {
		Guess = GetGuess();
		std::cout << "You guessed: " + Guess << std::endl;
		
		std::cout << std::endl;
	}

	return;
}

// Get a guess from the user and print it
std::string GetGuess()
{
	std::string Guess = "";

	std::cout << "Enter a guess: ";
	std::getline(std::cin, Guess);

	return Guess;
}

// Ask user if they want to play again
bool AskToPlayAgain()
{
	std::string Answer = "";
	bool bResult = false;

	std::cout << "Do you want to play again (y/n)? ";

	std::getline(std::cin, Answer);

	bResult = (Answer[0] == 'y') || (Answer[0] == 'Y');

	return bResult;
}