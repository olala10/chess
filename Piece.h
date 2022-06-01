#pragma once

#include <vector>
#include <algorithm>
#include "../Color.h"
#include "../Field.hpp"

using namespace std;

class Piece {
public:
    virtual std::string symbol() = 0;

    const Color color;

    explicit Piece(const Color color) : color(color) {}

    virtual ~Piece() = default;

    bool canMove(const Field &from, const Field &to, Piece *board[8][8]) {
        const vector<Field> moves = possibleMoves(from, board);
        return find(moves.begin(), moves.end(), to) != moves.end();
    }

    virtual vector<Field> possibleMoves(const Field &from, Piece *board[8][8]) = 0;
};




