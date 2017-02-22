//
//  main.cpp
//  eightQueens1D
//
//  Created by Jon Horn on 2/21/17.
//  Copyright © 2017 Jon Horn. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int board[8], c = 0, i;
    board[0] = 1;
nextColumn:
    c++;
    if (c == 8) goto print;
    board[c] = -1;
nextRow:
    board[c]++;
    if (board[c] == 8) goto backtrack;
    // row test
    for (i = 0; i < c; i++) {
        int deltaX = c - i;
        int deltaY = board[c] - board[i];
        if (board[i] == board[c] || deltaX == abs(deltaY)) goto nextRow;
    }
        goto nextColumn;
backtrack:
    c--;
    if (c == -1) return 0;
    goto nextRow;
print:
    for(int k = 0; k < 8; k++)
        cout << board[k] << " ";
    cout << endl;
}
