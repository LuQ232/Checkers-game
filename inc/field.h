#ifndef FIELD_H
#define FIELD_H

#include <iostream>


class Field{
int x,y; // Coordinates
int type; // 1 - free space ; 2 - normal pawn; 3 - King
char sign; // 1 - X ; 2- O; 3- ' '
public:
	Field();
	Field(int x1,int x2);
	Field(int x1,int x2,int type2,char sign2);
	void set(int x1,int y1);
	void set_2(int type2,char sign2);
	void set_sign(char sign2);
	void set_to_king();
	const int get_x();
	const int get_y();
	const int get_type();
	const char get_sign();
	//friend std::ostream& operator<<(std::ostream& os, const Field& f){os<<"|ROW: "<< f.x+1 << " COL:" << f.y+1 << "|";//<<std::endl;
    friend std::ostream& operator<<(std::ostream& os, const Field& f){os <<"|TYPE: "<<f.type<<"ROW: "<< f.x+1 << " COL:" << f.y+1 << "|";//<<std::endl;
    return os;}
};



#endif //FIELD_H