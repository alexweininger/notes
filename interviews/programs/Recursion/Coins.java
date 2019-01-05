class Coins {

	// returns the number of ways to represent the given integer n with an infinite amount of coins
	public static int coins(int n, int denom) {


		// for each number of coins
		// if it is larger than a coin, then calculate the ways for each number of coins
		int next = 0;
		switch (denom) {
			case 25:
				next = 10;
				break;
			case 10:
				next = 5;
				break;
			case 5:
				next = 1;
				break;
			case 1:
				return 1;
		}
		int ways = 0;
		for (int i = 0; i * denom <= n; i++) {
			ways += coins(n - (i * denom), next);
		}

		return ways;
	}

	public static void main(String[] args) {
		System.out.println(coins(10, 25));
		System.out.println(coins(1, 25));
		System.out.println(coins(2, 25));
		System.out.println(coins(5, 25));
		System.out.println("hello");
	}
}
