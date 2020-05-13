#include "board.h"


Board::Board()
{
	fields.resize(BOARD_SIZE);
	for(int i=0;i<BOARD_SIZE;i++)
	{
		fields[i].resize(BOARD_SIZE);
	}

	for(int i=0;i<fields.size();i++)
	{
		for(int j=0;j<fields[i].size();j++)
		{
			if(i<3 && i%2==0 && j%2==0)
			{
				fields[i][j]='O';
			}else if(i<3 && i%2==1 && j%2==1)
			{
				fields[i][j]='O';
			}else if(i>4 && i%2==1 && j%2==1)
			{
				fields[i][j]='X';
			}else if(i>4 && i%2==0 && j%2==0)
			{
				fields[i][j]='X';
			}else
			{
				fields[i][j]=' ';
			}
			
			
		}
	}

	/*
///////////FOR TESTS!!!
	for(int i=0;i<fields.size();i++)
	{
		for(int j=0;j<fields[i].size();j++)
		{
			fields[i][j]=' ';
		}
	}
	fields[7][7]= 'X';
	fields[0][0]= 'O';
	*/
	turn ='X';
}

Board::~Board()
{
std::cout<<"Board destructed"<<std::endl;
}

const int Board::range_of_move(Field start, Field destination)
{
	return abs(start.get_x()-destination.get_x());
}

void Board::change_turn()
{
	if(turn=='O')
	{
		turn='X';
	}else if(turn=='X')
	{
		turn='O';
	}
}

char Board::actual_turn()
{
	if(turn=='O')
	{
		return 'O';
	}else if(turn=='X')
	{
		return 'X';
	}
}


char Board::next_turn()
{
	if(turn=='O')
	{
		return 'X';
	}else if(turn=='X')
	{
		return 'O';
	}
}
		
int Board::number_of_actual_turn_pawns()
{
	int h=0;
	for(int i=0;i<fields.size();i++)
	{
		for(int j=0;j<fields[i].size();j++)
		{
			if(fields[i][j]==turn)
				h++;
		}
	}
	return h;
}

void Board::update_possible_moves()
{
	int h=0;
possible_moves.clear(); //clear last turn vector
	possible_moves.resize(number_of_actual_turn_pawns());
	for(int i=0;i<fields.size();i++)
	{
		for(int j=0;j<fields[i].size();j++)
		{
			if(fields[i][j]==turn)
			{
				//std::cout<<"Point->"<<Field(i+1,j+1)<<std::endl;
				possible_moves[h].emplace_back(i,j);
				h++;
			}
		}
	}
	// Adding possible captures to possible moves
	for(int i=0;i<possible_captures.size();i++)
	{
		for(int j=0;j<possible_captures[i].size();j++)
		{
			if(j>0)
			{
				possible_moves[i].emplace_back(possible_captures[i][j]);
			}
		}
	}

//TODO: add all possible moves to possible_moves vector/////////////

for(int i=0;i<possible_moves.size();i++)
	{

			if(possible_moves[i][0].get_x()-1 >= 0  && possible_moves[i][0].get_y() -1 >=0 ) // If we are not going out of array
			{
				if(fields[possible_moves[i][0].get_x()-1][possible_moves[i][0].get_y()-1] == ' ' )//left top
				{
					Field f1(possible_moves[i][0].get_x()-1,possible_moves[i][0].get_y()-1); // left top field
					if(is_move_forward(possible_moves[i][0],f1)) // IS MOVE FORWARD!!!
					{
						possible_moves[i].emplace_back(f1);
					}
				}	
			}
			
			if(possible_moves[i][0].get_x()+1 <= 7 && possible_moves[i][0].get_y()-1 >= 0)// If we are not going out of array
			{
				if(fields[possible_moves[i][0].get_x()+1][possible_moves[i][0].get_y()-1] == ' ' )//left bottom
				{
					Field f1(possible_moves[i][0].get_x()+1,possible_moves[i][0].get_y()-1); // left bottom field
					if(is_move_forward(possible_moves[i][0],f1)) // IS MOVE FORWARD!!!
					{
						possible_moves[i].emplace_back(f1);
					}
				}
			}
			if(possible_moves[i][0].get_x()-1 >= 0 && possible_moves[i][0].get_y()+1 <= 7)// If we are not going out of array
			{
				if(fields[possible_moves[i][0].get_x()-1][possible_moves[i][0].get_y()+1] == ' ' )//right top
				{
					Field f1(possible_moves[i][0].get_x()-1,possible_moves[i][0].get_y()+1); // right top field
					if(is_move_forward(possible_moves[i][0],f1)) // IS MOVE FORWARD!!!
					{
						possible_moves[i].emplace_back(f1);
					}
				}	
			}
			if(possible_moves[i][0].get_x()+1 <= 7 && possible_moves[i][0].get_y()+1 <= 7)// If we are not going out of array
			{
				if(fields[possible_moves[i][0].get_x()+1][possible_moves[i][0].get_y()+1] == ' ' )//right bottom
				{
					Field f1(possible_moves[i][0].get_x()+1,possible_moves[i][0].get_y()+1); // right bottom field
					if(is_move_forward(possible_moves[i][0],f1)) // IS MOVE FORWARD!!!
					{
						possible_moves[i].emplace_back(f1);
					}
				}
			}
			
	}

///////////////////////////////////////////////////////////////////

	std::cout<<"WYSWIETLAM MOZLIWOSCI!!!"<<std::endl;
// print
	std::cout<<"Ilosc pionkow: "<<possible_moves.size()<<std::endl;
for(int i=0;i<possible_moves.size();i++)
	{
		for(int j=0;j<possible_moves[i].size();j++)
		{
			std::cout<<possible_moves[i][j];
		}
		std::cout<<std::endl;
	}
}

