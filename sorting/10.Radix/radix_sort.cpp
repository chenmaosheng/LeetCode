#include "../../algorithms/precomp.h"

void radix_sort(vector<int>& arr)
{
    int max_val = *max_element(arr.begin(), arr.end());
    int max_digit = 0;
    while (max_val > 0)
    {
        max_digit++;
        max_val /= 10;
    }
    int mod = 10, div = 1;
    for (int i = 0; i < max_digit; ++i, mod*=10, div*=10)
    {
        vector<vector<int>> arr2(10);
        for (int j = 0; j < arr.size(); ++j)
        {
            arr2[(arr[j]%mod)/div].push_back(arr[j]);
        }
        int index = 0;
        for (int j = 0; j < arr2.size(); ++j)
        {
            for (int k = 0; k < arr2[j].size(); ++k)
            {
                arr[index++] = arr2[j][k];
            }
        }
    }
}

int main(int argc, char* argv[])
{
    vector<int> arr{4,5,10,2,5,3,100,25,1001,305};
    int len = arr.size();
    radix_sort(arr);

    for (int i = 0; i < arr.size(); ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}