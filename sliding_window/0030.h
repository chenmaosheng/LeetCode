#include <vector>
#include <string>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) 
{
    int length = words[0].size() * words.size();
    int word_len = words[0].size();
    if (s.size() < length) return vector<int>{};
    vector<int> res;
    unordered_map<string, int> m;
    for (int i = 0; i < words.size(); ++i) m[words[i]]++;
    for (int l = 0; l <= s.size()-length; ++l)
    {
        unordered_map<string, int> tmp;
        int count = 0;
        int i = l;
        while (i + word_len <= s.size())
        {
            string word = s.substr(i, word_len);
            if (m.find(word) != m.end())
            {
                tmp[word]++;
                if (tmp[word] > m[word]) break;
                count++;
                i += word_len;
            }
            else break;
        }

        if (count == words.size())
        {
            res.push_back(l);
            break;
        }
    }
}