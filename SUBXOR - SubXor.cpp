#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct trie{
	ll prefixes;
	trie *edges[2];

	trie()
	{
		prefixes=0;
		edges[0]=edges[1]=NULL;
	}
};

void add_word(trie *vertex,ll no,ll bit)
{
	vertex->prefixes++;
	if(bit!=-1)
	{
		bool no_bit=no&(1<<bit);
		if(vertex->edges[no_bit]==NULL)
		{
			vertex->edges[no_bit]=new trie();
		}
		return add_word(vertex->edges[no_bit],no,bit-1);
	}
	return ;
}

ll less_than_k(trie *vertex,ll no,ll k,ll bit,bool done)
{
	if(done)
	{
		return vertex->prefixes;
	}
	if(bit==-1)
	{
		return 0;
	}
	bool no_bit=no&(1<<bit),k_bit=k&(1<<bit);
	if(k_bit==0)
	{
		if(vertex->edges[no_bit]==NULL)
		{
			return 0;
		}
		return less_than_k(vertex->edges[no_bit],no,k,bit-1,done);
	}
	ll temp=0;
	if(vertex->edges[no_bit]!=NULL)
	{
		temp+=less_than_k(vertex->edges[no_bit],no,k,bit-1,1);
	}
	if(vertex->edges[!no_bit]!=NULL)
	{
		temp+=less_than_k(vertex->edges[!no_bit],no,k,bit-1,done);
	}
	return temp;
}

int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		trie *root=new trie();
		ll n,k,i,j;
		scanf("%lld%lld",&n,&k);
		ll curr=0;
		add_word(root,curr,31);
		ll ans=0;
		for(i=0;i<n;i++)
		{
			ll a;
			scanf("%lld",&a);
			curr=a^curr;
			ans+=less_than_k(root,curr,k,31,0);
			add_word(root,curr,31);
		}
		printf("%lld\n",ans);
	}
	return 0;
}