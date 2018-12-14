/**
 * ReplaceSpaces
 */
public class ReplaceSpaces {

	public static void main(String[] args) {

		System.out.println(replaceSpaces("alex weininger"));
		System.out.println(replaceSpaces("alex weininger   "));
		System.out.println(replaceSpaces(" alex weininger "));
		System.out.println(replaceSpaces(""));
		System.out.println(replaceSpaces(" "));
	}

	public static String replaceSpaces(String str) {
		StringBuilder result = new StringBuilder();
		if (!str.contains(" ")) return str;
		result.append(str.substring(0, str.indexOf(' ')));

		for (int i = str.indexOf(' '); i <= str.lastIndexOf(' '); i++) {
			if (str.charAt(i) == ' ') {
				result.append("%20");
			} else {
				result.append(str.charAt(i));
			}
		}
		result.append(str.substring(str.lastIndexOf(' ') + 1));
		return result.toString();
	}
}
