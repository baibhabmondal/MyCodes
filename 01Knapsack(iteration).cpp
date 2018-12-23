#include <iostream>
#include <cmath>

using namespace std;

/*
* Its a 0/1 knapsack probelem. It returns the maximum value possible.
* It uses an iterative solution. Because recursive needs a memoization, and I am too lazy to do one lol.
* It maintains a 2D array. 
	example: 
		values : 1 4 5 7
		weights: 1 3 4 5
		
		Answer:9 (Value) (3rd and 2nd element) 
		
		-The matrix formed will be
	wts: 0 1 2 3 4 5 6 7
		 0 0 0 0 0 0 0 0
		 0 1 1 1 1 1 1 1
		 0 1 1 4 5 5 5 5
		 0 1 1 4 5 6 6 9
		 0 1 1 4 5 7 8 9
		 
		 the final value is T[n][wt] i.e, t[5][7] = 9
	
		
*/



int main() {
	int val[20], wt[20], n, maxwt =0;
	cout<<"Enter the number of items: "<<endl;
	cin>>n;
	int i, j;
	cout<<"Enter the values: ";
	for(i=0;i<n;i++)
		cin>>val[i];
	cout<<"\nEnter the wts: ";
	for(i=0;i<n;i++)
		cin>>wt[i];
	cout<<"Enter the max wt: ";
	cin>>maxwt;
	int t[n+1][maxwt+1];
	for(i=0; i<=n; i++)
		for(j=0; j<maxwt+1; j++)
		{
			if(j==0 || i ==0)
				{
				t[i][j] = 0;
				continue;
				}
			else if (j-wt[i-1] >= 0)
			{
				t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]] , t[i-1][j]);
			} else {
				t[i][j] = t[i-1][j];
			}
			
		}
	cout<<"\nThe max value is: "<<t[n][maxwt];

return 0;
}
