// Huffman树原理
// 假设有n个权值，构造出的Huffman树有n个叶子结点。n个权值分别设为w1,w2,...,wn，那么哈夫曼树构造规则为：
// 1、将w1,w2,...,wn看作为有n棵树的森林（每棵树只有一个结点）
// 2、在森林中选出两个根结点的权值最小的树合并，作为一棵新树的左、右子树，且新树的根结点权值为其左、右子树根节点权值之和
// 3、从森林中删除选取的两棵树，并将新树加入森林。
// 4、重复2，3步，直到森林中只剩一棵树为止，那么现在这棵树就是哈夫曼树

// 那么对n个权值，构造Huffman树需要合并n-1次，形成的树结点总数为2n-1

// 根据huffman树，我们利用数组来存储每个结点

#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;

// 节点具有以下结构
// weight: 权值
// parent: 父节点在数组中的位置（同时判断该节点是否已经参与合并）
// lchild,rchild: 左右孩子节点在数组中的位置
// code: 该节点分配的编码
struct HNode
{
    float weight;  // 权值
    int parent;    // 父节点，父节点主要用来判断一个节点是否已经加入哈夫曼树
    int lchild, rchild;  // 左孩子，右孩子
    string code;   // 记录节点编码
    HNode()
    {
        weight = 0;
        parent = lchild = rchild = -1;
        code = ' ';
    }
    HNode(float w)
    {
        weight = w;
        parent = lchild = rchild = -1;
        code = ' ';
    }
};

class HuffmanTree
{
    HNode * Tree;  //哈夫曼树节点数组头部
    int TreeSize;  //树中节点数总数，TreeSize = 叶子节点n*2-1
public:
    HuffmanTree()
    {
        Tree = nullptr;
        TreeSize = 0;
    }
    ~HuffmanTree()
    {
        delete[] Tree;
    }
    // 构造哈夫曼树，输入权值数组 和 数组长度n
    void Create(float *a, int n)
    {
        TreeSize = 2 * n -1;   // 确定哈夫曼树的结点个数
        Tree = new HNode[TreeSize];
        // 将权值数组保存在哈夫曼数组的前n个数值
        for (int i =0; i<n; i++)
        {
            Tree[i].weight = a[i];
        }

        // 开始进行n-1次合并操作，形成一棵哈夫曼树
        int s1, s2;
        int nextPos = (TreeSize +1) / 2;  // 记录下一个插入位置，起始为n
        for (int i = 0; i< (TreeSize-1)/2;i++)
        {
            SelectTwoMin(nextPos,s1,s2);  // 找到数组中权值最小的两个点
            // 对Tree中新节点的孩子结点及权值赋值
            Tree[nextPos].lchild = s1;
            Tree[nextPos].rchild = s2;
            Tree[nextPos].weight = Tree[s1].weight + Tree[s2].weight;
            // 给这两个结点分配父结点（意味两个结点已经加入哈夫曼树）
            Tree[s1].parent = Tree[s2].parent = nextPos;
            nextPos++;
        }
    }
    
    // 寻找数组中权值最小的两个点
    void SelectTwoMin(int nextPos, int &s1, int &s2)
    {
        // 找到第一个未加入哈夫曼树的结点，标记未s1
        int i = 0;
        while(Tree[i].parent != -1)
        {
            i++;
        }
        // 从s1后一位开始找到第二个未加入哈夫曼树的结点，标记为s2
        s1 = i;
        int j = i+1;
        while(Tree[j].parent != -1)
        {
            j++;
        }
        s2 = j;
        // 调整s1 和s2对应的权值大小，确保s1对应点的权值更小，从而寻找更小的点时只需要与s2进行比较
        KeepOrder(s1,s2);

        // 从s2后一位开始，和s1,s2进行比较，从而确定数组中权重最小的两个点
        for (int k = j +1; k <nextPos; k++)
        {
            if (Tree[k].parent == -1)
            {
                if(Tree[k].weight < Tree[s2].weight)
                {
                    s2 = k;
                    // 找到小于s2的点后，需和s1比较确定大小顺序
                    KeepOrder(s1,s2);
                }
            }
        }
    }

    // 确保n1对应结点的权值小于n2
    void KeepOrder(int &n1, int &n2)
    {
        if (Tree[n1].weight > Tree[n2].weight)
        {
            float tmp = n1;
            n1 = n2;
            n2 = tmp;
        } 
    }

    // 输出构建完成的哈夫曼树
    void PrintTree()
    {
        cout << "index weight parent lchild rchild" << endl;
        for (int i = 0; i < TreeSize; i++)
        {
            cout << setw(5) << i;
            cout << setw(6) << Tree[i].weight;
            cout << setw(6) << Tree[i].parent;
            cout << setw(6) << Tree[i].lchild;
            cout << setw(6) << Tree[i].rchild;
            cout << endl; 
        }
    }

    // 对树中结点编码并输出
    void PrintCoder()
    {
        cout << "index weight     code" << endl;
        queue<int> codeQueue;    // 只保存编号
        int tmp;
        codeQueue.push(TreeSize - 1);
        while(!codeQueue.empty())
        {
            tmp = codeQueue.front();
            codeQueue.pop();
            if (Tree[tmp].lchild == -1 && Tree[tmp].rchild == -1)
            {
                // 叶子结点直接输出
                cout << setw(5) << tmp << setw(6) << Tree[tmp].weight << setw(10) << Tree[tmp].code << endl;

            }
            else
            {
                // 因为哈夫曼树只有N0和N2
                codeQueue.push(Tree[tmp].lchild);
                Tree[Tree[tmp].lchild].code = Tree[tmp].code + "1";    // 对左孩子编码

                codeQueue.push(Tree[tmp].rchild);
                Tree[Tree[tmp].rchild].code = Tree[tmp].code + "0";    // 对右孩子编码
            }
        }
    }
};

int main()
{
    ///哈夫曼树
    HuffmanTree hTree;
	float x[] = {5,29,7,8,14,23,3,11};
	hTree.Create(x,sizeof(x));
    hTree.PrintTree();
	hTree.PrintCoder();

}


