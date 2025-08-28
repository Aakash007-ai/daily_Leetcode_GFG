#include<bits/stdc++.h>
using namespace std;

// so think of solving it using dp , as we are given to find maximum price of item robber can rob,

/\*
Greedy approach
if robber try to pick costliest item first then it may be possible then its weight is so hight it can almost equal to its bag capacity

    and there are items whose worth is less and even less their weight
    then we have to chosse the less instead of more

    and sometime above condition may be false , more price will have less weight
    more price willl have more cost

    anything can be true
    that's why here greedy fails

\*/

/_
here we have combinations , we can pick any of combination but not all combination
situation where our condition get satisfy we choose only those cases, in this way we are avoding calculating extra stuff
_/

/_
so when there is case of combinations of various cases we choose recursion
and here fact is we put our condition while calculating combinations
memoizing combinations is called DP
_/
