#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 计算Bob需要购买的最小组件数
int min_components (int N, int M, vector<int> & components)
{
    sort(components.begin(),components.end(),greater<int>());  // 将其从大到小排序
    int total = 0; // 节点总数
    int count = 0;  // 组件总数

    for (int i = 0; i < components.size();i++)
    {
        total = total + components[i];
        count++;
        if (total > N)
        {
            break;
        }
    }
    return count;

}

int main()
{
    int N;
    cin >> N;
    int M;
    cin >> M;

    vector<int> components(M);
    for(int i = 0;i < M; i++)
    {
        cin >> components[i];
    }
    int result = min_components(N,M,components);
    cout << result << endl;

    return 0;

}