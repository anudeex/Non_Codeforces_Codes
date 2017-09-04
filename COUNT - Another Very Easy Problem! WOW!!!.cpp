/*
Question: COUNT - Another Very Easy Problem! WOW!!!
Link: http://www.spoj.com/problems/COUNT/
Algorithm: DP Classic.
Created: 2017-09-05 00:21 IST 
*/

/*
This is a tricky dynamic programming question.

What we need to do is find the number of solutions to
x1+x2+x3…+xK=N, with the constraint that
0 <x1 ≤x2 ≤x3 … ≤ xK

Define f(N,K), f(N,K) to be the number of solutions. To solve the problem, we will define g(N,K), 
g(N,K) to be the number of solutions to the  same equation with the same constraints, 
except that we allow zero  values as well. That is, g(N,K) is the number of solutions to
x1+x2+x3+…+xK=N
with the constraint that
0≤ x1≤ x2≤ x3 … ≤ xK

It  is easy to see that f(N,K)=g(N,K)−g(N,K−1) since ignoring all sequences with x1=0 leaves us with only those sequences 
satisfying the first set of constraints.
Thus, if we can compute g(N,K) we can find f(N,K) as well.

Let  us derive the recurrence relation for g. We either have x1=0 or not. In the first case, the number of valid solutions is just g(N,K−1) 
since we need to obtain the sum N from the remaining variables. 
On the other hand, ifx1 is greater than 0, it is at least 1. We can subtract 1 from  all variables, and 
we will be left with K variables in increasing order summing up to N−K. The number of solutions to this is just g(N−K,K). 
That is, g(N,K)=g(N,K−1)+g(N−K,K)

The base cases for the recurrence are g(0,K)=1 for all K, and g(N,0)=0 for all N>1.
*/

#include <bits/stdc++.h>

typedef long long ll;

#define maxN (ll) 5005
#define mod (ll) 1988

using namespace std;

ll DP[maxN][maxN];

ll g(ll n, ll k) {
	if(n < 0) {
		return 0;
	}
	if(n == 0) {
		return 1;
	}
	if(k == 0) {
		return 0;
	}
	if(DP[n][k] != -1) {
		return DP[n][k];
	}
	return DP[n][k] = (g(n, k - 1) + g(n - k, k)) % mod;
}

int main() {
	while(1) {
		ll n, k, i, j;
		scanf("%lld %lld", &n, &k);
		for(i = 0; i <= n; i++) {
			for(j = 0; j <= k; j++) {
				DP[i][j] = -1;
			}
		}
		if(n == 0 and k == 0) {
			return 0;
		}
		ll ans = (g(n, k) - g(n, k - 1) + mod) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}