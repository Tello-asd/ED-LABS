#include <iostream>
#include "Bintree.h"
#include "List.h"
using namespace std;

Bintree<char> readBintree();

/*
 * The complexity of the algorithm is O(n): we are only checking each node of the tree once,
 * by recursion. 
 */

int breakingRestriction(Bintree<char> t, int& people, int& sum) {

    if (!t.empty()) {
        if (t.root() == 'P') { // if there is a person below, we assume it is breaking the law
            sum++;
            people++;
        }
        else if (t.root() == 'S') { // if there is a shop below, the assumption of breaking the law was false (if any)
            sum = sum - people; // so we subtract the persons (0 if there wasn't any)
            people = 0;
        }

        breakingRestriction(t.leftChild(), people, sum);
        breakingRestriction(t.rightChild(), people, sum);
    }

    return sum;
}

int main()
{
    int numTestCases;
    cin >> numTestCases;

    if (numTestCases != -1) {
        for (int i = 0; i < numTestCases; ++i) {

            Bintree<char> t = readBintree();
            int sum = 0;
            int p = 0;

            if (!t.empty()) {
                sum = breakingRestriction(t, p, sum);
            }
            else {
                sum = 0;
            }

            cout << sum << endl;
        }
    }

    return 0;
}

// It reads a binary tree of characters from the standard input
Bintree<char> readBintree() {
    char c;
    cin >> c;
    switch (c) {
    case '#': return Bintree<char>();
    case '[': {
        char raiz;
        cin >> raiz;
        cin >> c;
        return Bintree<char>(raiz);
    }
    case '(': {
        Bintree<char> left = readBintree();
        char root;
        cin >> root;
        Bintree<char> right = readBintree();
        cin >> c;
        return Bintree<char>(left, root, right);
    }
    default:
        return Bintree<char>();
    }
}



