import java.util.Arrays;

/**
 * SetAllToZero
 */
public class SetAllToZero {

	public static void main(String[] args) {
		int a[][] = new int[][]{{1, 0, 0}, {1, 0, 0}, {1, 0, 0}, {1, 0, 0}};
		System.out.println(Arrays.deepToString(a));
		System.out.println(Arrays.deepToString(setToZero(a)));
	}

	public static int[][] setToZero(int[][] a) {
		boolean[] rows = new boolean[a.length];
		boolean[] cols = new boolean[a[0].length];

		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[0].length; j++) {
				if (a[i][j] == 0) {
					rows[i] = true;
					rows[j] = true;
				}
			}
		}

		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[0].length; j++) {
				if (rows[i] || cols[i]) a[i][j] = 0;
			}
		}
		return a;
	}
}
