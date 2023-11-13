#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

#include <thread>
#include <mutex>

class Game
{
public:
  Game(std::size_t grid_width, std::size_t grid_height);
  Game(const Game &other) = default;            // Copy constructor
  Game &operator=(const Game &other) = default; // Copy assignment operator
  Game(Game &&other) = default;                 // Move constructor
  Game &operator=(Game &&other) = default;      // Move assignment operator
  ~Game() = default;                            // Destructor

  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

  void SaveScore(const std::string &playerName);
  void DisplayTopPlayers();

private:
  Snake snake;
  SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};
  struct Player
  {
    std::string name;
    int score;
  };

  std::vector<Player> playerScores;
  void PlaceFood();
  void Update();
  void LoadScoresFromFile(); // Added function to load scores from file

  // Mutex for synchronizing access to game state
  std::mutex mutex;

  // Function to update the game state in a separate thread
  void UpdateThread(std::size_t target_frame_duration);
  // Flag to signal the game thread to exit
  bool running{true};
};

#endif