#ifndef __H_PRECOMP__
#define __H_PRECOMP__

#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <numeric> 
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <stack>
#include <algorithm>
#include <set>
#include <bitset>
#include <memory>
#include <functional>
#include <iostream>
#include <atomic>
#include <thread>
#include <new>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

#endif
