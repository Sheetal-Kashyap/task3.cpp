  #include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number between 1 and 100
    int targetNumber = std::rand() % 100 + 1;
    int guess = 0;
    int numberOfAttempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I'm thinking of a number between 1 and 100." << std::endl;

    // Game loop
    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        // Increment the number of attempts
        numberOfAttempts++;

        if (guess < targetNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > targetNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the number in " << numberOfAttempts << " attempts!" << std::endl;
        }
    } while (guess != targetNumber);

    return 0;
}
