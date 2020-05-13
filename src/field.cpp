#include "field.h"

Field::Field()
{
}
Field::Field(int x1, int x2)
{
	x = x1;
	y = x2;
}
Field::Field(int x1, int x2,int type2,char sign2)
{
	x = x1;
	y = x2;
	type = type2; 
	sign = sign2;
}
void Field::set(int x1,int x2)
{
	x=x1;
	y=x2;
}

void Field::set_2(int type2,char sign2)
{
	type = type2;
	sign = sign2;
}

void Field::set_sign(char sign2)
{
	sign = sign2;
}

void Field::set_to_king()
{
	type = 3;
}

const int  Field::get_x()
{
	return x;
}

const int  Field::get_y()
{
	return y;
}

const int Field::get_type()
{
	return type;
}

const char Field::get_sign()
{
	return sign;
}