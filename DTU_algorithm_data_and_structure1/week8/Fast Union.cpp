#include <iostream>
#include <vector>
using namespace std;

class QuickUnion {
public:
    // 快速并查集的构造函数，初始化id数组，使得每个元素的父节点为其本身
    QuickUnion(int n) {
        for (int i = 0; i < n; ++i) {
            id.push_back(i);
        }
    }

    // 查找p的根节点
    int find(int p) {
        while (p != id[p]) {
            p = id[p];
        }
        return p;
    }

    void unionSets(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) {
            return;
        }
        id[rootP] = rootQ;
    }

private:
    std::vector<int> id;
};

int main() {
    int N, M;
    std::cin >> N >> M;

    QuickUnion qu(N);

    for (int i = 0; i < M; ++i) {
        char operation;
        int x, y;
        std::cin >> operation >> x;

        if (operation == 'F') {
            std::cout << qu.find(x) << std::endl;
        } else if (operation == 'U') {
            std::cin >> y;
            qu.unionSets(x, y);
        }
    }

    return 0;
}
