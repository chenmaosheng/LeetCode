#include <string>
using namespace std;

string reverseWords(string s) 
{
    vector<string> v;
    const char* str = s.c_str();
    char* token = strtok(str, ' ');
    while (token != nullptr)
    {
        v.push_back(string(token));
        token = strtok(NULL, ' ');
    }  
    string res;
    for (int i = v.size()-1; i >= 0; --i)
    {
        res += v[i];
        if (i > 0) res += " ";
    }
    return res;
}