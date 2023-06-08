#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "studentsStruct.h"

using namespace std;

// 前置声明
class PeerTree;

class PeerTree {
private:
    tree::Student* root;

public:
    PeerTree();

    // 向树中插入学生信息
    void insertStudent(const string& name, int id, int grade);

    // 查询两个学生是否为直接或间接导生关系
    bool isPeerRelationship(int id1, int id2);

private:
    // 在树中查找指定ID的学生
    tree::Student* findStudent(tree::Student* current, int id);

    // 判断两个学生是否为直接导生关系
    bool isDirectPeer(tree::Student* student1, tree::Student* student2);

    // 判断两个学生是否为间接导生关系
    bool isIndirectPeer(tree::Student* student1, tree::Student* student2);
};

// 从Excel文件中读取学生信息，并构建树形结构
PeerTree buildPeerTreeFromTxt(const string& filename);