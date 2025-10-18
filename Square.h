#ifndef SQUARE_H
#define SQUARE_H

#include "Point.h"
#include <string>
using namespace std;

class Square : public Point {
public:
    Square(const string name, int x, int y, unsigned int side = 0);
    unsigned int getSide() const;
    unsigned int getArea() const;
    string getName() const;

    void setSide(unsigned int);
    void setArea(unsigned int);
    void setName(string);

private:
    unsigned int side;
    unsigned int area{ 0 };
    string name;
};

#endif