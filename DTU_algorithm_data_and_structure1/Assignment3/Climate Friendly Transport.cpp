#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
#define MAX_TIME 120
#define INF 1e9

// 这里很明显是一个无向图求解最短路径的问题，我们先考虑建立一个无向图

vector<int> shortest_path (int start, vector<vector<int>> &graph)
{
    int size = graph.size();
    vector<int> distance(size,INF);
    vector<bool> visited(size,false);
    distance[start] = 0;

    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pri_que;// min-heap
    // pri_que.push({start,0});    

    // while(!pri_que.empty())
    // {
    //     int cur_vertex = pri_que.top().first;
    //     int cur_distance = pri_que.top().second;
    //     pri_que.pop();

    //     if(visited[cur_vertex])
    //     {
    //         continue;
    //     }

    //     visited[cur_vertex] = true;   // 访问了cur_vertex ,mark

    //     for(int k=0;k<size;k++)
    //     {
    //         if(graph[cur_vertex][k] != INF && !visited[k])
    //         {
    //             int new_distance = cur_distance + graph[cur_vertex][k];
    //             if(new_distance < distance[k])
    //             {
    //                 distance[k] = new_distance;
    //                 pri_que.push({k,new_distance});
    //             }
    //         }
    //     }
    // }


    // 使用数组，但是time limit exceeded了
    for(int i = 0;i < size;i++)
    {
        int cur_vertex = -1;
        int cur_distance = INF;

        // 找到从当前点到未访问过的节点中距离最短的顶点
        for(int j=0; j < size ;j++)
        {
            if(!visited[j] && distance[j] < cur_distance)
            {
                cur_distance = distance[j];  // 此时找到更小的，就交给cur
                cur_vertex = j;   // 此时到顶点i最短距离的顶点就是j了
            }
        }
        visited[cur_vertex] = true;

        for(int k=0; k < size;k++)
        {
            if(graph[cur_vertex][k] != INF && !visited[k])
            {
                distance[k] = min(distance[k],distance[cur_vertex] + graph[cur_vertex][k]);
            }
        }
    }
    return distance;
}

int main()
{
    int N,M,F;
    cin >> N >> M >> F;
    // 初始化定义一个矩阵,使用邻接矩阵
    vector<vector<int>> graph(N,vector<int>(N,INF));

    // 将对角线上元素置为0，也就是graph[i][i] = 0
    for(int i = 0; i <N;i++)
    {
        graph[i][i] = 0;
    }

    for(int i = 0;i <M;i++)
    {
        int v,u,w;
        cin >> v >> u >> w;
        graph[v][u] = w;
        graph[u][v] = w;
    }

    for(int i = 0;i <F;i++)
    {
        int v,u;
        cin >> v >> u;
        vector<int> result = shortest_path(v,graph);
        if(result[u] > MAX_TIME)
        {
            cout << "keep" << endl;
        }
        else
        {
            cout <<"cancel" << endl;
        }
    }
    return 0;

    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < N; ++j) {
    //         if (graph[i][j] == INF) {
    //             cout << "INF ";
    //         } else {
    //             cout << graph[i][j] << " ";
    //         }
    //     }
    //     cout << endl;
    // }

}