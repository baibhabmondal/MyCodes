/*

Given an array and a sum, find the number of subarrays who's elements adds upto the given sum.
A classic subsequence problem. 

I have also shown the resultant subarray. 
My algorithm takes O(n^2) time. I'll look for a better algotrithm and replace it.

Sample i/p and o/p has been shown in the image. 

Look for output.jpg/png.

You can submit a PR for a better approach.

Pre-requisites: Vector, stack. (STL)

Thanks!


*/




#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
   if(a < b) return true;
   return false;
}

int main()
{
	int n;
	vector < stack<int> > result;
	stack <int> s;
	cout<<"Enter the size:"; cin>> n;
	int sum, *arr = (int*)malloc(sizeof(int)*n);
	cout<<"\nEnter the elements of the array:"; 
	register int i = 0, j = 0;
	for(i=0; i<n; i++) cin>>arr[i];
	cout<<"\nEnter the sum:"; cin>>sum;
	sort(arr, arr+n, cmp);
	for(i=0; i<n; i++)
	{
		int tsum = sum - arr[i];
		s.push(arr[i]);
		for(j=i+1; j<n; j++)
		{
			if (tsum == arr[j])
			{
				if(!s.empty())
					tsum += s.top();
				s.push(arr[j]);
				result.push_back(s);
				if(!s.empty())
				s.pop();
				if(!s.empty())
				s.pop();
			}
			else if (tsum > arr[j])
			{
				tsum -= arr[j];
				s.push(arr[j]);
			}
			else
			{
				if (!s.empty())
				{
					tsum += s.top();
					s.pop();
				}
			}
		}
		while(!s.empty())
			s.pop();
		}
	for (i=0; i<result.size(); i++)
	{
		cout<<"{ ";
		while(!result[i].empty())
		{
			cout<<result[i].top()<<", ";
			result[i].pop();
		}
		cout<<"}";
		cout<<endl;
	}
	cout<<"\n Number of subarrays: "<<result.size();
	return 0;
}
