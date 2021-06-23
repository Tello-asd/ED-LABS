/* Alejandro López-Tello Mora
* Juan Jesus Martos Escribano
*
* G08
*/
#include "Header.h"
#include <iostream>
#include <cmath>
using namespace std;


Circle::Circle(int p1_x, int p1_y, int p2_x, int p2_y) {
	_p1_x = p1_x;
	_p1_y = p1_y;
	_p2_x = p2_x;
	_p2_y = p2_y;

}
int Circle::calculateRadius() const {
	int r;
	if (_p1_x > 0 && _p2_x > 0) {
		r = (_p2_x - _p1_x) / 2;
	}
	if (_p1_x < 0 && _p2_x > 0) {
		r = (_p2_x + abs(_p1_x)) / 2;
	}
	if (_p1_x < 0 && _p2_x < 0) {
		r = (abs(_p2_x) - abs(_p1_x)) / 2;
	}
	return r;
}
//A point is inside a circle if the distance to the center is lower than the radius.
//Not completely sure if this is the right way to do it.
bool Circle::insideTheCircle(const int& c1_x, const int& c1_y) const {
	int r = calculateRadius();
	int center_x = _p2_x - r;
	int center_y = _p2_y;
	int dx = abs(c1_x - center_x);
	int dy = abs(c1_y - center_y);
	
	if (dx + dy <= r) {
		return true;
	}
	if (dx < r) {
		return false;
	}
	if (dy > r) {
		return false;
	}	
	else {
		return false;
	}
}


int Circle::area() const {//Area of circle = (Pi)r²
	int a, r;
	r = calculateRadius();
	a = n_pi * (pow(r, 2));
	return a;
}
