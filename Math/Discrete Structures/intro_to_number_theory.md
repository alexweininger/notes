# Introduction to Math and Logic

## A taste of Number Theory

In this section, we will work with the set of integers, `z = {.., -3, -2, -1, 0, 1, 2, 3, ...}`.  This sections is to get you acclimated to proving theorems involving numbers.

### Definitions

1. An integer `n` is **even** if `n = 2k` for some integer `k`.

2. An integer `n` is **odd** if `n = 2k + 1` for some integer `k`.

## Theorems with example proofs

1. For an integer `n`, if `n` is even then `n^2` is even.

From the definition of an even number (def 1), `n` is equal to `2k` where `k` is an integer.

And `n^2` is equal to `(2k)^2`, which is `4k^2`.

We can factor out a `2` which leaves us with `n^2 = 2(2k^2)`.

We can now substitute `q` for `2k^2`, where q is an integer.

Now we are left with `n^2 = 2(q)`, where `q` is an integer. Thus, by the definition of an even number (def 1), if n is an even integer n^2 is an even integer.