#include <vector>
using namespace std;

/*
首先用第一个数字来排序，确保所有start1 <= start2
连续两个merge的前提是，start1 <= start2 && end1>=start2，边界是max(end1, end2)
*/
vector<vector<int>> merge(vector<vector<int>>& intervals) 
{
    sort(intervals.begin(), intervals.end(), [](auto&a, auto& b){return a[0] < b[0];});
    int i = 0;
    vector<vector<int>> res;
    while (i < intervals.size())
    {
        vector<int> tmp = intervals[i];
        while (i + 1 < intervals.size())
        {
            if (tmp[1] >= intervals[i+1][0])
            {
                tmp[1] = max(tmp[1], intervals[i+1][1]);
                i++;
            }
            else break;
        }
        res.push_back(tmp);
        i++;
    }
    return res;
}