#ifndef FIELD_H
#define FIELD_H

#include <iostream>


class Field{
int x,y;

public:
	Field();
	Field(int x1,int x2);
	void set(int x1,int y1);
	const int get_x();
	const int get_y();
	friend std::ostream& operator<<(std::ostream& os, const Field& f){os <<"ROW: "<< f.x+1 << "| COL:" << f.y+1 << "|";//<<std::endl;
    return os;}
};



#endif //FIELD_H