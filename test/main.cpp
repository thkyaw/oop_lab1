#include "Util.hpp"
#include "Character.hpp"
#include "Blinky.hpp"
#include "Inky.hpp"
#include "Pinky.hpp"
#include "Clyde.hpp"
#include "Pacman.hpp"

#include <vector>
#include <memory>
#include <iostream>

bool CheckCollision(const Point& p1, const Point& p2) {
    return p1.x == p2.x && p1.y == p2.y;
}

std::vector<Point> GeneratePath(const Point& start, const Point& end) {
    std::vector<Point> path;
    Point current = start;

    while (current.x != end.x || current.y != end.y) {
        if (current.x < end.x) current.x++;
        else if (current.x > end.x) current.x--;

        if (current.y < end.y) current.y++;
        else if (current.y > end.y) current.y--;

        path.push_back(current);
    }

    return path;
}

int main() {
    std::vector<std::unique_ptr<Character>> characters;
    characters.push_back(std::make_unique<Blinky>("Blinky", Point(0, 0)));
    characters.push_back(std::make_unique<Inky>("Inky", Point(15, 15)));
    characters.push_back(std::make_unique<Pinky>("Pinky", Point(0, 15)));
    characters.push_back(std::make_unique<Clyde>("Clyde", Point(7, 7)));

    auto pacman = std::make_unique<Pacman>("Pacman", Point(10, 10));

    for (int round = 1; round <= 5; round++) {
        Draw(characters[0]->GetPosition(),
             characters[1]->GetPosition(),
             characters[2]->GetPosition(),
             characters[3]->GetPosition(),
             pacman->GetPosition());

        std::cout << "Round " << round << "\n";
        std::cout << "Move Pacman (W/A/S/D): ";

        Point pacmanStart = pacman->GetPosition();
        pacman->DoBehavior();
        Point pacmanEnd = pacman->GetPosition();

        std::vector<Point> pacmanPath = GeneratePath(pacmanStart, pacmanEnd);
        for (const auto& position : pacmanPath) {
            for (const auto& character : characters) {
                if (CheckCollision(position, character->GetPosition())) {
                    std::cout << "Game Over!\n";
                    return 0;
                }
            }
        }

        for (auto& character : characters) {
            Point enemyStart = character->GetPosition();
            if (character->GetId() == "Clyde") {
                character->DoBehavior(pacman->GetPosition());
            } else {
                character->DoBehavior();
            }
            Point enemyEnd = character->GetPosition();

            std::vector<Point> enemyPath = GeneratePath(enemyStart, enemyEnd);
            for (const auto& position : enemyPath) {
                if (CheckCollision(position, pacman->GetPosition())) {
                    std::cout << "Game Over!\n";
                    return 0;
                }
            }
        }
    }

    std::cout << "You Win!\n";
    return 0;
}