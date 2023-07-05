#include<iostream>
#include "tree.h"
#include "linkedList.h"
#include "SeqList.h"
#include "queue.h"
#include"sort.h"
#include"AVLBST.h"
#include"graph.h"
#include"blackred.h"
#include"kruskal.h"
#include"hash.h"
using namespace std;
void testkruskal();
void testBST();
void testOfSeqlist();
void testOfLinkedList();
void testOfTree();
void testOfQueue();
void test_sort();
void testRedBlackTree();
void test_hash();
void testGraph();
int main()
{
    while (1)
    {
        cout << "1:测试线性表和链表\n2:测试Queue\n3:测试树形结构朋辈导生关系\n4:测试二分查找树\n5:测试hash\n6:测试排序\n7测试友谊关系最短路\n8测试红黑树\n9测试最小生成树";
        int a;
        cin >> a;
        if (a == 1)
        {
            testOfSeqlist();
            testOfLinkedList();
        }
          
        if (a == 2)
            testOfQueue();
        if (a == 3)
            testOfTree();
        if(a==4)
            testBST();
        if (a == 5)
            test_hash();
        if(a==6)
            test_sort();
        if(a==7)
            testGraph();
        if(a==8)
          testRedBlackTree();
        if (a == 9)
          testkruskal();
        if (a == 0)
            break;

    }
    
    

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
            int id=5;
            string name="Jack";
            int score=93;
            cout << "测试样例数据为5,Jack,93" << endl;
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
            bst.inorderTraversal();
        }

        if (op == 3) {
            int score=93;
            cout << "测试样例为删除成绩为93的学生" << endl;
            bst.remove(score);
            bst.inorderTraversal();
        }
        if (op == 4) {
            int prescore=100;
            int postscore=99;
            cout << "修改前的分数为100" << endl;
            cout << "修改后的分数为99" << endl;
            bst.update(prescore, postscore);
            bst.inorderTraversal();
        }
        if (op == 5) {
            int score=90;
            cout << "查找的分数为90" << endl;
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
void testOfTree() 
{
    PeerMentorshipTree tree;

    std::ifstream inputFile("treedata.txt");
    std::string line;
    cout << "学生ID\t" << "导师ID\t" << "年级\t" << "学生姓名" << endl;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        int studentID, mentorID, grade;
        std::string studentName;
        

        if (iss >> studentID >> mentorID >> grade >> studentName) {
            cout << studentID << "\t" << mentorID << "\t" << grade << "\t" << studentName << endl;
            tree.insert(studentID, mentorID, grade, studentName);

        }
       
    }
    int mentorID=1, studentID=2;
    cout << "导师的学号：1"<<endl;
    cout << "学生的学号：2"<<endl;

    if (tree.isDirectMentor(mentorID, studentID)) {
        cout << "是直接导生关系" << endl;
    }
    else if (tree.isIndirectMentor(mentorID, studentID, 3)) {
        cout << "是间接导生关系" << endl;
    }
    else {
        cout << "不是导生关系" << endl;
    }

    mentorID = 1, studentID = 6;
    cout << "导师的学号：1" << endl;
    cout << "学生的学号：6" << endl;
    if (tree.isDirectMentor(mentorID, studentID)) {
        cout << "是直接导生关系" << endl;
    }
    else if (tree.isIndirectMentor(mentorID, studentID, 3)) {
        cout << "是间接导生关系" << endl;
    }
    else {
        cout << "不是导生关系" << endl;
    }

    mentorID = 3, studentID = 7;
    cout << "导师的学号：3" << endl;
    cout << "学生的学号：7" << endl;
    if (tree.isDirectMentor(mentorID, studentID)) {
        cout << "是直接导生关系" << endl;
    }
    else if (tree.isIndirectMentor(mentorID, studentID, 3)) {
        cout << "是间接导生关系" << endl;
    }
    else {
        cout << "不是导生关系" << endl;
    }
}

