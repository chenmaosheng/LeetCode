LeetCode
========

#LeetCode one by one


| # | Title | Solution | Difficulty | Readme |
|---| ----- | -------- | ---------- | ------ |
|1|[Two Sum](https://leetcode.com/problems/two-sum/)| [C++](./algorithms/0001.Two-Sum/Two-Sum.cpp)|Easy| [Readme](./algorithms/0001.Two-Sum/README.md)|
|2|[Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)| [C++](./algorithms/0002.Add-Two-Numbers/Add-Two-Numbers.cpp)|Medium| [Readme](./algorithms/0002.Add-Two-Numbers/README.md)|

Explanation: It's quite straightforward, the only thing need to concern is to notice the carry number and the highest position. Because 
the last number plus carry may be larger than 10

0003 Longest Substring Without Repeating Characters

[Description](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

[Solution](0003.h)

Explanation: use a map to store character and its last index. If map doesn't have this character, that means first occurence. Otherwise, 
from the index stored in map, to this same character index, these characters are uniqueness. Then use current index instead and loop.