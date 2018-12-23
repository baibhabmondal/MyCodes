#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;




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
