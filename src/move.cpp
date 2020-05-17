#include "move.h"

Move::Move()
{

}
Move::Move(Field start1, Field destination1)
{
	start = start1;
	destination = destination1;
}

Field Move::get_start()
{
	return start;
}

Field Move::get_destination()
{
	return destination;
}