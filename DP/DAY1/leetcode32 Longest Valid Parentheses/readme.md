# Brute force

<h2>Idea<h2>

<h4>

At first I wanted to use Longest palidromic subarray to solve it, which is to use 3d array to cache information. But 3*10^4 * 3*10^4   is too large or too expensive for this problem.

So, I used the idea of checking for valid brackets.
You'll notice that there are only two invalid patterns where there are more closing parentheses than opening parentheses or openning more than closing. With this, we can observe whether there are more closing parentheses than opening parentheses, and we can count the number of effective parentheses.
The same goes for opening parentheses.

What I do is check for invalid patterns where there are more closing brackets than opening brackets, and then use another loop to check for more opening brackets than closing brackets.

Simple structure.

I shouldn't think it's too complicated, it took me about 20 minutes to solve some useless problems.

<h4>

<h3>

    Time complexity: O(N) 

    Space Complexity: O(N)

<h3>


