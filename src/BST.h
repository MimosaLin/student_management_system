#pragma once
#include"studentsStruct.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>



struct TreeNode {
    BSTree::Student student;
    TreeNode* left;
    TreeNode* right;
};

class BST {
private:
    TreeNode* root;

    TreeNode* insertHelper(TreeNode* node, BSTree::Student student);
    TreeNode* deleteHelper(TreeNode* node, int score);
    TreeNode* findMin(TreeNode* node);
    void updateHelper(TreeNode* node, int score, int newScore);
    TreeNode* searchHelper(TreeNode* node, int score);
    void inorderTraversalHelper(TreeNode* node);

public:
    BST();
    void insert(BSTree::Student student);
    void remove(int score);
    void update(int score, int newScore);
    TreeNode* search(int score);
    void inorderTraversal();
};
