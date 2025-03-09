#include <string>
using namespace std;

/*
这是个滑动窗口问题，首先向右滑动，把每个字符的位置记录下来。
如果发现某个字符记录过，说明达到极限了，先记录最长，接着把起点向右滑动，起点要么不变，要么是记录过的字符往后一个。
最后再看看最终的窗口大小是否是最大
*/
int lengthOfLongestSubstring(string s) 
{
    vector<int> v(256, -1);
    int start = 0, res = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        int idx = static_cast<unsigned char>(s[i]);
        if (v[idx] != -1)
        {
            res = max(res, i-start);
            start = max(start, v[idx] + 1);
        }
        v[idx] = i;
    }
    res = max(res, size-start);
    return res;
}