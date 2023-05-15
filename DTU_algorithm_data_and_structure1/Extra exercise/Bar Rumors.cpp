#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
    int N,M,s;
    cin>>N>>M>>s;

    // 创建邻接列表存储图
    vector<vector<int>> graph(N+1);
    for (int i = 0;i < M;i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 初始化已访问数组
    vector<bool> visited(N+1,false);

    // 使用队列进行广度优先搜索
    queue<int> q;
    q.push(s);
    visited[s] = true;

    int max_day = 0, max_people = 0;
    int day = 0;
    while(!q.empty())
    {
        int size = q.size();
        // 更新最大人数和对应的天数
        if (size > max_people)
        {
            max_people = size;
            max_day = day;
        }
        for (int i= 0;i<size;i++)
        {
            int student = q.front();
            q.pop();
            // 对于学生的所有朋友，如果没有访问过，就加入队列
            for(int friend_student: graph[student])
            {
                if(!visited[friend_student])
                {
                    q.push(friend_student);
                    visited[friend_student] = true;
                }
            }
        }
        day ++;
    }
    cout << max_people <<" " << max_day << endl;

    return 0;
}