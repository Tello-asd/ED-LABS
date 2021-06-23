/* Alejandro López-Tello Mora
* Juan Jesus Martos Escribano
*
* G08
*/
#include "Header.h"
#include <iostream>
using namespace std;

int main() {
	int nOfCases;
	cin >> nOfCases;
	int i = 0;
	while (i < nOfCases) {
		int p1_x, p1_y, p2_x, p2_y, c_x, c_y;
		cin >> p1_x;
		cin >> p1_y;
		cin >> p2_x;
		cin >> p2_y;
		cin >> c_x; //x center point
		cin >> c_y; //Y center point
		Circle c(p1_x, p1_y, p2_x, p2_y);
		int area = c.area();
		cout << area << " ";
		bool inCircle = c.insideTheCircle(c_x, c_y);
		if (inCircle) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
		i++;
	}
	return 0;
}
