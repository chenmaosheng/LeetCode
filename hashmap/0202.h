#include <set>
using namespace std;

int tool(int n)
{
    int res = 0;
    while (n > 0)
    {
        int tmp = n % 10;
        n /= 10;
        res += tmp*tmp;
    }
    return res;
}

bool isHappy(int n) 
{
    set<int> s;
    s.insert(n);
    while (n!=1)
    {
        n = tool(n);
        if (s.find(n) != s.end()) return false;
        s.insert(n);
    }
    return true;
}