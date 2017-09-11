#include <vector>

using namespace std;

void permuteUnique_helper(vector<int>& nums, vector<vector<int>>& res, int index)
{
	if (index == nums.size() - 1)
	{
		res.push_back(nums);
		return;
	}

	for (int i = index; i < nums.size(); ++i)
	{
		bool found = false;
		for (int j = index; j < i; ++j)
		{
			if (nums[i] == nums[j])
			{
				found = true;
				break;
			}
		}
		if (!found)
		{
			swap(nums[i], nums[index]);
			permuteUnique_helper(nums, res, index+1);
			swap(nums[i], nums[index]);
		}
	}
}
vector<vector<int>> permuteUnique(vector<int>& nums)
{
	vector<vector<int>> res;
	permuteUnique_helper(nums, res, 0);
	return res;
}
