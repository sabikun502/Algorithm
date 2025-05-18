#include <iostream>
using namespace std;
char board[9] = {'1','2','3','4','5','6','7','8','9'};
int player = 1;
void drawBoard() {
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n\n";
}
bool isWinner() {

    int wins[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };

    for (auto &w : wins) {
        if (board[w[0]] == board[w[1]] && board[w[1]] == board[w[2]])
            return true;
    }
    return false;
}

void game() {
    int move;
    char mark;
    for (int turn = 0; turn < 9; turn++) {
        drawBoard();
        mark = (player == 1) ? 'X' : 'O';

        cout << "Player " << player << " (" << mark << "), enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O') {
            cout << "Invalid move! Try again.\n";
            turn--;
            continue;
        }

        board[move - 1] = mark;

        if (isWinner()) {
            drawBoard();
            cout << "Player " << player << " wins!\n";
            return;
        }

        player = (player == 1) ? 2 : 1;
    }

    drawBoard();
    cout << "It's a draw!\n";
}

int main() {
    game();
    return 0;
}
