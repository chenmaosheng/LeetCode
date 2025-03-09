#include <vector>
using namespace std;

/*
这一题可以交易多次，那么就是把每个波谷和波峰的差值加起来
*/
int maxProfit(vector<int>& prices) 
{
    int res = 0;
    for (int i = 1; i < prices.size(); ++i)
    {
        if (prices[i] > prices[i-1])
        {
            res += (prices[i] - prices[i-1]);
        }
    }
    return res;
}