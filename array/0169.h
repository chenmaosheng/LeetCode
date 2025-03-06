#include <vector>
using namespace std;

/*
默认是第一个，相同就加一，不同就减1
如果变成0就换一个新的数字，最后一个数字就是答案
*/
int majorityElement(vector<int>& nums) 
{
    int res = -1, idx = 0, cnt = 0;
    while (idx < nums.size())
    {
        if (cnt == 0)
        {
            res = nums[idx];
        }
        if (nums[idx] == res)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        idx++;
    }
    return res;
}