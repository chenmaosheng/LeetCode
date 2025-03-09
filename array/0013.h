#include <string>
using namespace std;

/*
用map存放字母和数字的映射，接着从后往前看，如果前一个比后一个小，说明是类似IX的情况，否则就是正常的顺序
*/
int romanToInt(string s) 
{
    unordered_map<char, int> m;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    int i = s.size()-1, res = 0;
    while (i >= 0)
    {
        if (i - 1 >= 0 && m[s[i]] > m[s[i-1]])
        {
            res += (m[s[i]] - m[s[i-1]]);
            i-=2;
        }
        else
        {
            res += m[s[i]];
            i-=1;
        }
    }
    return res;
}