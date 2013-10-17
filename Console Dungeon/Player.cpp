#include "stdafx.h"
#include "Player.h"

Player::Player(Engine &e,Texture &t, int x, int y,Map &m): Object(e,t,x,y), Creature(), map(m) {
	this->speed = 3;
	
}

int Player::_x() const {
	return (GetAsyncKeyState(VK_LEFT) ? -1 : GetAsyncKeyState(VK_RIGHT) ? 1 : 0) * this->speed;
}

bool Player::_j() const {
	return (bool) GetAsyncKeyState(VK_SPACE);
}

bool Player::_inAir() const {
	for(int c = 0; c < this->width; ++c)
		if( this->map(c + this->position.x) <= this->height + this->position.y )
			return false;
}

void Player::move() {
	static int lastCall = GetTickCount();

	if( GetTickCount() - lastCall < 1000/30 )
		return;

	lastCall = GetTickCount();

	//if( this->_inAir() ) this->position.y++;
	
	int mv = this->_x();
	if( !mv ) return;
	
	this->position.y = this->engine->getHeight() - this->map.getHighestBetween(this->position.x,this->position.x + this->width) - this->height;

	(*this->engine)(0,2,"");
	(*this->engine)(this->position.x);
	(*this->engine)(0,3,"");
	(*this->engine)(mv);
	

	

	if(mv > 0) {
		// moving right
		if( this->position.x > this->engine->getWidth() * 0.8 ) {
			this->map += mv;
		} else {
			this->position.x += mv;
		}
	} else {
		// moving left
		if( this->position.x < this->engine->getWidth() * 0.2 ) {
			this->map += mv;
		} else {
			this->position.x += mv;
		}
	}
	return;

	


}