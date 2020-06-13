#include <iostream>
#include <string>

int main() {
	constexpr int WORD_LENGTH = 6;

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";

	// Get a guess from the player
	std::string Guess = "";
	std::cin >> Guess;

	// Repeat the guess back to them

	return 0;
}