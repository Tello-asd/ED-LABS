/*
I08 - Alejandro López-Tello Mora
      Juan Jesus Martos Escribano
*/

#include <iostream>
#include "Bintree.h"
#include "List.h"
using namespace std;


Bintree<int> readBintree();

int specialNodeAux(Bintree<int> t, int antecessors, int& descendants) {


    if (t.empty()) {
        descendants = 1;
        return 0;
    }

    //operaciones al bajar en la recursion
    int num = t.root();

    int descendants_iz;
    int descendants_der;
    int singular_nodes_iz = specialNodeAux(t.leftChild(), antecessors * num, descendants_iz);
   
    //los que bajan no hace falta que sea &, es mas no lo coge bien.
    int singular_nodes_dr = specialNodeAux(t.rightChild(), antecessors * num, descendants_der);

    int singular_nodes = singular_nodes_iz + singular_nodes_dr;

    //operaciones al subir en la recursion
    if (descendants_der * descendants_iz == antecessors) {
        singular_nodes++;
    }

    descendants = descendants_der * descendants_iz * t.root();


    return singular_nodes;

}

int specialNode(Bintree<int> t, int& special_nodes) {
    int antProd = 1;
    int descProd = 1;
    return specialNodeAux(t, antProd, descProd);

}

int main()
{
    int numTestCases;
    cin >> numTestCases;

    if (numTestCases != -1) {
        for (int i = 0; i < numTestCases; ++i) {

            Bintree<int> t = readBintree();
            int sumSpecialNodes;

            if (!t.empty()) {
                sumSpecialNodes = specialNode(t, sumSpecialNodes);

            }
            else {
                sumSpecialNodes = 0;
            }
            cout << sumSpecialNodes << endl;
        }
    }

    return 0;
}

// It reads a binary tree of integers from the standard input
Bintree<int> readBintree() {
    char c;
    cin >> c;
    switch (c) {
    case '#': return Bintree<int>();
    case '[': {
        int raiz;
        cin >> raiz;
        cin >> c;
        return Bintree<int>(raiz);
    }
    case '(': {
        Bintree<int> left = readBintree();
        int root;
        cin >> root;
        Bintree<int> right = readBintree();
        cin >> c;
        return Bintree<int>(left, root, right);
    }
    default:
        return Bintree<int>();
    }
}