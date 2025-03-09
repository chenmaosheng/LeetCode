#include <vector>
using namespace std;

/*
找到最新的索引和上一个索引比较
*/
bool containsNearbyDuplicate(vector<int>& nums, int k) 
{
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i)
    {
        auto mit = m.find(nums[i]);
        if (mit == m.end())
        {
            m[nums[i]] = i;
        }
        else
        {
            if (i - m[nums[i]] <= k) return true;
            m[nums[i]] = i;
        }
    }        
    return false;
}