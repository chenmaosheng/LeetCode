#include <vector>
using namespace std;

/*
顺着找波谷和波峰，然后看哪个间距最大
*/
int maxProfit(vector<int>& prices) 
{
    int res = 0, min_price = prices[0];
    for (int i = 1; i < prices.size(); ++i)
    {
        if (prices[i] > min_price)
        {
            res = max(res, prices[i] - min_price);
        }
        else
        {
            min_price = prices[i];
        }
    }
    return res;
}