#include <vector>
using namespace std;

/*
遍历并逐步找到范围
*/
vector<string> summaryRanges(vector<int>& nums) 
{
    vector<string> res;
    int l = 0, r = 0;
    while (r < nums.size())
    {
        if (r+1 < nums.size() && nums[r] + 1 == nums[r+1])
        {
            r++;
            continue;
        }
        char buffer[256] = {0};
        if (l == r)
        {
            snprintf(buffer, 256, "%d", nums[l]);
        }
        else snprintf(buffer, 256, "%d->%d", nums[l], nums[r]);
        res.push_back(string(buffer));
        l = r+1;
        r++;
    }
    return res;
}