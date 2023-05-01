#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;

string is_path_between_buildings(int n, int m, int a, int b,vector<pair<int,int>>& paths)
{
    unordered_map<int,vector<int>> graph;

    // 构建邻接表
    for (auto& path:paths)
    {
        int u = path.first;
        int v = path.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // BFS 遍历
    unordered_set<int> visited;   // 存储访问过的顶点
    queue<int> q;   // 用于BFS遍历的队列
    q.push(a);   // 将起始建筑a加入队列

    while(!q.empty())
    {
        int u = q.front();  // 获取队列第一个元素
        q.pop();   // 移除队列第一个元素

        if (u == b)   // 如果当前顶点是目标建筑b,则返回yes
        {
            return "YES";
        }

        for (int v: graph[u])
        {
            // 遍历当前顶点u的所有相邻顶点v
            if (visited.find(v) == visited.end())
            {
                // 如果顶点v尚未访问过，那么将其加入已访问集合和队列
                visited.insert(v);
                q.push(v);
            }
        }
    }
    return "NO";
}

int main()
{
    int n = 4, m =3;
    int a = 1, b= 2;
    vector<pair<int,int>> paths = {{1,3},{2,4},{3,4}};

    cout << is_path_between_buildings(n,m,a,b,paths) << endl;
    return 0;
}