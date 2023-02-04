#include<iostream>
using namespace std;

class Solution1
{
public:
    int findPeakElement(int A[],int n)
    {
        if (A[0] >= A[1])
        {
            return 0;
        }
        for (int i = 1; i < n-1;i++)
        {
            if(A[i-1] <= A[i] && A[i] >= A[i+1])
            {
                return i;
            }
        }
        if (A[n-2] <= A[n-1])
        {
            return n-1;
        }
        return n -1;
    }
};


int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0;i<n;i++)
    {
        cin >> A[i];
    }
    Solution1 s;
    int pos = s.findPeakElement(A,n);
    cout << pos << endl;

}