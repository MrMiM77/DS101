#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;


#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 



ordered_set st;


int find(int x)
{
	int tmp = st.order_of_key(x);
	//cout << x <<" " << tmp << endl;
	return *(st.find_by_order(tmp));
}

int main()
{

	int n;
	cin >> n;
	long long sum = 0;
	for(int i=0;i<n;i++)
	{
		int x;
		int type;
		cin >> type >> x; 
		if(type == 1)
		{
			sum+=x;
			st.insert(x);
		}
		else 
		{
			sum-=x;
			st.erase(st.find(x));
		}
		if(sum%(int) st.size() == 0)
			cout << find(sum / (int) st.size()) << endl;
		else 
			cout << find(sum / (int) st.size() + 1) << endl;
	}
	return 0;
}