void testOfLinkedList() {
    LinkedList list;
    list.display();
    // Reading from file
    list.readFromFile("listdata.txt");
    while (1)
    {
        int choice;
        list.display();
        cout << "请输入操作" << endl;
        cout << "1:增加学生\n2:查找学生\n3:修改学生\n4:删除学生\n0:退出" << endl;
        cin >> choice;
        if (choice == 1)
        {
            string name="Jack";int num=6;int grade=99;
            cout << "测试数据为Jack,6,99" << endl;
            list.insert(name, num, grade);
            list.display();
        }
        else if (choice == 2)
        {
            int num=3;
            cout << "查找学生的学号是3" << endl;
            linkedlist::Student* student = list.search(num);
            if (student) {
                std::cout << "ID 为:" << num << "的学生" << endl;
                std::cout << "Name: " << student->name << std::endl;
                std::cout << "ID: " << student->id << std::endl;
                std::cout << "Grade: " << student->grade << std::endl;
            }
            else {
                std::cout << "没有找到\n";
            }
        }
        else if (choice == 3)
        {
            cout << "修改学生的学号为3" << endl;
            int num=3;
            string name="Jason";int grade=88;
            cout << "修改后的姓名是 Jason" << endl;
            cout << "修改后的成绩是88" << endl;
            list.update(num, name, grade);
            list.display();
        }
        else if (choice == 4)
        {

            cout << "删除学生的学号为5" << endl;
            int num=5;
            list.remove(num);
            list.display();
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            cout << "操作无效" << endl;
        }
    }
    // Saving to file
   // list.writeToFile("students.txt");
}

void testOfSeqlist() {
    SeqList list;
    string filename = "listdata.txt";
    // read from file
    list.readFromFile(filename);
    list.display();

    while (1)
    {
        cout << "请输入你的操作\n1:增加学生数据\n2:删除学生数据\n3:修改学生数据\n4:查找学生数据\n0:退出";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "测试数据为Dave 4 95" << endl;
            seqlist::Student s1 = { "Dave", 4, 95 };
            list.insert(s1);
            list.display();
        }
        else if (choice == 2)
        {
            cout << "删除ID为2的学生" << endl;
            list.deleteById(2);
            list.display();
        }
        else if (choice == 3)
        {
            cout << "将ID为1的学生修改为 Alice 1 100"<<endl;
            seqlist::Student s2 = { "Alice", 1, 100 };
            list.updateById(1, s2);
            list.display();
        }
        else if (choice == 4)
        {
            cout << "查找ID为3的数据";
            seqlist::Student* s3 = list.searchById(3);
            cout << s3->name << " " << s3->id << " " << s3->grade << endl;
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            cout << "操作错误";
        }
    }

}

void testOfQueue() {
    unordered_map<string, pair<Queue, int>> courses;
    courses["Math"] = { Queue(), 2 };
    courses["English"] = { Queue(), 1 };
    courses["History"] = { Queue(), 1 };

    unordered_map<string, string> students;
    students["Alice"] = "Math";
    students["Bob"] = "English";
    students["Charlie"] = "History";
    students["Dave"] = "Math";
    students["Eve"] = "English";

    for (auto& student : students) {
        string name = student.first;
        string course = student.second;
        queue::Student s{ name, 0 };
        if (courses[course].first.size() < courses[course].second) {
            courses[course].first.enqueue(s);
            cout << name << " successfully enrolled in " << course << endl;
        }
        else {
            cout << name << " failed to enroll in " << course << endl;
        }
    }

}

void test_sort()
{
    string filename = "sortdata.txt";
    //
    while (1)
    {
        int i;
        cout << "测试排序函数，1为插入排序，2为快速排序,3为堆排序,0为退出" << endl;
        cin >> i;
        if (i == 1)
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
        else if (i == 2)
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
        else if (i == 3)
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
        else if (i == 0)
        {
            break;
        }
        else
        {
            cout << "操作错误"<<endl;
        }
    }
   
}

