#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "field.h"

class Move{
	Field start;
	Field destination;

public:

	Move();
	Move(Field start1, Field destinaton1);

	Field get_start();
	Field get_destination();

	friend std::ostream& operator<<(std::ostream& os, const Move& m) {os <<"BOT MOVED FROM: "<<m.start<<" TO:"<<m.destination<<std::endl;return os;}
};



#endif //MOVE_H