#include "SeqList.h"

SeqList::SeqList() {
    length = 0;
}

void SeqList::readFromFile(string filename) {
    ifstream in(filename);
    if (!in) {
        cerr << "Error: cannot open file" << endl;
        exit(1);
    }
    string name;
    int id, grade;
    while (in >> name >> id >> grade) {
        seqlist::Student s = { name, id, grade };
        insert(s);
    }
}

void SeqList::writeToFile(string filename) {
    ofstream out(filename);
    if (!out) {
        cerr << "Error: cannot open file" << endl;
        exit(1);
    }
    for (int i = 0; i < length; i++) {
        out << data[i].name << " " << data[i].id << " " << data[i].grade << endl;
    }
}

void SeqList::insert(seqlist::Student s) {
    if (length == MAXSIZE) {
        cerr << "Error: list is full" << endl;
        return;
    }
    data[length++] = s;
}

void SeqList::deleteById(int id) {
    int i;
    for (i = 0; i < length; i++) {
        if (data[i].id == id) break;
    }
    if (i == length) {
        cerr << "Error: student not found" << endl;
        return;
    }
    for (int j = i; j < length - 1; j++) {
        data[j] = data[j + 1];
    }
    length--;
}

void SeqList::updateById(int id, seqlist::Student s) {
    int i;
    for (i = 0; i < length; i++) {
        if (data[i].id == id) break;
    }
    if (i == length) {
        cerr << "Error: student not found" << endl;
        return;
    }
    data[i] = s;
}

seqlist::Student* SeqList::searchById(int id) {
    for (int i = 0; i < length; i++) {
        if (data[i].id == id) return &data[i];
    }
    return nullptr;
}

void SeqList::display() {
    for (int i = 0; i < length; i++) {
        cout << data[i].name << " " << data[i].id << " " << data[i].grade << endl;
    }
}