#pragma once
#include"studentsStruct.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>



struct TreeNode {
    AVLBSTree::Student student;
    TreeNode* left;
    TreeNode* right;
};

class AVLBST {
private:
    TreeNode* root;

    TreeNode* insertHelper(TreeNode* node, AVLBSTree::Student student);
    TreeNode* deleteHelper(TreeNode* node, int score);
    TreeNode* findMin(TreeNode* node);
    void updateHelper(TreeNode* node, int score, int newScore);
    TreeNode* searchHelper(TreeNode* node, int score);
    void inorderTraversalHelper(TreeNode* node);

public:
    AVLBST();
    void insert(AVLBSTree::Student student);
    void remove(int score);
    void update(int score, int newScore);
    TreeNode* search(int score);
    void inorderTraversal();
};
