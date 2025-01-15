#include <iostream>
#include <bitset>
//#include <pieceRepresentations.h>
// black pawn   1, white pawn 8
// black knight 2, white knight 9
// black bishop 3, white bishop 10
// black rook   4, white rook 11
// black queen  5, white queen 12
// black king   6, white king 13
 
void setupBoard(uint16_t (&board)[8][8])
{
    for (int numeric = 0; numeric < 8; numeric++) {
        for (int alpha = 0; alpha < 8; alpha++) {
            board[numeric][alpha] = 0;
        }
    }
    int blackFirstRow[8] = {4, 2, 3, 5, 6, 3, 2, 4};
    int whiteFirstRow[8] = {11, 9, 10, 12, 13, 10, 9, 11};
    for (int numeric = 0; numeric < 8; numeric++) {
        board[numeric][0] = blackFirstRow[numeric];
        board[numeric][1] = 1;
        board[numeric][7] = whiteFirstRow[numeric];
        board[numeric][6] = 8;
    }
    return;
}

void renderBoard(uint16_t (&board)[8][8])
{
    char pieces[16] = {' ', 'b', 's', 'l', 't', 'd', 'k', 'x', 'B', 'S', 'L', 'T', 'D', 'K', 'x'};
    for (int numeric = 0; numeric < 8; numeric++) {
        for (int alpha = 0; alpha < 8; alpha++) {
            std::cout << '|' << ' ' << pieces[board[alpha][numeric]] << ' ';
            if (alpha == 7){
                std::cout << '|' << '\n';
            }
        }
        std::cout << "---------------------------------" << '\n';
    }
    return;
}

int main()
{
    std::cout << "Let's play chess." << '\n';
    uint16_t board[8][8];
    setupBoard(board);
    renderBoard(board);
    return 0;
}

