#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Point.h"
#include "Square.h"
using namespace std;

// Point 클래스 정의
Point::Point(int px, int py) : x(px), y(py) {}
int Point::getX() const { return x; }
int Point::getY() const { return y; }
void Point::setX(int px) { x = px; }
void Point::setY(int py) { y = py; }

// Square 클래스 정의
Square::Square(const string n, int x, int y, unsigned int s)
    : Point(x, y), name(n), side(s) {
    area = s * s;
}
unsigned int Square::getSide() const { return side; }
unsigned int Square::getArea() const { return area; }
string Square::getName() const { return name; }
void Square::setSide(unsigned int s) { side = s; area = s * s; }
void Square::setArea(unsigned int a) { area = a; }
void Square::setName(string n) { name = n; }

// 출력 함수
void printSquares(const vector<Square>& squares, int type) {
    if (type == 1) {
        cout << "Squares in increasing order of area\n";
        for (auto& s : squares)
            cout << s.getName() << "(" << s.getX() << ", " << s.getY()
            << ") side=" << s.getSide() << ", area=" << s.getArea() << "\n";
    }
    else if (type == 2) {
        cout << "Squares in increasing order of max x-coordinate\n";
        for (auto& s : squares)
            cout << s.getName() << "(" << s.getX() + s.getSide() << ", " << s.getY()
            << ") side=" << s.getSide() << ", area=" << s.getArea() << "\n";
    }
    else if (type == 3) {
        cout << "Squares in increasing order of max y-coordinate\n";
        for (auto& s : squares)
            cout << s.getName() << "(" << s.getX() << ", " << s.getY() + s.getSide()
            << ") side=" << s.getSide() << ", area=" << s.getArea() << "\n";
    }
}

int main() {
    int n;
    cin >> n;

    vector<Square> squares;
    for (int i = 0; i < n; i++) {
        string name;
        int x, y;
        unsigned int side;
        cin >> name >> x >> y >> side;
        squares.emplace_back(name, x, y, side);
    }

    cout << "\n";

    // 1️⃣ 면적 오름차순
    vector<Square> areaSorted = squares;
    sort(areaSorted.begin(), areaSorted.end(),
        [](const Square& a, const Square& b) {
            return a.getArea() < b.getArea();
        });
    printSquares(areaSorted, 1);

    cout << "\n";

    // 2️⃣ 최대 x좌표 오름차순
    vector<Square> xSorted = squares;
    sort(xSorted.begin(), xSorted.end(),
        [](const Square& a, const Square& b) {
            return (a.getX() + a.getSide()) < (b.getX() + b.getSide());
        });
    printSquares(xSorted, 2);

    cout << "\n";

    // 3️⃣ 최대 y좌표 오름차순
    vector<Square> ySorted = squares;
    sort(ySorted.begin(), ySorted.end(),
        [](const Square& a, const Square& b) {
            return (a.getY() + a.getSide()) < (b.getY() + b.getSide());
        });
    printSquares(ySorted, 3);

    return 0;
}