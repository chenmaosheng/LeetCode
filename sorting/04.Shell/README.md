## Solution

1, Shell sort is an improvement of insert sort.
2, Assume array has 8 elements, set initial "gap" to 4, then there are 4 sub arrays, (0, 4), (1, 5), (2, 6), (3, 7).
3, Use insert sort for each sub array
4, half the gap, then there are 2 sub arrays (0, 2, 4, 6), (1, 3, 5, 7)
5, Use insert sort for new sub arrays
5, half the gap again, now there is only one sub array