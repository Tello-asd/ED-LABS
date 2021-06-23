/*
        I08 - Alejandro López-Tello Mora
              Juan Jesus martos Escribano
*/
#ifndef LAWFIRM_H_
#define LAWFIRM_H_

#include "Table.h"
#include <string>
#include "List.h"
#include <iostream>

using namespace std;

class Inexistent_Case{};
class ThereAreNo_Cases{};

class LawFirm {
private:
    typedef struct{
        string name;
        string type;
        int priority;
    } t_case;

    Table<string, t_case> registro_cases;
    List<string> high_priority;
    List<string> med_priority;
    List<string> low_priority;
    string removeId = " ";

public:

    void add_case (string id, string name, string type, int priority) {
        if (priority == 0) {
            //push the id in the high priority list
            this->high_priority.push_front(id);
        }
        else if(priority == 1) {
            //push the id in the medium priority list
            this->med_priority.push_front(id);
        }
        else {
            //push the id in the low priority list
            this->low_priority.push_front(id);
        }

        t_case info;
        info.priority = priority;
        info.name = name;
        info.type = type;
        this->registro_cases.insert(id,info);
        removeId = id;
    }

    string getCase(string id) {
        string nametype, name, type;

        try {
            if (!this->registro_cases.exists(id)) { //if exists id
                throw Inexistent_Case();
            }
            else {
                name = this->registro_cases.get(id).name;
                type = this->registro_cases.get(id).type;
                nametype = name + " " + type;

            }
        }
        catch(Inexistent_Case &e) {
            cout << "This case does not exist" << endl;
        }

        return nametype;
    }

    string nextCase() {
        string id, idpriority;
        int priority;

        try {
            //if not empty, takes the id and priority
            if (!this->high_priority.empty()) {
                id = this->high_priority.back();
                priority = 0;
            }
            else if (!this->med_priority.empty()) {
                id = this->med_priority.back();
                priority = 1;
            }
            else if (!this->low_priority.empty()) {
                id = this->low_priority.back();
                priority = 2;
            }
            else {
                throw ThereAreNo_Cases();
            }

            idpriority = id + " " + to_string(priority);

            removeId = id; //id for removing later on
            return idpriority;
        }
        catch (ThereAreNo_Cases &e) {
            cout << "There are no cases" << endl;
        }

        return idpriority;
    }

    bool empty() {
        return !this->high_priority.empty() || !this->low_priority.empty() || !this->med_priority.empty();
    }

    void removeNextCase() {

        if (!this->high_priority.empty()) {
            //if the last id was the same than the first from high priority list
            if (removeId == this->high_priority.back()) {
                this->high_priority.pop_back();
            }
        }
        if (!this->med_priority.empty()) {
            //if the last id was the same than the first from medium priority list
            if (removeId == this->med_priority.back()) {
                this->med_priority.pop_back();
            }
        }

        if (!this->low_priority.empty()) {
            //if the last id was the same than the first from low priority list
            if (removeId == this->low_priority.back()) {
                //cout << this->low_priority.back() << endl;
                this->low_priority.pop_back();
                //cout << this->low_priority.back() << endl;

            }
        }

        this->registro_cases.remove(removeId);

    }

};


#endif