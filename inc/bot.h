#ifndef BOT_H
#define BOT_H

#include <iostream>
#include <vector>

#include "field.h"
#include "move.h"

class Bot{

public:

	Move return_move(std::vector<std::vector<Field>> vector_of_possible_moves,std::vector<std::vector<Field>> vector_of_possible_captures,bool is_capture_mandatory);


};



#endif //BOT_H