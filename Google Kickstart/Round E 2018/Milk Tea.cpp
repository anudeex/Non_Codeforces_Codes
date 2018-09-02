/*
 █████╗ ███╗   ██╗██╗   ██╗██████╗ ███████╗███████╗██╗  ██╗         ██████╗██████╗ ███████╗
██╔══██╗████╗  ██║██║   ██║██╔══██╗██╔════╝██╔════╝╚██╗██╔╝        ██╔════╝██╔══██╗╚════██║
███████║██╔██╗ ██║██║   ██║██║  ██║█████╗  █████╗   ╚███╔╝         ██║     ██████╔╝    ██╔╝
██╔══██║██║╚██╗██║██║   ██║██║  ██║██╔══╝  ██╔══╝   ██╔██╗         ██║     ██╔══██╗   ██╔╝ 
██║  ██║██║ ╚████║╚██████╔╝██████╔╝███████╗███████╗██╔╝ ██╗███████╗╚██████╗██║  ██║   ██║  
╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚═════╝ ╚══════╝╚══════╝╚═╝  ╚═╝╚══════╝ ╚═════╝╚═╝  ╚═╝   ╚═╝  
By: Anudeex D Shetty
Question: Milk Tea
Link: https://code.google.com/codejam/contest/4394486/dashboard#s=p1
Algorithm: Implementation.
Created: 2018-09-03 01:12 IST 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define f first
#define s second

//https://code.google.com/codejam/contest/4394486/dashboard#s=a&a=1

int main() {
	freopen("B-large-practice.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios_base :: sync_with_stdio(0);
	ll t, i, j, k, T;
	cin >> t;
	for(T = 1; T <= t; T++) {
		ll n, m, p;
		cin >> n >> m >> p;
		ll pow2[p + 1];
		pow2[0] = 1;
		for(i = 1; i <= p; i++) {
			pow2[i] = 2 * pow2[i - 1];
		}
		string N[n], M[m];
		for(i = 0; i < n; i++) {
			cin >> N[i];
		}
		for(i = 0; i < m; i++) {
			cin >> M[i];
		}
		ll sz = 0;
		vector <pair<string, ll> > mini;
		for(k = 0; k < n; k++) {
			if(N[k][0] == '1') {
				sz++;
			}
		}
		mini.pb({"1", (n - sz)});
		mini.pb({"0", sz});
		for(i = 2; i <= p; i++) {
			string str;
			sz = pow2[i];
 			vector <pair<ll, string> > temp;
			for(j = 0; j < mini.size(); j++) {
				string newS = mini[j].f;
				str = "0";
				newS += str;
				ll cnt = mini[j].s;
				for(k = 0; k < n; k++) {
					if(N[k][i - 1] == '1') {
						cnt++;
					}
				}
				temp.pb({cnt, newS});
				newS = mini[j].f;
				str = "1";
				newS += str;
				cnt = mini[j].s;
				for(k = 0; k < n; k++) {
					if(N[k][i - 1] == '0') {
						cnt++;
					}
				}
				temp.pb({cnt, newS});
			}
			sort(temp.begin(), temp.end());
			mini.clear();
			for(j = 0; j < min(m + 1, (ll) temp.size()); j++) {
				mini.pb({temp[j].s, temp[j].f}); 
			}
		}
		set <string> ss;
		for(i = 0; i < m; i++) {
			ss.insert(M[i]);
		}
		ll ans;
		for(i = 0; i < (ll) mini.size(); i++) {
			if(ss.find(mini[i].f) == ss.end()) {
				ans = mini[i].s;
				break;
			}
		}
		cout << "Case #" << T << ": " << ans << "\n";
	}
	return 0;
}

