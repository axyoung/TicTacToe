/* Tic tac toe game
 * Alex Young
 * C++ Period 5
 * This program runs a 2 player game of Tictactoe
 * 9/21/2017
 */

#include <iostream>
#include <cstring>
using namespace std;

void printBoard();

int main() {
	char board[3][3];
	printBoard();

return 0;
}

//My old java TicTacToe code for printBoard, checkWin functions
void printBoard() {
	cout << " \t1\t2\t3" << endl;
	for (int row = 0; row < 3; row++) {
		char output = static_cast <char> ('a' + row);	
		for (int column = 0; column < 3; column++) {
			// what happens when on a turn goes here X or O...
		}
		cout << output << '\t' << endl;
	}

}
