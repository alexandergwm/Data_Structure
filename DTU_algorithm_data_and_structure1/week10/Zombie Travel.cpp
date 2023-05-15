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
        int u =edge[0],v= edge[1];  // 对于每条边，提取边的起点('u')，终点('v')，和权重('w')
        double w =static_cast<double>(edge[2])/100.0;
        adj_list[u].emplace_back(v,w);  // 将节点'v'和权重'w'添加到节点'u'的邻接列表中
        adj_list[v].emplace_back(u,w);  // 将节点'u'和权重'w'添加到节点'v'的邻接列表中
    }
    return adj_list;
}

// 使用Dijkstra算法寻找最安全的路径
double dijkstra(int n, const vector<vector<pair<int,int>>> & adj_list)
{
    // 初始化城市，将城市2的距离设置为0，其他城市的距离设置为无穷大
    vector<int> dist(n+1,0.0);
    dist[2] = 1.0;
    // 使用优先队列来存储未访问的城市
    priority_queue <pair<double,int>> pq;
    pq.push({1.0,2});  

    while(!pq.empty())
    {
        double prob = pq.top().second;
        int node = pq.top().first;
        pq.pop();

        if(prob < dist[node])  // 如果当前节点找到了更短的路径，跳过
        {
            continue;
        }

        for (const auto &neighbor : adj_list[node])
        {
            int next_node = neighbor.first;
            double edge_prob = neighbor.second;
            double new_prob = prob * edge_prob;

            // 如果通过当前节点可以找到到达邻接的更短路径，更新邻居的距离并将邻居加入优先队列
            if (new_prob > dist[next_node])
            {
                dist[next_node] = new_prob;
                pq.push({new_prob,next_node});
            }
        }
    }
    return dist[4];
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
    double max_probability = dijkstra(n,adj_list);

    cout << max_probability << endl;

    return 0;
}