class Coins {

	// returns the number of ways to represent the given integer n with an infinite amount of coins
	public static int coins(int n) {
		if (n == 0)
			return 0;
		else if (n == 1)
			return 1;
		else if (n == 5)
			return 1 + coins(n - 1);
		else if (n == 10)
			return 1 + coins(n - 1);
		else if (n == 25)
			return 1 + coins(n - 1);
	}

	public static void main(String[] args) {

	}
}
