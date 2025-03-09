#include <vector>
using namespace std;

/*
max_reach是每次都找当前遍历过程能到的最大位置，这是整个过程中能看到的最远位置
end表示当前这次跳跃能到达的最远位置，也就是说遍历到end时，必须进行一次跳跃
这是一种贪心算法。
*/
int jump(vector<int>& nums) 
{
    int size = nums.size();
    int max_reach=0, end=0, res=0;
    for (int i = 0; i < size-1; ++i)
    {
        max_reach = max(max_reach, i+nums[i]);
        if (i == end)
        {
            res++;
            end = max_reach;
            if (end >= size-1) break;
        }
    }
    return res;
}