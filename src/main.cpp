#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main()
{
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  // Get user name
  std::string playerName;
  std::cout << "Enter your name: ";
  std::getline(std::cin, playerName);

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;

  {
    Game game(kGridWidth, kGridHeight);
    game.Run(controller, renderer, kMsPerFrame);

    // Save score
    game.SaveScore(playerName);

    // Display top 10 players
    game.DisplayTopPlayers();

    std::cout << "Game has terminated successfully!\n";
    std::cout << "Score: " << game.GetScore() << "\n";
    std::cout << "Size: " << game.GetSize() << "\n";
  }

  return 0;
}