#include <vector>
#include <string>

using namespace std;

string get_space(int num)
{
    return string(num, ' ');
}

/*
按正常逻辑
1，如果只有一个单词，那么就补充空格到最后即可
2，如果是最后一行，前面的单词补充一个空格，最后一个单词补全空格
3，其他行，按照前面多空格后面少空格的原则补全空格
*/
vector<string> fullJustify(vector<string>& words, int maxWidth) 
{
    vector<string> res;
    int idx = 0;
    while (idx < words.size())
    {
        int len = 0, start = idx;
        while (len + words[idx].size() <= maxWidth)
        {
            len = len + words[idx].size() + 1;
            idx++;
        }
        idx--;
        int size = idx - start + 1;
        if (size == 1)
        {
            res.push_back(words[idx] + get_space(maxWidth-words[idx].size()));
        }
        else 
        {
            int bytes = 0;
            for (int i = start; i <= idx; ++i)
            {
                bytes += words[i].size();
            }
            int allSpace = maxWidth - bytes;
            if (idx == words.size()-1)
            {
                string tmp;
                for (int i = start; i <= idx; ++i)
                {
                    tmp += words[i];
                    if (i != idx) {tmp+=get_space(1);allSpace-=1;}
                    else tmp+=get_space(allSpace);
                }
                res.push_back(tmp);
            }
            else
            {
                int medianSpace = allSpace / (size-1);
                vector<int> space(size-1, medianSpace);
                allSpace -= (size-1)*medianSpace;
                for (int j = 0; j < allSpace; ++j) space[j]++;
                string tmp;
                for (int i = start; i <= idx; ++i)
                {
                    tmp += words[i];
                    if (i != idx)
                    {
                        tmp+=get_space(space[i-start]);
                    }
                }
                res.push_back(tmp);
            }
        }
        idx++;
    }
    return res;
}