#include "bot.h"

Move Bot::return_move(std::vector<std::vector<Field>> vector_of_possible_moves)
{
	 int i=0;
	 int j=0;
	//j=vector_of_possible_moves.size();
	 do
	 {
	 	i = rand() % vector_of_possible_moves.size()-1;
	 }while(vector_of_possible_moves[i].size()<=1);
	do
	{ 
	 	j = rand() % vector_of_possible_moves[i].size();
	}while(j == 0);
	 	//std::cout<<"I->"<<i<<" J->"<<j<<std::endl;

	return Move(vector_of_possible_moves[i][0],vector_of_possible_moves[i][j]);


}
