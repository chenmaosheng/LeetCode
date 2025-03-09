#include <vector>
using namespace std;

/*
找映射关系，记住不能等于自己
*/
vector<int> twoSum(vector<int>& nums, int target) 
{
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); ++i)
    {
        m[nums[i]] = i;
    }        
    for (int i = 0; i < nums.size(); ++i)
    {
        int tmp = target - nums[i];
        auto mit = m.find(tmp);
        if (mit != m.end() && i != mit->second) return vector<int>{i, mit->second};
    }
    return vector<int>{};
}