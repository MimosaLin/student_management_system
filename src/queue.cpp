#include "queue.h"


Queue::Queue() {}

Queue::~Queue() {}

void Queue::enqueue(const queue::Student& student) {
    students.push_back(student);
}

queue::Student Queue::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    queue::Student frontStudent = students.front();
    students.erase(students.begin());
    return frontStudent;
}

bool Queue::isEmpty() const {
    return students.empty();
}

void Queue::readFromFile(const std::string& filename) {
    std::ifstream input(filename);
    if (!input.is_open()) {
        throw std::runtime_error("Failed to open file for reading");
    }
    students.clear();
    queue::Student student;
    int grade;
    while (input >> student.name >> student.id >> grade) {
        students.push_back(student);
    }
    input.close();
}

void Queue::writeToFile(const std::string& filename) const {
    std::ofstream output(filename);
    if (!output.is_open()) {
        throw std::runtime_error("Failed to open file for writing");
    }
    for (const auto& student : students) {
        output << student.name << ' ' << student.id << '\n';
    }
    output.close();
}
