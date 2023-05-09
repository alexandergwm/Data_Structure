#include<iostream>
#include<vector>
using namespace std;

class UnionFind{
public:
    UnionFind(int n): parent(n)
    {
        for(int i = 0;i < n;i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if(parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void union_sets(int x, int y)
    {
        parent[find(x)] = find(y);
    }

    bool connected(int x,int y)
    {
        return find(x) == find(y);
    }

private:
    vector<int> parent;
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);

    for (int i = 0; i < m; ++i) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == 'A') {
            uf.union_sets(a, b);
        } else if (op == 'C') {
            cout << (uf.connected(a, b) ? "YES" : "NO") << endl;
        }
    }

    return 0;
}