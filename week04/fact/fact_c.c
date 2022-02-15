int fact_c(int n) {
	if (n == 1) {
		// base case
		return 1;
	}

	// recursive case
	return n * fact_c(n - 1);
}
