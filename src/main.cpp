#include <iostream>

#include "board.h"
#include "bot.h"
#include "move.h"

int main (){
	srand (time(NULL));
	Bot bot;
	Board board;
	Move move;
	while (true)
	{
	
	
	board.reset_capture_data();
	board.update_kings();
	//board.display_data();
	board.display();
	

	board.update_possible_captures();
	board.update_possible_moves();
	move = bot.return_move(board.return_vector_of_possible_moves());
	std::cout<<move;
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