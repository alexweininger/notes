# 1. Counting

## 1.1 Introduction to Counting

To start the transition into higher level mathmatics we will take a detailed look at counting. In your experience counting has probably been pretty easy. This is not that type of counting. This chapter is not too hard, but may require a different way of thinking about math than most are comfortable with.

### Problems and Exercises

Before we dive deeper, take a look at these problems and exercises.  They may seem hard, but they are more than likely solvable with your current math understanding.

1. Suppose you have a bag containing red, blue, green, and white balls (one of each). Without looking in the bag you select a ball, note the color, and replace it in the bag.  When this process is repeated 4 times, how many sequences of colors are possible?

	Since we are selected a ball 4 times, and each time we have 4 different colors or balls to select, there are 4^4 different sequences of colors possible.

2. Referring to the previous question, suppose after you select a ball you didn't put it back in the bag.  How many different possible sequenced of colors are there now?

	As said before, we are choosing a ball from the bag 4 times.  Except this time the number of colors we have to choose from decreases after each selection.  So the answer is `4!` different sequences of colors.

## 1.2 Permutations and Combinations

### Definitions

1. An arrangment of `n` objects is called a **permutation** of the objects. An arrandment of `r` objects out of a collection of `n` distinct objects (where `n >= r`) is called an **r-permutation of n objects**.  We use the notation P(n, r) to represent a permutation.  We read these as _n permute r_ or _n arrange r_.

2. A collection of `r` objects taken from `n` distinct objects without regaurd to the order of the `r` objects is an **r-combination of the n objects**.  We is the notation C(n, r) for a combination.  We read this as _n choose r_.