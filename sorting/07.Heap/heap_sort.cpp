#include "../../algorithms/precomp.h"

void heap_adjust(vector<int>& arr, int parent, int len)
{
    int val = arr[parent], child = 2 * parent + 1;
    while (child < len)
    {
        if (child + 1 < len && arr[child+1] > arr[child]) child++;
        if (val > arr[child]) break;
        swap(arr[parent], arr[child]);
        parent = child;
        child = 2 * parent + 1;
    }
}

void heap_sort(vector<int>& arr)
{
    int len = arr.size();
    for (int i = len/2; i >= 0; --i)
        heap_adjust(arr, i, len);
    for (int i = len - 1; i > 0; --i)
    {
        swap(arr[i], arr[0]);
        heap_adjust(arr, 0, i);
    }
}

int main(int argc, char* argv[])
{
    vector<int> arr{4,5,10,2,5,3,100,25,1001,305};
    int len = arr.size();
    heap_sort(arr);

    for (int i = 0; i < arr.size(); ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}