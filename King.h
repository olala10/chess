#pragma once

#include "Piece.h"
#include <iostream>

using namespace std;

// 1. Jak zrobić ovveride?
//2. Czy mogę jakoś zrobić ruch bez sprawdzania czy pole jest puste i wykorzystać tylko warunek bicia?
//3. Jak z roszadą?
//4. Czy na pewno nie muszę sprawdzać wierszy?


class King : public Piece {

public:
    explicit King(const Color color) : Piece(color) {}

    string symbol() override {
        return "K";

        vector <Field> possibleMoves (const Field &from, Piece *board[8][8])
        override{
                vector<Field> moves;
                int direction = color == white ? 1 : -1;
                int startRow = color == white ? 0 : 7;
                int startCol = 4;
                //ruch do przodu
                if (
                (board[from.row + direction][from.col] == nullptr&&from.row>0&&from.row<7)
                //bicie
                ||(board[from.row + direction][from.col] != nullptr&&board[from.row + direction][from.col]->color!=color
                &&from.row>0&&from.row<7)
                )
                {
                    moves.emplace_back(from.row + direction, from.col)
                };
                //ruch w prawo do przodu
                if (
                (board[from.row + direction][from.col+1] == nullptr
                &&from.col<7)
                //bicie
                ||(board[from.row + direction][from.col+1] != nullptr&&board[from.row + direction][from.col]->color!=color
                &&from.col<7)
                )
                {
                    moves.emplace_back(from.row + direction, from.col + 1)
                };
                //ruch w lewo do przodu
                if (
                (board[from.row + direction][from.col-1] == nullptr
                &&from.col>0)
                //bicie
                ||(board[from.row + direction][from.col-1] != nullptr
                &&from.col>0&&board[from.row + direction][from.col-1]->color!=color)
                ){
                    moves.emplace_back(from.row + direction, from.col - 1)
                };
                //ruch w prawo tym samym wierszu
                if (
                (board[from.row][from.col+1] == nullptr
                &&from.col<7)
                //bicie
                ||(board[from.row][from.col+1] != nullptr
                &&from.col<7&&)
                ) {
                    moves.emplace_back(from.row, from.col + 1)
                };
                //ruch w lewo w tym samym wierszu
                if (
                (board[from.row][from.col-1] == nullptr
                &&from.col>0)
                //bicie
                ||(board[from.row][from.col-1] != nullptr
                &&from.col>0&&board[from.row][from.col-1]->color!=color)
                )
                {
                    moves.emplace_back(from.row, from.col - 1)
                };
                //ruch do tyłu
                if (
                (board[from.row-direction][from.col] == nullptr
                &&from.row>0)
                //bicie
                ||(board[from.row-direction][from.col] != nullptr
                &&from.row>0&&board[from.row-direction][from.col]->color!=color)
                )
                {
                    moves.emplace_back(from.row - direction, from.col)
                };
                //ruch w prawo do tyłu
                if (
                (board[from.row-direction][from.col+1] == nullptr
                &&from.row>1)
                //bicie
                || (board[from.row-direction][from.col+1] != nullptr
                &&from.row>1&&board[from.row-direction][from.col+1] ->color!=color)
                )
                {
                    moves.emplace_back(from.row - direction, from.col + 1)
                };
                //ruch w lewo do tyłu
                if (
                (board[from.row-direction][from.col-1] == nullptr
                &&from.row>1)
                //bicie
                (board[from.row-direction][from.col-1] != nullptr
                &&from.row>1&&board[from.row-direction][from.col-1]->color!=color)
                ){
                    moves.emplace_back(from.row - direction, from.col - 1)
                };
                //roszada -> nie mam wieży :(
                int counterL=0, counterR=0;
                if (from.row == startRow&& from.col == startCol)
                {
                    //if (board[from.row][from.col]->color==white)
                    //roszada w lewo
                    for (int i = startCol-1; i >0; --i) {
                        if (board[from.row][i] == nullptr)
                        {
                            counterL=counterL+1;
                        }
                    }
                    if(counterL==3)
                }
        };

    };
};