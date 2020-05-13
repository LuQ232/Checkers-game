#include "field.h"

Field::Field()
{
}
Field::Field(int x1, int x2)
{
	x=x1;
	y=x2;
}
void Field::set(int x1,int x2)
{
	x=x1;
	y=x2;
}

const int  Field::get_x()
{
	return x;
}

const int  Field::get_y()
{
	return y;
}