#include <vector>
using namespace std;

/*
这是一个滑动窗口问题，首先往右扩展窗口，如果和超过target，那么记录当前长度，再从左边收缩窗口
*/
int minSubArrayLen(int target, vector<int>& nums) 
{
    if (nums.size() == 1 && nums[0] >= target) return 1;
    int l = 0, r = 0, size = nums.size(), sum = nums[l], res = INT_MAX;
    while (l <= r && r < size)
    {
        if (sum >= target)
        {
            res = min(res, r-l+1);
            sum -= nums[l];
            l++;
        }
        else
        {
            r++;
            if (r < size) sum += nums[r];
        }
    }
    if (res == INT_MAX) return 0;
    return res;
}