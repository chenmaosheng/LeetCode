#include "../../algorithms/precomp.h"

void shell_sort(vector<int>& arr)
{
    int len = arr.size();
    for (int gap = floor(len/2); gap > 0; gap = floor(gap/2))
    {
        for (int i = gap; i < len; i+=gap)
        {
            int j = i - gap, val = arr[i];
            for (; j >= 0; --j)
            {
                if (val > arr[j]) break;
                arr[j+gap] = arr[j];
            }
            arr[j+gap] = val;
        }
    }
}

int main(int argc, char* argv[])
{
    vector<int> arr{4,5,10,2,5,3,100,25,1001,305};
    int len = arr.size();
    shell_sort(arr);

    for (int i = 0; i < arr.size(); ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}