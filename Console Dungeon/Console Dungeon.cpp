// Console Dungeon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const int height = 80;
const int width = 200;
const int hudHeight = 15;

int _tmain(int argc, _TCHAR* argv[])
{
	
	char z[] = "     \n"
			   "  o |\n"
		       " /|\\|\n"
			   " / \\ \n"
			   "     ";

	z[8] = 0x01;
	



	//for(int c = 0; c <= 255; c++) cout << (char)c << " " << c << endl;
	Engine p(width,height,1);
	Map map(p,width*20,height-hudHeight);

	p.clear();
	while (true) {
		if( GetAsyncKeyState(VK_LEFT) )	--map;
		if( GetAsyncKeyState(VK_RIGHT) ) ++map;
		map.erase();
		map.draw();
		p.draw();
		Sleep(1);
	}


	cin.get();

	return 0;
}