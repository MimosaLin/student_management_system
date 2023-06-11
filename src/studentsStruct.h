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

namespace queue {
    struct Student {
        std::string name;
        int id;
    };
}

namespace tree {
    struct Student {
        int id;
        string name;
        int grade;
        Student* left;
        Student* right;
    };
}

namespace BinarySearchTree{
    struct Student {
        int id;
        string name;
        int score;
    };
}
