package ArraysAndStrings;

/**
 * ReverseCStyleString
 */
public class ReverseCStyleString {
	public static void main(String[] args) {
		System.out.println(reverseCString("string\0"));
	}


	/*
	 * notes:
	 * c strings end with a terminating character, so we must reverse everything but the last character
	 *
	 * reverse all but the last character
	 */

	 public static String reverseCString(String str) {
		StringBuilder reversed = new StringBuilder();
		for (int i = str.length() - 2; i >= 0; i--) {
			reversed.append(str.charAt(i));
		}
		reversed.append('\0');
		return reversed.toString();
	 }
}
