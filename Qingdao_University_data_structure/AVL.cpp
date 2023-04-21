#include<iostream>
using namespace std;

class TreeNode
{
public:
    int key, height;
    TreeNode* left;
    TreeNode* right;
    // 树节点构造函数, 初始化节点值，高度和左右子节点。
    TreeNode(int key):key(key),height(1),left(NULL),right(NULL){}
};

class AVLTree
{
public:
    TreeNode* root;

    // AVL构造函数，初始化根节点为空
    AVLTree(): root(NULL){}
    
    int height(TreeNode*node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return node->height;
    }

    // 计算节点的平衡因子
    int balanceFactor(TreeNode* node)
    {
        return height(node->left) - height(node->right);
    }

    // 对节点x左旋
    TreeNode* leftRotate(TreeNode* x)
    {
        if (x == nullptr || x->right == nullptr) {
        return x;
    }
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        // 更新x和y的高度
        x->height = max(height(x->left),height(x->right))+1;
        y->height = max(height(y->left),height(y->right))+1;

        return y;
    }

    // 对节点y右旋
    TreeNode* rightRotate(TreeNode *y)
    {
        if (y == nullptr || y->left == nullptr) {
        return y;
    }

        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        // 更新y和x的高度
        y->height = max(height(y->left),height(y->right))+1;
        x->height = max(height(x->left),height(x->right))+1;

        return x;
    }

    // 插入节点并保持AVL树的平衡
    TreeNode* insert(TreeNode* node, int key)
    {
        if (node == NULL)
        {
            return new TreeNode(key);
        }

        if (key <node->key)
        {
            node->left = insert(node->left,key);
        }else if(key > node->key)
        {
            node->right = insert(node->right,key);
        }else
        {
            return node;
        }

        // 更新节点的高度
        node->height = max(height(node->left),height(node->right))+1;

        int balance = balanceFactor(node);

        cout << "Key: " << key << " | Node: " << node->key << " | Balance: " << balance << endl;

        // 左-左情况
        if(balance > 1 && key < (node->left != nullptr ? node->left->key : 0))
        {
            return rightRotate(node);
        }

        // 右-右情况
        if(balance < -1 && key > (node->right != nullptr ? node->right->key : 0))
        {
            return leftRotate(node);
        }

        // 左-右情况
        if(balance > 1 && key > (node->left != nullptr ? node->left->key : 0))
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // 右-左情况
        if (balance < -1 && key < (node->right != nullptr ? node->right->key : 0))
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        
        return node;
    }

    // 插入新节点
    void insert(int key)
    {
        root = insert(root,key);
    }

    void insertAndPrint(int key) {
    root = insert(root, key);
    cout << "After inserting " << key << ":\n";
    printTree(root, 0);
    cout << endl;
}

    void inorderTraversal()
    {
        inorderTraversalHelper(root);
        cout << endl;
    }

private:
    void inorderTraversalHelper(TreeNode* node)
    {
        if(node !=NULL)
        {
            inorderTraversalHelper(node->left);
            cout << node->key <<" ";
            inorderTraversalHelper(node->right);
        }
    }

    void printTree (TreeNode * node ,int level)
{
    if (node == nullptr)
    {
        return;
    }

    printTree(node->right,level+1);

    for (int i = 0; i < level; ++i)
    {
        cout << " ";
    }
    cout << node->key << endl;
    printTree(node->left,level+1);
}
};



int main()
{
    AVLTree avl;

    avl.insertAndPrint(16);
    avl.insertAndPrint(3);
    avl.insertAndPrint(7);
    avl.insertAndPrint(11);
    avl.insertAndPrint(9);
    avl.insertAndPrint(26);
    avl.insertAndPrint(18);
    avl.insertAndPrint(14);
    avl.insertAndPrint(15);

    return 0;
}