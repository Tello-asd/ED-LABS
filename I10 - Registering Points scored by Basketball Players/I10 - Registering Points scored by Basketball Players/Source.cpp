/*
    I08 - Alejandro López-Tello Mora
          Juan jesus MArtos Escribano 
*/
#include <iostream>
#include <string>
#include "SearchTree.h"

void registeringPoints() {
    SearchTree<std::string, int> st = SearchTree<std::string, int>();
    std::string key;
    int value = 0, num = 0;
    std::cin >> num;

    if (num == 0) { //check if 0
        std::cout << std::endl;
    }
    for (int i = 0; i < num; ++i) {
        std::cin >> key;
        std::cin >> value;

        if (!st.exists(key)) {
            st.insert(key, value);
        }
        else { //if exists, replace with new value
            int newValue = 0;
            newValue = st.get(key);
            newValue = value + newValue;
            st.insert(key, newValue);
        }
    }

    SearchTree<std::string, int>::Iterator it = st.begin();
    while (it != st.end()) {
        std::cout << "(" << it.key() << ":" << it.value() << ")";
        it.next();
    }

    std::cout << std::endl;
}

int main()
{
    int numTestCases;
    std::cin >> numTestCases;

    if (numTestCases != -1) {
        for (int i = 0; i < numTestCases; ++i) {
            registeringPoints();
        }
    }

    return 0;
}