#include "../../algorithms/precomp.h"

void bubble_sort(vector<int>& arr)
{
    for (int i = 0; i < arr.size()-1; ++i)
    {
        for (int j = 0; j < arr.size()-1-i; ++j)
        {
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

int main(int argc, char* argv[])
{
    vector<int> arr{4,5,10,2,5,3,100,25,1001,305};
    int len = arr.size();
    bubble_sort(arr);

    for (int i = 0; i < arr.size(); ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}