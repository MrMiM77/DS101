
// A Stack based C++ program to find next 
// greater element for all array elements. 
#include <bits/stdc++.h> 
using namespace std; 

/* prints element and NGE pair for all 
   elements of arr[] of size n */
const int max_n = 100010;
int ans[max_n];
void printNGE(int arr[], int n) { 
	stack < pair<int ,int >  > s; 

	/* push the first element to stack */
	s.push(make_pair(arr[0] , 0)); 

	// iterate for rest of the elements 
	for (int i = 1; i < n; i++) { 

		if (s.empty()) { 
			s.push(make_pair(arr[i] , i)); 
			continue; 
		} 

		/* if stack is not empty, then 
		   pop an element from stack. 
		   If the popped element is smaller 
		   than next, then 
		   a) print the pair 
		   b) keep popping while elements are 
		   smaller and stack is not empty */
		while (s.empty() == false && s.top().first < arr[i]) 
		{		 
			//cout << arr[i] << " ";
			ans[s.top().second] =  arr[i]; 
			s.pop();
		} 

		/* push next to stack so that we can find 
		   next greater for it */
		s.push(make_pair(arr[i] , i)); 
	} 

	/* After iterating over the loop, the remaining 
	   elements in stack do not have the next greater 
	   element, so print -1 for them */
	while (s.empty() == false) { 
		//cout << -1 << " ";
		ans[s.top().second] = -1;
		s.pop(); 
	} 
} 

/* Driver program to test above functions */
int arr[max_n];
int main() { 
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	printNGE(arr, n); 
	for(int i=0;i<n;i++) cout << ans[i] <<" ";
	cout << endl;
	return 0; 
}


