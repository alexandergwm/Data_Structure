#include<iostream>
using namespace std;
#include<vector>


class Solution
{
public:
    void sort(vector<int> &stones)
    {
        int n = stones.size();
        for (int i = 0; i < n-1; i++)
        {
            for (int j = 0; j < n-i-1; j++)
            {
                if (stones[j] > stones[j+1])
                {
                    int temp = stones[j];
                    stones[j] = stones[j+1];
                    stones[j+1] = temp;
                }
            }
        }
    }

    int result(vector<int> &stones, int n, int k)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (stones[i] <= k)
            {
                count++;
                k -= stones[i];
            }
            else
            {
                break;
            }
        }
        return count;
    }
};

void printVector(vector<int> &v)
{
    for(vector<int>::iterator it =v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >>n;
    int k;
    cin>> k;
    vector<int> stones;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        stones.push_back(temp);
    }

    // define the vector which contains the stones
    // define the number of stones
    // firstly sorting the stones from small to large
    Solution s;
    //printVector(stones);
    s.sort(stones);
    //printVector(stones);
    int result = s.result(stones, n, k);
    cout << result << endl;
}