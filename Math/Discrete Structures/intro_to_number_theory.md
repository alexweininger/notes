# Chapter 2. Introduction to Math and Logic

## 1. An Introduction to Number Theory

In this section, we will work with the set of integers, `z = {.., -3, -2, -1, 0, 1, 2, 3, ...}`.  This sections is to get you acclimated to proving theorems involving numbers.

### Definitions

1. An integer `n` is **even** if `n = 2k` for some integer `k`.

2. An integer `n` is **odd** if `n = 2k + 1` for some integer `k`.

3. An integer `n` **divides** the integer `m`, written `m|n`, if and only if there exists an integer k such that `m = nk`.  We might also say that `m` is divisible by `n`.

### Theorems with example proofs

1. For an integer `n`, if `n` is even then `n^2` is even.

	From the definition of an even number (def 1), `n` is equal to `2k` where `k` is an integer.

	And `n^2` is equal to `(2k)^2`, which is `4k^2`.

	We can factor out a `2` which leaves us with `n^2 = 2(2k^2)`.

	We can now substitute `q` for `2k^2`, where q is an integer.

	Now we are left with `n^2 = 2(q)`, where `q` is an integer. Thus, by the definition of an even number (def 1), if n is an even integer n^2 is an even integer.

2. Assume n, m, and a are integers. If `a|n`, then `a|mn`.

	Taking `a|n`, we know that `n = ak` for some integer `k`. We can now substitute this expression in for `n`, leaving us with `a|akm`.

	Since we know that `a` divides `ak`, `a` also divides `akm` or `mn`.

### Problems and Exercises

1. Let `n` be an integer.  Prove or provide a counterexample: if 6 divedes n, then 3 divides n.

	If 6 divides n, we can say than `n = 6k`, where `k` is an integer.  We know that 3 divides 6.  Thus we know that 3 divides `6k`, or `n`.

2. Let `n` be an integer.  Prove or provide a counterexample: if 6 divedes n, then 4 divides n.

	To disprove this, lets use a counterexample.

	6 divides 18.  However 4 does not divide 18.

	_Note: In this scenario, providing a counterexample alone is enough to disprove this proposition._
