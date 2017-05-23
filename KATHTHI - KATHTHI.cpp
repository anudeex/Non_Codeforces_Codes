//KATHTHI - KATHTHI
//http://www.spoj.com/problems/KATHTHI/

#include <bits/stdc++.h>

#define ll long long

#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll r,c,i,j,k;
		scanf("%lld%lld",&r,&c);
		string s[r];
		for(i=0;i<r;i++)
		{
			cin>>s[i];
		}
		ll distance[r][c];
		memset(distance,-1,sizeof distance);
		deque<pair<ll,ll> > q;
		q.push_back(mp(0,0));
		distance[0][0]=0;
		while(!q.empty())
		{
			ll curr_r=q.front().f,curr_c=q.front().s;
			ll new_r=curr_r+1,new_c=curr_c;
			q.pop_front();
			if(new_r>=0 and new_r<r and new_c>=0 and new_c<c)
			{
				ll w,new_dist;
				if(s[curr_r][curr_c]==s[new_r][new_c]) w=0;
				else w=1;
				new_dist=distance[curr_r][curr_c]+w;
				if(distance[new_r][new_c]==-1 or distance[new_r][new_c]>new_dist){
					distance[new_r][new_c]=new_dist;
					if(w) q.push_back(mp(new_r,new_c));
					else q.push_front(mp(new_r,new_c));
				}
			}
			new_r=curr_r-1;new_c=curr_c;
			if(new_r>=0 and new_r<r and new_c>=0 and new_c<c)
			{
				ll w,new_dist;
				if(s[curr_r][curr_c]==s[new_r][new_c]) w=0;
				else w=1;
				new_dist=distance[curr_r][curr_c]+w;
				if(distance[new_r][new_c]==-1 or distance[new_r][new_c]>new_dist){
					distance[new_r][new_c]=new_dist;
					if(w) q.push_back(mp(new_r,new_c));
					else q.push_front(mp(new_r,new_c));
				}
			}
			new_r=curr_r;new_c=curr_c+1;
			if(new_r>=0 and new_r<r and new_c>=0 and new_c<c)
			{
				ll w,new_dist;
				if(s[curr_r][curr_c]==s[new_r][new_c]) w=0;
				else w=1;
				new_dist=distance[curr_r][curr_c]+w;
				if(distance[new_r][new_c]==-1 or distance[new_r][new_c]>new_dist){
					distance[new_r][new_c]=new_dist;
					if(w) q.push_back(mp(new_r,new_c));
					else q.push_front(mp(new_r,new_c));
				}
			}
			new_r=curr_r;new_c=curr_c-1;
			if(new_r>=0 and new_r<r and new_c>=0 and new_c<c)
			{
				ll w,new_dist;
				if(s[curr_r][curr_c]==s[new_r][new_c]) w=0;
				else w=1;
				new_dist=distance[curr_r][curr_c]+w;
				if(distance[new_r][new_c]==-1 or distance[new_r][new_c]>new_dist){
					distance[new_r][new_c]=new_dist;
					if(w) q.push_back(mp(new_r,new_c));
					else q.push_front(mp(new_r,new_c));
				}
			}
		}
		printf("%lld\n",distance[r-1][c-1]);
	}
	return 0;
}