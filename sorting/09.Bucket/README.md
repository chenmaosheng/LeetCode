## Solution

Bucket sort improves counting sort, don't need to create a very large array, create a k size array.
The idea is to create a mapping functor, and put each element to bucket, and use insert sort for each bucket

Here the functor is "val / k"
1, Find maximal value
2, create a new array, the size is (max_val+1)/k
3, iterate arary, put each element to correct bucket
4, run insert sort for each bucket, and copy each element to original array
5, loop buckets
6, finish