# [2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

## Question

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

## Solution

It's quite straightforward, the only thing need to concern is to notice the carry number and the highest position. Because 

the last number plus carry may be larger than 10