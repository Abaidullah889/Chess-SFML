#include "Piece.h"
#include"Header.h"
#include"Header.h"


Piece::Piece(int Row, int Col, Color c,Board* _b)
{
	this->row = Row;
	this->col = Col;
	this->C = c;
	this->B = _b;
}
void Piece::Move(int r, int c)
{
	this->row = r;
	this->col = c;
}

Color Piece::getColor()
{
	return C;
}







