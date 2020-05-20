#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 8


#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>

#include "field.h"
#include "bot.h"

class Board{

	std::vector<std::vector<Field>> fields;
	std::vector<std::vector<Field>> possible_captures;
	std::vector<std::vector<Field>> possible_moves;
	
	char turn;
	bool was_capture = false;

	public:
	Board();
	~Board();

	char actual_turn();
	char next_turn();

	void display();
	void display_data();
	void display_possible_moves();
	void display_possible_captures();
	void display_info_about_kings();
	
	void change_turn();
	void move();
	void pawn_place_change(Field which, Field where);
	
	void update_kings();
	void update_possible_captures();
	void update_possible_moves();
	void update_possible_captures(Field start); // after first capture
	void update_possible_moves(Field start); // after first capture

	void reset_capture_data();
	void delete_captured_pawn(Field start, Field destination);
	
	const bool is_any_capture_mandatory();
	const bool is_any_move_possible();
	const bool is_this_move_on_possible_captures(Field start, Field destination);
	const bool is_this_move_on_possible_moves(Field start, Field destination);
	const bool is_there_capture_for_pawn(Field start);
	const bool is_move_possible(Field start, Field destination);
	const bool is_move_forward(Field start, Field destination);
	const bool is_end_of_game();
	const bool was_capture_in_this_round();
	
	const int range_of_move(Field start, Field destination);
	const int number_of_actual_turn_pawns();

	Field read_move();
		
	std::vector<std::vector<Field>> return_vector_of_possible_moves();
	std::vector<std::vector<Field>> return_vector_of_possible_captures();

};

#endif //BOARD_H