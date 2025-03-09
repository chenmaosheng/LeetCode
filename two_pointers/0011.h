#include <vector>
using namespace std;

/*
双指针法，找到l和r的最小值再乘以宽度，找到最大面积
接着比较l和r，哪个更小就往哪边移动
*/
int maxArea(vector<int>& height) 
{
    int l = 0, size = height.size(), r = size-1, res = 0;
    while (l < r)
    {
        res = max(res, min(height[l], height[r]) * (r - l));
        if (height[l] < height[r]) l++;
        else r--;
    }
    return res;
}