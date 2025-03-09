#include <string>
using namespace std;

/*
用map来做，然后比较字符的个数
*/
bool canConstruct(string ransomNote, string magazine) 
{
    unordered_map<char, int> m, m2;
    for (auto c : magazine) m[c]++;
    for (auto c : ransomNote) m2[c]++;
    for (auto mit = m2.begin(); mit != m2.end(); ++mit)
    {
        char c = mit->first;
        char cnt = mit->second;
        auto mit2 = m.find(c);
        if (mit2 == m.end()) return false;
        if (mit2->second < cnt) return false;
    }
    return true;
}