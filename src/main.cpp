#include <iostream>

#include "board.h"

int main (){
	Board board;
	while (true)
	{
	board.reset_capture_data();
	board.update_kings();
	//board.display_data();
	board.display();
	board.move();
	board.change_turn();
	
	}
	return 0;
}