## Solution

Counting sort is only suitable for positive integer and the maximal value is not too large

1, Find maximal value
2, create a new array, the size is max_val+1
3, iterate the array, and put each value to value-th in new array, increment it
4, iterate the new array, write back to array
5, finish