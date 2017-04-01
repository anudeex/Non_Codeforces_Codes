#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct segtree{
	ll left_bracket,right_bracket;

	void assign_leaf(ll value)
	{
		if(value==1)
		{
			right_bracket=1;left_bracket=0;
		}
		else
		{
			left_bracket=1;right_bracket=0;
		}
	}

	void merge(segtree& left,segtree& right)
	{
		ll new_matches=min(left.right_bracket,right.left_bracket);
		left_bracket=(right.left_bracket+left.left_bracket)-new_matches;
		right_bracket=(right.right_bracket+left.right_bracket)-new_matches;
	}

	void get_value()
	{
		//cout<<"Segment tree get value\n";
		if(left_bracket==0 && right_bracket==0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
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

void query_tree()
{
	segtree result=get_value(1,1,n,1,n);
	result.get_value();
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

void update_tree(ll index)
{
	ll value;
	if(arr[index]==-1)
	{
		value=1;
	}
	else
	{
		value=-1;
	}
//	cout<<"VALUE IS "<<value<<endl;
	update_value(1,1,n,index,value);
}

int main()
{
	for(ll l=1;l<=10;l++)
	{
		ll m,i,j;
		scanf("%lld",&n);
		string s;
		cin>>s;
		for(i=0;i<n;i++)
		{
			if(s[i]=='(')
			{
				arr[i+1]=1;
			}
			else
			{
				arr[i+1]=-1;
			}
		}
		/*for(i=1;i<=n;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;*/
		build_tree(1,1,n);
		//cout<<"BEFORE\n";
		//cout<<"L is "<<l<<endl;
		printf("Test %lld:\n",l);
		scanf("%lld",&m);
		while(m--)
		{
			//cout<<"INSIDE\n";
			ll k;
			scanf("%lld",&k);
			//cout<<"K is "<<k<<endl;
			if(k==0)
			{
				query_tree();
			}
			else
			{
				//cout<<"BEFORE UPDATE ROOT VALUE IS "<<nodes[1].parenthesis<<endl;
				update_tree(k);
				//cout<<"ROOT VALUE IS "<<nodes[1].parenthesis<<endl;
			}
		}
	}
	return 0;
}