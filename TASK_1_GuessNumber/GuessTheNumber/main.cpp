#include <iostream>
#include <stdlib.h>
#include <cstdlib>

#define MIN 0
#define MAX 1000

int generateRandomNumber(void)
{
    if (MIN > MAX)
    {
        std::cout << "Invalid range. Minimum value should be less than or equal to maximum value.\n";
        return -1;
    }
   return (rand()% (MAX-MIN+1)-MIN); // Generate a random number in the range [min, max]
}
int main()
{
    int guess;
    int attempts=0, flag=1;
    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I have generated a random number between " << MIN << " and " << MAX << ".\n";
    std::cout << "Try to guess it!\n\n";
    int randomNumber = generateRandomNumber();
    while(flag && (randomNumber!= -1))      //-1 means that the range is invalid and the user should terminate the program to edit the range
    {
        std::cout<< "Enter ur Guess: ";
        std::cin>> guess;
        attempts++;
        if(guess > randomNumber)
        {
            std::cout << "Too high. Try again.\n";
        }
        else if(guess < randomNumber)
        {
            std::cout << "Too low. Try again.\n";
        }
        else
        {
            std::cout << "Congrats! You guessed the correct number " << randomNumber << " in " << attempts << " attempts.\n";
            flag=0; // to exit from while loop " i USE flag to be readable more than break keyword
        }
    }
    return 0;
}
