/**
 * \file GameBoard.h
 * \author Dominik Buszowiecki
 * \brief Represents the grid/board of game of life
 */

#ifndef A4_GAMEBOARD_H
#define A4_GAMEBOARD_H

#include <vector>
/**
 * \brief Local type Grid is a vector of (vector of booleans)
 */
typedef std::vector<std::vector<bool>> Grid;

/**
 * \brief Module stores the current state of the game
 */
class BoardT{
private:
    Grid S;

    bool UpdateCell (Grid G , unsigned int x, unsigned int y);
    unsigned int NumAdj(Grid G, unsigned int x, unsigned int y);
    bool IsInBounds(Grid G, unsigned int x, unsigned int y);
public:
    /**
     * Constructor for a Game of Life Board
    * @param S A game of life grid
    */
    explicit BoardT(Grid S);
    /**
    * Transitions the board to the next stage
     * @return The current board after a transition
     */
    BoardT nextStage();
    /**
    * Returns the grid representation of the board
    * @return A Grid of the board
    */
    Grid toGrid();
};

#endif //A4_GAMEBOARD_H
