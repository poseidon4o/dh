#include "Engine.h"
#include "Map.h"
#include "Texture.h"
#include "Player.h"
#include <iostream>

const int height = 80;
const int width = 200;
const int hudHeight = 15;

int main(int argc, char * argv[])
{
    using namespace std;


	Engine p(width,height,1);
	Map map(p,width*20,height-hudHeight);
	char t_data[1000] = "                                                                                                                                             /O\\           x ^ x     (@@)x  |  x(@@) (@)x  |  x(@)      x | x            x       ";
	//char t_data[100] = "  (     @(    @@    ))    xx   x  x /     O^|||x\      x  x   xx    ((    @@    @)    )   ";
	//char t_data[100] = "xxxxxx  xx  ";




	Texture text(3, 5, "                                           ");

	Player obj(p,text,10,30,map);


	p.clear();
	while (true) {

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
