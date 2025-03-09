#include <vector>
using namespace std;

/*
双指针法，不足就向右移动l，太多则向左移动r
*/
vector<int> twoSum(vector<int>& numbers, int target) 
{
    int l = 0, size = numbers.size(), r = size-1;
    while (l < r)
    {
        int total = numbers[l] + numbers[r];
        if (total == target) return vector<int>{l+1, r+1};
        if (total < target)
        {
            l++;
        }
        else
        {
            r--;
        }
    }    
    return vector<int>{};    
}