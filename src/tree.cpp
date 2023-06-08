#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "tree.h"

using namespace std;

PeerTree::PeerTree() {
    root = nullptr;
}

// 向树中插入学生信息
void PeerTree::insertStudent(const string& name, int id,  int grade) {
    tree::Student* newNode = new tree::Student;
    newNode->id = id;
    newNode->name = name;
    newNode->grade = grade;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (root == nullptr) {
        root = newNode;
    }
    else {
        tree::Student* current = root;
        while (true) {
            if (id < current->id) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    break;
                }
                else {
                    current = current->left;
                }
            }
            else if (id > current->id) {
                if (current->right == nullptr) {
                    current->right = newNode;
                    break;
                }
                else {
                    current = current->right;
                }
            }
            else {
                // 若ID已存在，可以根据需要处理，这里简单忽略重复ID的情况
                break;
            }
        }
    }
}

// 查询两个学生是否为直接或间接导生关系
bool PeerTree::isPeerRelationship(int id1, int id2){
    tree::Student* student1 = findStudent(root, id1);
    tree::Student* student2 = findStudent(root, id2);

    if (student1 == nullptr || student2 == nullptr) {
        return false; // 至少有一个学生不存在，不可能是导生关系
    }

    if (isDirectPeer(student1, student2)) {
        return true; // 直接导生关系
    }

    // 遍历查找间接导生关系
    return isIndirectPeer(student1, student2);
}

// 在树中查找指定ID的学生
tree::Student* PeerTree::findStudent(tree::Student* current, int id) {
    if (current == nullptr || current->id == id) {
        return current;
    }

    if (id < current->id) {
        return findStudent(current->left, id);
    }
    else {
        return findStudent(current->right, id);
    }
}

// 判断两个学生是否为直接导生关系
bool PeerTree::isDirectPeer(tree::Student* student1, tree::Student* student2) {
    return (student1->grade == student2->grade);
}

// 判断两个学生是否为间接导生关系
bool PeerTree::isIndirectPeer(tree::Student* student1, tree::Student* student2) {
    if (student1 == nullptr || student2 == nullptr) {
        return false;
    }

    // 若两个学生年级不同，则继续在较高或较低年级的子树中查找
    if (student1->grade < student2->grade) {
        return isIndirectPeer(student1, student2->left) || isIndirectPeer(student1, student2->right);
    }
    else if (student1->grade > student2->grade) {
        return isIndirectPeer(student1->left, student2) || isIndirectPeer(student1->right, student2);
    }

    // 若两个学生年级相同，则继续在同级子树中查找
    return isIndirectPeer(student1->left, student2->left) || isIndirectPeer(student1->right, student2->right);
}

PeerTree buildPeerTreeFromTxt(const string& filename) {
    PeerTree peerTree; ifstream file(filename); // 定义一个文件流对象
    if (!file.is_open()) {
        cout << "无法打开文件 " << filename << endl;
        return peerTree;
    }

    string line;
    while (getline(file, line)) { // 逐行读取文件
        // 解析每行数据
        int id, grade;
        string name;
        istringstream stream(line); // 定义一个字符串流对象
        stream >> name >> id >> grade; // 用空格分隔数据
        peerTree.insertStudent(name, id, grade);
        cout << name << endl << id << endl << grade << endl;
    }

    file.close(); // 关闭文件
    return peerTree;
}