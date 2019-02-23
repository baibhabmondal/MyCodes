/*

Given an array of integers (both positive and negative), and a sum, check whether a sub array exists that adds upto the sum.

example:
[1,2,3,-5,-3,2]

sum: 4

o/p: exists. (since 2,2 results in 4)


Time: O(n)

*/



#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

bool sumSubArray(int *arr, int n, int sum)
{
	register int i = 0;
	int lsum = arr[0]; map<int, int> m;
	m.insert(pair<int, int>(sum, sum));
	for(i=0; i<n; i++)
	{
		lsum += arr[i];
		if (m.find(lsum - sum) != m.end())
			return true;
		else
		 	m.insert(pair<int, int>(arr[i], arr[i]));
	}
	return false;
}

int main() {
	int n, sum;
	cout<<"Enter the size: ";cin>>n;
	int *arr = (int*)malloc(n*sizeof(int));
	register int i = 0;
	cout<<"\nEnter the elements: ";
	for(i=0; i<n; i++) cin>>arr[i];
	cout<<"\nEnter the sum: "; cin>>sum;
	sumSubArray(arr, n, sum) ? cout<<"\nSum exists" : cout<<"\nSubarray not found";
	return 0;
}
