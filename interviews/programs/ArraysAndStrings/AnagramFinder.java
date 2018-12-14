/**
 * AnagramFinder
 */
public class AnagramFinder {

	public static void main(String[] args) {
		System.out.println(isAnagram("alex", "xeal"));
		System.out.println(isAnagram("alexa", "xeal"));
		System.out.println(isAnagram("alee", "xeal"));
	}

	public static boolean isAnagram(String base, String str) {

		if (base.length() != str.length())
			return false;

		for (int i = 0; i < base.length(); i++) {
			if (str.indexOf(base.charAt(i)) < 0) return false;
			if (base.indexOf(str.charAt(i)) < 0) return false;
		}
		return true;
	}
}
