#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "studentsStruct.h"
using namespace std;

const int MAXSIZE = 100;

class SeqList {
public:
    SeqList();
    void readFromFile(string filename);
    void writeToFile(string filename);
    void insert(seqlist::Student s);
    void deleteById(int id);
    void updateById(int id, seqlist::Student s);
    seqlist::Student* searchById(int id);
    void display();
private:
    seqlist::Student data[MAXSIZE];
    int length;
};