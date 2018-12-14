class ArraysAndStrings {
	public static void main(String[] args) {
		System.out.println(uniqueCharacters("alex"));
	}

	public static boolean uniqueCharacters(String str) {
		for (int i = 0; i < str.length() - 1; i++) {
			for (int j = i + 1; j < str.length(); j++) {
				if (str.charAt(j) == str.charAt(i)) return false;
			}
		}
		return true;
	}
}
