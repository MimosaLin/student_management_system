#include<iostream>
#include"sqlist.h"
using namespace std;
int main()
{
    const int maxSize = 20; // �������Ϊ20
    // ʵ�������Ա����
    SqList sqList(maxSize);
    // ���ļ���ȡѧ����Ϣ
    sqList.readFromFile("student.txt");
    // ִ����ɾ�Ĳ�Ȳ���
    // ʾ������λ��0����һ��ѧ����Ϣ
    Student newStudent;
    newStudent.name = "John";
    newStudent.id = 123456;
    newStudent.score = 85.5;
    sqList.insert(0, newStudent);
    // ʾ����ɾ��λ��2��ѧ����Ϣ
    sqList.remove(2);
    // ʾ�����޸�λ��1��ѧ����Ϣ
    Student modifiedStudent;
    modifiedStudent.name = "Alice";
    modifiedStudent.id = 654321;
    modifiedStudent.score = 92.0;
    sqList.modify(1, modifiedStudent);

    // ʾ��������ѧ�Ų���ѧ��λ��
    int position = sqList.searchById(123456);
    if (position != -1)Student data = sqList.get(position);
    else cout << "���Ҵ���û�д�ѧ��" << endl;
    // �����Ա������д���ļ�
    sqList.writeToFile("output.txt");
	return 0;
}