// Console Dungeon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const int height = 80;
const int width = 200;
const int hudHeight = 15;

int _tmain(int argc, _TCHAR* argv[])
{
	

	//for(int c = 0; c <= 255; c++) cout << (char)c << " " << c << endl;
	Engine p(width,height,1);
	Map map(p,width*20,height-hudHeight);
	char t_data[10] = "xxxxxxxxx";
	Texture text(3,3,t_data);

	Player obj(p,text,10,30,map);


	p.clear();
	while (true) {
		//if( GetAsyncKeyState(VK_LEFT) )	--map;
		//if( GetAsyncKeyState(VK_RIGHT) ) ++map;
		
		map.erase();
		obj.erase();		
		
		obj.move();

		map.draw();
		obj.draw();
		
		p.draw();
		Sleep(1000/60);
	}


	cin.get();

	return 0;
}