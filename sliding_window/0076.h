#include <string>
using namespace std;

string minWindow(string s, string t) 
{
    if (t.size() > s.size()) return "";
    unordered_map<char, int> m;
    for (int i = 0; i < t.size(); ++i) m[t[i]]++;
    unordered_map<char, int> m2;
    int l = 0, r = 0;
    string res;
    for (; r < s.size(); ++r)
    {
        char c = s[r];
        m2[c]++;
        if (m2[c] <= m[c]) count++;
        while (count == t.size())
        {
            if (r - l < s.size())
        }
        int count = 0;
        while (r < s.size())
        {
            auto mit = m.find(s[r]);
            if (mit != m.end())
            {
                m2[s[r]]++;
                if (m2[s[r]] >= mit->second)
                {
                    count++;
                }
            }
            if (count == m.size()) break;
            r++;
        }
        string tmp = s.substr(l, r-l+1);
        if (tmp.size() < res.size()) res = tmp;

        while (l < r)
        {
            auto mit = m.find(s[l]);
            if (mit == m.end()) l++;
            else
            {
                l++;
                mit->second--;
                break;
            }
        }
    }    
    return res;
}