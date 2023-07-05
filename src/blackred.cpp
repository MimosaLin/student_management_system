#include "blackred.h"
#include <iostream>
#include <fstream>
#include <sstream>

Node::Node(int id, const string& n, const string& g)
    : studentID(id), name(n), gender(g), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}

RedBlackTree::RedBlackTree() : root(nullptr) {}

void RedBlackTree::readStudentInfo(const string& filename) {
    ifstream file(filename);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            istringstream iss(line);
            string idStr, name, gender;
            getline(iss, idStr, ',');
            getline(iss, name, ',');
            getline(iss, gender, ',');

            int studentID = stoi(idStr);
            insertStudent(studentID, name, gender);
        }

        file.close();
    }
    else {
        cout << "Unable to open file: " << filename << endl;
    }
}

void RedBlackTree::insertStudent(int studentID, const string& name, const string& gender) {
    Node* newNode = new Node(studentID, name, gender);
    Node* parent = nullptr;
    Node* current = root;

    while (current != nullptr) {
        parent = current;

        if (studentID < current->studentID)
            current = current->left;
        else
            current = current->right;
    }

    newNode->parent = parent;

    if (parent == nullptr) {
        root = newNode;
    }
    else if (studentID < parent->studentID) {
        parent->left = newNode;
    }
    else {
        parent->right = newNode;
    }

    fixInsertion(newNode);
}

void RedBlackTree::fixInsertion(Node* node) {
    while (node != root && node->parent->color == RED) {
        if (node->parent == node->parent->parent->left) {
            Node* uncle = node->parent->parent->right;

            if (uncle != nullptr && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else {
                if (node == node->parent->right) {
                    node = node->parent;
                    rotateLeft(node);
                }

                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rotateRight(node->parent->parent);
            }
        }
        else {
            Node* uncle = node->parent->parent->left;

            if (uncle != nullptr && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            }
            else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rotateRight(node);
                }

                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                rotateLeft(node->parent->parent);
            }
        }
    }

    root->color = BLACK;
}

void RedBlackTree::rotateLeft(Node* node) {
    Node* rightChild = node->right;
    node->right = rightChild->left;

    if (rightChild->left != nullptr) {
        rightChild->left->parent = node;
    }

    rightChild->parent = node->parent;

    if (node->parent == nullptr) {
        root = rightChild;
    }
    else if (node == node->parent->left) {
        node->parent->left = rightChild;
    }
    else {
        node->parent->right = rightChild;
    }

    rightChild->left = node;
    node->parent = rightChild;
}

void RedBlackTree::rotateRight(Node* node) {
    Node* leftChild = node->left;
    node->left = leftChild->right;

    if (leftChild->right != nullptr) {
        leftChild->right->parent = node;
    }

    leftChild->parent = node->parent;

    if (node->parent == nullptr) {
        root = leftChild;
    }
    else if (node == node->parent->right) {
        node->parent->right = leftChild;
    }
    else {
        node->parent->left = leftChild;
    }

    leftChild->right = node;
    node->parent = leftChild;
}

void RedBlackTree::countGenders(int& numMale, int& numFemale) {
    numMale = 0;
    numFemale = 0;

    countGendersHelper(root, numMale, numFemale);
}

void RedBlackTree::countGendersHelper(Node* node, int& numMale, int& numFemale) {
    if (node == nullptr)
        return;

    if (node->gender == "male")
        numMale++;
    else if (node->gender == "female")
        numFemale++;

    countGendersHelper(node->left, numMale, numFemale);
    countGendersHelper(node->right, numMale, numFemale);
}

Node* RedBlackTree::searchStudent(int studentID) {
    Node* current = root;

    while (current != nullptr) {
        if (studentID == current->studentID)
            return current;
        else if (studentID < current->studentID)
            current = current->left;
        else
            current = current->right;
    }

    return nullptr;
}

