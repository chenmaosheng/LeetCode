#include "../../algorithms/precomp.h"

void select_sort(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        int min_index = i;
        for (int j = i+1; j < arr.size(); ++j)
        {
            if (arr[j] < arr[min_index]) min_index = j;
        }
        swap(arr[min_index], arr[i]);
    }
}

int main(int argc, char* argv[])
{
    vector<int> arr{4,5,10,2,5,3,100,25,1001,305};
    int len = arr.size();
    select_sort(arr);

    for (int i = 0; i < arr.size(); ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}