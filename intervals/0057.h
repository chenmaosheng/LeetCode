#include <vector>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
{
    intervals.push_back(newInterval);        
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