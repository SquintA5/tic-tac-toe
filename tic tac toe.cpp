//Programming Challenge 18
//Tic-Tac-Toe Game
#include <iostream>
#include <vector>
using namespace std;

//Global variables
//Loop counter
int row;
int col;

//User input
int rowNum;
int colNum;

//Constant
const int ARRAY_LENGTH = 3;

//Characters
char player1 = 'X';
char player2 = 'O';


//Array
char gameBoard[][ARRAY_LENGTH] = { {'*', '*', '*'}, {'*', '*', '*'}, {'*', '*', '*'} };

//Function prototype
void gameDisplay();
void playerChoice(char);
bool letterPlace(char[][ARRAY_LENGTH], int, int, char);
bool winCondition(char[][ARRAY_LENGTH]);

int main() {

	//Boolean
	bool running = true;
	bool nextTurn;
	bool gameOver = false;

	//Game loop
	while (running == true) {

		gameDisplay();
		gameOver = winCondition(gameBoard);
		if (gameOver == true) {
			running = false;
			break;
		}

		if (running == true) {
			playerChoice(player1);
			nextTurn = letterPlace(gameBoard, rowNum, colNum, player1);
			while (nextTurn == false) {
				playerChoice(player1);
				nextTurn = letterPlace(gameBoard, rowNum, colNum, player1);
			}
		}

		gameDisplay();
		gameOver = winCondition(gameBoard);
		if (gameOver == true) {
			running = false;
			break;
		}

		if (running == true) {
			playerChoice(player2);
			nextTurn = letterPlace(gameBoard, rowNum, colNum, player2);
			while (nextTurn == false) {
				playerChoice(player2);
				nextTurn = letterPlace(gameBoard, rowNum, colNum, player2);
			}
		}

	}
	return 0;
}

void gameDisplay() {

	for (row = 0; row < ARRAY_LENGTH; row++) {
		for (col = 0; col < ARRAY_LENGTH; col++) {
			cout << gameBoard[row][col];
		}
		cout << endl;
	}
}

void playerChoice(char player) {

	if (player == 'X') {
		cout << "Player 1";
	}
	else if (player == 'O') {
		cout << "Player 2";
	}

	cout << ", choose where to put an " << player << ": \n";
	cout << "Row (1, 2, 3): ";
	cin >> rowNum;
	cout << "Column (1, 2, 3): ";
	cin >> colNum;

}


bool letterPlace(char board[][ARRAY_LENGTH], int rowNum, int colNum, char player) {
	bool result;

	if (gameBoard[rowNum - 1][colNum - 1] == '*') {
		for (row = 0; row < ARRAY_LENGTH; row++) {
			for (col = 0; col < ARRAY_LENGTH; col++) {
				gameBoard[rowNum - 1][colNum - 1] = player;
			}
			cout << endl;
		}
		result = true;
	}
	else if (gameBoard[rowNum - 1][colNum - 1] != '*') {
		cout << "There is already a letter here.\n\n";
		result = false;
	}

	return result;
}

bool winCondition(char[][ARRAY_LENGTH]) {
	bool result = false;
	int p1count;
	int p2count;

	//Check each row for a match
	for (row = 0; row < ARRAY_LENGTH; row++) {
		//Zero the count so the rows are counted separately
		p1count = 0;
		p2count = 0;
		for (col = 0; col < ARRAY_LENGTH; col++) {
			if (gameBoard[row][col] == player1) {
				p1count++;
				if (p1count == ARRAY_LENGTH) {
					row = ARRAY_LENGTH;
				}
			}
			else if (gameBoard[row][col] == player2) {
				p2count++;
				if (p2count == ARRAY_LENGTH) {
					row = ARRAY_LENGTH;
				}
			}
		}

	}
	if (p1count == ARRAY_LENGTH) {
		cout << "Player 1 win\n";
		result = true;
	}
	else if (p2count == ARRAY_LENGTH) {
		cout << "Player 2 win\n";
		result = true;
	}

	//Check each column for a match
	for (col = 0; col < ARRAY_LENGTH; col++) {
		//Zero the count so the columns are counted separately
		p1count = 0;
		p2count = 0;
		for (row = 0; row < ARRAY_LENGTH; row++) {
			if (gameBoard[row][col] == player1) {
				p1count++;
				if (p1count == ARRAY_LENGTH) {
					col = ARRAY_LENGTH;
				}
			}
			else if (gameBoard[row][col] == player2) {
				p2count++;
				if (p2count == ARRAY_LENGTH) {
					col = ARRAY_LENGTH;
				}
			}
		}
	}


	if (p1count == ARRAY_LENGTH) {
		cout << "Player 1 win\n";
		result = true;
	}
	else if (p2count == ARRAY_LENGTH) {
		cout << "Player 2 win\n";
		result = true;
	}

	//Check left-to-right diagonal for a match
	p1count = 0;
	p2count = 0;
	for (row = 0; row < ARRAY_LENGTH; row++) {
		for (col = 0; col < ARRAY_LENGTH; col++) {
			if (gameBoard[p1count][p1count] == player1) {
				p1count++;
			}
			else if (gameBoard[p2count][p2count] == player2) {
				p2count++;
			}
		}

	}

	if (p1count == ARRAY_LENGTH) {
		cout << "Player 1 win\n";
		result = true;
	}
	else if (p2count == ARRAY_LENGTH) {
		cout << "Player 2 win\n";
		result = true;
	}

	//Check right-to-left diagonal for a match
	p1count = 0;
	p2count = 0;
	for (row = 0; row < ARRAY_LENGTH; row++) {
		for (col = (ARRAY_LENGTH - 1); col >= 0; col--) {
			if (gameBoard[p1count][col] == player1) {
				p1count++;
			}
			else if (gameBoard[p2count][col] == player2) {
				p2count++;
			}
		}

	}
	if (p1count == ARRAY_LENGTH) {
		cout << "Player 1 win\n";
		result = true;
	}
	else if (p2count == ARRAY_LENGTH) {
		cout << "Player 2 win\n";
		result = true;
	}
	return result;
}