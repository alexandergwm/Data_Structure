#include<iostream>
#include<vector>
using namespace std;

class Merge_sort
{
public:
    vector<int> sortArray(vector<int>& nums)
    {
        if (nums.size() <=1)
        {
            return nums;
        }
        int middle = nums.size()/2;
        vector<int> left(nums.begin(),nums.begin()+middle);
        vector<int> right(nums.begin()+middle,nums.end());
        left = sortArray(left);
        right = sortArray(right);
        return merge(left,right);
    }
private:
    vector<int> merge(vector<int> &left,vector<int>&right)
    {
        vector<int> result;
        int i = 0, j=0;
        while(i<left.size() && j<right.size())
        {
            if(left[i] <= right[j])
            {
                result.push_back(left[i++]);
            }
            else
            {
                result.push_back(right[j++]);
            }
        }
        while(i<left.size())
        {
            result.push_back(left[i++]);
        }
        while(j<right.size())
        {
            result.push_back(right[j++]);
        }
        return result;
    }
};

void printVector(vector<int>&v)
{
    for(vector<int>::iterator it = v.begin();it!= v.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {16,31,1,36,47,50,42,12,7,4,51,28,45,25,18,33};
    Merge_sort s;
    vector<int> result = s.sortArray(nums);
    printVector(nums);
    cout << 'after sorting' << endl;
    printVector(result);
}