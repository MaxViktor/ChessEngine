#include <iostream>
#include <bitset>
#include <string>
//#include <pieceRepresentations.h>
// black pawn   1, white pawn 8
// black knight 2, white knight 9
// black bishop 3, white bishop 10
// black rook   4, white rook 11
// black queen  5, white queen 12
// black king   6, white king 13

const int asciioffset = 97;
const char alphabet[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
 
void setupBoard(char (&board)[8][8])
{
    for (int numeric = 0; numeric < 8; numeric++) {
        for (int alpha = 0; alpha < 8; alpha++) {
            board[numeric][alpha] = ' ';
        }
    }
    const char blackFirstRow[8] = {'t', 's', 'l', 'd', 'k', 'l', 's', 't'};
    const char whiteFirstRow[8] = {'T', 'S', 'L', 'D', 'K', 'L', 'S', 'T'};
    for (int numeric = 0; numeric < 8; numeric++) {
        board[numeric][0] = blackFirstRow[numeric];
        board[numeric][1] = 'b';
        board[numeric][7] = whiteFirstRow[numeric];
        board[numeric][6] = 'B';
    }
    return;
}

void renderBoard(char (&board)[8][8])
{

    for (int numeric = 0; numeric < 8; numeric++) {
        for (int alpha = 0; alpha < 8; alpha++) {
            std::cout << '|' << ' ' << board[alpha][numeric] << ' ';
            if (alpha == 7){
                std::cout << '|' << '\n';
            }
        }
        std::cout << "---------------------------------" << '\n';
    }
    return;
}

bool movePiece(char (&board)[8][8], uint16_t alpha, uint16_t numeric, char piece, char inLetter, char inNumber)
{
    board[inLetter][inNumber] = piece;
    board[alpha][numeric] = ' ';
    return true;
}

bool turn(char (&board)[8][8])
{
    char piece = 'x'; // kommer behöva skilja på om det är svart eller inte för att hitta rätt pjäs
    char inLetter = 'x';
    char inNumber = 'x';
    std::cout << "Gotta make your move. Please type it here:" << '\n';
    std::cin >> piece >> inLetter >> inNumber;
    int xpos = 0;
    for (int i = 0; i < 8; i++) {
        if (inLetter == alphabet[i])
        {break;}
        xpos++;
    }
    bool moveMade = false;
    for (int numeric = 0; numeric < 8; numeric++) {
        for (int alpha = 0; alpha < 8; alpha++) {
            if (board[alpha][numeric] == piece) {
                moveMade = movePiece(board, alpha, numeric, piece, 7 - xpos, inNumber - '0');
            }
            if (moveMade) {return false;}
        }
    }
    return false;
}

int main()
{
    std::cout << "Let's play chess." << '\n';
    char board[8][8];
    setupBoard(board);
    renderBoard(board);
    bool gameOver = false;
    while (!gameOver) 
    {
        gameOver = turn(board);
        std::cout << "Rendering board" << '\n';
        renderBoard(board);
    }
    return 0;
}

