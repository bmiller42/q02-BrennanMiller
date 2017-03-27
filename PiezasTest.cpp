/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, testDefaultPiece)
{
	Piezas board;
	Piece piece = board.dropPiece(1);
	ASSERT_TRUE(piece == X);
}

TEST(PiezasTest, testNewBlankBoard)
{
	Piezas board;
	ASSERT_TRUE(board.pieceAt(0,0) == Blank);
}

TEST(PiezasTest, testDropPiece)
{
	Piezas board;
	board.dropPiece(1);
	ASSERT_TRUE(board.dropPiece(1) == O);
}

TEST(PiezasTest, testInvalidDropPiece)
{
	Piezas board;
	ASSERT_TRUE(board.dropPiece(4) == Invalid);
}

TEST(PiezasTest, testIfFullColumn)
{
	Piezas board;
	board.dropPiece(1);	
	board.dropPiece(1);		
	board.dropPiece(1);	
	ASSERT_TRUE(board.dropPiece(1) == Blank);
}

TEST(PiezasTest, testBoardReset)
{
	Piezas board;
	board.dropPiece(0);
	Piece piece = board.dropPiece(1);	
	board.reset();
	ASSERT_TRUE(piece == O && board.pieceAt(0,0) == Blank);
}

TEST(PiezasTest, testOutOfBoundsPiece)
{
	Piezas board;
	Piece test1 = board.pieceAt(-1, 0);
	Piece test2 = board.pieceAt(0, 4);
	ASSERT_TRUE(test1 == Invalid && test2 == Invalid);	
}

TEST(PiezasTest, testOwinner)
{
	Piezas board;
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(1);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2);
	ASSERT_TRUE(board.gameState() == O);
	
}	

TEST(PiezasTest, testXwinner)
{
	Piezas board;
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(2);
	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(0);
	board.dropPiece(3);
	board.dropPiece(2);
	board.dropPiece(0);
	board.dropPiece(1);
	ASSERT_TRUE(board.gameState() == X);
	
}	


TEST(PiezasTest, testTie)
{
	Piezas board;
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(2);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	ASSERT_TRUE(board.gameState() == Blank);	
}	

TEST(PiezasTest, testUnfinishedGame)
{
	Piezas board;
	board.dropPiece(3);
	board.dropPiece(3);
	ASSERT_TRUE(board.gameState() == Invalid);	
}	

TEST(PiezasTest, testGetPiece)
{
	Piezas board;
	board.dropPiece(0);
	ASSERT_TRUE(board.pieceAt(0,0) == X);
}

TEST(PiezasTest, testGetPieceRow)
{
	Piezas board;
	board.dropPiece(0);
	board.dropPiece(0);
	board.dropPiece(0);
	ASSERT_TRUE(board.pieceAt(2,0) == X);
}









