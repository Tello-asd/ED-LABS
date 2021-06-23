/*
I08 -  Alejandro López-Tello Mora
       Juan Jesus Martos Escribano
 */

#include <iostream>
#include "Queue.h"
using namespace std;


template<class T>
class list :public Queue<T> {
    using Node = typename Queue<T>::Node;

public:

    int raffling(const int f) {
        Node* prev = this->_first;
        Node* node = this->_first;
        int j = this->_numElems;
        this->_last->_next = this->_first;
        int leader;

        while (j > 1) {
            for (int i = 1; i < f; i++) {
                prev = node;
                node = node->_next;
            }

            prev->_next = node->_next;
            node = node->_next;

            j--;
        }

        leader = node->_elem;
        this->_numElems = 0;
        this->_first = this->_last = NULL;

        return leader;
    }
};

int main() {

    list<int> members;
    int n, f;
    int leader;

    cin >> n;

    while (n != -1) {

            cin >> f;

            for (int i = 0; i < n; i++) {
                members.push(i + 1);
            }
            leader = members.raffling(f);    

        cout << leader << endl;

        cin >> n;
    }

    return 0;
}