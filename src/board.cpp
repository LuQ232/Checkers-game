#include "board.h"


Board::Board()
{
	fields.resize(BOARD_SIZE);
	for(int i=0;i<BOARD_SIZE;i++)
	{
		fields[i].resize(BOARD_SIZE);
	}
/*
	for(int i=0;i<fields.size();i++)
	{
		for(int j=0;j<fields[i].size();j++)
		{
			if(i<3 && i%2==0 && j%2==0)
			{
				//fields[i][j]='O';
				Field f1(i,j,2,'O');
				fields[i][j]=f1;
			}else if(i<3 && i%2==1 && j%2==1)
			{
				Field f1(i,j,2,'O');
				//fields[i][j]='O';
				fields[i][j]=f1;	
			}else if(i>4 && i%2==1 && j%2==1)
			{
				Field f1(i,j,2,'X');
				//fields[i][j]='X';
				fields[i][j]=f1;	
			}else if(i>4 && i%2==0 && j%2==0)
			{
				Field f1(i,j,2,'X');
				//fields[i][j]='X';
				fields[i][j]=f1;
			}else
			{
				Field f1(i,j,1,' ');
				//fields[i][j]=' ';
				fields[i][j]=f1;
			}
			
			
		}
	}
*/

///////////FOR TESTS!!!
	for(int i=0;i<fields.size();i++)
	{
		for(int j=0;j<fields[i].size();j++)
		{
			Field f1(i,j,1,' ');
				//fields[i][j]=' ';
			fields[i][j]=f1;
		}
	}
	//Field f1(4,0,2,'X');
	//fields[4][0]= f1;

	//Field f3(1,5,2,'X');
	//fields[1][5]= f3;
	//Field f3(6,4,2,'X');
	//fields[6][4]= f3;
				//fields[i][j]=' ';
				//fields[i][j]=f1;
	Field f2(1,7,3,'O');
	fields[1][7]= f2;

	turn ='O';
}



Board::~Board()
{
std::cout<<"Board destructed"<<std::endl;
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

const int Board::range_of_move(Field start, Field destination)
{
	return abs(start.get_x()-destination.get_x());
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
			if(fields[i][j].get_sign()==turn)
				h++;
		}
	}
	return h;
}

