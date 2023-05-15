#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 从边的列表中创建邻接列表表示的图
vector<vector<pair<int,int>>> create_adj_list(int n, vector<vector<int>> &edges)
{
    vector<vector<pair<int,int>>> adj_list(n+1);  // 初始化邻接列表未n+1大小的向量，每个元素是一个空的pair向量
    for (const auto &edge:edges)   // 遍历输入边的列表
    {
        int u =edge[0],v= edge[1],w = edge[2];  // 对于每条边，提取边的起点('u')，终点('v')，和权重('w')
        adj_list[u].emplace_back(v,w);  // 将节点'v'和权重'w'添加到节点'u'的邻接列表中
        adj_list[v].emplace_back(u,w);  // 将节点'u'和权重'w'添加到节点'v'的邻接列表中
    }
    return adj_list;
}

// 使用Dijkstra算法寻找从基站到所有房屋的最短路径
vector<int> dijkstra(int n, const vector<vector<pair<int,int>>> & adj_list)
{
    // 初始化距离数组，将基站的距离设置为0，其他节点的距离设置为无穷大
    vector<int> dist(n+1,1e9);
    dist[1] = 0;
    // 使用优先队列存储未访问节点
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1}); // 将节点1，距离为0 存放进优先队列

    while(!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(d > dist[u])  // 如果当前节点找到了更短的路径，跳过
        {
            continue;
        }

        for (const auto &neighbor : adj_list[u])
        {
            int v = neighbor.first;
            int w = neighbor.second;

            // 如果通过当前节点可以找到到达邻接的更短路径，更新邻居的距离并将邻居加入优先队列
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m,vector<int>(3));

    for(int i = 0; i< m;i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    vector<vector<pair<int,int>>> adj_list = create_adj_list(n,edges);
    vector<int> shortest_paths = dijkstra(n,adj_list);

    cout << shortest_paths[1]<<endl;
    for(int i =2 ;i <= n;i++)
    {
        cout << shortest_paths[i] << endl;
    }

    return 0;
}