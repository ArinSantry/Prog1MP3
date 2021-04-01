/* File: MP3.cpp
*  Author: Arin Santry
*  Date started: 31 October 2018
*  Date due: 8 November 2018
*  Description: Two-player tic tac toe. One player will always play 'X' and the other will always play 'O.'
*               The gameboard will have the layout of a number keypad.
*/

#include <iostream>
#include <string>
using namespace std;

// symbolic constant for size of array
const int SIZE = 10;

// function prototypes
int getPlayerInput(string playerName);
bool isLegalMove(int location, char board[]);
void placeMarkOnBoard(char playerMark, int location, char board[]);
void clearBoard(char board[]);
bool hasThreeInRow(char playerMark, char board[]);
void displayBoard(char board[]);

int main(void)
{
	// player names
	string p1name;
	string p2name;

	// X and O symbols
	const char CROSS = 'X';
	const char CIRCLE = 'O';

	cout << "Tic Tac Toe" << endl;

	// get player names
	cout << "Enter name 1: ";
	getline(cin, p1name);
	cout << "\nEnter name 2: ";
	getline(cin, p2name);

	// assign characters and initialize location variables
	cout << endl << p1name << ", you will be X. " << p2name << ", you will be O." << endl << endl;
	char p1mark = CROSS;
	char p2mark = CIRCLE;
	int p1location;
	int p2location;

	// win/loss/tie
	int p1win = 0;
	int p2win = 0;
	int tie = 0;

	// number of games to keep track who goes first
	int numGame = 0;

	while (true)
	{
		// initialize board
		char square[SIZE] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		// index value and character are equal for sake of simplicity

		// display board
		displayBoard(square);

		// player 1 goes first on even games
		if (numGame % 2 == 0)
		{
			// get input until there is three in a row
			while (!hasThreeInRow(p1mark, square) && !hasThreeInRow(p2mark, square))
			{
				while (true)
				{
					// get location for player 1
					p1location = getPlayerInput(p1name);

					// check if player 1's move was legal
					if (isLegalMove(p1location, square))
					{
						// if the move was legal, place the marker
						placeMarkOnBoard(p1mark, p1location, square);
						break;
					}
					else
						cout << "Illegal move, try again" << endl;
				}

				// display updated board
				cout << endl;
				displayBoard(square);

				// p1 win?
				if (hasThreeInRow(p1mark, square))
				{
					cout << endl << p1name << ", you won!" << endl;
					p1win++;
					break;
				}

				// check tie
				// when no legal moves are left (every square is x or o), break out of loop
				if (square[1] != '1' && square[2] != '2' && square[3] != '3'
					&& square[4] != '4' && square[5] != '5' && square[6] != '6'
					&& square[7] != '7' && square[8] != '8' && square[9] != '9')
				{
					cout << endl << "It's a tie!" << endl;
					tie++;
					break;
				}

				while (true)
				{
					// get location for player 2
					p2location = getPlayerInput(p2name);

					// check if player 2's move was legal
					if (isLegalMove(p2location, square))
					{
						// if the move was legal, place the marker
						placeMarkOnBoard(p2mark, p2location, square);
						break;
					}
					else
						cout << "Illegal move, try again" << endl;
				}

				// display updated board
				cout << endl;
				displayBoard(square);

				// p2 win?
				if (hasThreeInRow(p2mark, square))
				{
					cout << endl << p2name << ", you won!" << endl;
					p2win++;
					break;
				}

				// check tie
				// when no legal moves are left (every square is x or o), break out of loop
				if (square[1] != '1' && square[2] != '2' && square[3] != '3'
					&& square[4] != '4' && square[5] != '5' && square[6] != '6'
					&& square[7] != '7' && square[8] != '8' && square[9] != '9')
				{
					cout << endl << "It's a tie!" << endl;
					tie++;
					break;
				}
			}
		}
		else // player 2 goes first
		{
			while (!hasThreeInRow(p1mark, square) && !hasThreeInRow(p2mark, square))
			{
				while (true)
				{
					// get location for player 2
					p2location = getPlayerInput(p2name);

					// check if player 2's move was legal
					if (isLegalMove(p2location, square))
					{
						// if the move was legal, place the marker
						placeMarkOnBoard(p2mark, p2location, square);
						break;
					}
					else
						cout << "Illegal move, try again" << endl;
				}

				// display updated board
				cout << endl;
				displayBoard(square);

				// p2 win?
				if (hasThreeInRow(p2mark, square))
				{
					cout << endl << p2name << ", you won!" << endl;
					p2win++;
					break;
				}

				// check tie
				// when no legal moves are left (every square is x or o), break out of loop
				if (square[1] != '1' && square[2] != '2' && square[3] != '3'
					&& square[4] != '4' && square[5] != '5' && square[6] != '6'
					&& square[7] != '7' && square[8] != '8' && square[9] != '9')
				{
					cout << endl << "It's a tie!" << endl;
					tie++;
					break;
				}

				while (true)
				{
					// get location for player 1
					p1location = getPlayerInput(p1name);

					// check if player 1's move was legal
					if (isLegalMove(p1location, square))
					{
						// if the move was legal, place the marker
						placeMarkOnBoard(p1mark, p1location, square);
						break;
					}
					else
						cout << "Illegal move, try again" << endl;
				}

				// display updated board
				cout << endl;
				displayBoard(square);

				// p1 win?
				if (hasThreeInRow(p2mark, square))
				{
					cout << endl << p1name << ", you won!" << endl;
					p1win++;
					break;
				}

				// check tie
				// when no legal moves are left (every square is x or o), break out of loop
				if (square[1] != '1' && square[2] != '2' && square[3] != '3'
					&& square[4] != '4' && square[5] != '5' && square[6] != '6'
					&& square[7] != '7' && square[8] != '8' && square[9] != '9')
				{
					cout << endl << "It's a tie!" << endl;
					tie++;
					break;
				}
			}
		}

		char answer;
		cout << endl << "Play again? (Y/N): ";
		cin >> answer;
		if (answer == 'N')
			break;
		else
			numGame++;

		clearBoard(square);
	}

	cout << p1name << "'s wins: " << p1win << endl;
	cout << p2name << "'s wins: " << p2win << endl;
	cout << "Ties: " << tie << endl;
}

