#LeetCode one by one

0001 Two Sum
Description: https://leetcode.com/problems/two-sum
Solution: 0001TwoSum.h
Explanation: The simplest way is to sort the array and use two pointers from start and end, but the complexity is O(nlgn). Another way
is to maintain a hash map, key is array value, value is array index, if you can't find key "target minus current value", that means there
is no pair, then keep this value in hash map, otherwise, that means the existing index in hash map and current index are pair.
