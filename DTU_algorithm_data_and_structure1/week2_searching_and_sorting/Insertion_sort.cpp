#include<iostream>
#include<vector>
using namespace std;

class Insertion_sort
{
public:
    void Sort(vector<int> &nums)
    {
        int n = nums.size();
        for (int i=1;i<n;i++)
        {
            int key = nums[i];
            int j = i-1;
            while(j>=0 && nums[j]>key)
            {
                nums[j+1] = nums[j];
                j--;
            }
            nums[j+1] = key;
        }
    }

};

void printVector(vector<int> &v)
{
    for(vector<int>::iterator it = v.begin();it !=v.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {4,18,25,28,33,45,7,12,36,1,47,42,50,16,31};
    printVector(nums);
    Insertion_sort s;
    s.Sort(nums);
    cout << 'after sorting' << endl;
    printVector(nums);
    
}