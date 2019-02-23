/*

Given an array of integers (both positive and negative), check whether a sub array exists that adds upto the 0.

example:
[1,2,3,-5,-3,2]


o/p: exists. (since 3, -3 results in 0)

other arrays: [1,2,-3], [3,2,-5]..etc


*/

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

bool zeroSubArray(int *arr, int n)
{
	register int i = 0;
	int sum = arr[0]; map<int, int> m;
	m.insert(pair<int, int>(0, 0));
	for(i=0; i<n; i++)
	{
		sum += arr[i];
		if (m.find(sum) != m.end())
			return true;
		else
		 	m.insert(pair<int, int>(arr[i], arr[i]));
	}
	return false;
}

int main() {
	int n;
	cout<<"Enter the size: ";cin>>n;
	int *arr = (int*)malloc(n*sizeof(int));
	register int i = 0;
	cout<<"\nEnter the elements: ";
	for(i=0; i<n; i++) cin>>arr[i];
	zeroSubArray(arr, n) ? cout<<"\nZero Array exists" : cout<<"\nSubarray not found";
	return 0;
}