void Board::update_possible_captures()
{
	int h=0;
	possible_captures.clear(); //clear last turn vector
	possible_captures.resize(number_of_actual_turn_pawns());
	for(int i=0;i<fields.size();i++)
	{
		for(int j=0;j<fields[i].size();j++)
		{
			if(fields[i][j]==turn)
			{
				//std::cout<<"Point->"<<Field(i+1,j+1)<<std::endl;
				possible_captures[h].emplace_back(i,j);
				h++;
			}
		}
	}

	for(int i=0;i<possible_captures.size();i++)
	{

			if(possible_captures[i][0].get_x()-2 >= 0  && possible_captures[i][0].get_y() -2 >=0 ) // If we are not going out of array
			{
				if(fields[possible_captures[i][0].get_x()-1][possible_captures[i][0].get_y()-1] == next_turn() )//left top
				{
					if(fields[possible_captures[i][0].get_x()-2][possible_captures[i][0].get_y()-2] == ' ')				
					{
						possible_captures[i].emplace_back(possible_captures[i][0].get_x()-2,possible_captures[i][0].get_y()-2);
					}
				}	
			}
			if(possible_captures[i][0].get_x()+2 <= 7 && possible_captures[i][0].get_y()-2 >= 0)// If we are not going out of array
			{
				if(fields[possible_captures[i][0].get_x()+1][possible_captures[i][0].get_y()-1] == next_turn() )//left bottom
				{
					if(fields[possible_captures[i][0].get_x()+2][possible_captures[i][0].get_y()-2] == ' ')				
					{
						possible_captures[i].emplace_back(possible_captures[i][0].get_x()+2,possible_captures[i][0].get_y()-2);
					}
				}
			}
			if(possible_captures[i][0].get_x()-2 >= 0 && possible_captures[i][0].get_y()+2 <= 7)// If we are not going out of array
			{
				if(fields[possible_captures[i][0].get_x()-1][possible_captures[i][0].get_y()+1] == next_turn() )//right top
				{
					
					if(fields[possible_captures[i][0].get_x()-2][possible_captures[i][0].get_y()+2] == ' ')				
					{
						possible_captures[i].emplace_back(possible_captures[i][0].get_x()-2,possible_captures[i][0].get_y()+2);
					}
				}	
			}
			if(possible_captures[i][0].get_x()+2 <= 7 && possible_captures[i][0].get_y()+2 <= 7)// If we are not going out of array
			{
				if(fields[possible_captures[i][0].get_x()+1][possible_captures[i][0].get_y()+1] == next_turn() )//right bottom
				{
					if(fields[possible_captures[i][0].get_x()+2][possible_captures[i][0].get_y()+2] == ' ')				
					{
						possible_captures[i].emplace_back(possible_captures[i][0].get_x()+2,possible_captures[i][0].get_y()+2);
					}
				}
			}
	}


/*
	std::cout<<"WYSWIETLAM MOZLIWOSCI!!!"<<std::endl;
	
	for(int i=0;i<possible_captures.size();i++)
	{
		for(int j=0;j<possible_captures[i].size();j++)
		{
			std::cout<<possible_captures[i][j];
		}
		std::cout<<std::endl;
	}
*/
}

const bool Board::is_any_capture_mandatory()
{
	for(int i=0;i<possible_captures.size();i++)
	{
		if(possible_captures[i].size()>1)
			return true;		
	}
	return false;
}

const bool Board::is_any_move_possible()
{
	for(int i=0;i<possible_moves.size();i++)
	{
		if(possible_moves[i].size()>1)
			return true;		
	}
	return false;
}

const bool Board::is_move_forward(Field start, Field destination)
{
	if(fields[start.get_x()][start.get_y()]=='X')
	{
		if(destination.get_x()<start.get_x())
		{
			return true;
		}else
		{
			return false;
		}
	}

	if(fields[start.get_x()][start.get_y()]=='O')
	{
		if(destination.get_x()>start.get_x())
		{
			return true;
		}else
		{
			return false;
		}	
	}

}


