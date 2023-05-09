#include<iostream>
#include<vector>
using namespace std;

class WeightedUnion{
public:
    // 构造函数，初始化id数组，每个元素的组为其自身
    WeightedUnion(int n)
    {
        for(int i = 0;i < n;i++)
        {
            id.push_back(i);
            sz.push_back(1);
        }
    }
    
    // 查找元素p的根节点
    int find(int p)
    {
        while(p != id[p])
        {
            p = id[p];
        }
        return p;
    }

    // 合并包含元素p和元素q的组
    void unionSets(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
        {
            return;
        }

        // 将较小的树连接到较大的树
        if (sz[rootP] < sz[rootQ])
        {
            id[rootP] = rootQ;
            sz[rootQ] += sz[rootP];
        }
        else
        {
            id[rootQ] = rootP;
            sz[rootP] += sz[rootQ];
        }
    }
private:
    vector<int> id;   // 存储每个元素的值
    vector<int> sz;   // 存储每个根节点的大小
};

int main() {
    int N, M;
    std::cin >> N >> M;

    WeightedUnion wu(N);

    for (int i = 0; i < M; ++i) {
        char operation;
        int x, y;
        std::cin >> operation >> x;

        // 对于Find操作，输出元素x的根节点
        if (operation == 'F') {
            std::cout << wu.find(x) << std::endl;
        }
        // 对于Union操作，合并包含元素x和y的组
        else if (operation == 'U') {
            std::cin >> y;
            wu.unionSets(x, y);
        }
    }

    return 0;
}