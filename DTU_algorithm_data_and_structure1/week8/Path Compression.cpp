#include<iostream>
#include<vector>
using namespace std;

class WeightedQuickUnionWithPathCompression{
public:
    WeightedQuickUnionWithPathCompression(int n):count(n), parent(n),size(n,1)
    {
        for (int i = 0; i< n;i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        int root = x;
        while (root != parent[root])
        {
            root = parent[root];
        }

    // 路径压缩
    while (x != root)
    {
        int temp = parent[x];
        parent[x] = root;
        x = temp;
    }

    return root;
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }

    void union_sets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY) 
        {
            return;
        }
        // 将较小树连接到较大树上
        if (size[rootX] > size[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        }
        count--;
    }
    
    int count_groups()
    {
        return count;
    }

private:
    int count;
    vector<int> parent;
    vector<int> size;
};

int main() {
    int n = 5;
    WeightedQuickUnionWithPathCompression uf(n);
    uf.union_sets(1, 2);
    uf.union_sets(1, 4);
    cout << uf.find(1) << endl;
    cout << uf.find(2) << endl;
    cout << uf.find(0) << endl;
    return 0;
}