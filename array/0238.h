#include <vector>
using namespace std;

/*
第一步，从第二个数字开始，把前面的数字逐一相乘，得到新的res数组，这个数组每个数字都等于前面所有数字的乘积
第二步，从倒数第二个数字开始，把后面的数字逐一相乘，然后和res数组同位置再相乘，这样所有位置都被乘到了，除了自己
*/
vector<int> productExceptSelf(vector<int>& nums) 
{
    vector<int> res(nums.size(), 1);
    int x = 1;
    for (int i = 1; i < nums.size(); ++i)
    {
        x *= nums[i-1];
        res[i] *= x;
    }
    x = 1;
    for (int i = nums.size()-2; i >= 0; --i)
    {
        x *= nums[i+1];
        res[i] *= x;
    }
    return res;
}