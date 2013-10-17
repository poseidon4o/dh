#pragma once
#include "stdafx.h"
class Player :
	public Creature,
	public Object
{
public:
	Player(Engine &,Texture &, int, int,Map &);

	void move();
protected:
	int _x() const;
	bool _j() const;

	void _right();
	void _left();

	int speed;


	bool _inAir() const;;

	Map &map;
};

