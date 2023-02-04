#include<iostream>
using namespace std;

class Solution
{
public:
    int FindMax(int A[],int n)
    {
        int max = 0;
        for (int i = 0;i<n;i++)
        {
            if(A[i]>A[max])
            {
                max = i;
            }
        }
        return max;
    }
};

int main()
{
    int n;
    cin >> n;
    int A[n];
    for(int i = 0 ;i < n; i++)
    {
        cin >> A[i];
    }
    Solution peakDetection;
    int res = peakDetection.FindMax(A,n);
    cout << res;

}