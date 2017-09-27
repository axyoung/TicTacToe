/* Tic tac toe game
 * Alex Young
 * C++ Period 5
 * This program runs a 2 player game of Tictactoe
 * 9/27/2017
 */

#include <iostream>
#include <cstring>
using namespace std;

void printBoard();
void resetBoard();
int checkWin(int player);
int checkTie();
//lots of problems, need to get the whole pointer thing figured out
int main() {
	int blank = 0;
	int x_move = 1;
	int o_move = 2;
	int x_turn = 0;
	int o_turn = 1;
	int turn = x_turn;
	int playing = 0;
	cout << "This is a game of TicTacToe." << endl << "The goal is to get 3 in a row" << endl
		<< "Player X goes firstm then Player O" << endl;
	int board[3][3];
	// int (*p)[3] = board; // get this pointer stuff figured out
	printBoard();
	while (playing == 0) {
		while (checkWin(x_move) == 0 && checkWin(o_move) == 0 && checkTie() == 0) {
		
		}
	}

	return 0;
}

//My old java TicTacToe code for printBoard, checkWin functions
void printBoard() {
	cout << " \t1\t2\t3" << endl;
	for (int row = 0; row < 3; row++) {
		char output[4] = static_cast <char> ('a' + row) + '\t';	
		for (int column = 0; column < 3; column++) {
			// what happens when on a turn goes here X or O...
			if (board[row][column] == blank) {
				output += "\t";
			}
			else if (board[row][column] == x_move) {
				output += "X\t";
			}
			else if (board[row][column] == o_move) {
				output += "O\t";
			}

		}
		cout << output << endl;
	}

}

void resetBoard() {
// copy printboard and change so  if it is a xomove make it blank in board and printboard
}
int checkWin(int player) { // line below need fix board...
	if (board[0][0] == player && board[0][1] == player && board[0][2] == player) {
		return 1;
	}
	if (board[1][0] == player && board[1][1] == player && board[1][2] == player) {
		return 1;
	}
	if (board[2][0] == player && board[2][1] == player && board[2][2] == player) {
		return 1;
	}
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
		return 1;
	}
	if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
		return 1;
	}
	if (board[0][0] == player && board[1][0] == player && board[2][0] == player) {
		return 1;
	}
	if (board[0][1] == player && board[1][1] == player && board[2][1] == player) {
		return 1;
	}
	if (board[0][2] == player && board[1][2] == player && board[2][2] == player) {
		return 1;
	}
	cout << player << endl;
}
int checkTie() {
	for (int row = 0; row < 3; row++) {
		for(int column = 0; column < 3; column++) {
		// need to fix line below so board and blank can be read in...
			if(board[row][column] == 0) {
				return 1;
			}
		}
	}
	return 0;
}
