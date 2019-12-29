/**
 * \file View.h
 * \author Dominik Buszowiecki
 * \brief Priovides I/O methods to view a Grid
 */

#ifndef A4_VIEW_H
#define A4_VIEW_H

#include "GameBoard.h"
#include <string>
/**
 * \brief Provides methods to read, write, and simulate the Game of Life
 */
class View{
private:
    static BoardT gameBoard;
    static std::vector<bool> stringToRow(std::string s);
    static void printStage();
public:
    /**
     * Reads a file representation of a game of life board
     * @param s the name/path of the text file
     */
    static void readStage(const std::string &s);
    /**
     * Creates a unpopulated game of life board
     * @param x the width of the board
     * @param y the height of the board
     */
    static void initStage(unsigned int x, unsigned int y);
    /**
     * Simulates the current board and displays each transition
     * @param n The number of transitions to perform
     */
    static void simulate(unsigned int n);
    /**
     * Writes a file representation of a game of life board to a file
     * @param s the name/path of the text file
     */
    static void writeStage(const std::string &s);
};

#endif //A4_VIEW_H
