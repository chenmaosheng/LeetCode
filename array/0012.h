#include <string>
using namespace std;

/*
首先得把最重要的那些显示都记录到map中
接着开始从高到低逐步消化num，持续减，减到不够减了，再往map下一个继续
*/
string intToRoman(int num) 
{
    map<int, string> m;
    m[1] = "I"; m[4] = "IV"; m[5] = "V"; m[9] = "IX"; m[10] = "X"; 
    m[40] = "XL"; m[50] = "L"; m[90] = "XC"; m[100] = "C"; 
    m[400] = "CD"; m[500] = "D"; m[900] = "CM"; m[1000] = "M";
    string res;
    for (auto mit = m.rbegin(); mit != m.rend(); ++mit)
    {
        int tmp = mit->first;
        string s = mit->second;
        while (num >= tmp)
        {
            res += s;
            num -= tmp;
        }
    }
    return res;
}