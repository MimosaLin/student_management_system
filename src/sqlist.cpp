#include<iostream>
#include<fstream>
#include <locale>
#include <codecvt>
#include <sstream>
#include"sqlist.h"
using namespace std;
#include<string>
SqList::SqList(int size) {
    maxSize = size;
    data = new Student[maxSize];
    length = 0;
}
SqList::~SqList() {
    delete[] data;
}
void SqList::readFromFile(string filename)
{
    std::ifstream file(filename); // �滻Ϊ����ļ�·��

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string name;
            std::string idStr;
            std::string scoreStr;

            if (std::getline(iss, name, ',') &&
                std::getline(iss, idStr, ',') &&
                std::getline(iss, scoreStr)) {
                Student student;
                student.name = name;
                student.id = std::stoi(idStr);
                student.score = std::stod(scoreStr);
                data[length] = student;
                length++;
                std::cout << "����: " << student.name << ", ѧ��: " << student.id << ", �ɼ�: " << student.score << std::endl;
            }
        }
        file.close();
    }
    else {
        std::cout << "�޷����ļ�" << std::endl;
    }
}
void SqList::writeToFile(string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < length; i++) {
            file << data[i].name << " " << data[i].id << " " << data[i].score << endl;
        }
        file.close();
    }
    else {
        cout << "�޷����ļ���" << filename << endl;
    }
}
bool SqList::insert(int position, Student stu) {
    if (position < 0 || position > length) {
        cout << "����λ����Ч��" << endl;
        return false;
    }
    if (length >= maxSize) {
        cout << "���Ա��������޷�����ѧ����Ϣ��" << endl;
        return false;
    }
    for (int i = length; i > position; i--) {
        data[i] = data[i - 1];
    }
    data[position] = stu;
    length++;
    return true;
}
bool SqList::remove(int position) {
    if (position < 0 || position >= length) {
        cout << "ɾ��λ����Ч��" << endl;
        return false;
    }
    for (int i = position; i < length - 1; i++) {
        data[i] = data[i + 1];
    }
    length--;
    return true;
}

bool SqList::modify(int position, Student stu) {
    if (position < 0 || position >= length) {
        cout << "�޸�λ����Ч��" << endl;
        return false;
    }
    data[position] = stu;
    return true;
}

int SqList::searchById(int id)
{
        for (int i = 0; i < length; i++)
        {
            if (data[i].id == id)
                return i;
        }
        return -1;
}

Student SqList::get(int position)
{
    if(position<0||position>length)throw std::out_of_range("λ��Խ��"); // �׳�Խ���쳣
    return data[position];
}

int SqList::getLength()
{
    return length;
}