void testRedBlackTree()
{
    RedBlackTree tree;
    tree.readStudentInfo("blackred.txt");

    cout << "请选择您的操作：" << endl;
    cout << "1. 统计男女生总数" << endl;
    cout << "2. 修改学生信息" << endl;
    cout << "3. 删除学生信息" << endl;
    cout << "4. 查找学生信息" << endl;
    cout << "5. 增加学生信息" << endl;
    cout << "0. 退出 " << endl;
    while (1)
    {
        cout << "当前数据遍历结果如下" << endl;
        tree.traverseTree(tree.getRoot());
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            int numMale, numFemale;
            tree.countGenders(numMale, numFemale);
            cout << "男生总数: " << numMale << ", 女生总数: " << numFemale << endl;
        }
        else if (choice == 2)
        {
            int studentID=10001;
            string newName="Jack", newGender="male";
            cout << "修改的学生ID: 1"<<endl;
            cout << "新的姓名: Jack"<<endl;
            cout << "新的性别: male"<<endl;
            tree.modifyStudent(studentID, newName, newGender);
            cout << "修改成功" << endl;
        }
        else if (choice == 3)
        {
            int studentID=10003;
            cout << "要删除的学生ID: 10003";
            tree.removeStudent(studentID);
            cout << "删除成功" << endl;
        }
        else if (choice == 4)
        {
            int studentID=10005;
            cout << "查找的学生ID: 10005";
            Node* student = tree.searchStudent(studentID);
            if (student != nullptr) {
                cout << "ID: " << student->studentID << ", Name: " << student->name << ", Gender: " << student->gender << endl;
            }
            else {
                cout << "未找到该学生信息" << endl;
            }

        }
        else if (choice == 5)
        {
            int studentID=10003;
            string name="Jane", gender="female";
            cout << "增加的学生ID: 10003";
            cout << "姓名: Jane";
            cout << "请输入性别: female";
            tree.insertStudent(studentID, name, gender);
            cout << "添加成功" << endl;
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            cout << "无效选择" << endl;

        }
    }
}

void testGraph() {
    Graph g;
    g.read_from_file("graphStudent.txt");
    cout << "计算Alice 到 Eve 合作最好拉上谁" << endl;
    std::string start = "Alice";
    std::string end = "Eve";

    std::vector<std::string> path = g.get_shortest_path(start, end);

    std::cout << "从 " << start << " 到" << end << ": ";
    for (const std::string& v : path) {
        std::cout << v << ' ';
    }
    std::cout << endl;
}

void testkruskal()
{
    ifstream inputFile("graphstudent.txt");
    if (!inputFile.is_open()) {
        cout << "无法打开文件。" << endl;
        return;
    }

    vector<Edge> edges;
    vector<string> vertices;

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string source, destination;
        int weight;

        ss >> source >> destination >> weight;

        edges.push_back({ source, destination, weight });
        if (find(vertices.begin(), vertices.end(), source) == vertices.end())
            vertices.push_back(source);
        if (find(vertices.begin(), vertices.end(), destination) == vertices.end())
            vertices.push_back(destination);
    }

    inputFile.close();

    // 计算最小生成树
    vector<Edge> minimumSpanningTree = kruskalMST(edges, vertices);

    // 输出最小生成树的边及权重
    cout << "Minimum Spanning Tree:" << endl;
    for (const auto& edge : minimumSpanningTree) {
        cout << edge.source << " -- " << edge.destination << " : " << edge.weight << endl;
    }

}
void test_hash()
{
    SeqList students;
    students.readFromFile("hash.txt");
    Hash table = Hash(students.get_length() * 2 - 1);
    for (int i = 0; i < students.get_length(); i++)
    {
        table.insert(students[i], i + 1);
    }
    for (int i = 0; i < students.get_length(); i++)
    {
        hash_group info = table.search_seat(students[i]);
        cout << info.stu.name << ' ' << info.seat_num << endl;
    }
    cout << "*************************************" << endl;
    seqlist::Student s1;
    s1.id = 21;
    s1.grade = 99;
    s1.name = "Mimosa";
    table.insert(s1, students.get_length() + 1);
    for (int i = 0; i < students.get_length(); i++)
    {
        hash_group info = table.search_seat(students[i]);
        cout << info.stu.name << ' ' << info.seat_num << endl;
    }
    hash_group info = table.search_seat(s1);
    cout << info.stu.name << ' ' << info.seat_num << endl;
}