void RedBlackTree::modifyStudent(int studentID, const string& newName, const string& newGender) {
    Node* node = searchStudent(studentID);

    if (node != nullptr) {
        node->name = newName;
        node->gender = newGender;
    }
}

void RedBlackTree::removeStudent(int studentID) {
    Node* node = searchStudent(studentID);

    if (node != nullptr)
        deleteNode(node);
}

void RedBlackTree::deleteNode(Node* node) {
    Node* replacement = nullptr;
    Node* fixNode = nullptr;

    if (node->left == nullptr || node->right == nullptr) {
        replacement = node;
    }
    else {
        replacement = minimum(node->right);
    }

    if (replacement->left != nullptr) {
        fixNode = replacement->left;
    }
    else {
        fixNode = replacement->right;
    }

    if (fixNode != nullptr) {
        fixNode->parent = replacement->parent;
    }

    if (replacement->parent == nullptr) {
        root = fixNode;
    }
    else if (replacement == replacement->parent->left) {
        replacement->parent->left = fixNode;
    }
    else {
        replacement->parent->right = fixNode;
    }

    if (replacement != node) {
        node->studentID = replacement->studentID;
        node->name = replacement->name;
        node->gender = replacement->gender;
    }

    if (replacement->color == BLACK)
        fixDeletion(fixNode);

    delete replacement;
}

Node* RedBlackTree::minimum(Node* node) {
    while (node->left != nullptr)
        node = node->left;

    return node;
}

void RedBlackTree::transplant(Node* u, Node* v) {
    if (u->parent == nullptr)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    if (v != nullptr)
        v->parent = u->parent;
}
void RedBlackTree::traverseTree(Node* node) {
    if (node != nullptr) {
        traverseTree(node->left);
        std::cout << "ID: " << node->studentID << ", Name: " << node->name << ", Gender: " << node->gender << std::endl;
        traverseTree(node->right);
    }
}
Node* RedBlackTree::getRoot()
{
    return root;
}
void RedBlackTree::fixDeletion(Node* node) {
    while (node != root && (node == nullptr || node->color == BLACK)) {
        if (node == node->parent->left) {
            Node* sibling = node->parent->right;

            if (sibling->color == RED) {
                sibling->color = BLACK;
                node->parent->color = RED;
                rotateLeft(node->parent);
                sibling = node->parent->right;
            }

            if ((sibling->left == nullptr || sibling->left->color == BLACK) &&
                (sibling->right == nullptr || sibling->right->color == BLACK)) {
                sibling->color = RED;
                node = node->parent;
            }
            else {
                if (sibling->right == nullptr || sibling->right->color == BLACK) {
                    sibling->left->color = BLACK;
                    sibling->color = RED;
                    rotateRight(sibling);
                    sibling = node->parent->right;
                }

                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                sibling->right->color = BLACK;
                rotateLeft(node->parent);
                node = root;
            }
        }
        else {
            Node* sibling = node->parent->left;

            if (sibling->color == RED) {
                sibling->color = BLACK;
                node->parent->color = RED;
                rotateRight(node->parent);
                sibling = node->parent->left;
            }

            if ((sibling->left == nullptr || sibling->left->color == BLACK) &&
                (sibling->right == nullptr || sibling->right->color == BLACK)) {
                sibling->color = RED;
                node = node->parent;
            }
            else {
                if (sibling->left == nullptr || sibling->left->color == BLACK) {
                    sibling->right->color = BLACK;
                    sibling->color = RED;
                    rotateLeft(sibling);
                    sibling = node->parent->left;
                }

                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                sibling->left->color = BLACK;
                rotateRight(node->parent);
                node = root;
            }
        }
    }

    if (node != nullptr)
        node->color = BLACK;
}

void RedBlackTree::printStudentInfo(Node* node) {
    if (node != nullptr) {
        printStudentInfo(node->left);
        std::cout << "ID: " << node->studentID << ", Name: " << node->name << ", Gender: " << node->gender << std::endl;
        printStudentInfo(node->right);
    }
}
