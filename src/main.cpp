#include <iostream>

#include "board.h"

int main (){
	Board board;
	while (true)
	{
	board.display();
	board.move();
	board.change_turn();
	}
	return 0;
}