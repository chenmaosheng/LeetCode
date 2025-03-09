#include <vector>
using namespace std;

/*
先通过set去重，然后判断每个数字的前一个数字是否存在，存在说明已经遍历过了。
如果不存在就逐一去set里找，直到不存在就结束
*/
int longestConsecutive(vector<int>& nums) 
{
    if (nums.empty()) return false;
    unordered_set<int> s(nums.begin(), nums.end());
    for (auto i : s)
    {
        auto mit = s.find(i - 1);
        if (mit == s.end())
        {
            int x = i, tmp = 0;
            while (s.find(x) != s.end())
            {
                x++;
                tmp++;
            }
            res = max(res, tmp);
        }
    }
    return res;
}