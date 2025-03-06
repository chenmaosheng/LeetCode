#include <vector>
using namespace std;

/*
一个简单的方法，把数组分割为前n-k个和后k个
然后分别反转，最后整体反转
*/
void rotate(vector<int>& nums, int k) 
{
    int n = nums.size();
    reverse(nums.begin(), nums.begin()+n-k);
    reverse(nums.begin()+n-k, nums.end());
    reverse(nums.begin(), nums.end());
}