const bool Board::is_move_forward(Field start, Field destination)
{
	if(fields[start.get_x()][start.get_y()].get_sign()=='X')
	{
		if(destination.get_x()<start.get_x())
		{
			return true;
		}else
		{
			return false;
		}
	}

	if(fields[start.get_x()][start.get_y()].get_sign()=='O')
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

void Board::display_data()
{
	for(int i=0;i<fields.size();i++)
	{
		for(int j=0;j<fields[i].size();j++)
		{
			std::cout<<fields[i][j]<<std::endl;
		}
	}
}
void Board::update_kings()
{
	for(int i=0;i<fields.size();i++)
	{
		for(int j=0;j<fields[i].size();j++)
		{
			if(fields[i][j].get_sign() == 'X') // if X
			{
				if(fields[i][j].get_x() == 0)
				{
					fields[i][j].set_to_king();
				}
			}else if(fields[i][j].get_sign() == 'O') // if O
			{
				if(fields[i][j].get_x() == 7)
				{
					fields[i][j].set_to_king();
				}
			}
		}
	}
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
			if(fields[i][j].get_sign()==turn)
			{
				//std::cout<<"Point->"<<Field(i+1,j+1)<<std::endl;
				possible_moves[h].emplace_back(i,j,fields[i][j].get_type(),fields[i][j].get_sign());
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



for(int i=0;i<possible_moves.size();i++)
	{
		if(possible_moves[i][0].get_type() == 2) // IF NORMAL PAWN
		{
			if(possible_moves[i][0].get_x()-1 >= 0  && possible_moves[i][0].get_y() -1 >=0 ) // If we are not going out of array
			{
				if(fields[possible_moves[i][0].get_x()-1][possible_moves[i][0].get_y()-1].get_sign() == ' ' )//left top
				{
					Field f1(possible_moves[i][0].get_x()-1,possible_moves[i][0].get_y()-1,1,' '); // left top field
					if(is_move_forward(possible_moves[i][0],f1)) // IS MOVE FORWARD!!!
					{
						possible_moves[i].emplace_back(f1);
					}
				}	
			}
			
			if(possible_moves[i][0].get_x()+1 <= 7 && possible_moves[i][0].get_y()-1 >= 0)// If we are not going out of array
			{
				if(fields[possible_moves[i][0].get_x()+1][possible_moves[i][0].get_y()-1].get_sign() == ' ' )//left bottom
				{
					Field f1(possible_moves[i][0].get_x()+1,possible_moves[i][0].get_y()-1,1,' '); // left bottom field
					if(is_move_forward(possible_moves[i][0],f1)) // IS MOVE FORWARD!!!
					{
						possible_moves[i].emplace_back(f1);
					}
				}
			}
			if(possible_moves[i][0].get_x()-1 >= 0 && possible_moves[i][0].get_y()+1 <= 7)// If we are not going out of array
			{
				if(fields[possible_moves[i][0].get_x()-1][possible_moves[i][0].get_y()+1].get_sign() == ' ' )//right top
				{
					Field f1(possible_moves[i][0].get_x()-1,possible_moves[i][0].get_y()+1,1,' '); // right top field
					if(is_move_forward(possible_moves[i][0],f1)) // IS MOVE FORWARD!!!
					{
						possible_moves[i].emplace_back(f1);
					}
				}	
			}
			if(possible_moves[i][0].get_x()+1 <= 7 && possible_moves[i][0].get_y()+1 <= 7)// If we are not going out of array
			{
				if(fields[possible_moves[i][0].get_x()+1][possible_moves[i][0].get_y()+1].get_sign() == ' ' )//right bottom
				{
					Field f1(possible_moves[i][0].get_x()+1,possible_moves[i][0].get_y()+1,1,' '); // right bottom field
					if(is_move_forward(possible_moves[i][0],f1)) // IS MOVE FORWARD!!!
					{
						possible_moves[i].emplace_back(f1);
					}
				}
			}
		}else if(possible_moves[i][0].get_type() == 3) // When its a KING
		{
			// LEFT TOP!!!!
			int k=1;
			while(possible_moves[i][0].get_x()-k >= 0  && possible_moves[i][0].get_y() -k >=0  ) // If we are not going out of array
			{
				if(fields[possible_moves[i][0].get_x()-k][possible_moves[i][0].get_y()-k].get_sign() == ' ' )//left top
				{
					Field f1(possible_moves[i][0].get_x()-k,possible_moves[i][0].get_y()-k,1,' '); // left top field
					possible_moves[i].emplace_back(f1);
				}else
				{
					break;
				}
				k++;
			}

			// TODO: ALL DIRECTIONS!!!!!!////////////////////////////////////////////////////////////////////////
			/////// LEFT BOTTOM	
			////// RIGHT TOP
			/////// RIGHT BOTTOM
		}	
	}

///////////////////////////////////////////////////////////////////

//	std::cout<<"WYSWIETLAM MOZLIWOSCI!!!"<<std::endl;
// print
	//std::cout<<"Ilosc pionkow: "<<possible_moves.size()<<std::endl;
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
			if(fields[i][j].get_sign()==turn)
			{
				//std::cout<<"Point->"<<Field(i+1,j+1)<<std::endl;
				possible_captures[h].emplace_back(i,j,fields[i][j].get_type(),fields[i][j].get_sign());
				h++;
			}
		}
	}

	for(int i=0;i<possible_captures.size();i++)
	{

		if(possible_captures[i][0].get_type() == 2) // NORMAL PAWN
		{
			if(possible_captures[i][0].get_x()-2 >= 0  && possible_captures[i][0].get_y() -2 >=0 ) // If we are not going out of array
			{
				if(fields[possible_captures[i][0].get_x()-1][possible_captures[i][0].get_y()-1].get_sign() == next_turn() )//left top
				{
					if(fields[possible_captures[i][0].get_x()-2][possible_captures[i][0].get_y()-2].get_sign() == ' ')				
					{
						possible_captures[i].emplace_back(possible_captures[i][0].get_x()-2,possible_captures[i][0].get_y()-2);
					}
				}	
			}
			if(possible_captures[i][0].get_x()+2 <= 7 && possible_captures[i][0].get_y()-2 >= 0)// If we are not going out of array
			{
				if(fields[possible_captures[i][0].get_x()+1][possible_captures[i][0].get_y()-1].get_sign() == next_turn() )//left bottom
				{
					if(fields[possible_captures[i][0].get_x()+2][possible_captures[i][0].get_y()-2].get_sign() == ' ')				
					{
						possible_captures[i].emplace_back(possible_captures[i][0].get_x()+2,possible_captures[i][0].get_y()-2);
					}
				}
			}
			if(possible_captures[i][0].get_x()-2 >= 0 && possible_captures[i][0].get_y()+2 <= 7)// If we are not going out of array
			{
				if(fields[possible_captures[i][0].get_x()-1][possible_captures[i][0].get_y()+1].get_sign() == next_turn() )//right top
				{
					
					if(fields[possible_captures[i][0].get_x()-2][possible_captures[i][0].get_y()+2].get_sign() == ' ')				
					{
						possible_captures[i].emplace_back(possible_captures[i][0].get_x()-2,possible_captures[i][0].get_y()+2);
					}
				}	
			}
			if(possible_captures[i][0].get_x()+2 <= 7 && possible_captures[i][0].get_y()+2 <= 7)// If we are not going out of array
			{
				if(fields[possible_captures[i][0].get_x()+1][possible_captures[i][0].get_y()+1].get_sign() == next_turn() )//right bottom
				{
					if(fields[possible_captures[i][0].get_x()+2][possible_captures[i][0].get_y()+2].get_sign() == ' ')				
					{
						possible_captures[i].emplace_back(possible_captures[i][0].get_x()+2,possible_captures[i][0].get_y()+2);
					}
				}
			}
		}
		/////////////////////////////////////////////////////TODO: when 2 X in row !!
		else if(possible_captures[i][0].get_type() == 3) // When its a KING
		{
			std::cout<<"THERE IS A KING!"<<std::endl;
			////////LEFT TOP
			int k = 2;
			while(possible_captures[i][0].get_x()-k  >= 0  && possible_captures[i][0].get_y() -k >= 0 ) // If we are not going out of array
			{
				if(fields[possible_captures[i][0].get_x()-k+1][possible_captures[i][0].get_y()-k+1].get_sign() == next_turn() )//left top == next turn
				{
					if(fields[possible_captures[i][0].get_x()-k][possible_captures[i][0].get_y()-k].get_sign() == ' ')	// next to left top is free			
					{
						if(k==2)
						{
							possible_captures[i].emplace_back(possible_captures[i][0].get_x()-k,possible_captures[i][0].get_y()-k);	
						}else if(k>2)
						{
							if(fields[possible_captures[i][0].get_x()-k+2][possible_captures[i][0].get_y()-k+2].get_sign() == ' ') // before to left top is free
							{
								possible_captures[i].emplace_back(possible_captures[i][0].get_x()-k,possible_captures[i][0].get_y()-k);
							}
						}
						
	
					}
				}
				k++;
			}

			/////// LEFT BOTTOM
			k = 2;
			while(possible_captures[i][0].get_x()+k <= 7 && possible_captures[i][0].get_y()-k >= 0)// If we are not going out of array
			{
				if(fields[possible_captures[i][0].get_x()+k-1][possible_captures[i][0].get_y()-k+1].get_sign() == next_turn() )//left bottom
				{
					if(fields[possible_captures[i][0].get_x()+k][possible_captures[i][0].get_y()-k].get_sign() == ' ') // field i want to jump				
					{
						if(k==2)
						{
							possible_captures[i].emplace_back(possible_captures[i][0].get_x()+k,possible_captures[i][0].get_y()-k);	
						}else if(k>2)
						{
							if(fields[possible_captures[i][0].get_x()+k-2][possible_captures[i][0].get_y()-k+2].get_sign() == ' ') // before to left bottom is free
							{
								possible_captures[i].emplace_back(possible_captures[i][0].get_x()+k,possible_captures[i][0].get_y()-k);
							}
						}
					}
				}
				k++;
			}
			////// RIGHT TOP
			k = 2;
			while(possible_captures[i][0].get_x()-k >= 0 && possible_captures[i][0].get_y()+k <= 7)// If we are not going out of array
			{
				if(fields[possible_captures[i][0].get_x()-k+1][possible_captures[i][0].get_y()+k-1].get_sign() == next_turn() )//right top
				{	
					if(fields[possible_captures[i][0].get_x()-k][possible_captures[i][0].get_y()+k].get_sign() == ' ')		// field i want to jump		
					{
						
						if(k==2)
						{
							possible_captures[i].emplace_back(possible_captures[i][0].get_x()-k,possible_captures[i][0].get_y()+k);
						}else if(k>2)
						{
							if(fields[possible_captures[i][0].get_x()-k+2][possible_captures[i][0].get_y()+k-2].get_sign() == ' ') // before to right top is free
							{
								possible_captures[i].emplace_back(possible_captures[i][0].get_x()-k,possible_captures[i][0].get_y()+k);
							}
						}
						
					}
				}
				k++;	
			}
			


			/////// RIGHT BOTTOM
			k = 2;
			while(possible_captures[i][0].get_x()+k <= 7 && possible_captures[i][0].get_y()+k <= 7)// If we are not going out of array
			{
				if(fields[possible_captures[i][0].get_x()+k-1][possible_captures[i][0].get_y()+k-1].get_sign() == next_turn() )//right bottom
				{
					if(fields[possible_captures[i][0].get_x()+k][possible_captures[i][0].get_y()+k].get_sign() == ' ')		 // field i want to jump				
					{

						if(k==2)
						{
							possible_captures[i].emplace_back(possible_captures[i][0].get_x()+k,possible_captures[i][0].get_y()+k);
						}else if(k>2)
						{
							if(fields[possible_captures[i][0].get_x()+k-2][possible_captures[i][0].get_y()+k-2].get_sign() == ' ') // before to right bottom is free
							{
								possible_captures[i].emplace_back(possible_captures[i][0].get_x()+k,possible_captures[i][0].get_y()+k);
							}
						}
					}
				}
				k++;
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
		Field f1(destination.get_x()+1,destination.get_y()+1,1,' ');
		fields[destination.get_x()+1][destination.get_y()+1]=f1;
		//fields[destination.get_x()+1][destination.get_y()+1].set_2(1,' ');// = ' ';
	}else if(start.get_x()>destination.get_x() && start.get_y()<destination.get_y()) // capture was in RIGHT TOP direction
	{
		//fields[destination.get_x()+1][destination.get_y()-1].set_2(1,' ');// = ' ';
		Field f1(destination.get_x()+1,destination.get_y()-1,1,' ');
		fields[destination.get_x()+1][destination.get_y()-1]=f1;
	}else if(start.get_x()<destination.get_x() && start.get_y()>destination.get_y()) // capture was in LEFT BOTTOM direction
	{
		//fields[destination.get_x()-1][destination.get_y()+1].set_2(1,' ');// = ' ';
		Field f1(destination.get_x()-1,destination.get_y()+1,1,' ');
		fields[destination.get_x()-1][destination.get_y()+1]=f1;
	}else if(start.get_x()<destination.get_x() && start.get_y()<destination.get_y()) // capture was in RIGHT BOTTOM direction
	{
		//fields[destination.get_x()-1][destination.get_y()-1].set_2(1,' ');// = ' ';
		Field f1(destination.get_x()-1,destination.get_y()-1,1,' ');
		fields[destination.get_x()-1][destination.get_y()-1]=f1;
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

void Board::move()
{
	//print_possible_moves();
	update_possible_captures();
	update_possible_moves();
	//std::cout<<"NUMBER OF PAWNS->"<<number_of_actual_turn_pawns()<<std::endl;
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
		Field new_place_for_pawn(where.get_x(),where.get_y(),fields[which.get_x()][which.get_y()].get_type(),fields[which.get_x()][which.get_y()].get_sign());
		fields[where.get_x()][where.get_y()]=new_place_for_pawn;

		Field tmp(which.get_x(),which.get_y(),1,' ');
		fields[which.get_x()][which.get_y()]=tmp;
	}

////////////////////////////DOIING MOVE!/////////////////////////////
	//


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
			std::cout<<"|"<<fields[i][j].get_sign();
		}
		std::cout<<"|"<<std::endl;
	}

	std::cout<<"   +-+-+-+-+-+-+-+-+"<<std::endl;
}