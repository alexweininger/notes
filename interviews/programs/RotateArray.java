import java.util.Arrays;

/**
 * RotateArray
 */
public class RotateArray {

	public static void main(String[] args) {
		int[] a = new int[]{1, 2, 3, 4, 5};
		System.out.println(Arrays.toString(rotateLeft(a, 1)));
		System.out.println(Arrays.toString(rotateLeft(a, 2)));
		System.out.println(Arrays.toString(rotateLeft(a, 5)));
	}

	public static int[] rotateLeft(int[] m, int rotations) {
		for (int i = 0; i < rotations; i++) {
			m = rotateLeft(m);
		}
		return m;
	}

	public static int[] rotateLeft(int[] m) {
		int[] r = new int[m.length];
		r[r.length -1] = m[0];
		for (int i = 0; i < m.length - 1; i++) {
			r[i] = m[i + 1];
		}
		return r;
	}
}
