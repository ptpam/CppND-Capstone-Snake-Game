#include "game.h"
#include <iostream>
#include "SDL.h"
#include <fstream>
#include <iomanip>
#include <algorithm>

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1))
{
  // Load previous player scores from file (if any)
  LoadScoresFromFile();
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration)
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running)
  {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);

    // Check if the user pressed 'q' or if the snake is not alive
    if (!running || !snake.alive)
    {
      break;
    }

    Update();
    renderer.Render(snake, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000)
    {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration)
    {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood()
{
  int x, y;
  while (true)
  {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y))
    {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update()
{
  if (!snake.alive)
    return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y)
  {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }

void Game::SaveScore(const std::string &playerName)
{
  Player player;
  player.name = playerName;
  player.score = score;
  playerScores.push_back(player);

  // Sort the player scores in descending order
  std::sort(playerScores.begin(), playerScores.end(),
            [](const Player &a, const Player &b)
            { return a.score > b.score; });

  // Save the scores to a file
  std::ofstream file("scores.txt");
  if (file.is_open())
  {
    for (const auto &p : playerScores)
    {
      file << p.name << " " << p.score << "\n";
    }
    file.close();
  }
}

void Game::DisplayTopPlayers()
{
  // Display the top 10 players
  std::cout << "\nTop 10 Players:\n";
  for (int i = 0; i < std::min(10, static_cast<int>(playerScores.size())); ++i)
  {
    std::cout << std::setw(2) << i + 1 << ". " << std::setw(15) << playerScores[i].name
              << "   Score: " << playerScores[i].score << "\n";
  }
}

void Game::LoadScoresFromFile()
{
  // Load previous player scores from file
  std::ifstream file("scores.txt");
  if (file.is_open())
  {
    Player player;
    while (file >> player.name >> player.score)
    {
      playerScores.push_back(player);
    }
    file.close();
  }
}
