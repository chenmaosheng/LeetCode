#include <vector>
using namespace std;

/*
先拿出一个，然后l和r收缩，由于可能存在重复的，需要额外剔除。
当有一个成功后，需要l向右直到没有该数字，r也要向左直到没有该数字
此外，每次完成一轮后，第一个数字也要去重
*/
vector<vector<int>> threeSum(vector<int>& nums) 
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    for (int i = 0; i < size-2; ++i)
    {
        if (nums[i] > 0) break;
        int reminder = -nums[i];
        int l = i+1, r = size-1;
        while (l < r)
        {
            int tmp = nums[l] + nums[r];
            if (tmp == reminder) {
                res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l+1]) l++;
                while (l < r && nums[r] == nums[r-1]) r--;
                l++; r--;
            }
            else if (tmp < reminder) l++;
            else r--;
        }
        while (i + 1 < size - 2 && nums[i] == nums[i+1]) i++;
    }           
    return res;
}