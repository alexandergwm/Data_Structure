#include<iostream>
using namespace std;

class TreeNode
{
public:
    int key;
    TreeNode* left;
    TreeNode* right;

    // 构造函数，初始化节点值和左右子节点
    TreeNode(int key):key(key),left(NULL),right(NULL){}
};

class BinarySearchTree
{
public:
    TreeNode* root;

    // 构造函数，初始化根节点为空
    BinarySearchTree(): root(NULL){}

    // 插入节点
    void insert(int key)
    {
        root = insert(root,key);
    }

    TreeNode * insert(TreeNode * node,int key)
    {
        // 如果当前节点为空，创建并返回一个新节点
        if (node == nullptr)
        {
            return new TreeNode(key);
        }
        // 根据key值决定在左子树还是右子树插入新节点
        if(key < node->key)
        {
            node->left = insert(node->left,key);
        }
        else
        {
            node->right = insert(node->right,key);
        }
        return node;
    }

    // 查找key值
    TreeNode *search(int key)
    {
        return search(root,key);
    }

    TreeNode * search(TreeNode * node,int key)
    {
        // 如果当前节点为空或者找到目标key，那么返回当前节点
        if (node == nullptr || key == node->key)
        {
            return node;
        }
        // 根据key值决定在左子树还是右子树插入新节点
        if (key < node->key)
        {
            return search(node->left,key);
        }
        return search(node->right,key);
    }

    // 删除节点
    void  remove(int key)
    {
        root = remove(root,key);
    }

    // 递归的删除
    TreeNode * remove(TreeNode * node,int key)
    {
        // 如果当前节点为空，那么直接返回
        if (node == NULL)
        {
            return node;
        }
        // 根据key值决定在左子树还是右子树插入新节点
        if (key < node->key)
        {
            node->left = remove(node->left,key);
        } else if (key > node->key)
        {
            node->right = remove(node->right,key);
        } else
        {
            // 如果找到目标节点，进行删除
            if (node->left == NULL)
            {
                TreeNode * temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr)
            {
                TreeNode * temp = node->left;
                delete node;
                return temp;
            }
            // 用右子树的最小值替换当前节点的值，并删除右子树的最小节点
            if (node->right != NULL) {
                TreeNode* successor = minValueNode(node->right);
                node->key = successor->key;
                node->right = remove(node->right, successor->key);
        }
        }
        return node;
    }

    // 函数，找到树的最小值
    TreeNode* minValueNode(TreeNode* node) {
        if (node == NULL) {
            return NULL;
        }
        while (node->left != NULL) {
            node = node->left;
        }
        return node;    
    }   

    // 打印二叉树
    void inorderTraversal()
    {
        inorderTraversalHelper(root);
        cout << endl;
    }
private:
    // 递归中序遍历二叉树
    void inorderTraversalHelper(TreeNode * node)
    {
        if (node!=NULL)
        {
            inorderTraversalHelper(node->left);
            cout << node->key << " ";
            inorderTraversalHelper(node->right);
        }
    }

};

int main()
{
    BinarySearchTree bst;
    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(14);
    bst.insert(4);
    bst.insert(7);
    bst.insert(13);

    cout << "Inorder traversal before removal:" << endl;
    bst.inorderTraversal();

    bst.remove(3);

    cout << "Inorder traversal after removal:" << endl;
    bst.inorderTraversal();
    return 0;
}