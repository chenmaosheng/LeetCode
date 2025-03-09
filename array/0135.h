#include <vector>
using namespace std;

/*
首先最小都是1
从左往右遍历，后一个如果比前一个大，那么后一个比前一个多1，但后一个比前一个小的情况没考虑
接着从右往左遍历，前一个比后一个大，那么前一个比后一个多1，考虑到之前遍历过一次了，取最大值
*/
int candy(vector<int>& ratings) 
{
    int size = ratings.size();
    vector<int> res(size, 1);
    for (int i = 1; i < size; ++i)
    {
        if (ratings[i] > ratings[i-1])
        {
            res[i] = res[i-1] + 1;
        }
    }

    for (int i = size-2; i >= 0; --i)
    {
        if (ratings[i] > ratings[i+1])
        {
            res[i] = max(res[i], res[i+1] + 1);
        }
    }
    return std::accumulate(res.begin(), res.end(), 0);
}