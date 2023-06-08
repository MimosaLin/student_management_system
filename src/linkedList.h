#pragma once
#ifndef STUDENTSSTRUCT_H
#define STUDENTSSTRUCT_H

#include <string>
#include "studentsStruct.h"

class LinkedList {
private:
    linkedlist::Student* head;

public:
    LinkedList();
    ~LinkedList();
    void insert(const std::string& name, int id, int grade);
    void remove(int id);
    void update(int id, const std::string& name, int grade);
    linkedlist::Student* search(int id);
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename);
};

#endif  // STUDENTSSTRUCT_H
