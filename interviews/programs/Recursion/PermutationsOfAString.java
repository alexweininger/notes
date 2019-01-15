import java.util.ArrayList;

class PermutationsOfAString {

	public static ArrayList<String> getPermutations(String str) {
		ArrayList<String> p2 = new ArrayList<String>();
		if (1 == str.length()) {
			p2.add(str);
			return p2;
		} else {
			String c = str.substring(0, 1);
			ArrayList<String> p = getPermutations(str.substring(1));
			for (String s : p) {
				for (int i = 0; i <= s.length(); i++) {
					p2.add(s.substring(0, i) + c + s.substring(i));
				}
			}
		}
		return p2;
	}

	public static void main(String[] args) {
		ArrayList<String> p = getPermutations("abc");
		for (int i = 0; i < p.size(); i++) {
			System.out.println(p.get(i));
		}
	}
}
