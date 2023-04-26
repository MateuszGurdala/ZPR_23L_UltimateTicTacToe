
#ifndef ULTIMATETICTACTOESERVER_PLAYER_HPP
#define ULTIMATETICTACTOESERVER_PLAYER_HPP

#include <string>
#include <array>
#include <vector>
#include "BoardBase.hpp"

class Player {
protected:
    char symbol;
    int points = 0;
public:
    Player(char symbol);
    int GetPoints() const;
    char GetSymbol() const;
    void IncrementPoints();
    virtual std::array<Point, 2> ChooseMove(const std::vector<Point>& availableOuterBoardMoves,
                               const std::vector<Point>& availableInnerBoardMoves ) = 0;
};

#endif //ULTIMATETICTACTOESERVER_PLAYER_HPP
