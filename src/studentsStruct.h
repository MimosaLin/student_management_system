#pragma once
#include <string>

using namespace std;

namespace seqlist {
    struct Student {
        string name;
        int id;
        int grade;
    };
}

namespace linkedlist {
    struct Student {
        std::string name;
        int id;
        int grade;
        Student* next;
    };
}

namespace tree {
    struct Student {
        int id;
        string name;
        int grade; // 年级信息
        Student* left;
        Student* right;
    };
}
