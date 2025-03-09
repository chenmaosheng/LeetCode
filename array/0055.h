#include <vector>
using namespace std;

/*
这是一道典型的贪心算法，不断的寻找能到达的最大位置，如果超过数组长度则成功
如果遍历的位置比能达到的最大位置还要大，说明到不了了
简单来说，就是最大能到的位置，和当前遍历位置的比较
*/
bool canJump(vector<int>& nums) 
{
    /*int size = nums.size();
    vector<int> reach(size, 0);
    reach[0] = 1;
    for (int i = 0; i < size-1; ++i)
    {
        int max_reach = min(i+nums[i], size-1);
        for (int j = i+1; j <= max_reach; ++j)
            reach[j] = 1;
    }
    return reach[size-1] == 1;*/
    int size = nums.size();
    int max_reach = 0;
    for (int i = 0; i < size-1; ++i)
    {
        if (i > max_reach) return false;
        max_reach = max(max_reach, i + nums[i]);
        if (max_reach >= size-1) return true;
    }
    return false;
}