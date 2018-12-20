
/**
 * RotateArray
 */
import java.util.Arrays;

public class RotateMatrix {

	public static void main(String[] args) {
		int a[][] = new int[][] { { 1, 0, 0 }, { 1, 0, 0 }, { 1, 0, 0 } };
		System.out.println(Arrays.deepToString(a));
		int[][] m = rotate(a);

		System.out.println(Arrays.deepToString(m));

	}

	public static int[][] rotate(int[][] a) {
		for (int level = 0; level < a.length / 2; level++) {
			for (int offset = level; offset < a.length - level; offset++) {

				int temp = a[offset][level];
				a[offset][level] = a[offset][a.length - 1 - level];
				a[offset][a.length - 1 - level] = a[a.length - 1 - level][a.length - 1 - offset];
				a[a.length - 1 - level][a.length - 1 - offset] = a[a.length - 1 - offset][level];
				a[a.length - 1 - offset][level] = temp;
			}
		}
		return a;
	}
}
