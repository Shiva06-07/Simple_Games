#include <iostream>
#include <cstdlib>
#include <ctime>
int main()
{
  srand(time(0));
  int secretNumber = (rand() % 100) + 1;
  int playerguess = 0, aiguess = 0;
  int low = 0, high = 100;
  int playeratt, aiatt;
  std::cout << "This is the game btw You and AI" << std::endl;
  std::cout << "In this game you need guess no. from 1 to 100 " << std::endl;
  while (true)
  {
    std::cout << "Enter your number:";
    std::cin >> playerguess;
    playeratt++;
    if (playeratt == secretNumber)
    {
      std::cout << "Yup you are correct!!: " << playeratt << " was the number" << std::endl;
      break;
    }
    else if (playeratt > secretNumber)
    {
      std::cout << "The number you guessed was greater than the secert number:" << std::endl;
    }
    else
    {
      std::cout << "The number you guessed was lesser than the secert number:" << std::endl;
    }
    aiguess = (rand() % 100);
    aiatt++;
    if (aiguess == secretNumber)
    {
      
      std::cout << "Oops!! AI guessed the number correctly.!!!!" << std::endl;
      break;
    }
    else if (aiguess > secretNumber)
    {
      std::cout << "The number AI guessed was greater than the secert number:" << std::endl;
    }
    else
    {
      std::cout << "The number AI guessed was lesser than the secert number:" << std::endl;
    }
    std::cout << "Game over!!!!" << std::endl;
    return 0;
  }
}