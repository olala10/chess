#include <iostream>
#include "Board.h"

using namespace std;

int main() {
    Board board;
    while (true) {
        board.print();
        cout << "Ruch: ";
        string move;
        cin >> move;
        Field from(move[1] - '1', move[0] - 'a');
        Field to(move[4] - '1', move[3] - 'a');
        board.move(from, to);
    }

    return 0;
}
