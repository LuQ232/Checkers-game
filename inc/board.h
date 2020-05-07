#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 8


#include <iostream>
#include <vector>
#include <cmath>

#include "field.h"

class Board{

	std::vector<std::vector<char>> fields;
	char turn;

	public:
	Board();
	~Board();
	void display();
	void change_turn();
	void move();
	const int range_of_move(Field start, Field destination);
	bool is_move_possible(Field start, Field destination);




		
};

#endif //BOARD_H