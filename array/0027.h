#include <vector>
using namespace std;

/*
这一题不能用内存，那么就是记住位置，把元素逐步往前移动
*/
int removeElement(vector<int>& nums, int val) 
{
    int idx = 0, new_idx = 0;
    while (idx < nums.size())
    {
        if (nums[idx] != val)
        {
            nums[new_idx] = nums[idx];
            new_idx++;
        }
        idx++;
    }
    return new_idx;
}