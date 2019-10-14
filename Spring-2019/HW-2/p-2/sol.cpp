#include <bits/stdc++.h>
using namespace std;

const int max_n = 100010;
int n;
vector<int>adj[max_n];
int d[max_n];
deque<int> q;


void bfs()
{
	for(int i=1;i<=n;i++)
		d[i] = n+1;
	d[0] = 0;
	q.push_back(0);
	while(q.size())
	{
		int v = q.front();
		q.pop_front();
		for(int i=0;i<adj[v].size();i++)
		{
			int u = adj[v][i];
			if(d[u] > d[v]+1)
			{
				q.push_back(u);
				d[u] = d[v]+1;
			}
		}
	}
}

int main()
{
	int m , k;
	cin >> n >> k >> m;
	for(int i=0;i<k;i++) 
	{
		int x;
		cin >> x;
		adj[0].push_back(x);
		adj[x].push_back(0);
	}
	for(int i=0;i<m;i++)
	{
		int u , v;
		cin >> u >>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bfs();
	for(int i=1;i<=n;i++)
		cout << d[i]-1 <<" ";
	cout << endl;
	return 0;
}

