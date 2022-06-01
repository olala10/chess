#pragma once

using namespace std;

class Field {
public:
    const int row, col;

    Field(int row, int col) : row(row), col(col) {
        if (row < 0 || col < 0 || row > 7 || col > 7) throw out_of_range("Wiersz lub kolumna spoza zakresu");
    }

    bool operator==(const Field &other) const {
        return row == other.row && col == other.col;
    }
};