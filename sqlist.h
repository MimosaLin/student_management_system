#pragma once
#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H
#include <iostream>
#include <fstream>
// 学生信息结构体
struct Student {
    std::string name;
    int id;
    float score;
};
// 线性表的顺序存储方式
class SqList {
public:
    SqList(int);
    ~SqList();
    // 从文件读取学生信息到线性表
    void readFromFile(std::string);
    // 将线性表的内容写入文件
    void writeToFile(std::string);
    // 在指定位置插入学生信息
    bool insert(int, Student);
    // 删除指定位置的学生信息
    bool remove(int);
    // 修改指定位置的学生信息
    bool modify(int,Student);
    // 根据学号查找
    int searchById(int id);
    //获取指定位置的学生信息
    Student get(int position);
    // 获取线性表的长度
    int getLength();

private:
    Student* data;  // 存储学生信息的数组
    int maxSize;    // 线性表的最大容量
    int length;     // 当前线性表的长度
};

#endif // !1