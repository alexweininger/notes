clsas PermutationsOfString {
	public static void main(String[] args) {

	}

	public static int permutationsOfString(String str) {
		if (str.length() == 2) {
			return 2;
		} else if (str.length() == 1) {
			return 1;
		} else {
			return permutationsOfString(str.substring(0, str.length() - 1));
		}
	}
}
