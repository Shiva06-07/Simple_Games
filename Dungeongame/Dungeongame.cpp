#include <iostream>
#include <vector>
class Dungeon
{
public:
  int x, y;

  std::vector<std::vector<char>> grid{
      {'p', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', 'X', '.'},
      {'.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', 'E'}};
  Dungeon()
      : x(0), y(0)
  {
  }
  void move()
  {
    char move1;

    std::cout << "Enter the direction in which you want to move" << std::endl;
    std::cout << "W,A,S,D" << std::endl;
    std::cin >> move1;
    grid[x][y] = '.';

    if (move1 == 'W' && x > 0)
    {
      x--;
      grid[x][y] = '!';
    }
    else if (move1 == 'S' && x < 5)
    {
      x++;
      grid[x][y] = '!';
    }
    else if (move1 == 'A' && y > 0)
    {
      y--;
      grid[x][y] = '!';
    }
    else if (move1 == 'D' && y < 5)
    {
      y++;
      grid[x][y] = '!';
    }

    grid[x][y] = 'P';
  }
  void displayGrid()
  {
    for (const auto &row : grid)
    {
      for (char cell : row)
      {
        std::cout << cell << " ";
      }
      std::cout << "\n";
    }
  }
};
int main()
{
  Dungeon dungeon; // Create a Dungeon object

  while (true)
  {
    dungeon.displayGrid();

    dungeon.move(); // Move the player

    // Check if the player has reached the exit
    if (dungeon.grid[dungeon.x][dungeon.y] == 'E')
    {
      std::cout << "You reached the exit! You win!\n";
      break;
    }
  }

  return 0;
}
