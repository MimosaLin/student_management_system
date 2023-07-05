#include<iostream>
#include "tree.h"
#include "linkedList.h"
#include "SeqList.h"
#include "queue.h"
#include"sort.h"
#include"AVLBST.h"
using namespace std;

void testBST();
void testOfSeqlist();
void testOfLinkedList();
void testOfTree();
void testOfQueue();
void test_sort(int i);

int main()
{
    cout << "1:queue 2:BST";
    int a;
    cin >> a;
    if (a == 1)
        testOfQueue();
    if (a == 2)
        testBST();

}
void testBST()
{
    AVLBST bst;

    ifstream inputFile("BSTdata.txt");
    if (!inputFile) {
        cerr << "未能成功打开文件" << std::endl;
        return;
    }
    while (1) {
        string line;
        while (getline(inputFile, line)) {
            stringstream ss(line);
            string token;
            AVLBSTree::Student student;
            getline(ss, token, ',');
            student.id = stoi(token);
            getline(ss, token, ',');
            student.name = token;
            getline(ss, token, ',');
            student.score = stoi(token);
            bst.insert(student);
        }

        inputFile.close();
        cout << "请输入您的操作：1为展示全部数据，2为增加学生信息，3为删除学生信息，4为修改学生信息，5为查找学生信息, 0为退出程序" << endl;
        int op;
        cin >> op;
        if (op == 0)
            break;
        if (op == 1)
            bst.inorderTraversal(); // 遍历二分查找树
        if (op == 2) {
            int id;
            string name;
            int score;

            cout << "请输入学生ID：";
            cin >> id;
            cout << "请输入学生姓名：";
            cin >> name;

            cout << "请输入学生成绩：";
            cin >> score;

            // 创建新的 Student 对象
            AVLBSTree::Student student;
            student.id = id;
            student.name = name;
            student.score = score;

            // 调用 bst.insert() 插入学生信息到二叉搜索树中
            bst.insert(student);
            ofstream outputFile("data.txt", ios::app);
            if (!outputFile) {
                cerr << "未能成功打开文件" << endl;
                return;
            }
            outputFile << student.id << "," << student.name << "," << student.score << endl;
            outputFile.close();
        }

        if (op == 3) {
            int score;
            cout << "请输入需要删除的学生分数" << endl;
            cin >> score;
            bst.remove(score);
        }
        if (op == 4) {
            int prescore;
            int postscore;
            cout << "请输入修改前的分数" << endl;
            cin >> prescore;
            cout << "请输入修改后的分数" << endl;
            cin >> postscore;
            bst.update(prescore, postscore);
        }
        if (op == 5) {
            int score;
            cout << "请输入要查找的分数" << endl;
            cin >> score;
            // 查询学生成绩为90的学生信息
            TreeNode* result = bst.search(score);
            if (result != nullptr) {
                cout << "ID: " << result->student.id << " 姓名: " << result->student.name << " 分数: " << result->student.score << endl;
            }
            else {
                cout << "未能找到该学生" << endl;
            }
        }
    }
}
void testOfTree() {
    string filename = "student.txt";
    PeerTree peerTree = buildPeerTreeFromTxt(filename);

    // 示例查询
    int studentId1 = 1;
    int studentId2 = 2;

    if (peerTree.isPeerRelationship(studentId1, studentId2)) {
        cout << "学生 " << studentId1 << " 和学生 " << studentId2 << " 为导生关系。" << endl;
    }
    else {
        cout << "学生 " << studentId1 << " 和学生 " << studentId2 << " 不是导生关系。" << endl;
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
    string filename = "student.txt";
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

void testOfQueue() {
    Queue q;
    string filename = "student.txt";
    q.readFromFile(filename);

    while (!q.isEmpty()) {
        queue::Student student = q.dequeue();
        std::cout << student.name << ' ' << student.id << '\n';
    }

}


void test_sort(int i)
{
    string filename = "student.txt";
    //测试排序函数，0为插入排序，1为快速排序,2为堆排序
    if (i == 0)
    {
        cout << "插入排序：" << endl;
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
        cout << "快速排序：" << endl;
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
        cout << "堆排序：" << endl;
        SeqList list;
        list.readFromFile(filename);
        list.display();
        cout << "*******************************************" << endl;
        heap_sort(list);
        list.display();
        cout << "*******************************************" << endl;
    }
}
