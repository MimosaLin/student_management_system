#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "studentsStruct.h"

using namespace std;

// ǰ������
class PeerTree;

class PeerTree {
private:
    tree::Student* root;

public:
    PeerTree();

    // �����в���ѧ����Ϣ
    void insertStudent(const string& name, int id, int grade);

    // ��ѯ����ѧ���Ƿ�Ϊֱ�ӻ��ӵ�����ϵ
    bool isPeerRelationship(int id1, int id2);

private:
    // �����в���ָ��ID��ѧ��
    tree::Student* findStudent(tree::Student* current, int id);

    // �ж�����ѧ���Ƿ�Ϊֱ�ӵ�����ϵ
    bool isDirectPeer(tree::Student* student1, tree::Student* student2);

    // �ж�����ѧ���Ƿ�Ϊ��ӵ�����ϵ
    bool isIndirectPeer(tree::Student* student1, tree::Student* student2);
};

// ��Excel�ļ��ж�ȡѧ����Ϣ�����������νṹ
PeerTree buildPeerTreeFromTxt(const string& filename);