#include <vector>
using namespace std;

/*
用排序的字符串和原字符串映射
*/
vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    unordered_map<string, vector<string>> m;
    for (int i = 0; i < strs.size(); ++i)
    {
        string s = strs[i];
        sort(s.begin(), s.end());
        m[s].push_back(strs[i]);
    }
    vector<vector<string>> res;
    for (auto mit : m)
    {
        res.push_back(mit.second);
    }
    return res;
}