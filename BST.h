
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

    // int findPredecessor(TreeNode * t, int num);

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

    void destroyTree();

    int isTreeBalanced();

    // int getPredecessor(int num);

    void deleteLeafNode(int num);

};
