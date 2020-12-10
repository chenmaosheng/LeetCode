#include "../../algorithms/precomp.h"

void merge_helper(vector<int>& arr, int start, int mid, int end)
{
    vector<int> temp;
    int index1 = start, index2 = mid+1;
    while (index1 <= mid && index2 <= end)
    {
        if (arr[index1] < arr[index2])
            temp.push_back(arr[index1++]);
        else
            temp.push_back(arr[index2++]);
    }
    while (index1 <= mid)
        temp.push_back(arr[index1++]);
    while (index2 <= end)
        temp.push_back(arr[index2++]);
    for (int i = 0; i < temp.size(); ++i)
        arr[start+i] = temp[i];
}

void merge_sort(vector<int>& arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start+end)/2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);
        merge_helper(arr, start, mid, end);
    }
}

void merge_sort(vector<int>& arr)
{
    merge_sort(arr, 0, arr.size()-1);
}

int main(int argc, char* argv[])
{
    vector<int> arr{4,5,10,2,5,3,100,25,1001,305};
    int len = arr.size();
    merge_sort(arr);

    for (int i = 0; i < arr.size(); ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}