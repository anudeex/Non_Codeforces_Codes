//KGSS - Maximum Sum
//http://www.spoj.com/problems/KGSS/
#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct segtree{
	ll maxi,s_maxi;

	void assign_leaf(ll value)
	{
		maxi=value;s_maxi=-1;
	}

	void merge(segtree& left,segtree& right)
	{
		maxi=max(left.maxi,right.maxi);
		s_maxi=max(min(left.maxi,right.maxi),max(left.s_maxi,right.s_maxi));
	}

	ll get_value()
	{
		return maxi+s_maxi;
	}
};

ll arr[500005],n;

segtree nodes[1000005];

segtree get_value(ll st_index,ll left,ll right,ll l,ll r)
{
	//cout<<"Index "<<st_index<<" Left is  "<<left<<" Right is "<<right<<endl;
	if(left==l && right==r)
	{
		return nodes[st_index];
	}
	ll mid=left+(right-left)/2;
	if(l>mid)
	{
		return get_value(2*st_index+1,mid+1,right,l,r);
	}
	if(r<=mid)
	{
		return get_value(2*st_index,left,mid,l,r);
	}
	segtree left_result=get_value(2*st_index,left,mid,l,mid);
	segtree right_result=get_value(2*st_index+1,mid+1,right,mid+1,r);
	segtree result;
	result.merge(left_result,right_result);
	return result;
}

void query_tree(ll l,ll r)
{
	segtree result=get_value(1,1,n,l,r);
	printf("%lld\n",result.get_value());
}

void build_tree(ll st_index,ll left,ll right)
{
	//cout<<"Index "<<st_index<<" Left is  "<<left<<" Right is "<<right<<endl;
	if(left==right)
	{
		nodes[st_index].assign_leaf(arr[left]);
		return;
	}
	ll mid=left+(right-left)/2;
	build_tree(2*st_index,left,mid);
	build_tree(2*st_index+1,mid+1,right);
	nodes[st_index].merge(nodes[2*st_index],nodes[2*st_index+1]);
}

void update_value(ll st_index,ll left,ll right,ll index,ll value)
{
	if(left==right)
	{
		arr[left]=value;
		nodes[st_index].assign_leaf(value);
		return;
	}
	ll mid=left+(right-left)/2;
	if(index<=mid)
	{
		update_value(2*st_index,left,mid,index,value);
	}
	else
	{
		update_value(2*st_index+1,mid+1,right,index,value);
	}
	nodes[st_index].merge(nodes[2*st_index],nodes[2*st_index+1]);
}

void update_tree(ll index,ll value)
{
	update_value(1,1,n,index,value);
}

int main()
{
	ll m,i,j,k;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&arr[i]);
	}
	build_tree(1,1,n);
	scanf("%lld",&m);
	while(m--)
	{
		char a;
		cin>>a;
		ll b,c;
		scanf("%lld%lld",&b,&c);
		if(a=='Q')
			query_tree(b,c);
		else
			update_tree(b,c);
	}
	return 0;
}