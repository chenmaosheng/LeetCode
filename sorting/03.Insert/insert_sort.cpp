#include "../../algorithms/precomp.h"

void insert_sort(vector<int>& arr)
{
    for (int i = 1; i < arr.size(); ++i)
    {
        int j = i-1, val = arr[i];
        for (; j >= 0; --j)
        {
            if (val > arr[j]) break;
            arr[j+1] = arr[j];
        }
        arr[j+1] = val;
    }
}

int main(int argc, char* argv[])
{
    vector<int> arr{4,5,10,2,5,3,100,25,1001,305};
    int len = arr.size();
    insert_sort(arr);

    for (int i = 0; i < arr.size(); ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}