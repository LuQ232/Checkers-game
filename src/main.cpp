#include <iostream>

#include "board.h"
#include "bot.h"
#include "move.h"

int main (){
	srand (time(NULL));
	std::cout<<"LET'S BEGIN THE GAME!"<<std::endl<<"WHEN YOU WANT TO INPUT PAWN COORDINATES NEEDED FOR MOVE"<<std::endl<<"FIRST WRITE COLUMN, THEN ROW."<<std::endl<<"FOR EXAMPLE: 'A3' OR 'D4'. REMEMBER ABOUT CAPITAL LETTERS!"<<std::endl<<"GOOD LUCK!"<<std::endl;
	Board board;
	Move move;
	while (true)
	{
		board.reset_capture_data();
		board.update_kings();
		board.display();
		//board.display_info_about_kings();

		board.update_possible_captures();
		board.update_possible_moves();
		
		if(!board.is_any_move_possible())
			{
				break;
			}
		board.move();

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