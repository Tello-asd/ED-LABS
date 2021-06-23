/*
I08 - Alejandro López-Tello Mora, Juan Jesus Martos Escribano
*/
#include <iostream>
#include "StackLL.h"
using namespace std;

void balanced() {
    StackLL<char>pile;
    char aux, n;

    bool valid = true;

    cin >> n;
    while (n != '\r' && n != '\n' && valid == true) {
        if (n == '[' || n == '{' || n == '(') {
            pile.push(n);
        }
        else if (n == ']' || n == '}' || n == ')') {
            if (pile.numElems() == 0) {
                valid = false;
            }
            else {
                aux = pile.top();

                if (n == ']' && aux == '[') {
                    pile.pop();
                }
                else if (n == '}' && aux == '{') {
                    pile.pop();
                }
                else if (n == ')' && aux == '(') {
                    pile.pop();
                }
                else {
                    valid = false;
                }
            }
        }

        cin.get(n);
    }

    if (n != '\r' && n != '\n') {
        while (n != '\r' && n != '\n') {
            cin.get(n);
        }
    }

    if (pile.numElems() > 0) {
        valid = false;
    }

    if (valid) {
        cout << "yes\n";
    }
    else {
        cout << "no\n";
    }
}

void solveCase() {
    int n;

    cin >> n;
    while (n > 0) {
        balanced();
        n--;
    }
}

int main() {

    solveCase();

    return 0;
}
