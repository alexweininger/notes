package ArraysAndStrings;
/**
 * RemoveDuplicates
 */
public class RemoveDuplicates {

	public static void main(String[] args) {
		System.out.println(removeDuplicates("Alex"));
		System.out.println(removeDuplicates("alexander"));
		System.out.println(removeDuplicates(""));
		System.out.println(removeDuplicates("a"));
		System.out.println(removeDuplicates("aaaaa"));
		System.out.println(removeDuplicates("abcda"));
		System.out.println(removeDuplicates("bbaa"));
		System.out.println(removeDuplicates("  "));
	}

	public static String removeDuplicates(String str) {
		StringBuilder result = new StringBuilder();

		for (int i = 0; i < str.length(); i++) {
			boolean d = false;
			for (int j = i - 1; j >= 0;  j--) {
				if (str.charAt(i) == str.charAt(j))
					d = true;
			}
			if (!d)
				result.append(str.charAt(i));
		}
		return result.toString();
	}
}
