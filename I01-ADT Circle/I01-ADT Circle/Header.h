/* Alejandro López-Tello Mora
* Juan Jesus Martos Escribano
* 
* G08
*/

#ifndef HEADER
#define HEADER
#pragma once

class Circle {
private:
	static const int MAX_VAL = 10000;
	static constexpr double n_pi = 3.1416;
	int _p1_x, _p1_y, _p2_x, _p2_y; //coordinates of the 2 points.
   /*
	* 
	* We've chosen to define the coordinates as 2 integers, _px_x and px_y. Dealing with more coordinates and point, we could posibly create a new header file, a 
	* new class that includes both coordinates. We supposed that for this case, this was enough
	*/

public:
	//Constructor
	Circle(int p1_x, int p1_y, int p2_x, int p2_y);
	
	//operation to calculate the radius of the circle - Observer
	int calculateRadius() const;
	
	//Returns true if the point is inside the circle - Observer
	bool insideTheCircle(const int& c1_x, const int& c1_y) const;
	
	//Calculate Observer method
	int area() const;//Pi*r²
};



#endif 