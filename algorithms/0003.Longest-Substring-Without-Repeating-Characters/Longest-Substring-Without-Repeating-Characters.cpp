#include "../precomp.h"

int lengthOfLongestSubstring(string s) {
	unordered_map<char, int> m;
	int res = 0, start = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (m.find(s[i]) != m.end())
			start = max(start, m[s[i]] + 1);
		res = max(res, i - start + 1);
		m[s[i]] = i;
	}
	return res;
}

int main(int argc, char* argv[])
{
	int res = lengthOfLongestSubstring("pwwkew");
	printf("%d\n", res);
	return 0;
}
