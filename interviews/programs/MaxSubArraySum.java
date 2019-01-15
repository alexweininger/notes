import java.lang.Math.*;
/**
 * MaxSubArraySum
 */
public class MaxSubArraySum {

	public static int maxSubArraySum(int[] arr) {
		int max_ending_here = 0;
		int max_sum = Integer.MIN_VALUE;
		for (int i = 0; i < arr.length; i++) {
			max_ending_here = Math.max(arr[i], max_ending_here + arr[i]);
			max_sum = Math.max(max_sum, max_ending_here);
		}
		return max_sum;
	}
	public static void main(String[] args) {
		int arr[] = new int[]{1, 2, 3, 4, -10, 12};
		System.out.println(maxSubArraySum(arr));
	}
}
