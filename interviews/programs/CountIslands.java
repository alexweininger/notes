/**
 * CountIslands
 */
public class CountIslands {

	public static void main(String[] args) {
		int m[][] = new int[][]{{1, 0, 0, 0}, {1, 0, 1, 1}, {1, 1, 0, 0}, {1, 1, 0, 0}};
		System.out.println(countIslands(m));
	}

	public static int countIslands(int m[][]) {
		int count = 0;
		for (int i = 0; i < m.length; i++) {
			for (int j = 0; j < m.length; j++) {
				if (m[i][j] == 1) {
					count++;
					m = zero(m, i, j);
				}
			}
		}
		return count;
	}

	public static int[][] zero(int m[][], int i, int j) {
		if (i < 0 || j < 0 || i >= m.length || j >= m.length) return m;
		if (m[i][j] == 0) return m;
		else m[i][j] = 0;

		m = zero(m, i - 1, j);
		m = zero(m, i - 1, j + 1);
		m = zero(m, i - 1, j - 1);
		m = zero(m, i + 1, j);
		m = zero(m, i + 1, j + 1);
		m = zero(m, i + 1, j - 1);
		m = zero(m, i, j - 1);
		m = zero(m, i, j + 1);
		return m;
	}
}
