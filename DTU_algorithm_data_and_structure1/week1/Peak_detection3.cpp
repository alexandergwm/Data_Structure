#include<iostream>
#include<math.h>
using namespace std;

void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

class Solution
{
public:
    void BubbleSort(int A[],int n)
    {
        for (int i = 0;i<n;i++)
        {
            for (int j = i+1;j<n-1;j++)
            {
                if (A[i]>A[j])
                {
                    swap(A,j,i);
                }
            }
        }
    }
    int FindMax(int A[],int i,int j)
    {
        while(i != j)
        {
            int m = floor(i+j)/2;
            if (m == 0)
            {
                return m;
            }
            if (A[m]>= A[m-1] && A[m] >= A[m+1])
            {
                return m;
            }
            else if (A[m-1] > A[m])
            {
                return FindMax(A,i,m-1);
            }
            else if (A[m] < A[m+1])
            {
                return FindMax(A,m+1,j);
            }
        }
        return 0;
    }
    
};


int main()
{
    int n;
    cin >> n;
    int A[n];
    int j = n;
    for(int i = 0 ;i < n; i++)
    {
        cin >> A[i];
    }
    int i = 0;
    Solution s;
    s.BubbleSort(A,n);
    for(int i = 0;i < n; i++)
    {
        cout << A[i] << " " ;
    }
    cout << endl;
    int res = s.FindMax(A,i,j);
    cout << res;
    return 0;
}