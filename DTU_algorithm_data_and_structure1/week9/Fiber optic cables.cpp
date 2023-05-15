#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<limits>
using namespace std;

const int INF = 1e9;

int prim(vector<vector<pair<int,int>>>&adj, int n)
{
    vector<bool> visited(n+1,false);   // 标记节点是否已访问
    vector<int> min_edge(n+1,INF);   // 存储连接到每个节点的最小权重边

    int start = 1;    // 设置起始节点
    min_edge[start] = 0;  // 其最小边权重为0
    int total_cost = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({0,start});  // 将起始节点加入优先级队列，权重为0

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if(!visited[u])
        {
            visited[u] = true;
            total_cost += min_edge[u];
            
            // 遍历与当前节点相邻的节点
            for(const auto &[v,w]:adj[u])
            {
                if(!visited[v] && w < min_edge[v])
                {
                    min_edge[v] = w;  // 更新连接到节点v的最小边权重
                    pq.push({w,v});  // 将节点v和权重w加入优先队列
                }
            }
        }
    }
    return total_cost;   // 返回最小生成树的总权重



}

int main()
{
    int n,m;
    cin >> n >> m;

    // 使用邻接表存储图
    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 0;i < m;i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].emplace_back(v,cost);   // 将边(u,v)和权重cost添加到邻接表中
        adj[v].emplace_back(u,cost);   // 无向图需要双向添加


    }
    int min_cost = prim(adj,n);  // 计算最小生成树的总权重
    cout << min_cost << endl;
    return 0;
}
