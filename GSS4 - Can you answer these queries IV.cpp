#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct segtree{
	int start,end;
	ll total=0;
	bool pending_update=0;
	
	void assign_leaf(ll value)
	{
		total=value;
	}

	void merge(segtree& left,segtree& right)
	{
		total=left.total+right.total;
	}

	ll get_value()
	{
		return total;
	}

	bool is_propogation_required()
	{
		return total>(end-start+1);
	}

	void apply_pending_update()
	{
		total=(ll)sqrt(total);
		pending_update=0;
	}

	void add_update(bool value)
	{
		pending_update=1;
	}

	bool get_pending_update()
	{
		return 1;
	}

	void clear_pending_update()
	{
		pending_update=0;
	}

};

segtree nodes[300000];

int arr[100005];

segtree get_value(int st_index,int start,int end)
{
	//cout<<"Node Index is "<<st_index<<"Start is "<<start<<" End is "<<end<<endl;
	int node_start=nodes[st_index].start,node_end=nodes[st_index].end;
	if(node_end==end && node_start==start)
	{
		return nodes[st_index];
	}
	int mid=node_start+((node_end-node_start)>>1),left_child=st_index<<1,right_child=left_child+1;
	//cout<<"Mid is "<<mid<<" Left Child is "<<left_child<<" Right Child is "<<right_child<<endl;
	if(start>mid)
	{
		return get_value(right_child,start,end);
	}
	if(end<=mid)
	{
		return get_value(left_child,start,end);
	}
	segtree left_child_result=get_value(left_child,start,mid);
	segtree right_child_result=get_value(right_child,mid+1,end);
	segtree result;
	result.merge(left_child_result,right_child_result);
	return result;
}

void query_tree(int l,int r)
{
	//cout<<"INSIDE QUERY TREE\n\n";
	segtree result=get_value(1,l,r);
	printf("%lld\n", result.get_value());
}

void lazy_propogation_pending_update_to_subtree(int st_index,bool value)
{
	int node_start=nodes[st_index].start,node_end=nodes[st_index].end;
	nodes[st_index].add_update(value);
	if(!nodes[st_index].is_propogation_required())
	{
		return;
	}
	if(node_start==node_end)
	{
		nodes[st_index].apply_pending_update();
		return ;
	}
	bool pending_update=nodes[st_index].get_pending_update();
	nodes[st_index].clear_pending_update();	
	int mid=node_start+((node_end-node_start)>>1),left_child=st_index<<1,right_child=left_child+1;
	lazy_propogation_pending_update_to_subtree(left_child,pending_update);
	lazy_propogation_pending_update_to_subtree(right_child,pending_update);
	nodes[st_index].merge(nodes[left_child],nodes[right_child]);
}

void update(int st_index,int start,int end,bool value)
{
	int node_start=nodes[st_index].start,node_end=nodes[st_index].end;
	if(node_start==start && node_end==end)
	{
		lazy_propogation_pending_update_to_subtree(st_index,value);
		return ;
	}

	int mid=node_start+((node_end-node_start)>>1),left_child=st_index<<1,right_child=left_child+1;
	if(start>mid)
		update(right_child,start,end,value);
	else if(end<=mid)
		update(left_child,start,end,value);
	else
	{
		update(left_child,start,mid,value);
		update(right_child,mid+1,end,value);
	}
	nodes[st_index].merge(nodes[left_child],nodes[right_child]);
}

void update_tree(int l,int r)
{
	update(1,l,r,1);
}

void build_tree(int st_index,int start,int end)
{
	//cout<<"INDEX "<<st_index<<" Start "<<start<<" End "<<end<<endl;
	nodes[st_index].start=start;nodes[st_index].end=end;
	if(start==end)
	{
		nodes[st_index].assign_leaf(arr[start]);
		return;
	}

	int mid=start+((end-start)>>1);
	//cout<<"Mid is "<<mid<<endl;
	int left_child=st_index<<1,right_child=left_child+1;

	build_tree(left_child,start,mid);
	build_tree(right_child,mid+1,end);
	nodes[st_index].merge(nodes[left_child],nodes[right_child]); 
}

int main()
{
	int n,m,i,j,k,t=1;
	while(scanf("%d",&n)!=EOF)
	{
		//cout<<"N is "<<n<<endl;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&arr[i]);
		}
		build_tree(1,1,n);
		/*for(i=1;i<2*n;i++)
		{
			cout<<nodes[i].total<<" ";
		}
		cout<<endl;*/
		scanf("%d",&m);
		//cout<<"M is "<<m<<endl;
		printf("Case #%d:\n",t);
		while(m--)
		{
			int a,b,c;
			//cin>>a>>b>>c;
			scanf("%d%d%d",&a,&b,&c);
			//cout<<"A is "<<a<<" B is "<<b<<" C is "<<c<<endl;
			if(a==1)
			{
				//cout<<"query_tree\n";
				query_tree(min(b,c),max(b,c));
			}
			else
			{
				/*for(i=1;i<2*n;i++)
				{
					cout<<nodes[i].total<<" ";
				}
				cout<<endl;*/
				update_tree(min(b,c),max(b,c));
				/*for(i=1;i<2*n;i++)
				{
					cout<<nodes[i].total<<" ";
				}
				cout<<endl;*/
			}
		}
		t++;
		printf("\n");
	}
	return 0;
}