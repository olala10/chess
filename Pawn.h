#pragma once

#include "Piece.h"

using namespace std;

class Pawn : public Piece {
public:
    explicit Pawn(const Color color) : Piece(color) {}

    string symbol() override {
        return "p";
    }

    vector<Field> possibleMoves(const Field &from, Piece *board[8][8]) override {
        vector<Field> moves;
        int direction = color == white ? 1 : -1;
        int startRow = color == white ? 1 : 6;
        if (board[from.row + direction][from.col] == nullptr) {
            moves.emplace_back(from.row + direction, from.col);
            if (from.row == startRow && board[from.row + 2 * direction][from.col] == nullptr) {
                moves.emplace_back(from.row + 2 * direction, from.col);
            }
        }
        //bicie w prawo
        if (from.col < 7 && board[from.row + direction][from.col + 1] != nullptr &&
            board[from.row + direction][from.col + 1]->color != color) {
            moves.emplace_back(from.row + direction, from.col + 1);
        }
        //bicie w lewo?
        if (from.col > 1 && board[from.row + direction][from.col - 1] != nullptr &&
            board[from.row + direction][from.col - 1]->color != color) {
            moves.emplace_back(from.row + direction, from.col - 1);
        }
    }
};
