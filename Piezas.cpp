#include "Piezas.h"
#include <vector>
#include <iostream>

using namespace std;

/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
	board.resize(3);
	for(int i = 0; i < BOARD_ROWS; i++)
	{
		board[i].resize(4);
		for(int j = 0; j < BOARD_COLS; j++)
		{
			board[i][j] = Blank;	
		}
	}
	turn = X;	
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
	for(int i = 0; i < BOARD_ROWS; i++)
	{
		for(int j = 0; j < BOARD_COLS; j++)
		{
			board[i][j] = Blank;
		}
	}
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/ 
Piece Piezas::dropPiece(int column)
{
	Piece blank = Blank;
	Piece oldTurn = turn;
	Piece invalid = Invalid;
	
	if(turn == X)
		turn = O;
	else if(turn == O)
		turn = X;

	if(column > 3 || column < 0)
	{
		return invalid;
	}
	else if(board[2][column] == Blank)
	{
		board[2][column] = oldTurn;	
	}
	else if(board[1][column] == Blank)
	{
		board[1][column] = oldTurn;
	}
	else if(board[0][column] == Blank)
	{
		board[0][column] = oldTurn;
	}
	else
	{
		return blank;
	}

	return oldTurn;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
	if(row == 2)
		row = 0;
	else if(row == 0)
		row = 2;
	if(row <= 2 && row >= 0 && column <= 3 && column >= 0)
	{
		return board[row][column];
	}
	else
	{
		return Invalid;
	}

}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
	Piece check = Invalid;
	int countX = 1, countO = 1;
	int maxX = 0, maxO = 0;

	for(int i = 0; i < BOARD_ROWS; i++)
	{
		for(int j = 0; j < BOARD_COLS; j++)
		{
			if(board[i][j] == Blank)
				return Invalid;
			else if(board[i][j] == check)
			{
				if(check == X)
				{
					countX++;
					if(countX > maxX)
						maxX = countX;
				}
				else if(check == O)
				{					
					countO++;		
					if(countO > maxO)
						maxO = countO;
				}
			}
			check = board[i][j];
		}

		check = Invalid;
		countX = 1;
		countO = 1;
	}

	
	for(int i = 0; i < BOARD_COLS; i++)
	{
		for(int j = 0; j < BOARD_ROWS; j++)
		{
			if(board[j][i] == Blank)
				return Invalid;
			else if(board[j][i] == check)
			{
				if(check == X)
				{
					countX++;
					if(countX > maxX)
						maxX = countX;
				}
				else if(check == O)
				{					
					countO++;		
					if(countO > maxO)
						maxO = countO;
				}
			}
			check = board[j][i];
		}
		check = Invalid;
		countX = 1;
		countO = 1;

	}	


	if(maxX > maxO)	
		return X;
	else if(maxO > maxX)
		return O;
	else
		return Blank;
	
}
