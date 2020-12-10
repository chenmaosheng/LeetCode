## Solution

The idea is to split array with a pivot, and all the elements left of this pivot is not bigger than pivot, right of this pivot is not smaller than pivot

1, Choose pivot, for example 0th element, now there is 0 element smaller than pivot, set pivot index = 0
2, iterate from 1st element, if this element is smaller than pivot, then increase pivot index and swap this element and pivot index element, after this swap, pivot index = 1, means there is 1 element smaller than pivot
3, finish iterate, now pivot index is confirmed, then swap element in pivot index and 0th element (pivot value), all the elements left of this pivot is not bigger than pivot, right of this pivot is not smaller than pivot
4, now there are two sub arrays, 0 to pivot index and pivot index to end, iterate both of them use step 1 - 3
5, finish