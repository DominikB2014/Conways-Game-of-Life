#include "../include/View.h"
#include <iostream>
#include <fstream>

BoardT View::gameBoard = BoardT(std::vector<std::vector<bool>>({{false},{false}}));

void View::readStage(const std::string &s) {
    std::string line;
    std::ifstream inFile;
    inFile.open(s);

    if (inFile.is_open()){
        std::vector<std::vector<bool>> G;
        while (getline(inFile,line) )
        {
            G.push_back(stringToRow(line));
        }
        inFile.close();
        gameBoard = BoardT(G);
    } else throw std::invalid_argument("File not Found");
}

void View::initStage(unsigned int x, unsigned int y) {
    if (x <= 0 || y <= 0) throw std::invalid_argument("Length/Width must be greater than 0");
    std::vector<std::vector<bool>> G;
    std::vector<bool> temp;
    for (unsigned int i = 0; i < x; i++) {
        temp.clear();
        for (unsigned int j = 0; j < y; j++) {
            temp.push_back(false);
        }
        G.push_back(temp);
    }
    gameBoard = BoardT(G);
}

void View::simulate(unsigned int n) {
    std::cout << "Start State\n";
    printStage();
    for (unsigned int i = 0; i < n; ++i) {
        gameBoard = gameBoard.nextStage();
        printStage();
    }
}

void View::writeStage(const std::string &s) {
    std::ofstream file;
    file.open(s);
    std::string row;
    for (const auto &i : gameBoard.toGrid()){
        row = "";
        for(const auto &cell : i){
            if (cell != 0) row += "0";
            else row += "_";
        }
        file << row + "\n";
    }
}

// Private Methods

std::vector<bool> View::stringToRow(std::string s) {
    std::vector<bool> row;
    for(char &c : s) {
        row.push_back(c == '0');
    }
    return row;
}

void View::printStage() {
    for (const auto &i : gameBoard.toGrid()){
        for(const auto &cell : i){
            if (cell != 0) std::cout << "[#]";
            else std::cout << "[ ]";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}


