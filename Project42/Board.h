#pragma once

#include <fstream>
#include"Header.h"
using namespace std;

class Piece;
class Cell;

class Board
{
public:
	Cell*** C;
	Board();
	Board(Board* B);
	Board(ifstream&);
	void setBoard(char** B);
	void writer(ofstream&, char***& mb, int& bn);
	void displayBoard(sf::RenderWindow* );
	void Move(int sr, int sc, int dr, int dc);
	Piece* getPiece(int r,int c);
	Cell* getCell(int r, int c);
	bool isLegalMove(Board*, int, int, int, int);
	void updateBoard(int sr, int sc, int dr, int dc);
	
};

