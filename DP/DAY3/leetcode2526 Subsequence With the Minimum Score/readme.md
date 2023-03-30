# Idea
The question asks us to delete any number to make t a sequence of s.

The score is calculated based on smallest index and biggest index, <br> it is irrelevant to the length of interval, which means we can delete<br>the whole subarray, and get the index by left right pointer.

# ThreePass

This is a classical three pass question!

what is threepass?

basically, we can the question require us to find the optimal value,
which related to suffix, prefix <br>
, the original array can be divided to three part.

# O(nlogn) solution

We can use two pointer to precompute the prefix and suffix array by O(n) time complexity.<br>

The prefix and suffix array support us to fast check is t[:i] and t[j:] is the subsequence of s or not. <br>

The rest of things is to find an interval to delete and satisfied prefix and suffix array are valid<br> value.

As enumberate the interval cost us O(n^2) time, and we know if the interval become larger<br> the score is larger too. As right - left + 1 is larger. Thus this is monotonic, we can use <br> binary search to reduce the time complexity to O(nlogn)

# O(N) solution

<h2>intuition<h2>

<h4>We know if t contains or t is the subsequence of s, no matter how we delete subarray from t, it wouldn't change the property.<br>


we can scan s, we know s[:i] and s[i:] must contains a subsequence that equals <br> to t[:j] and t[j + len:].<br>
we can precompute the suffix common subsequence of s[i:] and t[j + len] to support <br> us fast check if i s.t s[i:] contain subsequence equal t[j:].<br>

we can loop s from left to right, to find the prefix just like suffix, and then we can get the delete interval. <br>

note we need to do a conditional checking about suffix[i:] > prefix[:i], in this case t must be the subsequence of s, no cost needed so 0 scores.