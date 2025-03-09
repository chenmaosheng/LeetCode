#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) 
{
    string res;
    int len = strs[0].size();
    for (int i = 0; i < len; ++i)
    {
        char c = strs[0][i];
        bool same = true;
        for (int j = 1; j < strs.size(); ++j)
        {
            if (strs[j][i] != c)
            {
                same = false;
                break;
            }
        }
        if (same) res.push_back(c);
        else break;
    }
    return res;
}