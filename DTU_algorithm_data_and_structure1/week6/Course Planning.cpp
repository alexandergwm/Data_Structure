#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int minSemesters(int N, vector<vector<int>> & dependencies)
{
    // 初始化入度数组和邻接表
    vector<int> in_degrees(N+1,0);
    vector<vector<int>> adj_list(N+1);

    // 根据依赖关系构建邻接表和入度数组
    for (auto &dep : dependencies)
    {
        int course = dep[0];
        int prerequisite = dep[1];
        adj_list[prerequisite].push_back(course);
        in_degrees[course]++;
    }

    // 将入度为0的节点加入队列
    queue <int> q;
    for (int i = 1;i<=N;i++)
    {
        if (in_degrees[i] == 0)
        {
            q.push(i);
        }
    }

    int semester = 0;
    // 当队列不为空时
    while(!q.empty())
    {
        int sz = q.size();
        semester++;
        // 遍历当前层的节点
        for (int i = 0;i<sz;i++)
        {
            int curr = q.front();
            q.pop();
            // 遍历邻接节点
            for (int neighbor: adj_list[curr])
            {
                // 更新邻接节点的入度
                if(--in_degrees[neighbor] == 0)
                {
                    // 如果邻接节点的入度为0，将其加入队列
                    q.push(neighbor);
                }
            }
        }

    }
    return semester;
}

int main()
{
    int N, E;
    cout << "Enter the number of courses and dependencies: ";
    cin >> N >> E;

    vector<vector<int>> dependencies(E, vector<int>(2));

    for (int i = 0; i < E; i++)
    {
        cin >> dependencies[i][0] >> dependencies[i][1];
    }

    cout <<minSemesters(N, dependencies) << endl;

    return 0;
}