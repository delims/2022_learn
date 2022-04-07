//
//  _03_07.cpp
//  cpp_test
//
//  Created by delims on 2022/3/7.
//

#include <stdio.h>
#include <math.h>

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int value;
    TreeNode():left(nullptr),right(nullptr),value(0){}
};


int treeDepth(TreeNode* node) {
    if (node == nullptr) return 0;
    int leftDeep = treeDepth(node->left);
    int rightDeep = treeDepth(node->right);
    if (leftDeep > rightDeep) {
        return leftDeep + 1;
    } else return rightDeep + 1;
}

int height(TreeNode *node) {
    if (node == nullptr) return 0;
    int rightHeight = height(node->right);
    int leftHeight = height(node->left);
    if (rightHeight > leftHeight) return rightHeight + 1;
    else return leftHeight + 1;
};

bool isAVLTree(TreeNode *node) {
    if (node == nullptr) return true;
    if (abs(height(node->left) - height(node->right)) <= 1)
        return isAVLTree(node->left) && isAVLTree(node->right);
    else return false;
}

struct AA {
    long long mem;
};

void _03_07()
{
//    AA b;
//
//    AA *a = &b;
    
    
    printf("hello delims !\n");
    
}
