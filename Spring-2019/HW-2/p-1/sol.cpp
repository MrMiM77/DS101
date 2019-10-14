#include <bits/stdc++.h>
using namespace std;


const int max_n = 1000100;

int ans[max_n];
int ln[max_n];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	ans[s.length()-1] = s.length();

	for(int i=s.length()-2;i>=0;i--)
	{
		if(s[i] == s[i+1])
			ans[i] = i , ln[i] = 1;
		else if(i != s.length() - 2 && s[i] == s[i+2])
			ans[i] = i , ln[i] = 2;
		else ans[i] = ans[i+1] , ln[i] = ln[i+1]; 
			
	}
	int q;
	cin >> q;
	for(int i=0;i<q;i++)
	{
		int l , r;
		cin >> l >> r;
		l-- , r--;
		if(ans[l] + ln[l] <= r)
			cout <<"Yes" << "\n";
		else 
			cout <<"No" << "\n";
	}



	return 0;
}

