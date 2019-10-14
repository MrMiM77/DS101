

#include <bits/stdc++.h>
using namespace std;

const int max_n = 100010;
vector<int> adj[max_n];
bool mark[max_n];
int bad = 0;

void dfs(int v,int p)
{
	if(!mark[v])
		bad++;
	mark[v] = true;
	for(int i=0;i<adj[v].size();i++)
	{
		int u = adj[v][i];
		if(u!=p && !mark[u])
			dfs(u , v);
	}
}

int main()
{
	int n , q;
	cin >> n >> q;
	for(int i=0;i<n-1;i++)
	{
		int u , v;
		cin >> u >> v;
		u--,v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0;i<q;i++)
	{
		int u , v;
		cin >> u >> v;
		u--,v--;
		dfs(u , v);
		cout << n - bad <<endl;
	}


	return 0;
}

