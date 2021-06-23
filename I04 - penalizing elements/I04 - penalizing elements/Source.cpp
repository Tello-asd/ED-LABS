//I08
#include "Exceptions.h"
#include <iostream>
#include "Queue.h"

int main() {
	Queue<int> elements;
	int numCases;
	std::cin >> numCases;
	
	for (int i = 0; i < numCases; i++) {
		int penalized_elem, num;
		std::cin >> num;
		for (int j = 0; j < num; j++) {
			int x;
			std::cin >> x;
			elements.push(x);
		}
		std::cin >> penalized_elem;
		elements.penalizeElem(penalized_elem);

		//output the stack
		for (int z = 0; z < num; z++) {
			std::cout << elements.front() << " ";
			elements.pop();
		}
	}

	return 0;
}