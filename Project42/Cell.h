#pragma once
#include "Board.h"
#include"Piece.h"
#include"Pawn.h"
#include"Header.h"
#include"Rook.h"
#include"Bishop.h"
#include"King.h"
#include"Knight.h"
#include"Queen.h"

class Cell
{
	int r;
	int c;
	Piece* P;

public:
	Cell(int, int, Piece*);
	void draw(int, int,int, int);
	Piece* getpc();
	void setpc(Piece*);
	sf::Sprite square;
};

