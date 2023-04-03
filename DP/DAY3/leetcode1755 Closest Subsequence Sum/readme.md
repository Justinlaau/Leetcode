# idea
the input size is not large only 40, it is the same question as leetcode 2035 partition array into two arrays<br> we can use meet in middle and convert it to two sum problem.<br>
use a arrA to store half of the array and arrB to store another.<br>
use bitmask to get all the subset sum of these two array.<br>
we loop the sumA array, and use binary search to find the other val in sumB array that <br> sums up closest to goal