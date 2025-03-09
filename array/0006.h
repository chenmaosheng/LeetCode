#include <string>
using namespace std;

/*
直接按步骤进行，刚开始方向是向下的，那么就不断自增x，如果x达到最大，那么就方向开始向上
方向向上的时候，自减x，自增y，当x回到0之后，方向继续向下
*/
string convert(string s, int numRows) 
{
    if (numRows == 1) return s;
    vector<string> res(numRows, string(s.size(), ' '));
    int x = 0, y = 0, direction = 0;
    for (int i = 0; i < s.size();++i)
    {
        res[x][y] = s[i];
        if (x == 0) direction = 0;
        else if (x == numRows-1) direction = 1;

        if (direction == 0)
        {
            x++;
        }
        else
        {
            x--;
            y++;
        }
    }        
    string ret;
    for (int i = 0; i < res.size(); ++i)
    {
        for (int j = 0; j < res[i].size(); ++j)
        {
            if (res[i][j] != ' ') ret.push_back(res[i][j]);
        }
    }
    return ret;
}