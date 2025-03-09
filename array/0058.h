#include <string>
using namespace std;

int lengthOfLastWord(string s) 
{
    int start = s.size()-1;
    while (start >= 0 && s[start] == ' ') start--;
    int index = start;
    while (index >= 0 && s[index] != ' ') index--;
    return start - index;
}