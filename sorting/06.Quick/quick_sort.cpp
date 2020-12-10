#include "../../algorithms/precomp.h"

void quick_sort(vector<int>& arr, int start, int end)
{
    if (start < end)
    {
        int pivot = arr[start];
        int i = start, j = start;
        for (; j <= end; ++j)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i], arr[start]);
        quick_sort(arr, start, i-1);
        quick_sort(arr, i+1, end);
    }
}

void quick_sort(vector<int>& arr)
{
    quick_sort(arr, 0, arr.size()-1);
}

int main(int argc, char* argv[])
{
    vector<int> arr{4,5,10,2,5,3,100,25,1001,305};
    int len = arr.size();
    quick_sort(arr);

    for (int i = 0; i < arr.size(); ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}