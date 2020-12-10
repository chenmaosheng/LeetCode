#include "../../algorithms/precomp.h"

void counting_sort(vector<int>& arr)
{
    int max_val = *max_element(arr.begin(), arr.end());
    vector<int> arr2(max_val+1);
    for (int i = 0; i < arr.size(); ++i)
        arr2[arr[i]]++;
    int index = 0;
    for (int i = 0; i < arr2.size(); ++i)
    {
        while (arr2[i] != 0)
        {
            arr[index++] = i;
            arr2[i]--;
        }
    }
}

int main(int argc, char* argv[])
{
    vector<int> arr{4,5,10,2,5,3,100,25,1001,305};
    int len = arr.size();
    counting_sort(arr);

    for (int i = 0; i < arr.size(); ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}