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
    friend std::ostream& operator<<(std::ostream& os, const Field& f)
    {
    	char col;
    	if(f.y==0){col = 'A';}if(f.y==1){col = 'B';}if(f.y==2){col = 'C';}if(f.y==3){col = 'D';}if(f.y==4){col = 'E';}if(f.y==5){col = 'F';}if(f.y==6){col = 'G';}if(f.y==7){col = 'H';}
    os << "|"<<col << f.x+1 <<"|";//<<std::endl;
    return os;}
	/*
    friend std::ostream& operator<<(std::ostream& os, const Field& f)
    {
    	char col;
    	if(f.y==0){col = 'A';}if(f.y==1){col = 'B';}if(f.y==2){col = 'C';}if(f.y==3){col = 'D';}if(f.y==4){col = 'E';}if(f.y==5){col = 'F';}if(f.y==6){col = 'G';}if(f.y==7){col = 'H';}
    os <<"|TYPE: "<<f.type<< " COL:" << col << " ROW: "<< f.x+1 <<"|";//<<std::endl;
    return os;}
    */
};



#endif //FIELD_H