#include <string>
using namespace std;

/*
逐一判断即可
*/
bool isSubsequence(string s, string t) 
{
    int j = 0;
    for (int i = 0; i < t.size(); ++i)
    {
        if (t[i] == s[j]) j++;
        if (j == s.size()) break;
    }
    return j == s.size();
}