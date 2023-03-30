#pragma once
#include"Piece.h"

class Knight:public Piece
{
private:
	bool isFirstMove;
	char sym = 'n';
public:
	Knight(int ri, int ci, Color C, Board* _b);
	virtual void Draw();
	virtual bool isLegal(Board* b, int sr, int sc, int dr, int dc);
	virtual void setMove();
	virtual char getSym();
	sf::Sprite sprite;
	virtual void setSprite(int r, int c);
	virtual sf::Sprite getSpirit();

	virtual bool getMove();

};


