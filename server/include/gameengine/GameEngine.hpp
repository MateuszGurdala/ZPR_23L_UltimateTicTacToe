#ifndef ULTIMATETICTACTOESERVER_GAMEENGINE_H
#define ULTIMATETICTACTOESERVER_GAMEENGINE_H

#include "../entities/MainBoard.hpp"

/*  Class: GameEngine
    Class responsible for checking and handling logic of the game. It inludes MainBoard,
    lists all available moves, checks if game has the winner.
 */
class GameEngine {
private:
    std::unique_ptr<MainBoard> mainBoard;
    std::vector<Point> availableOuterBoardMoves;
    std::vector<std::vector<Point>> allAvailableBoardMoves;
    std::vector<Point> currentLegalMoves;
    std::vector<Point> initializeAvailableSingleBoardMoves();
    std::vector<std::vector<Point>> initializeAvailableInnerBoardMoves();
    static bool areAllValuesTheSame(const std::vector<char>& values);
    void removePointFromOuterAvailableMoves(Point& pointToRemove);

public:
    GameEngine(std::unique_ptr<MainBoard> mainBoard);
    unsigned int GetBoardSize();
    std::vector<Point>& GetAvailableOuterBoardMoves();
    std::vector<std::vector<Point>>& GetAvailableInnerBoardMoves();
    bool CheckForLocalWinner(Point& mainBoardCoordinates, Point& innerBoardCellCoordinates, char figure);
    bool CheckForGlobalWinner(Point& changedWinnerBoardCellCoordinates);
    void HandleMove(Point& boardCoordinates, Point& innerCoordinates, char figure);
    std::string GetWinnerBoardAsJson(bool isNested);
    std::string GetBoardAsJson(bool isNested);

    void RemovePointFromAllAvailableMoves(unsigned int innerBoardIndex, Point &pointOfInnerBoardToRemove);

    void UpdateCurrentLegalMoves(Point &innerBoardCoordinates);
    bool IsSegmentChoosen(Point &innerBoardCoordinates);
};

#endif //ULTIMATETICTACTOESERVER_GAMEENGINE_H
