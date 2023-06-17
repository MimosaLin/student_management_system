#include "BST.h"

BST::BST() {
    root = nullptr;
}

TreeNode* BST::insertHelper(TreeNode* node, BSTree::Student student) {
    if (node == nullptr) {
        node = new TreeNode;
        node->student = student;
        node->left = nullptr;
        node->right = nullptr;
    }
    else if (student.score < node->student.score) {
        node->left = insertHelper(node->left, student);
    }
    else {
        node->right = insertHelper(node->right, student);
    }
    return node;
}

TreeNode* BST::deleteHelper(TreeNode* node, int score) {
    if (node == nullptr) {
        return node;
    }
    if (score < node->student.score) {
        node->left = deleteHelper(node->left, score);
    }
    else if (score > node->student.score) {
        node->right = deleteHelper(node->right, score);
    }
    else {
        if (node->left == nullptr) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }
        TreeNode* minNode = findMin(node->right);
        node->student = minNode->student;
        node->right = deleteHelper(node->right, minNode->student.score);
    }
    return node;
}

TreeNode* BST::findMin(TreeNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void BST::updateHelper(TreeNode* node, int score, int newScore) {
    if (node == nullptr) {
        return;
    }
    if (score < node->student.score) {
        updateHelper(node->left, score, newScore);
    }
    else if (score > node->student.score) {
        updateHelper(node->right, score, newScore);
    }
    else {
        node->student.score = newScore;
    }
}

TreeNode* BST::searchHelper(TreeNode* node, int score) {
    if (node == nullptr || node->student.score == score) {
        return node;
    }
    if (score < node->student.score) {
        return searchHelper(node->left, score);
    }
    else {
        return searchHelper(node->right, score);
    }
}

void BST::inorderTraversalHelper(TreeNode* node) {
    if (node != nullptr) {
        inorderTraversalHelper(node->left);
        std::cout << "ID: " << node->student.id << " Name: " << node->student.name << " Score: " << node->student.score << std::endl;
        inorderTraversalHelper(node->right);
    }
}

void BST::insert(BSTree::Student student) {
    root = insertHelper(root, student);
}

void BST::remove(int score) {
    root = deleteHelper(root, score);
}

void BST::update(int score, int newScore) {
    updateHelper(root, score, newScore);
}

TreeNode* BST::search(int score) {
    return searchHelper(root, score);
}

void BST::inorderTraversal() {
    inorderTraversalHelper(root);
}
