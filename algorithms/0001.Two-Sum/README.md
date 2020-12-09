# [1. Two Sum](https://leetcode.com/problems/two-sum/)

## Question

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

## Solution

The simplest way is to sort the array and use two pointers from start and end, but the complexity is O(nlgn). Another way

is to maintain a hash map, key is array value, value is array index, if you can't find key "target minus current value", that means there

is no pair, then keep this value in hash map, otherwise, that means the existing index in hash map and current index are pair.