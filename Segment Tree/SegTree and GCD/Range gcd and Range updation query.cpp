Updation     :  We can not use here squre root decomposition
             :  Have to use segment tree only
Problems     :  https://www.codechef.com/problems/DGCD
             :  https://www.hackerearth.com/practice/data-structures/advanced-data-structures/suffix-trees/practice-problems/algorithm/employee-performance-1/
             :  https://www.codechef.com/problems/DGCD
Idea         :  https://codeforces.com/blog/entry/9722#comment-560705


Store two segment trees: one for adding some number to range and taking value of element 
(usual segment tree with lazy propagation) and one based on differences of adjacent elements.
When you add a number to the range, only two values in second segment tree change, so you can
easily recalculate values in second tree.
Now use the property that gcd(al, al + 1, ..., ar) = gcd(al, al + 1 - al, al + 2 - al + 1, ..., ar - ar - 1).