// function definitions

// getPlayerInput - Takes square where player wants to place their mark on the board
// Use name of player to check for correct input. Input will be an integer.
// Returns 1-9 (inclusive)
int getPlayerInput(string playerName)
{
	// variables for the location the player chooses
	int location;

	cout << endl << playerName << ", where will you place your mark? ";
	cin >> location;

	return location;
}

// isLegalMove - Tell if player can play in the square they want to
// inputs location player want to play
// retunrs true if location on board has not been played, false otherwise
bool isLegalMove(int location, char board[])
{
	// is the location within the legal boundaries?
	if (location >= 1 && location <= 9)
	{
		// is the space taken?
		// space will be X or O if taken
		if (board[location] != 'X' && board[location] != 'O')
			return true;
		else
			return false;
	}
	else
		return false;
}

// placeMarkOnBoard - places X or O on board
// assumes legal placement
void placeMarkOnBoard(char playerMark, int location, char board[])
{
	board[location] = playerMark;
}

// clearBoard - Restores board to original (no Xs or Os)
// activated when players decide to end the game
void clearBoard(char board[])
{
	// visual studio was having a fit having the whole function on one line
	// so I'm breaking it up value by value
	// excluding index 0 because that should not change
	board[1] = '1';
	board[2] = '2';
	board[3] = '3';
	board[4] = '4';
	board[5] = '5';
	board[6] = '6';
	board[7] = '7';
	board[8] = '8';
	board[9] = '9';
}

// hasThreeInRow - check if there are 3 of the same markings in a row
// returns true when specified mark has 3 in a row vertically, horizontally, or diagonally
bool hasThreeInRow(char playerMark, char board[])
{
	// check horizontal
	if (board[7] == board[8] && board[8] == board[9])
		return true;
	else if (board[4] == board[5] && board[5] == board[6])
		return true;
	else if (board[1] == board[2] && board[2] == board[3])
		return true;
	// check vertical
	else if (board[7] == board[4] && board[4] == board[1])
		return true;
	else if (board[8] == board[5] && board[5] == board[2])
		return true;
	else if (board[9] == board[6] && board[6] == board[3])
		return true;
	// check diagonals
	else if (board[7] == board[5] && board[5] == board[3])
		return true;
	else if (board[9] == board[5] && board[5] == board[1])
		return true;
	else
		return false;
}

// displayBoard - print the current board
void displayBoard(char board[])
{
	cout << " " << board[7] << " | " << board[8] << " | " << board[9] << " " << endl;
	cout << "---+---+---" << endl;
	cout << " " << board[4] << " | " << board[5] << " | " << board[6] << " " << endl;
	cout << "---+---+---" << endl;
	cout << " " << board[1] << " | " << board[2] << " | " << board[3] << " " << endl;
}