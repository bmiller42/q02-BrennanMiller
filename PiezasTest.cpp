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

/*TEST(PiezasTest, testIfBlank)
{
	Piezas board;
	
}

TEST(PiezasTest, testIfBlank)
{
	Piezas board;
	
}

TEST(PiezasTest, testIfBlank)
{
	Piezas board;
	
}*/













