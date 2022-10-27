#include <iostream>
#include <vector>


class BST {
private:
    struct TreeNode {
        int val;
        TreeNode * left;
        TreeNode * right;
    };

    TreeNode * root;

// private function declarations here
    TreeNode* insert(TreeNode * t, int x);
    void inorder(TreeNode * t);
    void preorder(TreeNode * t);
    void postorder(TreeNode * t);

    int findHeight(TreeNode * t);

    int findValue(TreeNode * t, int num);

    int findTotalNodes(TreeNode * t);

    void demolishTree(TreeNode * t);

    int checkIfBalanced(TreeNode * t);

    TreeNode* deleteNode(TreeNode * t, int num);


public:
    // public function declarations here
    BST();
    void insertNode(int x);
    void inorderDisplay();
    void preorderDisplay();
    void postorderDisplay();

    int getHeight();

    int getValue(int num);

    int getTotalNodes();

    TreeNode* destroyTree();

    int isTreeBalanced();

    void deleteLeafNode(int num);


    std::vector<int> getArr(TreeNode * t, int num);

    void whatever(TreeNode * t, std::vector<int> &arr);

    int getPredecessor(int num);

    int getSuccessor(int num);

    int getPredecessorV2(int num);

    int getSuccessorV2(int num);

};
