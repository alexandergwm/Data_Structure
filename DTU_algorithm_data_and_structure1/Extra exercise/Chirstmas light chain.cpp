//这个问题的关键在于找出最长的连续的房屋编号序列，我们可以通过排序和线性扫描的方法来解决。

//首先，我们需要将收到的房屋编号进行排序。然后，我们从头到尾扫描排序后的房屋编号，
//记录当前连续的房屋编号序列的长度，并同时记录下最长的连续的房屋编号序列的长度。具体地，我们维护两个变量，一个是当前连续序列的长度（如果当前房屋编号和前一个房屋编号连续，则长度加1，否则重置为1），另一个是最长连续序列的长度。每次扫描一个新的房屋编号时，我们都更新这两个变量。

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> houses(N);
    for (int i = 0; i< N;i++)
    {
        cin >> houses[i];
    }

    // 对房屋编号进行排序
    sort(houses.begin(),houses.end());

    int longest_chain = 1, current_chain = 1;
    for (int i = 1; i< N;i++)
    {
        if (houses[i] == houses[i-1]+1)
        {
            // 如果当前房屋编号与前一个房屋编号连续，那么当前连续序列长度加1
            current_chain ++;
        }
        else if(houses[i] != houses[i-1])
        {
            // 如果当前房屋编号与前一个房屋编号不连续，那么重置当前连续序列长度再加1
            current_chain = 1;
        }
        // 更新最长连续序列的长度
        longest_chain = max(longest_chain,current_chain);
    }
    cout << longest_chain << endl;

    return 0;
}
