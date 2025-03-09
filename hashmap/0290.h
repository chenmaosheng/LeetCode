#include <string>
using namespace std;

/*
这题也是双向映射
*/
bool wordPattern(string pattern, string s) 
{
    vector<string> v;
    char* str = (char*)s.c_str();
    char* token = strtok(str, " ");
    while (token != NULL)
    {
        v.push_back(string(token));
        token = strtok(NULL, " ");
    }
    if (v.size() != pattern.size()) return false;
    unordered_map<char, string> m;
    unordered_map<string, char> m2;
    for (int i = 0; i < pattern.size(); ++i)
    {
        auto mit = m.find(pattern[i]);
        if (mit == m.end()) m[pattern[i]] = v[i];
        else
        {
            if (mit->second != v[i]) return false;
        }

        auto mit2 = m2.find(v[i]);
        if (mit2 == m2.end()) m[v[i]] = pattern[i];
        else
        {
            if (mit2->second != pattern[i]) return false;
        }
    }
    return true;
}