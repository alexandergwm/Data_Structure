#include <iostream>
#include <vector>
using namespace std;

class QuickFind{
public:
    QuickFind(int n)
    {
        for (int i = 0; i < n;i++)
        {
            id.push_back(i);
        }
    }

    // 查找元素p所属的租
    int find(int p)
    {
        return id[p];
    }

    // 合并包含元素p和q的组
    void unionSets(int p, int q)
    {
        int idP = find(p);
        int idQ = find(q);
        if(idP == idQ)
        {
            return;
        }
        for(int i =0 ;i < id.size();i++)
        {
            if(id[i] == idP)
            {
                id[i] = idQ;
            }
        }
    }
private:
    vector<int> id;
};

int main() {
    int N, M;
    std::cin >> N >> M;

    QuickFind qf(N);

    for (int i = 0; i < M; ++i) {
        char operation;
        int x, y;
        std::cin >> operation >> x;

        // 对于Find操作，输出元素x所在组
        if (operation == 'F') {
            std::cout << qf.find(x) << std::endl;
        }
        // 对于Union操作，合并包含元素x和y的组
        else if (operation == 'U') {
            std::cin >> y;
            qf.unionSets(x, y);
        }
    }

    return 0;
}