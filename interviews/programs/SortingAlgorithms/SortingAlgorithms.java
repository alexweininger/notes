import java.util.Arrays;

/**
 * InnerSortingAlgorithms_1
 */
public class SortingAlgorithms {

	public static int[] bubbleSort(int[] arr) {

		for (int i = 0; i < arr.length - 1; i++) {
			for (int j = 0; j < arr.length - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		return arr;
	}

	public static void main(String[] args) {
		int[] arr = new int[]{4, 2, 8, 10, 1, 3};
		System.out.println(Arrays.toString(arr));

		System.out.println(Arrays.toString(bubbleSort(arr)));

	}
}
