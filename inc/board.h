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
	std::vector<std::vector<Field>> possible_captures;
	std::vector<std::vector<Field>> possible_moves;


	public:
	Board();
	~Board();
	void display();
	void change_turn();
	char actual_turn();
	char next_turn();

	int number_of_actual_turn_pawns();
	
	void move();

	void update_possible_captures();
	const bool is_any_capture_mandatory();
	void update_possible_moves();
	const int range_of_move(Field start, Field destination);
	const bool is_move_possible(Field start, Field destination);
	const bool is_move_forward(Field start, Field destination);


		
};

#endif //BOARD_H