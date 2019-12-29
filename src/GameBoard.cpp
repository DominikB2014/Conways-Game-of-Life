#include <utility>

#include "../include/GameBoard.h"
#include <stdexcept>
#include <iostream>

// PUBLIC METHODS

BoardT::BoardT(Grid S) {
    if (S.empty()) throw std::invalid_argument("Invalid Grid");
    for (auto &i : S)
        if (S[0].size() != i.size()) throw std::invalid_argument("Invalid Grid");
    this->S = std::move(S);
}

BoardT BoardT::nextStage() {
    Grid G;
    // Creates a new Grid G with the updated version of each cell in S
    std::vector<bool> temp;
    for (unsigned int i = 0; i < S.size(); i++) {
        temp.clear();
        for(unsigned int j = 0; j< S[i].size(); j++){
            temp.push_back(UpdateCell(S,i,j));
        }
        G.push_back(temp);
    }
    return BoardT(G);
}

Grid BoardT::toGrid() {
    return S;
}

// PRIVATE METHODS

bool BoardT::UpdateCell(Grid G, unsigned int x, unsigned int y) {
    unsigned int adjacent = NumAdj(G,x,y);
    //If a cell is populated(true), update its value
    if (G[x][y] == true){
        if(adjacent < 2) return false;
        return adjacent < 4;
    }
    //An unpopulated cell becomes populated when there are 3 adjacent cells
    return (adjacent == 3);
}

unsigned int BoardT::NumAdj(Grid G, unsigned int x, unsigned int y) {
    unsigned int adj = 0;
    // Iterates through all the adjacent cells
    for (unsigned int i = (x == 0 ? 0 : x - 1); i <= x + 1; i++) {
        for (unsigned int j = (y == 0 ? 0 : y - 1); j <= y + 1; j++){
            if (i != x || j != y){
                //If an adjacent cell is populated(marked true), increment adj
                if(IsInBounds(G,i,j) && G[i][j] == true)
                    adj++;
            }
        }
    }
    return adj;
}

bool BoardT::IsInBounds(Grid G, unsigned int x, unsigned int y) {
    return x < G.size() && y < G[0].size();
}
