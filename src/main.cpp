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


	board.update_possible_captures();
	board.update_possible_moves();
	if(!board.is_any_move_possible())
		{
			break;
		}
	board.move();

	//board.display();

	board.update_kings();
	board.update_possible_captures();
	board.update_possible_moves();
	if(!board.is_any_move_possible())
		{
			break;
		}

	board.change_turn();
	std::cout<<"ZMIANA TURY!!!!"<<std::endl;


	}
	
	std::cout<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl;
	std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
	std::cout<<"WYGRAŁY ->"<<board.next_turn()<<std::endl;
	std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
	
	return 0;
}