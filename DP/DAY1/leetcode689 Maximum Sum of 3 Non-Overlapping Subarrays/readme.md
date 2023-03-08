# Idea

prefix sum and suffix sum 
```
3 nonoverlaaping
[0~k] [k + 1 ~ 2*k - 1] [2*k ~ n]

First, we can use sliding window idea, the window size is k, and when it moving forward, 
it adds a number, and substract a number from the window, by this, we can easily to get
a max interval and its index.
The only difficult part of this question is non overlapping, how to avoid overlapping?
if we can get the max interval, idx from [0:k], and [2*k:n], we just need to consider,
[k + 1: 2*k - 1], this is just another sliding window we just did. 

but this time, we are god, we knew everything of [0:k] and [2*k:n]

```