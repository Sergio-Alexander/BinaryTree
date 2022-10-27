#include <iostream>
#include <cmath>
#include "BST.h"

BST::TreeNode* BST::insert(TreeNode* t, int x){
    if (t == nullptr){
        t = new BST::TreeNode();
        t -> val = x;
    } else if (x == t -> val){
        std::cout << "Value is already in the tree, NO DUPLICATES ALLOWED";
    } 
    else if (x < t -> val){
        t -> left = insert(t -> left, x);
    } else if (x > t -> val){
        t -> right = insert(t -> right, x);
    }
    return t;
}

void BST::inorder(TreeNode* t){
    if (t == nullptr){
    return;
    }
    inorder(t -> left);
    std::cout << t -> val << " ";
    inorder(t -> right);
}

void BST::preorder(TreeNode* t){
    if (t == nullptr){
        return;
    }
    std::cout << t -> val << " ";
    preorder(t -> left);
    preorder(t -> right);
};
void BST::postorder(TreeNode* t){
    if (t == nullptr){
        return;
    }
    postorder(t -> left);
    postorder(t -> right);
    std::cout << t -> val << " ";
};

BST::BST(){
    root = nullptr;
}

void BST::insertNode(int x) {
    root = insert(root, x);
}

void BST::inorderDisplay() {
    inorder(root);
}

void BST::preorderDisplay(){
    preorder(root);
}

void BST::postorderDisplay(){
    postorder(root);
}

int BST::findHeight(TreeNode* t) {
    if (t == nullptr){
        return 0;
    }
    int leftHeight = findHeight(t -> left);
    int rightHeight = findHeight(t -> right);

    if (leftHeight > rightHeight){
        return 1 + leftHeight;
    } else{
        return 1 + rightHeight;
    }
}

int BST::getHeight() {
    return findHeight(root);
}

int BST::findValue(TreeNode* t, int num) {
    if (t == nullptr){
        return -1;
    }
    if (num == t -> val){
        return 1;
    }
    if (num > t -> val){
        return findValue(t -> right, num);
    } else{
        return findValue(t -> left, num);
    }

}
int BST::getValue(int num) {
    return findValue(root, num);
}

int BST::findTotalNodes(TreeNode *t) {
    if (t == nullptr){
        return 0;
    }
    return 1 + findTotalNodes(t -> left) + findTotalNodes(t -> right);
}

int BST::getTotalNodes() {
    return findTotalNodes(root);
}

void BST::demolishTree(TreeNode * t) {
    if (t == nullptr){
        return;
    }

    demolishTree(t -> left);
    demolishTree(t -> right);
    delete t;
    t = nullptr;
}

void BST::destroyTree() {
    demolishTree(root);
    root = nullptr;
    std::cout << "Tree has been destroyed";
}


int BST::checkIfBalanced(TreeNode * t){
    if (t == nullptr){
        return 1;
    }

    int leftIsBalanced = checkIfBalanced(t -> left);
    int rightIsBalanced = checkIfBalanced(t -> right);

    int leftHeight = findHeight(t -> left);
    int rightHeight = findHeight(t -> right);


    return (leftIsBalanced == 1) && (rightIsBalanced == 1) && (std::abs(leftHeight - rightHeight) <= 1);
}


int BST::isTreeBalanced(){
    return checkIfBalanced(root);
}

BST::TreeNode* BST::deleteNode(TreeNode * t, int num){
    if (t == nullptr){
        return nullptr;
    }

    t -> left = deleteNode(t -> left, num);
    t -> right = deleteNode(t -> right, num);

    if (t -> val == num && t -> left == NULL && t -> right == NULL) {
        return nullptr;
    }
    return t;
}

void BST::deleteLeafNode(int num){
    root = deleteNode(root, num);
}

// int BST::findPredecessor(TreeNode * t, int num){

//     if (t == nullptr){
//         return 0;
//     } else if (t -> right == nullptr){
//         return t -> val;
//     } else{
//         return findPredecessor(t -> left);
//     }
// }

// void BST::getPredecessor(int num){

//     if (num < root){

//     }

//    num = findPredecessor(root -> left);
//    std::cout << num;
// }
