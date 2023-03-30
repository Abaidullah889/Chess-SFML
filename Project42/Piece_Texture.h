#pragma once
#include"Header.h"
#include<string>
using namespace std;

class Piece_Texture
{
public:
    static sf::Texture blackKing;
    static sf::Texture blackQueen;
    static sf::Texture blackRook;
    static sf::Texture blackKnight;
    static sf::Texture blackBishop;
    static sf::Texture blackPawn;

    static sf::Texture whiteKing;
    static sf::Texture whiteQueen;
    static sf::Texture whiteRook;
    static sf::Texture whiteKnight;
    static sf::Texture whiteBishop;
    static sf::Texture whitePawn;

    static sf::Texture Square1;
    static sf::Texture Square2;

    static sf::Font font1;
    static sf::Font font2;
    static sf::Font font3;

    static sf::Texture Red;
    static sf::Texture Green;

    static sf::Texture Undo;
    static sf::Texture Redo;

    static sf::Texture BackGround;


    static sf::Texture loadTexture(string str);
    static sf::Font loadFont(string str);

};

