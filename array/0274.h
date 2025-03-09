#include <vector>
using namespace std;

/*
这题先排好序，那么每个元素之后的所有元素就是count of at least h citations
接着再找最大值
*/
int hIndex(vector<int>& citations) 
{
    sort(citations.begin(), citations.end());
    int res = 0;
    for (int i = 0; i < citations.size(); ++i)
    {
        int citation = citations[i];
        int count = citations.size() - i;
        res = max(res, min(citation, count));
    }
    return res;
}