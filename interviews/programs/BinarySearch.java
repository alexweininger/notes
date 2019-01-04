class BinarySearch {
	public static void main(String[] args) {
		int arr[] = new int[] { 0, 1, 4, 6, 7, 9, 10, 11, 13, 17, 22, 56, 59, 65 };
		System.out.println(binarySearch(65, arr, 0, arr.length));
		System.out.println(binarySearch(65, arr));
	}

	// recursive binary search O(log n)
	public static int binarySearch(int key, int arr[], int startIndex, int endIndex) {
		if (startIndex >= endIndex) {
			if (arr[startIndex] == key) {
				return startIndex;
			} else {
				return -1;
			}
		} else {
			int mid = (startIndex + endIndex) / 2;
			if (arr[mid] < key) {
				return binarySearch(key, arr, mid + 1, endIndex);
			} else {
				return binarySearch(key, arr, 0, mid);
			}
		}
	}

	// non recursive version of binary search to avoid a large stack cost
	public static int binarySearch(int key, int arr[]) {
		int startIndex = 0;
		int endIndex = arr.length - 1;
		while (startIndex < endIndex) {
			int mid = (startIndex + endIndex) / 2;
			if (arr[mid] < key) {
				startIndex = mid + 1;
			} else {
				endIndex = mid;
			}
		}
		if (arr[startIndex] == key) {
			return startIndex;
		}
		return -1;
	}
}
