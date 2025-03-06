#include <vector>
using namespace std;

/*
这一次的思路是从后往前考虑，因为不能使用额外的内存。
先找最大的放在数组的结尾，然后以此类推。
*/
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    int idx1 = m-1, idx2 = n-1, len = nums1.size(), idx = len-1;
    while (idx1 >= 0 && idx2 >= 0)
    {
        if (nums1[idx1] > nums2[idx2])
        {
            nums1[idx] = nums1[idx1];
            idx1--;
        }
        else
        {
            nums1[idx] = nums2[idx2];
            idx2--;
        }
        idx--;
    }
    while (idx1 >= 0)
    {
        nums1[idx] = nums1[idx1];
        idx1--;
        idx--;
    }
    while (idx2 >= 0)
    {
        nums1[idx] = nums2[idx2];
        idx2--;
        idx--;
    }
}