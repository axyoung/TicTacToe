/* Tic tac toe game
 * Alex Young
 * C++ Period 5
 * This program runs a 2 player game of Tictactoe
 * 9/28/2017
 */

#include <iostream>
#include <cstring>
using namespace std;

const int blank = 0;
const int x_move = 1;
const int o_move = 2;
const int x_turn = 0;
const int o_turn = 1;

void printBoard(const int board[3][3]);
void resetBoard(int board[3][3]);
bool checkWin(int turn, const int board[3][3]);
bool checkTie(const int board[3][3]);
void getMove(const int board[3][3], int turn, int &row, int &col);

// done, just need to comment all the code :)
int main() {
	int xWin = 0;
	int oWin = 0;
	bool playing = true;
	cout << "This is a game of TicTacToe." << endl << "The goal is to get 3 in a row." << endl
	     << "To enter a move, type the number then letter and press enter, for example: c2." <<endl;
	
	while (playing) {
		int turn = o_turn;
		int board[3][3];
		resetBoard(board);
		printBoard(board);
	
		while (!checkWin(x_move, board) && !checkWin(o_move, board) && !checkTie(board)) {
			if (turn == x_turn) {
				turn = o_turn;
			}
			else if (turn == o_turn) {
				turn = x_turn;
			}
			int row = 0;
			int col = 0;
			getMove(board, turn, row, col);
			if (turn == x_turn) {
				board[row][col] = x_move;
			}
			if (turn == o_turn) {
				board[row][col] = o_move;
			}
			printBoard(board);
		}
		
		if (checkWin(x_move, board)) {
			xWin++;
			cout << "X Player won!" << endl;
		}
		
		else if(checkWin(o_move, board)) {
			oWin++;
			cout << "O Player won!" << endl;
		}

		else if (checkTie(board)) {
			cout << "It was a tie" << endl;
		}
		
		cout << "Number of X wins: " << xWin << endl << "Number of O wins: " << oWin << endl;
		
		char again = 'a';
		cout << "Do you want to play again(y/n)?" << endl;
		cin >> again;
		cin.ignore(99, '\n');
		if (again != 'y' && again != 'Y') {
			playing = false;
		}
	}

	return 0;
}

void getMove(const int board[3][3], int turn, int &row, int &col) {
	if (turn == x_turn) {
		cout << "X Player go: ";
	}
	if (turn == o_turn) {
		cout << "O Player go: ";
	}
	
	char r = 0;
	char c = 0;
	cin >> r >> c;
	cin.ignore(99, '\n');
	row = r - 'a';
	col = c - '1';
	
	while (row > 4 || row < 0 || col > 4 || col < 0 || board[row][col] != blank) {
		cout << "Not a valid input." << endl;
		if (turn == x_turn) {
			cout << "X Player go: ";
		}
		if (turn == o_turn) {
			cout << "O Player go: ";
		}
		cin >> r >> c;
		cin.ignore(99, '\n');
		row = r - 'a';
		col = c - '1';
	}
}

//My old java TicTacToe code for printBoard, checkWin functions
void printBoard(const int board[3][3]) {
	cout << endl << " \t1\t2\t3" << endl;
	for (int row = 0; row < 3; row++) {
		cout << static_cast <char> ('a' + row) << '\t';	
		for (int column = 0; column < 3; column++) {
			// what happens when on a turn goes here X or O...
			if (board[row][column] == blank) {
				cout << "\t";
			}
			else if (board[row][column] == x_move) {
				cout << "X\t";
			}
			else if (board[row][column] == o_move) {
				cout << "O\t";
			}
		}
		
		cout << endl;
	}

	cout << endl;
}

// this function will reset the board to its original state
void resetBoard(int board[3][3]) {
// copy printboard and change so  if it is a xomove make it blank in board and printboard
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			board[row][column] = blank; 
		}
	}
}

// checking if there is a win for a player on their turn, running through all 6 win conditions
bool checkWin(int turn, const int board[3][3]) {
	
	if (board[0][0] == turn && board[0][1] == turn && board[0][2] == turn) {
		return true;
	}
	
	if (board[1][0] == turn && board[1][1] == turn && board[1][2] == turn) {
		return true;
	}
	
	if (board[2][0] == turn && board[2][1] == turn && board[2][2] == turn) {
		return true;
	}
	
	if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn) {
		return true;
	}
	
	if (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn) {
		return true;
	}
	
	if (board[0][0] == turn && board[1][0] == turn && board[2][0] == turn) {
		return true;
	}
	
	if (board[0][1] == turn && board[1][1] == turn && board[2][1] == turn) {
		return true;
	}
	
	if (board[0][2] == turn && board[1][2] == turn && board[2][2] == turn) {
		return true;
	}

	return false;
}

// this function checks for a tie in my board
bool checkTie(const int board[3][3]) {
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
		// check if the board has any blank spaces, if it does, it is not a tie
			if (board[row][column] == blank) {
				return false;
			}
		}
	}

	// everything is filled so it is a tie
	return true;
}