const bool Board::is_this_move_on_possible_captures(Field start, Field destination)
{

	for(int i=0;i<possible_captures.size();i++)
	{
		for(int j=0;j<possible_captures[i].size();j++)
		{
			if(j>0)
			{
				if(
				start.get_x() == possible_captures[i][0].get_x() &&
				start.get_y() == possible_captures[i][0].get_y() &&
				destination.get_x() == possible_captures[i][j].get_x() &&
				destination.get_y() == possible_captures[i][j].get_y() )
				{
					return true;
				}
			}
		}
	}
	return false;
}


const bool Board::is_this_move_on_possible_moves(Field start, Field destination)
{
	for(int i=0;i<possible_moves.size();i++)
	{
		for(int j=0;j<possible_moves[i].size();j++)
		{
			if(j>0)
			{
				if(
				start.get_x() == possible_moves[i][0].get_x() &&
				start.get_y() == possible_moves[i][0].get_y() &&
				destination.get_x() == possible_moves[i][j].get_x() &&
				destination.get_y() == possible_moves[i][j].get_y() )
				{
					return true;
				}
			}
		}
	}
	return false;
}
void Board::delete_captured_pawn(Field start, Field destination)
{
	if(start.get_x()>destination.get_x() && start.get_y()>destination.get_y()) // capture was in LEFT TOP direction
	{
		fields[destination.get_x()+1][destination.get_y()+1] = ' ';
	}else if(start.get_x()>destination.get_x() && start.get_y()<destination.get_y()) // capture was in RIGHT TOP direction
	{
		fields[destination.get_x()+1][destination.get_y()-1] = ' ';

	}else if(start.get_x()<destination.get_x() && start.get_y()>destination.get_y()) // capture was in LEFT BOTTOM direction
	{
		fields[destination.get_x()-1][destination.get_y()+1] = ' ';

	}else if(start.get_x()<destination.get_x() && start.get_y()<destination.get_y()) // capture was in RIGHT BOTTOM direction
	{
		fields[destination.get_x()-1][destination.get_y()-1] = ' ';

	}else
	{
		std::cout<<"ERROR";
	}


}


const bool Board::is_move_possible(Field start, Field destination)
{
	if(is_any_capture_mandatory())
	{
		
		if(is_this_move_on_possible_captures(start,destination))
		{
			delete_captured_pawn(start,destination);
			return true;	// THERE IS A CAPTURE!!!!
		}else
		{
			std::cout<<"THERE IS CAPTURE MANDATORY AND YOU HAVE TO DO IT!!!";
			return false;
		}
	}else if(is_any_move_possible())
	{
		if(is_this_move_on_possible_moves(start,destination))
		{
			return true;	
		}else
		{
			std::cout<<"You cant do this move!!!!!"<<std::endl;;
			return false;
		}
	}
	return false;
}

void Board::display()
{
	std::cout<<"ITS-> "<<turn<<" TURN!"<<std::endl;
	std::cout<<"    1 2 3 4 5 6 7 8"<<std::endl;		
	std::cout<<"   +-+-+-+-+-+-+-+-+"<<std::endl;
	for(int i=0;i<fields.size();i++)
	{
		std::cout<<i+1<<"  ";		
		for(int j=0;j<fields[i].size();j++)
		{
			std::cout<<"|"<<fields[i][j];
		}
		std::cout<<"|"<<std::endl;
	}

	std::cout<<"   +-+-+-+-+-+-+-+-+"<<std::endl;
}


void Board::move()
{
	update_possible_captures();
	update_possible_moves();
	Field which;
	Field where;
	int which_i,which_j,where_i,where_j;
	if(is_any_capture_mandatory())
	{
		std::cout<<"THERE IS AT LEAST 1 CAPTURE MANDATORY!"<<std::endl;
	}
	do
	{
	std::cout<<"Which pawn to move? Row:";
	std::cin>>which_i;
	while (std::cin.fail()||(which_i<1)||(which_i>8))
	{
		std::cout << "This value is incorrect. Try again: " << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin>>which_i;
	}
	std::cout<<" Col:";
	std::cin>>which_j;
	while (std::cin.fail()||(which_j<1)||(which_j>8))
	{
		std::cout << "This value is incorrect. Try again: " << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin>>which_j;
	}
	std::cout<<std::endl;
//////////////////////////////////////////////////////////////////////
	std::cout<<"Where move chosen pawn? Row:";
	std::cin>>where_i;
	while (std::cin.fail()||(where_i<1)||(where_i>8))
	{
		std::cout << "This value is incorrect. Try again: " << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin>>where_i;
	}
	std::cout<<" Col:";
	std::cin>>where_j;
	while (std::cin.fail()||(where_j<1)||(where_j>8))
	{
		std::cout << "This value is incorrect. Try again: " << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cin>>where_j;
	}

	which.set(which_i-1,which_j-1);
	where.set(where_i-1,where_j-1);
	std::cout<<std::endl;
	}while(!is_move_possible(which,where));

	

	if(is_move_possible(which,where))
	{
		std::cout<<std::endl<<"Move is possible"<<std::endl;
		fields[where.get_x()][where.get_y()]=turn;
		fields[which.get_x()][which.get_y()]=' ';
	}
////////////////////////////DOIING MOVE!/////////////////////////////
	//


}