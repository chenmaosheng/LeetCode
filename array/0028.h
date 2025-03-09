#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    if (haystack.size() < needle.size()) return -1;
    int size1 = haystack.size(), size2 = needle.size();
    for (int i = 0; i <= size1 - size2; ++i)
    {
        string tmp = haystack.substr(i, size2);
        if (tmp == needle) return i;
    }
    return -1;
}