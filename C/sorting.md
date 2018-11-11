# Sorting

## Selection sort

algorithm outline:

for i to length - 2
	s = position of smallest elemet from num[i] to num[i - 1]
	swap num[i] and num[s]
endfor

Code

```java

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

to find the smallest of k items, we must make k-1 comparisons. On the first pass we mane n-1 comparisons to find the smallest number, then n-2, and so on. So selection sort has a big O notation of O(n^2)

## Insertion Sort

Insertion sort goes number by number and inserts each number into its correct position.

Outline:

for h = 1 to n-1 do:
	insert num[h] among num[0] so that num[0] to num[h] is sorted
endfor

insertion sort is O(n^2)

## Heapsort

A **heap** is an almost complete binary tree such that the value at the root is greater than or equal to the values at the left and right children. And the left and right subtrees are also heaps.

After making a tree a heap, the largest value is at the root.

Sorting process

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

heap sort is O(n log n) and at most 4n comparisons

Quicksort

