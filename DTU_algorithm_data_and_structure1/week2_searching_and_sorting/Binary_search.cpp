#include<iostream>
#include<vector>
using namespace std;

class BinarySearch
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.size() <= 0)
        {
            return -1;
        }
        int left = 0;
        int right = nums.size() -1 ;
        while(left <= right)
        {
            int middle = left + ((right - left)/2);
            if (nums[middle] > target)
            {
                right = middle - 1;
            }else if (nums[middle] < target)
            {
                left = middle + 1;
            }else
            {
                return middle;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {1,4,7,12,16,18,25,28,31,33,36,42,45,47,50};
    BinarySearch s;
    cout << nums.size() << endl;
    int pos = s.search(nums, 50);
    cout << pos << endl;
}