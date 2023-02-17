// 二叉树是一种常用的树型数据结构,这个程序包含了二叉树常用的几种遍历方式：前序遍历，中序遍历和后序遍历
// 其中分别使用了递归和非递归的方法来实现
// 前序遍历：根，左，右
// 中序遍历：左，根，右
// 后续遍历：左，右，根

#include<iostream>
#include<stack>
#include<queue>
using namespace std;
typedef string Elemtype;


// 定义二叉树的节点
typedef struct BinaryNode
{
    //节点
    Elemtype data;
    //左子树
    BinaryNode * left;
    //右子树
    BinaryNode * right;
    BinaryNode(Elemtype data):data(data),left(nullptr),right(nullptr){}
}BinaryNode, *BiTree;
// 创建二叉树的类
class BinaryTree
{
public:
    // 创建一棵树
    void createTree();
    // 创建一个结点
    BiTree create();
    // 递归前序遍历
    void preOrder();
    // 非递归前序遍历
    void nonRec_preOrder();
    // 递归中序遍历
    void inOrder();
    // 非递归中序遍历
    void nonRec_inOrder();
    // 递归后序遍历
    void postOrder();
    // 非递归后序遍历
    void nonRec_postOrder();
    // 层次遍历 （用队列保存每一层的结点，一层层访问）
    void nonRec_levelOrder();

    
  
private:
    BinaryNode * mRoot;  // 根节点
    int size;  // 节点总数
    // 递归前序遍历
    void preOrder(BiTree root);
    // 非递归前序遍历
    void nonRec_preOrder(BiTree root);
    // 递归中序遍历
    void inOrder(BiTree root);
    // 非递归中序遍历
    void nonRec_inOrder(BiTree root);
    // 递归后续遍历
    void postOrder(BiTree root);
    // 非递归后续遍历
    void nonRec_postOrder(BiTree root);
    // 层次遍历 （用队列保存每一层的结点，一层层访问）
    void nonRec_levelOrder(BiTree root);
};



// 用前序遍历方式递归创建二叉树
BiTree BinaryTree::create()
{
    Elemtype value;
    cin >> value;
    if (value == "#")
    {
        return nullptr;
    }
    else
    {   
        // 递归创建左右子树，用size记录下树的结点数
        size++;
        BinaryNode * newNode = new BinaryNode(value);
        newNode->left = create();
        newNode->right = create();
        return newNode;
    }

}
void BinaryTree::createTree()
{
    size = 0;
    mRoot = create();
}

// 递归实现前序遍历二叉树
void BinaryTree::preOrder(BiTree root)
{
    if (root!=nullptr)
    {
        cout << root->data <<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void BinaryTree::preOrder()
{
    cout << "The result of the preoder traversal is " << endl;
    preOrder(mRoot);
    cout << endl;
}


// 非递归实现前序遍历二叉树
void BinaryTree::nonRec_preOrder(BiTree root)
{
    if(root == nullptr)
    {
        return;
    }
    stack<BiTree> s;
    BiTree p = root;
    s.push(p);
    while(!s.empty())
    {
        BiTree node = s.top();
        cout << node->data <<" ";
        s.pop();
        if(node->right)
        {
            s.push(node->right);
        }
        if(node->left)
        {
            s.push(node->left);
        }
    }
}

void BinaryTree::nonRec_preOrder()
{
    cout << "The result of the non-recursive preorder traversal is " << endl;
    nonRec_preOrder(mRoot);
    cout << endl;
}


// 递归实现中序遍历
void BinaryTree::inOrder(BiTree root)
{
    if(root != nullptr)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void BinaryTree::inOrder()
{
    cout << "The result of the in-order traversal is " << endl;
    inOrder(mRoot);
    cout << endl;
}


// 非递归实现中序遍历
void BinaryTree::nonRec_inOrder(BiTree root)
{
    if(root == nullptr)
    {
        return;
    }
    stack <BiTree> myStack;
    BiTree rt = root;
    while(rt != nullptr || !myStack.empty())
    {
        while(rt != nullptr)
        {
            myStack.push(rt);
            rt = rt->left;
        }
        rt = myStack.top();
        myStack.pop();
        cout << rt->data <<" ";
        rt = rt->right;
    }
}

void BinaryTree:: nonRec_inOrder()
{
    cout << "The result of the non-recursive in-order traversal is " << endl;
    nonRec_inOrder(mRoot);
    cout << endl;
}


// 递归实现后序遍历
void BinaryTree::postOrder(BiTree root)
{
    if(root!=nullptr)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}
void BinaryTree::postOrder()
{
    cout << "The result of the postorder traversal is " << endl;
    postOrder(mRoot);
    cout << endl;
}


// 非递归后续遍历
void BinaryTree::nonRec_postOrder(BiTree root)
{
    // 这里需要用到两个栈，采用双栈法
    // 栈s1入栈顺序：根结点->左结点->右结点
    // 栈s2入栈顺序：右结点->左结点->根结点
    // 出栈顺序：根结点-> 左结点 -> 右结点
    if(root == nullptr)
    {
        return;
    }
    stack<BiTree> s1;
    stack<BiTree> s2;
    s1.push(root);
    while(!s1.empty())
    {
        BiTree p = s1.top();
        s1.pop();
        s2.push(p);
        if(p->left)
        {
            s1.push(p->left);
        }
        if(p->right)
        {
            s1.push(p->right);
        }
    }
    while(!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }

}
void BinaryTree::nonRec_postOrder()
{
    cout << "The result of the non-recursive postorder trasversal is " << endl;
    nonRec_postOrder(mRoot);
    cout << endl;
}

// 层次遍历
void BinaryTree::nonRec_levelOrder(BiTree root)
{
    queue<BiTree> q;
    q.push(root);
    while(!q.empty())
    {
        int num_level = q.size();
        while(num_level--)
        {
            BiTree node = q.front();
            q.pop();
            cout << node->data << " ";
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
    }
}
void BinaryTree::nonRec_levelOrder()
{
    cout << "The result of the non-recursive sequence traversal is "<<endl;
    nonRec_levelOrder(mRoot);
    cout << endl;
}

int main()
{
    BinaryTree tree;
    cout << "Please enter the tree in the previos order traversal mode. If the node is empty, use # instead:" << endl;
    //"A B D G # # H # # # C E # I # # F # #";
    tree.createTree();
    tree.preOrder();
    tree.nonRec_preOrder();
    tree.inOrder();
    tree.nonRec_inOrder();
    tree.postOrder();
    tree.nonRec_postOrder();
    tree.nonRec_levelOrder();
    return 0;
}