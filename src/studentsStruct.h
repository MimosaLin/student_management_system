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

namespace Ntree {
    struct Student {
        string name;
        int id;
        int grade;
        
    };
}

namespace AVLBSTree{
    struct Student {
        int id;
        string name;
        int score;
    };
}
