#include<iostream>
#include"sqlist.h"
using namespace std;
int main()
{
    const int maxSize = 20; // 最大容量为20
    // 实例化线性表对象
    SqList sqList(maxSize);
    // 从文件读取学生信息
    sqList.readFromFile("student.txt");
    // 执行增删改查等操作
    // 示例：在位置0插入一个学生信息
    Student newStudent;
    newStudent.name = "John";
    newStudent.id = 123456;
    newStudent.score = 85.5;
    sqList.insert(0, newStudent);
    // 示例：删除位置2的学生信息
    sqList.remove(2);
    // 示例：修改位置1的学生信息
    Student modifiedStudent;
    modifiedStudent.name = "Alice";
    modifiedStudent.id = 654321;
    modifiedStudent.score = 92.0;
    sqList.modify(1, modifiedStudent);

    // 示例：根据学号查找学生位置
    int position = sqList.searchById(123456);
    if (position != -1)Student data = sqList.get(position);
    else cout << "查找错误：没有此学号" << endl;
    // 将线性表的内容写入文件
    sqList.writeToFile("output.txt");
	return 0;
}