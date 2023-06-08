#include "studentsStruct.h"
#include <fstream>
#include <iostream>
#include "linkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    while (head) {
        linkedlist::Student* current = head;
        head = head->next;
        delete current;
    }
}

void LinkedList::insert(const std::string& name, int id, int grade) {
    linkedlist::Student* newStudent = new linkedlist::Student;
    newStudent->name = name;
    newStudent->id = id;
    newStudent->grade = grade;
    newStudent->next = nullptr;

    if (!head) {
        head = newStudent;
    }
    else {
        linkedlist::Student* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newStudent;
    }
}

void LinkedList::remove(int id) {
    if (!head) {
        std::cout << "List is empty. Cannot remove student.\n";
        return;
    }

    if (head->id == id) {
        linkedlist::Student* current = head;
        head = head->next;
        delete current;
        return;
    }

    linkedlist::Student* current = head;
    while (current->next) {
        if (current->next->id == id) {
            linkedlist::Student* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }
        current = current->next;
    }

    std::cout << "Student with ID " << id << " not found.\n";
}

void LinkedList::update(int id, const std::string& name, int grade) {
    linkedlist::Student* student = search(id);
    if (student) {
        student->name = name;
        student->grade = grade;
        std::cout << "Student with ID " << id << " updated.\n";
    }
    else {
        std::cout << "Student with ID " << id << " not found.\n";
    }
}

linkedlist::Student* LinkedList::search(int id) {
    linkedlist::Student* current = head;
    while (current) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void LinkedList::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return;
    }

    // Read file and populate the linked list
    // ...
}

void LinkedList::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return;
    }

    // Write linked list to file
    // ...
}
