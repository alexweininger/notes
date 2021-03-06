# Sorting

## Selection sort

Big-O: `O(n^2)`

Pseudocode:

```text
for i to length - 2
	s = position of smallest elemet from num[i] to num[i - 1]
	swap num[i] and num[s]
endfor
```

Code:

```c

int getSmallest(int num[], int lo, int hi) {
	int smallest = lo;
	for (int i = lo + 1; i <= hi; i++) {
			if (num[h] < num[small]) {
				small = h;
			}
		return small;
	}
}

void swap (int num[]. int i, int j) {
	int hold = num[i];
	num[i] = num[j];
	num[j] = hold;
}

void selectionSort(list[], int lo, int hi) {
	for (int i = lo; i < hi; i++) {
		int s = getSmallest(list, lo, hi);
		swap(list, h, s);
	}
}
```

analysis of selection sort

To find the smallest of k items, we must make k-1 comparisons. On the first pass we make n-1 comparisons to find the smallest number, then n-2, and so on. So selection sort has a big O notation of O(n^2)

## Insertion Sort

Big-O: `O(n^2)`

Insertion sort goes number by number and inserts each number into its correct position.

Outline:

```text
for h = 1 to n-1 do:
	insert num[h] among num[0] so that num[0] to num[h] is sorted
endfor
```

## Heapsort

A **heap** is an almost complete binary tree such that the value at the root is greater than or equal to the values at the left and right children. And the left and right subtrees are also heaps.

After making a tree a heap, the largest value is at the root.

Sorting process

```text
for k = n downto 2 do:
  item = num[k] // extract current last item
  num[k] = num[1] // move top of heap to the current last node
  softDown(item, num, 1, k - 1)

end for

siftDown:
  find the largest child of num[root]
  if (key >= num[m]) we are done; put key in num[root]
    // key is smaller than the bigger child
    store num[m] in num[root] // promote bigger child
    set root to m
```

heap sort is O(n log n) and at most 4n comparisons

## Merge sort

Big-O: average: `O(n log n)` worst: `O(n log n)`

Merge sort breaks up the list into individual pieces and then _merges_ the items into sorted order.

## Quicksort

Big-O: average: `O(n log n)` worst: `O(n^2)`

The quicksort algorithm revolved around the idea of **partitioning** a list based on one of the values called a **pivot**.

Say we have the following list:

> 53 12 98 63 18 32 80 46 72 21

We can partition it with respect to the first value `53`. Meaning we will place `53` such that all of the values to the left of `53` are smaller, and all values to the right are larger.

This leaves us with the following list order:

> 12 21 18 32 46 53 80 98 72 63

`53` is the **pivot**. It is placed in position 5. The location at which the pivot is placed is called the **division point**.

Here is a step by step example of how the partition works.

>Found 2, last small = 1. Swap 2 with 8.
>
>`5 2 8 4 10 6 3 7 1` last small = 1
>
>Found 4, last small = 2. Swap 4 with 8.
>
>`5 2 4 8 10 6 3 7 1` last small = 2
>
>Found 3, last small = 3. Swap 3 with 8.
>
>`5 2 4 3 10 6 8 7 1` last small = 3
>
>Found 1, last small = 4. Swap 1 with 10.
>
>`5 2 4 3 1 6 8 7 10` last small = 4.
>
>Did not find number less than 5. Swap pivot with last smallest (last smallest = 4), swapping 5 with 1.
>
>`1 2 4 3 5 6 8 7 10` last smallest = 4
>
>Return 4.

Now we keep repeating this process on each _half_ of the list to achieve a fully sorted list.

If the pivot chosen is the smallest number in the list, then the recursive call _trims_ off the first value by calling it with low + 1

### Example problems

**1. Show the values of the given list after the partition step in quicksort using pivot value 30:**
`30 15 75 64 20 2 8 35`

**Answer:**

1. `30 15 75 64 20 2 8 35` 15 swaps with itself

2. `30 15 20 64 75 2 8 35` 20 is swapped with 75

3. `30 15 20 2 75 64 8 35` 2 is swapped with 64

4. `30 15 20 2 8 64 75 35` 8 is swapped with 75

5. `8 15 20 2 30 64 75 35` The pivot (30) is swapped with the last smallest (8).
