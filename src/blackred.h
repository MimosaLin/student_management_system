#pragma once

#include <string>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int studentID;
    string name;
    string gender;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int id, const string& n, const string& g);
};

class RedBlackTree {
private:
    Node* root;

public:
    RedBlackTree();
    void traverseTree(Node* node);
    Node* getRoot();
    void readStudentInfo(const string& filename);
    void insertStudent(int studentID, const string& name, const string& gender);
    void fixInsertion(Node* node);
    void rotateLeft(Node* node);
    void rotateRight(Node* node);
    void countGenders(int& numMale, int& numFemale);
    void countGendersHelper(Node* node, int& numMale, int& numFemale);
    Node* searchStudent(int studentID);
    void modifyStudent(int studentID, const string& newName, const string& newGender);
    void removeStudent(int studentID);
    void deleteNode(Node* node);
    Node* minimum(Node* node);
    void transplant(Node* u, Node* v);
    void fixDeletion(Node* node);
    void printStudentInfo(Node* node);
};



