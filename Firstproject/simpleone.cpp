#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For time()

class Character
{
public:
  std::string name;
  int health;
  int attackPower;

  Character(std::string n, int h, int a) : name(n), health(h), attackPower(a) {}

  void attack(Character &target)
  {
    int damage = (rand() % attackPower) + 1; // Random damage
    target.health -= damage;
    std::cout << name << " attacks " << target.name << " for " << damage << " damage!\n";
  }

  void critical_attack(Character &target)
  {
    int damage = (rand() % attackPower) + 6; // Random damage
    target.health -= damage;
    std::cout << name << " attacks " << target.name << " for " << damage << " damage!\n";
  }
};

int main()
{
  srand(time(0)); // Seed random number generator

  Character player("Hero", 30, 10);
  Character enemy("Goblin", 20, 8);

  while (player.health > 0 && enemy.health > 0)
  {
    std::cout << "\nYour Health: " << player.health << " | Enemy Health: " << enemy.health << "\n";
    std::cout << "1. Attack\n2.SuperKick \n3.Heal (+5 HP)  \nChoose: ";

    int choice;
    std::cin >> choice;

    if (choice == 1)
    {
      player.attack(enemy);
    }
    else if (choice == 2)
    {
      int cri = rand() % 100;
      if (cri < 30)
      {
        player.critical_attack(enemy);
      }
      else
      {
        std::cout << "your critical attack won't work this time try again\n";
      }
    }
    else
    {
      player.health += 5;
      std::cout << "You healed! Health: " << player.health << "\n";
    }

    if (enemy.health > 0)
    {
      enemy.attack(player);
    }
  }

  if (player.health > 0)
    std::cout << "\n You won the battle!\n";
  else
    std::cout << "\n You lost! Game over.\n";

  return 0;
}
