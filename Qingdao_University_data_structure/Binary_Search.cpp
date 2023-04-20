#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    int BinarySearch(vector<int>& nums, int target)
    {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        while(left <= right)
        {
            int middle = left + ((right - left)/2);
            if(nums[middle] > target)
            {
                right = right - 1;
            }
            else if (nums[middle] < target)
            {
                left = left + 1;
            }
            else
            {
                return middle;
            }
        }
        return right + 1;
    }
};

void PrintVector(vector<int> &v)
{
    for(vector<int>::iterator it = v.begin();it!=v.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    Solution s;
    vector<int> v;
    int size;
    int value;
    cout << " Please input the number of the vector" << endl;
    cin >> size;
    for (int i = 0;i < size;i++)
    {
        cout << "please input the " << i+1 << " th value:" <<   endl;
        cin >> value;
        v.push_back(value);
    }
    PrintVector(v);
    int target = 5;
    int res = s.BinarySearch(v,target);
    cout << target << " is at the " << res  <<" position" << endl;

}

int main()
{
    test01();
    return 0;
}