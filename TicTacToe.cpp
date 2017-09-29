/* Tic tac toe game
 * Alex Young
 * C++ Period 5
 * This program runs a 2 player game of Tictactoe
 * 9/28/2017
 */

#include <iostream>
#include <cstring>
using namespace std;

// my dad showed me what a const is
// these const that I am using are for when the board is empty or if a space has a move in it or for turn
const int blank = 0;
const int x_move = 1;
const int o_move = 2;
const int x_turn = 0;
const int o_turn = 1;

// these are the function I use :)
void printBoard(const int board[3][3]);
void resetBoard(int board[3][3]);
bool checkWin(int turn, const int board[3][3]);
bool checkTie(const int board[3][3]);
void getMove(const int board[3][3], int turn, int &row, int &col);

int main() {
	// count the wins of each player with xWin and oWin
	int xWin = 0;
	int oWin = 0;
	// I am still playing
	bool playing = true;
	// Print instructions
	cout << "This is a game of TicTacToe." << endl << "The goal is to get 3 in a row." << endl
	     << "To enter a move, type the number then letter and press enter, for example: c2." <<endl;
	
	// when I stop playing I exit the loop and am done
	// this loop controls multiple games
	while (playing) {
		// I start on o_turn because the first thing I do when I start a game is switch to the opposite turn
		// this way the first player who goes is actually x_turn
		int turn = o_turn;
		int board[3][3];
		// before playing I reset and print out the board
		resetBoard(board);
		printBoard(board);
	
		// this loop cotnrols what is happening for a single game
		// it runs until their is a win or a tie
		while (!checkWin(x_move, board) && !checkWin(o_move, board) && !checkTie(board)) {
			// start by switching turns
			if (turn == x_turn) {
				turn = o_turn;
			}
			else if (turn == o_turn) {
				turn = x_turn;
			}
			// my row and col are the ones actually being updated in my board[][]
			int row = 0;
			int col = 0;
			// I am going to getMove, which will take in the input from the player
			// and output the row and col they give as ints
			getMove(board, turn, row, col);
			// depending on whos turn it is I update the board
			if (turn == x_turn) {
				board[row][col] = x_move;
			}
			if (turn == o_turn) {
				board[row][col] = o_move;
			}
			// then I print the updated board for the player to see
			printBoard(board);
		}
		
		// I escaped the loop meaning that somehow the game ended
		// I will check who won and tell them so, keeping track of score
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
		
		// if they want to play again they can type y or Y
		// I will ignore everything except the first char they type
		char again = 'a';
		cout << "Do you want to play again(y/n)?" << endl;
		cin >> again;
		cin.ignore(99, '\n');
		// if they don't type y or Y they exit the playing loop and are done
		if (again != 'y' && again != 'Y') {
			playing = false;
		}
	}

	return 0;
}

// I got the idea to use getMove as a function from my father Jason Young
// He helped me use row and columns by reference so they update at their original address
// this function just takes in the input from the user and does validity checks
void getMove(const int board[3][3], int turn, int &row, int &col) {
	// first tell them to play
	if (turn == x_turn) {
		cout << "X Player go: ";
	}
	if (turn == o_turn) {
		cout << "O Player go: ";
	}
	
	char r = 0;
	char c = 0;
	cin >> r >> c;
	// cin.ignore makes it ignore the next 99 characters up until a new line so that i don't read in extra inputs
	cin.ignore(99, '\n');
	// give an int value to my column and row values
	row = r - 'a';
	col = c - '1';
	
	// this while loop will check if the row and column are valid values and if not it tels them
	// also it will check if the board is blank at a chosen spot so they don't rewrite a previous move
	// by checking the board last it reduces memory wastage if the user types in a ridiculous value
	while (row > 4 || row < 0 || col > 4 || col < 0 || board[row][col] != blank) {
		// tell them they are not valid and to try again
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
		// raveen showed me static_cast
		// on each row I print out a b c and a tab for room
		cout << static_cast <char> ('a' + row) << '\t';	
		for (int column = 0; column < 3; column++) {
			// on each column I update the board with X and O according to the move I got in getMove
			// otherwise everything is blank because I reset the board before I print
			// and when I reset the board everything is blank
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
	// add space for visibility
	cout << endl;
}

// this function will reset the board to a blank state
void resetBoard(int board[3][3]) {
// for all values in the board, make them blank
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			board[row][column] = blank; 
		}
	}
}

// checking if there is a win for a player on their turn, running through all 6 win conditions
bool checkWin(int turn, const int board[3][3]) {
	
	// if we win return true
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
	
	// if you haven't won return false
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

	// everything is filled so it is a tie (in the main function it checks for a tie last)
	return true;
}
