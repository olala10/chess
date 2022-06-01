#pragma once

#include "Field.hpp"
#include "pieces/Piece.h"

class Move {
public:
    const Field from, to;
    Piece *capturedPiece;

    Move(const Field &from, const Field &to, Piece *capturedPiece) : from(from), to(to),
                                                                     capturedPiece(capturedPiece) {}
};