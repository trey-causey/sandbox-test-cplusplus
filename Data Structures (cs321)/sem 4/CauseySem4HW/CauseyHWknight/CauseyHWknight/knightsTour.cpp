#include <iostream>
#include <iomanip>

using namespace std;

bool knightsTour(new int [size][size], int row,  int column);

int main()
{
	int r;
	int c;

	cout << "This program is designed to use a recursive algorithm to  determine /n"
		<< "a sequence of moves by a knight to visit every square of a chess board of \n"
		<< "any given size only once for any initial position on the board. " << endl;

	cout << " Enter the number of rows and columns you would like your board to be:  " << endl;
	cin >> size;
	cout << endl;
	int chessBoard[size][size] = {0};


	cout << "You will now choose an initial starting position. \n"
		<< "First, choose a row: ";

	cin >> r;
	r -= 1;
	cout << endl;
	
	cout << "Second, choose a column:  ";
	cin >> c;
	c -= 1;
	cout << endl;

	system("pause");


	if(knightsTour(chessBoard, r, c))
		cout << "Game Succeeded";
	else
		cout << "It didn't work";

	system("pause");

	return 0;

}

bool knightsTour( int Board[size][size], int row, int column)
{
	const int Adjust[8][2] =
	{
		{ -2, -1 },		
		{ -2, +1 },		
		{ -1, +2 },		
		{ +1, +2 },		
		{ +2, +1 },		
		{ +2, -1 },		
		{ +1, -2 },
		{ -1, -2 }	
	};
	static int Counter = 0;
	int i, j;

	// If we've accomplished 64 moves, then we're finished.
	if ( Counter >= (size * size))
	{
		cout << endl << "*** Solved ***" << endl;
		for ( i = 0; i < size; i++ )
		{
			for ( j = 0; j < size; j++ )
			   cout << setw(2) << Board[i][j] << " ";
			cout << endl;
		}
		return true;
	}

	// If we're moving outside of the board, 
 	//or to a square we've visited before, 
	// stop this path and back track.
	if ( row < 0 || row > size - 1 || column < 0 || column > size - 1 
                     || Board[row][column] != 0 )
		return false;

	// Count this move, and enter it into the Board array
	Board[row][column] = ++Counter;

	// Output a progress thermometer
	for ( i = 1; i <= Counter; i++ )
		cout << "*";
	cout << endl;

	// Check all eight possible branches from this move.
	for ( i = 0; i < size; i++ )
		if (knightsTour(Board, row+Adjust[i][0],column+Adjust[i][1]))
		{
			Counter--;
			Board[row][column] = 0;
			return true;
		}

	// This branch is a dead end. Back track again.
	Counter--;
	Board[row][column] = 0;
	return false;
}
