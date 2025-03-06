#include <vector>
using namespace std;

/*
这一题主要是记住位置，然后把元素往前移
*/
int removeDuplicates(vector<int>& nums) 
{
    int idx = 0, new_idx = 0;
    while (idx < nums.size())
    {
        while (idx + 1 < nums.size() && nums[idx] == nums[idx+1]) idx++;
        nums[new_idx] = nums[idx];
        new_idx++;
        idx++;
    }
    return new_idx;
}