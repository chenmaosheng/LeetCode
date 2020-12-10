## Solution

1, the 0th element, as a sub array, is sorted
2, pick up the ith element, and reverse iterate the sub sorted array, if element is bigger than ith element, then move this element to right place
3, Find the element which is not bigger than ith element, then move ith element to this right place of this element, the sorted sub array increase 1
4, loop
5, finish