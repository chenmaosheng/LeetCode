#include <string>
using namespace std;

/*
用两个map，互相映射
*/
bool isIsomorphic(string s, string t) 
{
    vector<int> m(256, 0), m2(256, 0);
    int size = s.size();
    for (int i = 0; i < size; ++i)
    {
        int s1 = (unsigned char)s[i];
        int t1 = (unsigned char)t[i];

        if (m[s1] == 0) m[s1] = t1;
        else if (m[s1] != t1) return false;

        if (m2[t1] == 0) m2[t1] = s1;
        else if (m2[t1] != s1) return false;
    }
    return true;
}