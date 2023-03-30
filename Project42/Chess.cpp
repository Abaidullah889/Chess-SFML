#include "Chess.h"
#include"Player.h"
#include"Piece.h"
#include"King.h"
#include"Board.h"
#include"Header.h"
#include"Cell.h"
#include<string>
#include<fstream>
#include<iostream>
using namespace std;


Chess::Chess()
{

	bool bar_Display = false;
	bool bar1_Display = false;

	int x = 0;
	int y = 0;
	char ans='0';
	sf::Text tx;
	sf::Text text1;


	tx.setFont(Piece_Texture::font2);
	tx.setString("New Game");
	tx.setPosition(200,250);


	text1.setFont(Piece_Texture::font2);
	text1.setString("Load Game");
	text1.setPosition(200,300);

	sf::RenderWindow w2(sf::VideoMode().getDesktopMode(), "Chess", sf::Style::Default);
	sf::Event e;

	//////////////////////////////////////////////////////

	sf::RectangleShape bar;
	sf::RectangleShape bar1;
	bar.setFillColor(sf::Color(128,128,128));
	bar.setSize(sf::Vector2f(135.f, 40.f));

	bar1.setFillColor(sf::Color(128, 128, 128));
	bar1.setSize(sf::Vector2f(143.f, 40.f));

	sf::Sprite bg;
	bg.setTexture(Piece_Texture::BackGround);
	bg.scale(sf::Vector2f(0.75f, 0.57f));
	///////////////////////////////////////////////////////
	while (w2.isOpen())
	{
		while (w2.pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::Closed:
				w2.close();
				//break;
			case sf::Event::KeyPressed:
				if (e.key.code == sf::Keyboard::Escape)
					w2.close();
				//break;
			case sf::Event::MouseButtonPressed:
				if (e.mouseButton.button == sf::Mouse::Left)
				{
					if (e.mouseButton.x > 200 && e.mouseButton.x <= 315 && e.mouseButton.y >= 250 && e.mouseButton.y <= 277)
					{
						ans = 'n';
						
						w2.close();
					}
					if (e.mouseButton.x >= 200 && e.mouseButton.x <= 315 && e.mouseButton.y >= 300 && e.mouseButton.y <= 327)
					{
						ans = 'l';
						
						w2.close();
					}
				}
			}
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		bar_Display = false;
		bar1_Display = false;
		x=sf::Mouse::getPosition().x;
		y = sf::Mouse::getPosition().y;

		if (x > 207 && x <= 323 && y >= 290 && y <= 310)
		{
			//cout << "POhnch gya bhai";
			bar_Display = true;

			bar.setPosition(190, 250);
		}
		else if (x > 207 && x <= 323 && y >= 330 && y <= 357)
		{
			//cout << "POhnch gya bhai";
			bar1_Display = true;
			bar1.setPosition(190, 300);
		}


		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		w2.clear();
		
		
		w2.draw(bg);
		if (bar_Display == true)
		{
			w2.draw(bar);
		}
		if (bar1_Display == true)
		{
			w2.draw(bar1);
		}

		w2.draw(tx);
		w2.draw(text1);
		w2.display();
	}


	if (ans == 'n')
	{
		Ps[0] = new Player("Black", black);
		Ps[1] = new Player("White", white);
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		mb = new char** [1000];
		for (int i = 0; i < 1000; i++)
		{
			mb[i] = new char* [8];
			for (int j = 0; j < 8; j++)
			{
				mb[i][j] = new char[8];
			}
		}

		this->bn = 0;
		this->t_b = 0;
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		ifstream rdr("Input.txt");
		B = new Board(rdr);
		Turn = 1;
		cb = new bool[1000];

		this->videoMode = sf::VideoMode();
		videoMode.getDesktopMode();
		this->window=new sf::RenderWindow(sf::VideoMode().getDesktopMode(), "Chess");
		/*Ws = 300;
		Bs = 300;
		wdelay = 0;
		bdelay = 0;*/

		rdr >> Ws;
		rdr >> Bs;
		rdr >> wdelay;
		rdr >> bdelay;

	}
	if (ans == 'l')
	{

		Ps[0] = new Player("Black", black);
		Ps[1] = new Player("White", white);
		ifstream rdr("Save.txt");
		B = new Board(rdr);
		rdr >> Turn;

		mb = new char** [1000];
		for (int i = 0; i < 1000; i++)
		{
			mb[i] = new char* [8];
			for (int j = 0; j < 8; j++)
			{
				mb[i][j] = new char[8];
			}
		}
		cb = new bool[1000];

		this->bn = 0;
		this->t_b = 0;
		rdr >> Ws;
		rdr >> Bs;
		rdr >> wdelay;
		rdr >> bdelay;
		this->window = new sf::RenderWindow(sf::VideoMode().getDesktopMode(), "Chess");
	}
	else if(ans=='0')
	{
		exit;
	}


	
}
void Chess::displayTurnMsg(Player* P)
{
	gotoRowCol(65, 0);
	cout << P->getName() << "'s Turn \n ";
}
void Chess::selectPiece(int &r,int &c,sf::RenderWindow*W)
{
	/*int row, col;
	cin >> row >> col;

	r = row;
	c = col;*/

	int ri = 0, ci = 0;
	getRowColbyLeftClick(ri, ci,W);

	c = ci / 71;
	r = ri / 71;


}
void Chess::selectDestination()
{
	cin >> dr >> dc;
}
bool Chess::validSourceSelection(Player* P, int r, int c,Board*B)
{
	if (r < 0 || r >= 8 || c<0 || c>=8)
	{
		return false;
	}

	Piece* pi = B->getPiece(r, c);

	return pi != nullptr && pi->getColor() == P->getColor();

}
bool Chess::validDestination(Player* P, int dr, int dc,Board *B)
{
	if (dr < 0 || dr >= 8 || dc < 0 || dc >= 8)
	{
		return false;
	}

	Piece* pi = B->getPiece(dr, dc);

	if (pi == nullptr)
	{
		return true;
	} 
	return !(pi->getColor() == P->getColor());
}
void Chess::turnChange()
{
	this->Turn = (this->Turn + 1) % 2;


}
void Chess::hBOX(int sr, int sc, int rdim, int cdim, char sym = -37)
{
	for (int r = 0; r < rdim; r++)
	{
		for (int c = 0; c < cdim; c++)
		{
			if (r == 0 || c == 0 || r == rdim - 1 || c == cdim - 1)
			{
				gotoRowCol(sr+r,sc+c);
				SetClr(3, 0);
				cout << sym;
			}
		}
	}
}
void Chess::unhBOX(int sr, int sc, int rdim, int cdim,int cols)
{
	char sym = -37;
	for (int r = 0; r < rdim; r++)
	{
		for (int c = 0; c < cdim; c++)
		{
			if (r == 0 || c == 0 || r == rdim - 1 || c == cdim - 1)
			{
				gotoRowCol(sr + r, sc + c);
				SetClr(cols, 0);
				cout << sym;
			}
		}
	}
}
bool** Chess::CompHigh(Board* B, int sri, int sci, Player** p, int turn)
{
	int dr=0, dc=0;
	bool** b = new bool* [8] {};
	for (int r = 0; r < 8; r++)
	{
		b[r] = new bool[8];
	}

	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			dc = c;
			dr = r;
			if ((validDestination(p[turn], dr, dc,B) && B->isLegalMove(B, sr, sc, dr, dc) && !selfCheck(B,sc,sr,dc,dr,Ps,Turn)))
			{
				//if (!SelfCheck1(B, dim, Turn, Dc, Sc))
					b[r][c] = true;
			}

		}
	}

	return b;
}
void Chess::Highlight(Board* B, int sri, int sci, bool**b, int turn)
{
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (b[r][c] == true)
			{
				hBOX(r * 8, c * 8, 8, 8);
			}
		}
	}

}
void Chess::unHighlight(Board* B, int sri, int sci, bool** b, int turn)
{
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (b[r][c] == true)
			{
				if ((r + c) % 2 == 0)
				{
					unhBOX(r * 8, c * 8, 8, 8,15);
				}
				else
				{
					unhBOX(r * 8, c * 8, 8, 8,8);
				}
				
			}
		}
	}
}
void Chess::findKing(Board* B, Player* p, int& Kr, int& Kc)
{

	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			King* kptr = dynamic_cast <King*>(B->getPiece(r,c));

			if (B->getPiece(r,c) != nullptr)
			{
				if (B->getPiece(r, c) == kptr && kptr->getColor() == p->getColor())
				{
					Kr = r;
					Kc = c;
				}
			}
		}
	}
}
bool Chess::Check(Board* b, Player** p, int turn)
{
	int Kr = 0, Kc = 0;

	findKing(b, p[!turn], Kr, Kc);

	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (validSourceSelection(p[turn], r, c, b) && b->isLegalMove(b, r, c, Kr, Kc))
			{
				return true;
			}
		}
	}
	return false;

}
bool Chess::selfCheck(Board* B, int sci, int sri, int dci, int dri, Player** p, int turn)
{
	Board b(B);
	Board* tB = &b;

	tB->Move(sri, sci, dri, dci);
	return (Check(tB, p, !turn));
}
bool Chess::selfCheck1(Board* B, int sci, int sri, int dci, int dri, Player** p, int turn)
{

	return (Check(B, p, !turn));
}
bool Chess::CanIMove(Board* B, Player** p, int turn)
{
	Board b(B);
	Board* tB = &b;
	for (int sr = 0; sr < 8; sr++)
	{
		for (int sc = 0; sc < 8; sc++)
		{
			for (int dr = 0; dr < 8; dr++)
			{
				for (int dc = 0; dc < 8; dc++)
				{
					if (validSourceSelection(p[turn], sr, sc, tB) && validDestination(p[turn], dr, dc, tB) && tB->isLegalMove(tB, sr, sc, dr, dc) && !selfCheck(B, sc, sr, dc, dr, p, turn))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
bool Chess::StaleMate(Board*B,int Turn,Player** P)
{
	if (Check(B, Ps, !Turn))
	{
		return false;
	}
	for (int sr = 0; sr < 8; sr++)
	{
		for (int sc = 0; sc < 8; sc++)
		{
			for (int dr = 0; dr < 8; dr++)
			{
				for (int dc = 0; dc < 8; dc++)
				{
					if (validSourceSelection(P[Turn], sr, sc, B) && validDestination(P[Turn], dr, dc, B) && B->isLegalMove(B, sr, sc, dr, dc) && !selfCheck(B, sc, sr, dc, dr, P, Turn))
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}
void Chess::Promotion(Board* B,int sr,int sc,int dr,int dc,Player** P,int Turn)
{
	int n=0;
	Piece* p;
	if (B->getPiece(sr, sc)->getSym()=='p' && dr==0 && B->getPiece(sr,sc)->getColor() == white)
	{

		sf::RenderWindow Window(sf::VideoMode(134,134), "Promotion",sf::Style::Default);
		sf::Event ev;


		sf::Sprite Piece1;
		sf::Sprite Square1;
		sf::Sprite Piece2;
		sf::Sprite Square2;

		sf::Sprite Piece3;
		sf::Sprite Square3;
		sf::Sprite Piece4;
		sf::Sprite Square4;
		Piece1.setTexture(Piece_Texture::whiteQueen);
		Piece1.setScale(sf::Vector2f(0.245f, 0.245f));
		Piece1.setPosition(sf::Vector2f(0,0));

		Square1.setTexture(Piece_Texture::Square1);
		Square1.setScale(sf::Vector2f(0.245f, 0.245f));
		Square1.setPosition(sf::Vector2f(0, 0));

		Piece2.setTexture(Piece_Texture::whiteRook);
		Piece2.setScale(sf::Vector2f(0.245f, 0.245f));
		Piece2.setPosition(sf::Vector2f(76, 0));

		Square2.setTexture(Piece_Texture::Square2);
		Square2.setScale(sf::Vector2f(0.245f, 0.245f));
		Square2.setPosition(sf::Vector2f(71, 0));

		Piece3.setTexture(Piece_Texture::whiteKnight);
		Piece3.setScale(sf::Vector2f(0.245f, 0.245f));
		Piece3.setPosition(sf::Vector2f(3,71));

		Square3.setTexture(Piece_Texture::Square2);
		Square3.setScale(sf::Vector2f(0.245f, 0.245f));
		Square3.setPosition(sf::Vector2f(0,71));

		Piece4.setTexture(Piece_Texture::whiteBishop);
		Piece4.setScale(sf::Vector2f(0.245f, 0.245f));
		Piece4.setPosition(sf::Vector2f(71, 71));

		Square4.setTexture(Piece_Texture::Square1);
		Square4.setScale(sf::Vector2f(0.245f, 0.245f));
		Square4.setPosition(sf::Vector2f(71, 71));


		///////////////////////////////////////////////////////////////////////////////////////



		while (Window.isOpen())
		{
			sf::Event ev;
			while (Window.pollEvent(ev))
			{
				switch (ev.type)
				{
				case sf::Event::MouseButtonPressed:
					if (ev.mouseButton.button == sf::Mouse::Left)
					{
						if ((ev.mouseButton.x >= 0) && (ev.mouseButton.x <= 62) && (ev.mouseButton.y >= 0) && (ev.mouseButton.y <= 62))
						{
							p = new Queen(sr, sc, white, B);
							B->getCell(sr, sc)->setpc(p);
							Window.close();
						}
						else if ((ev.mouseButton.x >= 72) && (ev.mouseButton.x <= 134) && (ev.mouseButton.y >= 0) && (ev.mouseButton.y <= 62))
						{
							p = new Rook(sr, sc, white, B);
							B->getCell(sr, sc)->setpc(p);
							Window.close();
						}

						else if ((ev.mouseButton.x >= 0) && (ev.mouseButton.x <= 62) && (ev.mouseButton.y >= 71) && (ev.mouseButton.y <= 134))
						{
							p = new Knight(sr, sc, white, B);
							B->getCell(sr, sc)->setpc(p);
							Window.close();
						}
						else if ((ev.mouseButton.x >= 72) && (ev.mouseButton.x <= 134) && (ev.mouseButton.y >= 71) && (ev.mouseButton.y <= 134))
						{
							p = new Bishop(sr, sc, white, B);
							B->getCell(sr, sc)->setpc(p);
							Window.close();
						}
					}
				}
			}

			Window.clear();
			Window.draw(Square1);
			Window.draw(Piece1);
			Window.draw(Square2);
			Window.draw(Piece2);
			Window.draw(Square3);
			Window.draw(Piece3);
			Window.draw(Square4);
			Window.draw(Piece4);
			// window.draw(shape);
			Window.display();


		}








		/*gotoRowCol(10, 100);
		cout << "1. for Queen" << endl;
		gotoRowCol(11, 100);
		cout << "2. for Rook" << endl;
		gotoRowCol(12, 100);
		cout << "3. for Knight" << endl;
		gotoRowCol(13, 100);
		cout << "4. for Bishop" << endl;
		gotoRowCol(14, 100);
		cout << "Enter your Option: ";
		cin >> n;

		switch (n)
		{
		case 1:
			p = new Queen(sr,sc,white,B);
			B->getCell(sr, sc)->setpc(p);
			break;
		case 2:
			p = new Rook(sr, sc, white, B);
			B->getCell(sr, sc)->setpc(p);
			break;
		case 3:
			p = new Knight(sr, sc, white, B);
			B->getCell(sr, sc)->setpc(p);
			break;
		case 4:
			p = new Bishop(sr, sc, white, B);
			B->getCell(sr, sc)->setpc(p);
			break;
		}*/


	}
	else if (B->getPiece(sr, sc)->getSym() == 'p' && dr == 7 && B->getPiece(sr, sc)->getColor() == black)
	{



		sf::RenderWindow Window(sf::VideoMode(134, 134), "Promotion", sf::Style::Default);
		sf::Event ev;


		sf::Sprite Piece1;
		sf::Sprite Square1;
		sf::Sprite Piece2;
		sf::Sprite Square2;

		sf::Sprite Piece3;
		sf::Sprite Square3;
		sf::Sprite Piece4;
		sf::Sprite Square4;
		Piece1.setTexture(Piece_Texture::blackQueen);
		Piece1.setScale(sf::Vector2f(0.245f, 0.245f));
		Piece1.setPosition(sf::Vector2f(0, 0));

		Square1.setTexture(Piece_Texture::Square1);
		Square1.setScale(sf::Vector2f(0.245f, 0.245f));
		Square1.setPosition(sf::Vector2f(0, 0));

		Piece2.setTexture(Piece_Texture::blackRook);
		Piece2.setScale(sf::Vector2f(0.245f, 0.245f));
		Piece2.setPosition(sf::Vector2f(76, 0));

		Square2.setTexture(Piece_Texture::Square2);
		Square2.setScale(sf::Vector2f(0.245f, 0.245f));
		Square2.setPosition(sf::Vector2f(71, 0));

		Piece3.setTexture(Piece_Texture::blackKnight);
		Piece3.setScale(sf::Vector2f(0.245f, 0.245f));
		Piece3.setPosition(sf::Vector2f(3, 71));

		Square3.setTexture(Piece_Texture::Square2);
		Square3.setScale(sf::Vector2f(0.245f, 0.245f));
		Square3.setPosition(sf::Vector2f(0, 71));

		Piece4.setTexture(Piece_Texture::blackBishop);
		Piece4.setScale(sf::Vector2f(0.245f, 0.245f));
		Piece4.setPosition(sf::Vector2f(71, 71));

		Square4.setTexture(Piece_Texture::Square1);
		Square4.setScale(sf::Vector2f(0.245f, 0.245f));
		Square4.setPosition(sf::Vector2f(71, 71));



		while (Window.isOpen())
		{
			sf::Event ev;
			while (Window.pollEvent(ev))
			{
				switch (ev.type)
				{
				case sf::Event::MouseButtonPressed:
					if (ev.mouseButton.button == sf::Mouse::Left)
					{
						if ((ev.mouseButton.x >= 0) && (ev.mouseButton.x <= 62) && (ev.mouseButton.y >= 0) && (ev.mouseButton.y <= 62))
						{
							p = new Queen(sr, sc, black, B);
							B->getCell(sr, sc)->setpc(p);
							Window.close();
						}
						else if ((ev.mouseButton.x >= 72) && (ev.mouseButton.x <= 134) && (ev.mouseButton.y >= 0) && (ev.mouseButton.y <= 62))
						{
							p = new Rook(sr, sc, black, B);
							B->getCell(sr, sc)->setpc(p);
							Window.close();
						}

						else if ((ev.mouseButton.x >= 0) && (ev.mouseButton.x <= 62) && (ev.mouseButton.y >= 71) && (ev.mouseButton.y <= 134))
						{
							p = new Knight(sr, sc, black, B);
							B->getCell(sr, sc)->setpc(p);
							Window.close();
						}
						else if ((ev.mouseButton.x >= 72) && (ev.mouseButton.x <= 134) && (ev.mouseButton.y >= 71) && (ev.mouseButton.y <= 134))
						{
							p = new Bishop(sr, sc, black, B);
							B->getCell(sr, sc)->setpc(p);
							Window.close();
						}
					}
				}
			}

			Window.clear();
			Window.draw(Square1);
			Window.draw(Piece1);
			Window.draw(Square2);
			Window.draw(Piece2);
			Window.draw(Square3);
			Window.draw(Piece3);
			Window.draw(Square4);
			Window.draw(Piece4);
			// window.draw(shape);
			Window.display();


		}








		/*gotoRowCol(10, 100);
		cout << "1. for Queen" << endl;
		gotoRowCol(11, 100);
		cout << "2. for Rook" << endl;
		gotoRowCol(12, 100);
		cout << "3. for Knight" << endl;
		gotoRowCol(13, 100);
		cout << "4. for Bishop" << endl;
		gotoRowCol(14, 100);
		cout << "Enter your Option: ";
		cin >> n;

		switch (n)
		{
		case 1:
			p = new Queen(sr, sc, black, B);
			B->getCell(sr, sc)->setpc(p);
			break;
		case 2:
			p = new Rook(sr, sc, black, B);
			B->getCell(sr, sc)->setpc(p);
			break;
		case 3:
			p = new Knight(sr, sc, black, B);
			B->getCell(sr, sc)->setpc(p);
			break;
		case 4:
			p = new Bishop(sr, sc, black, B);
			B->getCell(sr, sc)->setpc(p);
			break;
		}*/
	}

}
void Chess::Save(Board* B)
{
	ofstream wtr("Save.txt");
	B->writer(wtr,mb,bn);
	t_b++;
	wtr << Turn<<endl;
	wtr << Ws << endl;
	wtr << Bs << endl;
	wtr << wdelay << endl;
	wtr << bdelay << endl;
}
bool Chess::Castling(Board* B, int sr, int sc, int dr, int dc,int& tr,int& tc)
{
	int r_r = 0, r_c = 0;
	int C = abs(dc - sc);

	r_r = sr;
	if (dc > sc)
		r_c = sc + 1;
	if (dc < sc)
		r_c = sc - 1;

		if (B->C[sr][sc]->getpc()->getColor()==white)
		{
			if (B->C[sr][sc]->getpc()->getSym() == 'k' && sr == 7)
			{
				while ((r_c >= 0) && (r_c < 8))
				{
					if ((B->C[r_r][r_c]->getpc()!=nullptr))
					{
						break;
					}
					
					else if (dc < sc)
					{
						r_c--;
					}

					else if (dc > sc)
					{
						r_c++;
					}	
				}

				if (B->C[r_r][r_c]->getpc()->getSym() == 'r')
				{
					if (B->C[sr][sc]->getpc()->getMove() == true && B->C[r_r][r_c]->getpc()->getMove() == true)
					{
						if (C == 2 && sr == dr)
						{
							if (!selfCheck(B,sc, sr, dc, dr,Ps,Turn))
							{
								tr = r_r;
								tc = r_c;
								return true;
							}
						}
					}
				}

			}
		}

		if (B->C[sr][sc]->getpc()->getColor() == black)
		{
			if (B->C[sr][sc]->getpc()->getSym() == 'k' && sr == 0)
			{

				while (r_c >= 0 && r_r < 8 )
				{
					if ((B->C[r_r][r_c]->getpc()!= nullptr))
					{
						break;
					}

					else if (dc < sc)
					{
						r_c--;
					}

					else if (dc > sc)
					{
						r_c++;
					}
				}

				if (B->C[r_r][r_c]->getpc()->getSym() == 'r')
				{
					if (B->C[sr][sc]->getpc()->getMove() == true && B->C[r_r][r_c]->getpc()->getMove() == true)
					{
						if (C == 2 && sr == dr)
						{
							if (!selfCheck(B, sc, sr, dc, dr, Ps, Turn))
							{
								tr = r_r;
								tc = r_c;
								return true;
							}
						}
					}
				}
			}
		}
		return false;

}
void Chess::Play()
{
	/////////////////////////////////////////////////////////////////////////////Time Based Work////////////////////////////////////////////////////////////////////

	int Ws=300;
	int Bs=300;
	int wdelay = 0;
	int bdelay = 0;
	string h;
	string m;

	sf::Text time;
	time.setFont(Piece_Texture::font2);
	h = to_string(Ws);
	time.setString(h);
	time.setPosition(71 * 16 + 31, 71 * 5 + 19);;


	sf::Text time2;
	time2.setFont(Piece_Texture::font2);
	m = to_string(Bs);
	time2.setString(m);
	time2.setPosition(71 * 16 + 31, 71 * 1 + 19);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	bool cundo = false;
	bool textdone = false;
	bool isundo = false;
	bool firstTime = true;
	bool firstTimeDisplay = false;
	bool bcheck = false;
	bool compHigh = false;
	int Kr = 0, Kc = 0;
	sf::Event event;
	bool** b = nullptr;
	bool bcheckmate = false;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	sf::Sprite Redo;
	Redo.setTexture(Piece_Texture::Redo);
	Redo.setPosition(700, 600);


	sf::Sprite Undo;
	Undo.setTexture(Piece_Texture::Undo);
	Undo.setPosition(600, 600);



	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	shape.setScale(sf::Vector2f(0.13f, 0.13f));


	sf::Text text3;
	text3.setFont(Piece_Texture::font2);
	sf::Text text4;
	text4.setFont(Piece_Texture::font2);
	sf::Text text5;
	text5.setFont(Piece_Texture::font2);

	////////////////////////////////////////////////////////


	while (window->isOpen())
	{

		while (window->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window->close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					window->close();
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					if ((event.mouseButton.x >= 0) && (event.mouseButton.x <= 568) && (event.mouseButton.y >= 0) && (event.mouseButton.y <= 568) && firstTime == true)
					{
						this->sr = event.mouseButton.y / 71;
						this->sc = event.mouseButton.x / 71;
						
						if (validSourceSelection(Ps[Turn], this->sr, this->sc, this->B))
						{
							b = CompHigh(B, sr, sc, Ps, Turn);
							compHigh = true;
							firstTime = false;
						}

					}
					else if ((event.mouseButton.x >= 0) && (event.mouseButton.x <= 568) && (event.mouseButton.y >= 0) && (event.mouseButton.y <= 568) && firstTime == false)
					{
						this->dr = event.mouseButton.y / 71;
						this->dc = event.mouseButton.x / 71;
						int temp_r = 0, temp_c = 0;


						if (Castling(B, sr, sc, dr, dc, temp_r, temp_c))
						{
							bcheck = false;
							if (B->getPiece(sr, sc)->getSym() == 'k' || B->getPiece(temp_r, temp_c)->getSym() == 'r')
							{
								if (sc < dc)
								{
									// First MOve
									B->C[dr][dc]->setpc(B->C[sr][sc]->getpc());
									B->C[dr][dc]->getpc()->setSprite(dr, dc);
									B->C[dr][dc - 1]->setpc(B->C[temp_r][temp_c]->getpc());
									B->C[dr][dc - 1]->getpc()->setSprite(dr, dc - 1);
									B->C[temp_r][temp_c]->setpc(nullptr);
									B->C[sr][sc]->setpc(nullptr);
								}
								else
								{
									// First MOve
									B->C[dr][dc]->setpc(B->C[sr][sc]->getpc());
									B->C[dr][dc]->getpc()->setSprite(dr, dc);
									B->C[dr][dc + 1]->setpc(B->C[temp_r][temp_c]->getpc());
									B->C[dr][dc + 1]->getpc()->setSprite(dr, dc + 1);
									B->C[temp_r][temp_c]->setpc(nullptr);
									B->C[sr][sc]->setpc(nullptr);
								}

							}

							turnChange();
							cb[t_b] = bcheck;

							cundo = true;

							if (Check(B, Ps, !Turn))
							{
								text4.setString("Check");
								text4.setPosition((71 * 14 + 11), (71 * 3 + 7));
								bcheck = true;
								cb[t_b] = bcheck;
								if (!CanIMove(B, Ps, Turn))
								{
									//bool bcheckmate = ;
									bcheck = false;
									text3.setString("CheckMate");
									text3.setPosition((71 * 14 + 11), (71 * 3 + 7));
									if (Turn == 0)
									{
										text5.setString("White Win");
										text5.setPosition((71 * 15 - 7 + 24), (71 * 3 + 7 + 26));
									}
									if (Turn == 1)
									{
										text5.setString("Black Win");
										text5.setPosition((71 * 15 - 7 + 24), (71 * 3 + 7 + 26));
									}
								}
							}
							else
							{
								cb[t_b] = bcheck;
							}
							if (StaleMate(B, Turn, Ps))
							{
								text3.setString("StaleMate");
								text3.setPosition((71 * 14 + 11), (71 * 3 + 7));
								text5.setString("Game Draw");
								text5.setPosition((71 * 15 - 7 + 24), (71 * 3 + 7 + 26));
							}


							Save(B);

							compHigh = false;
							firstTime = true;
						}
						else if (validDestination(Ps[Turn], dr, dc, B) && !selfCheck(B, sc, sr, dc, dr, Ps, Turn) && B->isLegalMove(B, sr, sc, dr, dc))
						{

							bcheck = false;
							if (B->getPiece(sr, sc)->getSym() == 'p' || B->getPiece(sr, sc)->getSym() == 'k' || B->getPiece(sr, sc)->getSym() == 'r')
							{
								B->getPiece(sr, sc)->setMove();// First MOve
							}

							Promotion(B, sr, sc, dr, dc, Ps, Turn);
							B->Move(sr, sc, dr, dc);
							B->C[dr][dc]->getpc()->setSprite(dr, dc);// changing sprite position


							firstTime = true;
							compHigh = false;

							turnChange();
							cb[t_b] = bcheck;

							cundo = true;

							if (Check(B, Ps, !Turn))
							{
								text4.setString("Check");
								text4.setPosition((71 * 14 + 11), (71 * 3 + 7));
								bcheck = true;
								cb[t_b] = bcheck;
								if (!CanIMove(B, Ps, Turn))
								{
									bcheck = false;
									text3.setString("CheckMate");
									text3.setPosition((71 * 14 + 11), (71 * 3 + 7));
									if (Turn == 0)
									{
										text5.setString("White Win");
										text5.setPosition((71 * 15 - 7 + 24), (71 * 3 + 7 + 26));
									}
									if (Turn == 1)
									{
										text5.setString("Black Win");
										text5.setPosition((71 * 15 - 7 + 24), (71 * 3 + 7 + 26));
									}
								}
							}
							else
							{
								cb[t_b] = bcheck;
							}
							if (StaleMate(B, Turn, Ps))
							{
								text3.setString("StaleMate");
								text3.setPosition((71 * 14 + 11), (71 * 3 + 7));
								text5.setString("Game Draw");
								text5.setPosition((71 * 15 - 7 + 24), (71 * 3 + 7 + 26));
							}


							Save(B);

							compHigh = false;
							firstTime = true;
						}
						else
						{
							firstTime = true;
							compHigh = false;
						}

							
							
					}
					else if ((event.mouseButton.x >= 600) && (event.mouseButton.x <= 650) && (event.mouseButton.y >= 600) && (event.mouseButton.y <= 650))
					{

						if ((bn-1)> 0 && cundo==true)
						{
							Board NB;
							NB.setBoard(mb[bn - 2]);
							bcheck = cb[bn-2];
							this->B = nullptr;
							this->B = &NB;
							if (Turn == 0)
							{
								Turn = 1;
							}
							else
							{
								Turn = 0;
							}
							bn--;
							continue;
							isundo = true;
						}
						if ((bn - 1)== 0)
						{
							ifstream rdr("input.txt");
							Board startBoard(rdr);
							this->B = &startBoard;
							if (Turn == 0)
							{
								Turn = 1;
							}
							else
							{
								Turn = 0;
							}
							cundo = false;
							isundo = false;
							mb = nullptr;
							cb = nullptr;
							cb = new bool[1000];
							mb = new char** [1000];
							for (int i = 0; i < 1000; i++)
							{
								mb[i] = new char* [8];
								for (int j = 0; j < 8; j++)
								{
									mb[i][j] = new char[8];
								}
							}

							this->bn = 0;
							this->t_b = 0;
						}

						if ((bn - 1) < 0)
						{
							continue;
						}
						
					}
					else if ((event.mouseButton.x >= 760) && (event.mouseButton.x <= 790) && (event.mouseButton.y >= 600) && (event.mouseButton.y <= 650))
					{



						if (isundo == false)
						{
							if (bn != t_b)
							{

								Board NB;
								NB.setBoard(mb[bn]);
								bcheck = cb[bn];
								this->B = nullptr;
								this->B = &NB;
								if (Turn == 0)
								{
									Turn = 1;
								}
								else
								{
									Turn = 0;
								}
								bn++;
								continue;
							}
							if (bn  >= t_b )
							{
								continue;
							}
							
						}

					}
				}
			}


			
			
		}


		
		if (Ws == 0)
		{
			text3.setString("Black Wins");
			text3.setPosition((71 * 8 + 11), (71 * 5 + 7));
			textdone = true;
		}
		if (Bs == 0)
		{
			text3.setString("White Wins");
			text3.setPosition((71 * 8 + 11), (71 * 5 + 7));
			textdone = true;
		}

		this->window->clear();

		if ((Ws == 0 || Bs == 0) && textdone==true)
		{
			this->window->draw(text3);
			this->window->display();
			int n=0;
			while (n != 10000000000)
			{
				n++;
			}
			window->close();
		}



		for (int i = 0; i < 8; i++)
		{
			for (int c = 0; c < 8; c++)
			{
				this->window->draw(B->C[i][c]->square);
			}
		}


		sf::Sprite temp;
		temp.setTexture(Piece_Texture::Red);
		temp.setScale(sf::Vector2f(0.235f, 0.235f));

		sf::Sprite temp2;
		temp2.setTexture(Piece_Texture::Green);
		temp2.setScale(sf::Vector2f(0.138f, 0.195f));


		if (compHigh == true)
		{
			for (int i = 0; i < 8; i++)
			{
				for (int c = 0; c < 8; c++)
				{
					if (b[i][c] == true)
					{
						if (B->C[i][c]->getpc() != nullptr && B->C[i][c]->getpc()->getColor() != Ps[Turn]->getColor())
						{
							temp.setPosition(71 * c, 71 * i);
							this->window->draw(temp);
						}
						else
						{
							temp2.setPosition(71 * c, 71 * i);
							this->window->draw(temp2);
						}

					}
				}
			}
		}

		if (bcheck == true)
		{
			this->window->draw(text4);

			findKing(B, Ps[Turn], Kr, Kc);
			temp.setPosition(sf::Vector2f((71 * Kc), (71 * Kr)));
			window->draw(shape);
			window->draw(temp);
		}



		for (int i = 0; i < 8; i++)
		{
			for (int c = 0; c < 8; c++)
			{
				if (B->C[i][c]->getpc() != nullptr)
				{
					this->window->draw(B->C[i][c]->getpc()->getSpirit());
				}
			}
		}


		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		sf::Sprite blackP;
		sf::Text text;
		text.setFont(Piece_Texture::font2);
		text.setString(Ps[0]->getName());
		text.setPosition(71 * 15 + 11, 71 * 1 + 19);
		blackP.setTexture(Piece_Texture::blackPawn);
		blackP.setScale(sf::Vector2f(0.245f, 0.245f));
		blackP.setPosition((71 * 14 + 11), (71 * 1 + 7));
		this->window->draw(blackP);



		sf::Sprite whiteP;
		whiteP.setPosition((71 * 14 + 11), (71 * 5 + 7));
		whiteP.setScale(sf::Vector2f(0.245f, 0.245f));
		whiteP.setTexture(Piece_Texture::whitePawn);
		this->window->draw(whiteP);
		sf::Text text2;
		text2.setFont(Piece_Texture::font2);
		text2.setString(Ps[1]->getName());
		text2.setPosition(71 * 15 + 11, 71 * 5 + 19);

		this->window->draw(text);
		this->window->draw(text2);
		this->window->draw(text3);
		this->window->draw(text5);


		this->window->draw(Undo);
		this->window->draw(Redo);
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if (Ps[Turn]->getColor() == black)
		{
			shape.setPosition((71 * 14 - 20), (71 * 1 + 24));
			this->window->draw(shape);
		}
		if (Ps[Turn]->getColor() == white)
		{
			shape.setPosition((71 * 14 - 20), (71 * 5 + 24));
			this->window->draw(shape);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


		if (Turn == 1)
		{
			wdelay++;
		}
		if (wdelay == 400)
		{
			Ws--;
			h = to_string(Ws);
			time.setString(h);
			time.setPosition(71 * 16 + 31, 71 * 5 + 19);
			wdelay=0;
		}
		this->window->draw(time);


		if (Turn == 0)
		{
			bdelay++;
		}
		if (bdelay == 400)
		{
			Bs--;
			m = to_string(Bs);
			time2.setString(m);
			time2.setPosition(71 * 16 + 31, 71 * 1 + 19);
			bdelay = 0;
		}
		this->window->draw(time2);
		this->window->display();


	}
}
Chess::~Chess()
{
	delete[]this->window;
}