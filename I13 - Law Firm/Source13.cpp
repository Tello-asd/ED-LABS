/*
		I08 - Alejandro López-Tello Mora
			  Juan Jesus martos Escribano
*/
#include <iostream>
#include <string>
#include "lawFirm.h"

using namespace std;

int main() {
    int numCases;
    cin >> numCases;

    for (int i = 0; i < numCases; ++i) {
        LawFirm lf = LawFirm();
        int numLines;

        cin >> numLines;
        for (int j = 0; j < numLines; ++j) {

            string command;
            cin >> command;
            if (command == "add") {
                string id, name, type;
                int priority;
                cin >> id >> name >> type >> priority;
                lf.add_case(id,name,type,priority);

            }
            else if (command == "get") {
                string id;
                cin >> id;
                string result = lf.getCase(id);
                cout << result << endl;
            }
            else if (command == "next") {
                string result = lf.nextCase();
                cout << result << endl;
            }
            else if (command == "remove") {
                lf.removeNextCase();
            }
            else if (command == "empty") {
                bool result = lf.empty();
                if (result) {
                    cout << "no" << endl;
                }
                else {
                    cout << "yes" << endl;
                }
            }
        }
    }

    return 0;
}
