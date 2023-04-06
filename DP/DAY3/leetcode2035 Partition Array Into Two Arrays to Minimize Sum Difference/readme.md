# idea

This question is almost the same with leetcode1755, closest subsequence sum to target<br>
But we have to do a little conversion to the formula.<br>
```
Step1: convert the formula to easy version

let say the original array can be decompisite to two array. 
arr1 and arr2, they have the same length and arr1.size() + arr2.size() = arr.size()

if we want to minimize the value of abs(sum(arr1) - sum(arr2)), the best way to do it
is to find is there are sum that closest to the sum(arr)/2, as sum(arr1) + sum(arr2) =
sum(arr).

Step2: how can we can find such arr1

the N is 30, which is pretty large, if we find all the subset, it will definitly time
limit exceed.
if the N is 15, the problem would be much easy, so, this is a typical meet in middle 
question, the same like leetcode1755.
we first do a precomputation, we use bitmask, to store the every possible sum of the half of the arr. we can mark the number of bit1 with its sum. 

And then we search in the arr2, that their number of bit1 adds up to be N/2; 

the key point here, is not give a shit about the arr2, we just need to focus on arr1, 
because we already transferred the formula to SUM/2 - x; which x is sum(arr1);

```