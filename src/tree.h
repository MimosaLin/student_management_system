#pragma once
#include <iostream>
#include <vector>
#include <string>

struct MentorTreeNode {
    int studentID;
    int grade;
    std::string studentName;
    std::vector<MentorTreeNode*> children;

    MentorTreeNode(int id, int grd, const std::string& name)
        : studentID(id), grade(grd), studentName(name) {}
};

class PeerMentorshipTree {
private:
    MentorTreeNode* root;

public:
    PeerMentorshipTree();
    ~PeerMentorshipTree();
    void deleteTree(MentorTreeNode* node);
    void insert(int studentID, int mentorID, int grade, const std::string& studentName);
    MentorTreeNode* findNode(MentorTreeNode* currentNode, int studentID);
    bool isDirectMentor(int mentorID, int studentID);
    bool isIndirectMentor(int mentorID, int studentID, int maxGenerations);
    bool isIndirectMentorHelper(MentorTreeNode* currentNode, MentorTreeNode* studentNode, int maxGenerations);
};


