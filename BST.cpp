#include <iostream>
#include <cmath>
#include "BST.h"
#include <vector>

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

void BST::whatever(TreeNode * t, std::vector<int> &arr){
    if (t == nullptr){
        return;
    }
    whatever(t -> left, arr);
    arr.push_back(t -> val);
    whatever(t -> right, arr);
}

 std::vector<int> BST::getArr(TreeNode * t, int num){
    std::vector<int> arr;

    whatever(t, arr);
    return arr;
}

int BST::getPredecessor(int num){
    std::vector<int> arr = getArr(root, num);
    for (int i = 0; i < arr.size(); i++){
        if (num == arr[i]){
            if (i == 0){
                return -1;
            }
            return arr[i - 1];
        }
    }
    return -1;
}

int BST::getSuccessor(int num){
    std::vector<int> arr = getArr(root, num);
    for (int i = 0; i < arr.size(); i++){
        if (num == arr[i]){
            if (i == arr.size() - 1){
                return -1;
            }
            return arr[i + 1];
        }
    }
    return -1;
}

int BST::getPredecessorV2(int num){
    TreeNode * pred_node = nullptr;
    TreeNode * curr_node = root;

    while (curr_node -> val != num){
        if (curr_node -> val < num){
            pred_node = curr_node;
            curr_node = curr_node -> right;
        } else if (curr_node -> val > num){
            curr_node = curr_node -> left;
        } 
    }

    curr_node = curr_node -> left;

    while (curr_node != nullptr){
        pred_node = curr_node;
        curr_node = curr_node -> right;
    }

    if (pred_node == nullptr){
        return -1;
    }
    
    return pred_node -> val;
}

int BST::getSuccessorV2(int num){
    TreeNode * succ_node = nullptr;
    TreeNode * curr_node = root;

    while (curr_node -> val != num){
        if (curr_node -> val < num){
            curr_node = curr_node -> right;
        } else if (curr_node -> val > num){
            succ_node = curr_node;
            curr_node = curr_node -> left;
        } 
    }
    curr_node = curr_node -> right;

    while (curr_node != nullptr){
        succ_node = curr_node;
        curr_node = curr_node -> left;
    }

    if (succ_node == nullptr){
        return -1;
    }

    return succ_node -> val;
}