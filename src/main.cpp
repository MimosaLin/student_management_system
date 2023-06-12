#include<iostream>
#include "tree.h"
#include "linkedList.h"
#include "SeqList.h"
#include "queue.h"
#include"sort.h"

using namespace std;

string filename = "D:\\learningDocs\\DataStructure\\student.txt"; // �滻Ϊ����ļ���

void testOfSeqlist();
void testOfLinkedList();
void testOfTree();
void testOfQueue();
void test_sort(int i);

int main()
{
    testOfQueue();
}

void testOfTree() {
    PeerTree peerTree = buildPeerTreeFromTxt(filename);

    // ʾ����ѯ
    int studentId1 = 1;
    int studentId2 = 2;

    if (peerTree.isPeerRelationship(studentId1, studentId2)) {
        cout << "ѧ�� " << studentId1 << " ��ѧ�� " << studentId2 << " Ϊ������ϵ��" << endl;
    }
    else {
        cout << "ѧ�� " << studentId1 << " ��ѧ�� " << studentId2 << " ���ǵ�����ϵ��" << endl;
    }
}

void testOfLinkedList() {
    LinkedList list;

    // Inserting students
    list.insert("Alice", 1, 90);
    list.insert("Bob", 2, 80);
    list.insert("Charlie", 3, 85);

    // Searching and displaying student
    linkedlist::Student* student = list.search(2);
    if (student) {
        std::cout << "Found student with ID 2:\n";
        std::cout << "Name: " << student->name << std::endl;
        std::cout << "ID: " << student->id << std::endl;
        std::cout << "Grade: " << student->grade << std::endl;
    }
    else {
        std::cout << "Student with ID 2 not found.\n";
    }

    // Updating student
    list.update(3, "Charlie Brown", 88);

    // Removing student
    list.remove(1);

    // Saving to file
    list.wiriteToFile("students.txt");
}

void testOfSeqlist() {
    SeqList list;

    // read from file
    list.readFromFile(filename);
    list.display();

    // insert
    seqlist::Student s1 = { "Dave", 4, 95 };
    list.insert(s1);

    // delete
    list.deleteById(2);

    // update
    seqlist::Student s2 = { "Alice", 1, 100 };
    list.updateById(1, s2);

    // search
    seqlist::Student* s3 = list.searchById(3);
    cout << s3->name << " " << s3->id << " " << s3->grade << endl;

    // write to file
    list.writeToFile(filename);
}

void testOfQueue(){
    Queue q;

    q.readFromFile(filename);

    while (!q.isEmpty()) {
        queue::Student student = q.dequeue();
        std::cout << student.name << ' ' << student.id << '\n';
    }

}


void test_sort(int i)
{
    //������������0Ϊ��������1Ϊ��������,2Ϊ������
    if (i == 0)
    {
        cout << "��������" << endl;
        SeqList list;
        list.readFromFile(filename);
        list.display();
        cout << "*******************************************" << endl;
        insert_sort(list);
        list.display();
        cout << "*******************************************" << endl;
    }
    else if (i == 1)
    {
        cout << "��������" << endl;
        SeqList list;
        list.readFromFile(filename);
        list.display();
        cout << "*******************************************" << endl;
        quick_sort(list, 0, list.get_length() - 1);
        list.display();
        cout << "*******************************************" << endl;
    }
    else if (i == 2)
    {
        cout << "������" << endl;
        SeqList list;
        list.readFromFile(filename);
        list.display();
        cout << "*******************************************" << endl;
        heap_sort(list);
        list.display();
        cout << "*******************************************" << endl;
    }
}