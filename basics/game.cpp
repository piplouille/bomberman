#include "game.hpp"

Game::Game(Player** table_players, Map* table_map) : players (table_players), map (table_map) {
    start = std::chrono::system_clock::now();
}
