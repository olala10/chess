#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-loop-convert"
#pragma once

#include "pieces/Piece.h"
#include "pieces/Pawn.h"
#include "Field.hpp"
#include "Move.hpp"
#include <iostream>
#include <vector>
#include "pieces/King.h"

using namespace std;


class Board {
    Piece *board[8][8];
    Color whoseMove = white;
    vector<Move> history;

    Field findKing() {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] != nullptr
                    && dynamic_cast<King *>(board[i][j]) != nullptr
                    && board[i][j]->color == whoseMove) {
                    return {i, j};
                }
            }
        }
    }

public:
    Board() { // NOLINT(cppcoreguidelines-pro-type-member-init)
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; ++j) {
                board[i][j] = nullptr;
            }
        }
        for (int i = 0; i < 8; i++) {
            board[1][i] = new Pawn(white);
        }
    }

    void print() {
        for (int i = 7; i >= 0; --i) {
            for (Piece *piece: board[i]) {
                cout << (piece == nullptr ? " " : piece->symbol());
            }
            cout << endl;
        }
    }

    bool move(Field from, Field to) {

        Piece *piece = board[from.row][from.col];
        if (piece == nullptr) {
            cerr << "Brak piona na polu" << endl;
            return false;
        }
        if (piece->color != whoseMove) {
            cerr << "Pion niepoprawnego koloru" << endl;
            return false;
        }
        Piece *targetPiece = board[to.row][to.col];
        if (!piece->canMove(from, to, board)) {
            cerr << "Brak możliwości ruchu" << endl;
            return false;
        }
        if (targetPiece != nullptr && targetPiece->color == whoseMove) {
            cerr << "Próba zbicia wlasnego piona" << endl;
            return false;
        }

        history.emplace_back(from, to, targetPiece);
        board[to.row][to.col] = piece;
        board[from.row][from.col] = nullptr;
        whoseMove = whoseMove == white ? black : white;
        return true;
    }

    void undo() {
        Move move = history.back();
        history.pop_back();
        board[move.from.row][move.from.col] = board[move.to.row][move.to.col];
        board[move.to.row][move.to.col] = move.capturedPiece;
        whoseMove = whoseMove == white ? black : white;
    }

    bool isCurrentPlayerChecked() {
        Field kingPos = findKing();
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] != nullptr
                    && board[i][j]->color != whoseMove
                    && board[i][j]->canMove()) {
                    return true;
                }
            }
        }
        return false;
    }
};

#pragma clang diagnostic pop