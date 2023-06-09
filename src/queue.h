#pragma once
#include <string>
#include <fstream>
#include <vector>
#include "studentsStruct.h"

class Queue {
public:
    Queue();
    ~Queue();
    void enqueue(const queue::Student& student);
    queue::Student dequeue();
    bool isEmpty() const;
    void readFromFile(const std::string& filename);
    void writeToFile(const std::string& filename) const;
private:
    std::vector<queue::Student> students;
};

