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

bool Board::is_move_possible(Field start, Field destination)
{
	//TO GET ACTUA DATA REMEMBER ABOUT get_x-1!!!! -1!!!
	//std::cout<<"TEST"<<std::endl;
	//std::cout<<"Actual turn its ->"<<turn<<std::endl;
	//std::cout<<"Choosen pawn->"<<fields[start.get_x()-1][start.get_y()-1];
	if(turn==fields[start.get_x()-1][start.get_y()-1]) // IF YOUR PAWN CHOOSEN
	{
		if(range_of_move(start,destination)==1) // IF RANGE IS GOOD
		{
			//TODO - ALL CASES
			//std::cout<<"RANGE OF MOVE WAS->"<<range_of_move(start,destination)<<std::endl;
			
			return true;
		}else
		{
			std::cout<<"YOU CANT MOVE THAT FAR!!"<<std::endl;
			return false;
		}
		
	}else
	{
		std::cout<<"IT'S NOT YOUR PAWN! / IT'S NOT PAWN!"<<std::endl;
		return false;
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
	Field which;
	Field where;
	int which_i,which_j,where_i,where_j;
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
	which.set(which_i,which_j);
	where.set(where_i,where_j);
	std::cout<<std::endl;
	}while(!is_move_possible(which,where));

	

	if(is_move_possible(which,where))
	{
		std::cout<<std::endl<<"Move is possible"<<std::endl;
		fields[where_i-1][where_j-1]=turn;
		fields[which_i-1][which_j-1]=' ';
	}
////////////////////////////DOIING MOVE!/////////////////////////////
	//


}