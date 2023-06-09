# student_management_system
## 数据结构大作业，学生管理系统

### 作业要求：
1. **（finished）**（05）实现线性表的顺序存储方式和链式存储方式。
2. **（finished）**（05）实现队列Queue数据结构，顺序存储或者链式存储方式，模拟学生选课操作，先到先得。
3. （15）实现树形结构存储朋辈导生关系，至少需要在此树形结构上实现一个查询功能，即查询二人是否为直接导生关系。有能力的同学可以实现例如是否是间隔很多代的间接导生关系。学生信息增加一个年级信息用于表示该生在树形结构中的第几层。
4. （13）假设所有同学的分数不同，以同学的分数为index建立二分查找树binary search，不要求AVL和红黑，实现增删改查功能，自拟数据。
5. （10）以hashing算法为基础设计学生座位分配及查询系统。可以使用学号或者姓名为key。
6. （10）实现插入排序、快速排序、堆排序对同学以成绩为指标进行排序。
7. （12）自拟数据，以图为数据结构模拟同学间的友谊关系，并实现最短路径算法查询两个同学间如果要进行合作最好拉上其他哪些同学。
8. （20）实验报告及展示
9. （10）个性化功能

目前的示例数据
```
Alice 1 95

Bob 2 85

Calvin 3 90

David 4 92
```

***

## 6/8
### **@haoquan_zhang** seqList.h 
### **@haoquan_zhang** seqList.cpp
### **@haoquan_zhang** main.cpp update `testOfseqList() `
由于顺序表，链表以及树结构的student结构体有差别，添加了studentsStruct头文件用于管理student结构体。
```cpp
    namespace sqlist {
        struct Student {
            // 这里是顺序表中使用的Student结构体的定义
        };
    }

    namespace linkList {
        struct Student {
            // 这里是链式表中使用的Student结构体的定义
        };
    }
```
这样不同的student在不同的命名空间中，可以避免student重定义的问题。

***

## 6/8
### **@haoquan_zhang** linkedList.h 
### **@haoquan_zhang** linkedList.h 
### **@haoquan_zhang** main.cpp update `testOfLinkedList() `
重写了链式存储与顺序存储，重写了测试样例，均可正常运行

***

## 6/9
### **@haoquan_zhang** queue.h
### **@haoquan_zhang** queue.cpp
### **@haoquan_zhang** main.cpp update `testOfQueue()`
`testOfQueue()`函数现在可以处理文件中的数据格式为 `name id grade`，每个数据后换行。请注意，由于 `queue::Student` 结构体只包含 `name` 和 `id` 两个成员变量，所以 `grade` 数据将被忽略。
循环中
```c++
    while (!q.isEmpty()) {
        queue::Student student = q.dequeue();
        std::cout << student.name << ' ' << student.id << '\n';
    }
```
`student`从dequeue中pop获得，所以最终队列未空，
所以编写的示例中没有包含`writeToFile()`函数

***
