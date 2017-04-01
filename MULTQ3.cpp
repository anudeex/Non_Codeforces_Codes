#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct segtree{
	int start,end,pending_update=0,countt[3];

	void assign_leaf(int value)
	{
		countt[0]=1;
		countt[1]=0;
		countt[2]=0;
		pending_update=0;
	}

	void merge(segtree& left,segtree& right)
	{
		if(left.pending_update==0)
		{
			countt[0]=left.countt[0];
			countt[1]=left.countt[1];
			countt[2]=left.countt[2];
		}
		else if(left.pending_update==1)
		{
			countt[0]=left.countt[2];
			countt[1]=left.countt[0];
			countt[2]=left.countt[1];
		}
		else
		{
			countt[0]=left.countt[1];
			countt[1]=left.countt[2];
			countt[2]=left.countt[0];
		}
		if(right.pending_update==0)
		{
			countt[0]+=right.countt[0];
			countt[1]+=right.countt[1];
			countt[2]+=right.countt[2];
		}
		else if(right.pending_update==1)
		{
			countt[0]+=right.countt[2];
			countt[1]+=right.countt[0];
			countt[2]+=right.countt[1];
		}
		else
		{
			countt[0]+=right.countt[1];
			countt[1]+=right.countt[2];
			countt[2]+=right.countt[0];
		}
	}

	int get_value()
	{
		return countt[0];
	}
	

	int get_pending_update()
	{
		return pending_update;
	}

	bool is_there_pending_update()
	{
		return pending_update!=0;
	}

	void add_update(int value)
	{
		pending_update+=value;
		pending_update%=3;
	}

	void apply_pending_update()
	{
		int a=countt[0],b=countt[1],c=countt[2];
		if(pending_update==1)
		{
			countt[0]=c;
			countt[1]=a;
			countt[2]=b;
		}
		else if(pending_update==2)
		{
			countt[0]=b;
			countt[1]=c;
			countt[2]=a;
		}
		pending_update=0;
	}

};

int arr[100005];
segtree nodes[300005];
void update(int st_index,int start,int end,int value)
{
	int node_start=nodes[st_index].start,node_end=nodes[st_index].end;
	if(node_start==start && node_end==end)
	{
		nodes[st_index].add_update(value);
		return ;
	}
	int mid=(node_end+node_start)>>1,left_child=st_index<<1,right_child=left_child+1;
	if(start>mid)
	{
		update(right_child,start,end,value);
	}
	else if(end<=mid)
	{
		update(left_child,start,end,value);
	}
	else
	{
		update(left_child,start,mid,value);
		update(right_child,mid+1,end,value);
	}
	nodes[st_index].merge(nodes[left_child],nodes[right_child]);
}

void update_tree(int l,int r,int value)
{
	update(1,l,r,value);
}

segtree get_value(int st_index,int start,int end)
{
	int node_start=nodes[st_index].start,node_end=nodes[st_index].end;
	if(node_start==start && node_end==end)
	{
		segtree result=nodes[st_index];
		if(result.is_there_pending_update())
		{
			result.apply_pending_update();
		}
		return result;
	}
	int mid=(node_end+node_start)>>1,left_child=st_index<<1,right_child=left_child+1;
	segtree result;
	if(start>mid)
	{
		result=get_value(right_child,start,end);
	}
	else if(end<=mid)
	{
		result=get_value(left_child,start,end);
	}
	else
	{
		segtree left_child_result=get_value(left_child,start,mid);
		segtree right_child_result=get_value(right_child,mid+1,end);
		result.start=left_child_result.start;result.end=right_child_result.end;
		result.merge(left_child_result,right_child_result);
	}
	if(nodes[st_index].is_there_pending_update())
	{
		result.add_update(nodes[st_index].get_pending_update());
		result.apply_pending_update();
	}
	return result;
}

void query_tree(int l,int r)
{
	segtree result=get_value(1,l,r);
	printf("%d\n",result.get_value());
}

void build_tree(int st_index,int start,int end)
{
	int i;
	nodes[st_index].start=start;
	nodes[st_index].end=end;

	if(start==end)
	{
		nodes[st_index].assign_leaf(arr[start]);
		return;
	}

	int mid=(start+end)>>1,left_child=st_index<<1,right_child=left_child+1;
	build_tree(left_child,start,mid);
	build_tree(right_child,mid+1,end);
	nodes[left_child].pending_update=0;nodes[right_child].pending_update=0;
	nodes[st_index].merge(nodes[left_child],nodes[right_child]);
}

int main()
{
	int t;
	t=1;
	while(t--)
	{
		int n,m,i,j,k;
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			arr[i]=0;
		}
		build_tree(1,1,n);
		while(m--)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			b++;c++;
			if(a==0)
			{
				/*cout<<"UPDATE\n\n";
				cout<<"BEFORE\n";
				for(i=1;i<=7;i++)
				{
					cout<<nodes[i].ans<<" ";
				}
				cout<<endl;*/
				update_tree(min(b,c),max(b,c),1);
				/*cout<<"AFTER\n";
				for(i=1;i<=7;i++)
				{
					cout<<nodes[i].ans<<" ";
				}
				cout<<endl;*/
			}
			else
			{
				/*cout<<"BEFORE\n";
				for(i=1;i<=7;i++)
				{
					cout<<nodes[i].ans<<" ";
				}
				cout<<endl;*/
				query_tree(min(b,c),max(b,c));
			}
		}
	}
	return 0;
}
