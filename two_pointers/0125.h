#include <string>
using namespace std;

/*
用双指针法，l和r分别向右和左移动，如果不是alphanumeric就跳过，是就lower后比较
*/
bool isPalindrome(string s) 
{
    int l = 0, r = s.size()-1;
    while (l < r)
    {
        while (l < r && !std::isalnum(s[l])) l++;
        while (l < r && !std::isalnum(s[r])) r--;
        char x = tolower(s[l]);
        char y = tolower(s[r]);
        if (x != y) return false;
    }
    return true;
}