class Fibonacci {
	public static void main(String[] args) {
		System.out.println(fibonacci(10));
	}

	public static int fibonacci(int n) {
		if (n == 1 || n == 2) return 1; // base case
		else if (n > 1) return fibonacci(n - 1) + fibonacci(n - 2);
		else return -1; // error checking
	}
}
