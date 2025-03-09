#include <string>
using namespace std;

/*
字符映射后，判断字符数量
*/
bool isAnagram(string s, string t) 
{
    vector<int> m(256, 0), m2(256, 0);
    if (s.size() != t.size()) return false;
    for (int i = 0; i < s.size(); ++i)
    {
        int s1 = (unsigned char)s[i];
        int t1 = (unsigned char)t[i];
        m[s1]++;
        m2[t1]++;
    }        
    for (int i = 0; i < 256; ++i)
    {
        if (m[i] != m2[i]) return false;
    }
    return true;
}