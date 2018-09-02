/*
 █████╗ ███╗   ██╗██╗   ██╗██████╗ ███████╗███████╗██╗  ██╗         ██████╗██████╗ ███████╗
██╔══██╗████╗  ██║██║   ██║██╔══██╗██╔════╝██╔════╝╚██╗██╔╝        ██╔════╝██╔══██╗╚════██║
███████║██╔██╗ ██║██║   ██║██║  ██║█████╗  █████╗   ╚███╔╝         ██║     ██████╔╝    ██╔╝
██╔══██║██║╚██╗██║██║   ██║██║  ██║██╔══╝  ██╔══╝   ██╔██╗         ██║     ██╔══██╗   ██╔╝ 
██║  ██║██║ ╚████║╚██████╔╝██████╔╝███████╗███████╗██╔╝ ██╗███████╗╚██████╗██║  ██║   ██║  
╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚═════╝ ╚══════╝╚══════╝╚═╝  ╚═╝╚══════╝ ╚═════╝╚═╝  ╚═╝   ╚═╝  
By: Anudeex D Shetty
Question: Yogurt
Link: https://code.google.com/codejam/contest/4394486/dashboard#s=p0
Algorithm: Implementation.
Created: 2018-08-26 10:36 IST 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	ll t;
	scanf("%lld", &t);
	int j = 1;
	while(t--) {
		ll n, k, i;
		scanf("%lld %lld", &n, &k);
		ll arr[n];
		for(i = 0; i < n; i++) {
			scanf("%lld", &arr[i]);
		}
		sort(arr, arr + n);
		ll ans = 0;
		ll day = 0;
		i = 0;
		while(i < n) {
			if(arr[i] > day) {
				if((i + k - 1) < n) {
					ans += k;
					i += k;
				}
				else {
					ans += (n - i);
					i = n;
				}
				day++;
			}
			else {
				i++;
			}
		}
		printf("Case #%lld: %lld\n", j, ans);
		j++;
	}
	return 0;
}

