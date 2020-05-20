#include "bot.h"

Move Bot::return_move(std::vector<std::vector<Field>> vector_of_possible_moves,std::vector<std::vector<Field>> vector_of_possible_captures,bool is_capture_mandatory)
{
	 int i=0;
	 int j=0;
	if(is_capture_mandatory == false)
	{
		do
		{
			i = rand() % vector_of_possible_moves.size();
		}while(vector_of_possible_moves[i].size()<=1);
		do
		{ 
		 	j = rand() % vector_of_possible_moves[i].size();
		}while(j == 0);

		return Move(vector_of_possible_moves[i][0],vector_of_possible_moves[i][j]);
	}else if (is_capture_mandatory == true){
		do
		{
			i = rand() % vector_of_possible_captures.size();
		}while(vector_of_possible_captures[i].size()<=1);
		do
		{ 
		 	j = rand() % vector_of_possible_captures[i].size();
		}while(j == 0);

		return Move(vector_of_possible_captures[i][0],vector_of_possible_captures[i][j]);
	}
}
