#include <vector>
using namespace std;

/*
这一题要保留最多2个，那么代码需要稍做修改，记录每个元素的个数，然后再填充，其他代码和0026基本一致
新思路：判断当前元素和新数组的前两个是否相同，有一个不同就可以放入
*/
int removeDuplicates(vector<int>& nums) 
{
    /*while (idx < nums.size())
    {
        int cnt = 1;
        while (idx + 1 < nums.size() && nums[idx] == nums[idx+1])
        {
            idx++;
            cnt++;
        }
        if (cnt == 1)
        {
            nums[new_idx] = nums[idx];
            new_idx++;
        }
        else
        {
            nums[new_idx] = nums[idx];
            nums[new_idx+1] = nums[idx];
            new_idx+=2;
        }
        idx++;
    }
    return new_idx;*/
    int new_idx = 1;
    for (int idx = 2; idx < nums.size(); ++idx)
    {
        if (nums[idx] != nums[new_idx] || nums[idx] != nums[new_idx-1])
        {
            nums[new_idx+1] = nums[idx];
            new_idx++;
        }
    }
    return new_idx+1;
}