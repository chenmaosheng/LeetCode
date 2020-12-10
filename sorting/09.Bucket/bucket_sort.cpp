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

void bucket_sort(vector<int>& arr)
{
    int k = 10, max_val = *max_element(arr.begin(), arr.end());
    vector<vector<int>> bucket(max_val/k+1);
    for (int i = 0; i < arr.size(); ++i)
    {
        bucket[arr[i]/k].push_back(arr[i]);
    }
    int index = 0;
    for (int i = 0; i < bucket.size(); ++i)
    {
        if (!bucket[i].empty())
        {
            insert_sort(bucket[i]);
        }
        for (int j = 0; j < bucket[i].size(); ++j)
        {
            arr[index++] = bucket[i][j];
        }
    }
}

int main(int argc, char* argv[])
{
    vector<int> arr{4,5,10,2,5,3,100,25,1001,305};
    int len = arr.size();
    bucket_sort(arr);

    for (int i = 0; i < arr.size(); ++i)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}