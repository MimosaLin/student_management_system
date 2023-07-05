#include "tree.h"

PeerMentorshipTree::PeerMentorshipTree() : root(nullptr) {}

PeerMentorshipTree::~PeerMentorshipTree() {
    deleteTree(root);
}

void PeerMentorshipTree::deleteTree(MentorTreeNode* node) {
    if (node == nullptr) {
        return;
    }
    for (MentorTreeNode* child : node->children) {
        deleteTree(child);
    }
    delete node;
}

void PeerMentorshipTree::insert(int studentID, int mentorID, int grade, const std::string& studentName) {
    MentorTreeNode* newNode = new MentorTreeNode(studentID, grade, studentName);
    if (root == nullptr) {
        root = newNode;
    }
    else {
        MentorTreeNode* mentorNode = findNode(root, mentorID);
        if (mentorNode != nullptr) {
            mentorNode->children.push_back(newNode);
        }
        else {
            std::cout << "未找到该学生 " << studentID << std::endl;
            delete newNode;
        }
    }
}

MentorTreeNode* PeerMentorshipTree::findNode(MentorTreeNode* currentNode, int studentID) {
    if (currentNode == nullptr) {
        return nullptr;
    }
    if (currentNode->studentID == studentID) {
        return currentNode;
    }
    for (MentorTreeNode* child : currentNode->children) {
        MentorTreeNode* foundNode = findNode(child, studentID);
        if (foundNode != nullptr) {
            return foundNode;
        }
    }
    return nullptr;
}

bool PeerMentorshipTree::isDirectMentor(int mentorID, int studentID) {
    MentorTreeNode* mentorNode = findNode(root, mentorID);
    if (mentorNode == nullptr) {
        std::cout << "未找到导师" << std::endl;
        return false;
    }
    for (MentorTreeNode* child : mentorNode->children) {
        if (child->studentID == studentID) {
            return true;
        }
    }
    return false;
}

bool PeerMentorshipTree::isIndirectMentor(int mentorID, int studentID, int maxGenerations) {
    MentorTreeNode* mentorNode = findNode(root, mentorID);
    MentorTreeNode* studentNode = findNode(root, studentID);
    if (mentorNode == nullptr || studentNode == nullptr) {
        std::cout << "导师或学生未找到" << std::endl;
        return false;
    }
    return isIndirectMentorHelper(mentorNode, studentNode, maxGenerations);
}

bool PeerMentorshipTree::isIndirectMentorHelper(MentorTreeNode* currentNode, MentorTreeNode* studentNode, int maxGenerations) {
    if (maxGenerations < 0) {
        return false;
    }
    if (currentNode == studentNode) {
        return true;
    }
    for (MentorTreeNode* child : currentNode->children) {
        if (isIndirectMentorHelper(child, studentNode, maxGenerations - 1)) {
            return true;
        }
    }
    return false;
}
