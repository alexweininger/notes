package ArraysAndStrings;
import java.util.ArrayList;
class UniqueCharacters {
	public static void main(String[] args) {

		System.out.println(uniqueCharacters("Alexander"));
		System.out.println(uniqueCharacters("Alex"));

		System.out.println(uniqueCharacters2("Alexander"));
		System.out.println(uniqueCharacters2("Alex"));
	}

	// this method uses 2 for loops to compare the characters in the string
	public static boolean uniqueCharacters(String str) {
		for (int i = 0; i < str.length() - 1; i++) {
			for (int j = i + 1; j < str.length(); j++) {
				if (str.charAt(j) == str.charAt(i)) return false;
			}
		}
		return true;
	}

	// this method uses an ArrayList to store the characters
	public static boolean uniqueCharacters2(String str) {
		ArrayList<Character> characters = new ArrayList<Character>();
		for (int i = 0; i < str.length(); i++) {
			if (characters.contains((str.charAt(i)))) return false;
			characters.add(str.charAt(i));
		}
		return true;
	}
}
