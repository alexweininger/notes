class ValidParenthesisCombinations {

	// print all possible valid combinations of n pairs of parenthesis
	public static void printParens(int l, int r, char[] str, int count) {
		if (l < 0 || r < l)
			return; // invalid state
		if (l == 0 && r == 0) {
			System.out.println(str); // found one, so print it
		} else {
			if (l > 0) { // try a left paren, if there are some available
				str[count] = '(';
				printParens(l - 1, r, str, count + 1);
			}
			if (r > l) { // try a right paren, if there's a matching left
				str[count] = ')';
				printParens(l, r - 1, str, count + 1);
			}
		}
	}

	public static void main(String[] args) {
		int count = 3;
		char[] str = new char[count * 2];
		printParens(count, count, str, 0);
	}
}
