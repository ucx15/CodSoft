#include <iostream>
#include <random>


constexpr int LOWER_LIM = 0;
constexpr int UPPER_LIM = 100;
constexpr int CHANCES   = 10;


int main() {
	// Initialise random number generator
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(LOWER_LIM, UPPER_LIM);
	
	// Generate a PRN
	int random_integer = uni(rng);
	int guess_num;

	std::cout << "You've " << CHANCES << " Chances!\nGuess a number between 1 - 100\n";

	// Guessing Loop
	bool is_guessed = false;
	for (int i=0; i<CHANCES; ++i) {
		std::cin >> guess_num;
		
		if (guess_num > random_integer) {
			std::cout << "Guess a smaller number\n";
		}
		
		else if (guess_num < random_integer) {
			std::cout << "Guess a Larger number\n";
		}

		else {
			is_guessed = true;
			break;
		}
	}

	if (is_guessed) {
		std::cout << "\nCongrats! You've guessed the right number\n";
	}
	else {
		std::cout << "\nSorry! you've exhausted guessing limit\n Random Number is " << random_integer << '\n';
	}

	return 0;
}