#pragma once
#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H
#include <iostream>
#include <fstream>
// ѧ����Ϣ�ṹ��
struct Student {
    std::string name;
    int id;
    float score;
};
// ���Ա��˳��洢��ʽ
class SqList {
public:
    SqList(int);
    ~SqList();
    // ���ļ���ȡѧ����Ϣ�����Ա�
    void readFromFile(std::string);
    // �����Ա������д���ļ�
    void writeToFile(std::string);
    // ��ָ��λ�ò���ѧ����Ϣ
    bool insert(int, Student);
    // ɾ��ָ��λ�õ�ѧ����Ϣ
    bool remove(int);
    // �޸�ָ��λ�õ�ѧ����Ϣ
    bool modify(int,Student);
    // ����ѧ�Ų���
    int searchById(int id);
    //��ȡָ��λ�õ�ѧ����Ϣ
    Student get(int position);
    // ��ȡ���Ա�ĳ���
    int getLength();

private:
    Student* data;  // �洢ѧ����Ϣ������
    int maxSize;    // ���Ա���������
    int length;     // ��ǰ���Ա�ĳ���
};

#endif // !1