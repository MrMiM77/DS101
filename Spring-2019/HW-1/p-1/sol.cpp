#include <bits/stdc++.h>
using namespace std;

const int max_n = 100010;

int a[max_n];

int main()
{
	int n; 
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(i>1 && a[i] > a[i/2])
		{
			cout <<"NO" << endl;
			return 0;
		}
	}
	cout <<"YES" << endl;
	return 0;
}

