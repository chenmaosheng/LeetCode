#ifndef __0001__
#define __0001__

#include "precomp.h"

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> m;
	int size = (int)nums.size();
	for (int i = 0; i < size; ++i)
	{
		if (m.find(target - nums[i]) != m.end())
			return vector<int>{m[target - nums[i]], i};
		m[nums[i]] = i;
	}
	return vector<int>{-1, -1};
}

void testcase_0001()
{
	vector<int> nums{ 2, 7, 11, 15 };
	vector<int> res = twoSum(nums, 9);
	printf("%d %d\n", res[0], res[1]);
}

#endif