#include <vector>
using namespace std;

/*
题目里说了必然有唯一答案，那么就两种可能
1，全加起来是负的，那么就没有答案
2，如果全加起来非负，第一个往后加全为非负的点就是起点，有一个为负说明不是起点，要重新找起点
*/
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
{
    int size = gas.size();
    vector<int> diff(size, 0);
    for (int i = 0; i < size; ++i)
    {
        diff[i] = gas[i] - cost[i];
    }
    int total = 0, current = 0, start = 0;
    for (int i = 0; i < size; ++i)
    {
        total += diff[i];
        current += diff[i];
        if (current < 0)
        {
            start = i+1;
            current = 0;
        }
    }
    return total < 0 ? -1 : start;
}