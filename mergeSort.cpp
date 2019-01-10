#include <iostream>

using namespace std;

int* merge(int left[], int right[], int l, int r)
{
	int c[l+r], i=0, j=0, k=0;
	while(i<l && j<r)
	{
		if (left[i] <= right [j])
			{
				c[k] = left[i];
				i++;
			}
		else {
			c[k] = right[j];
			j++;
		}
		k++;
	}
	cout<<"\nAfter merge: "<<endl;
	for(i = 0; i <l+r; i++)
		cout<<c[i]<<" ";
	return c;
}

void mergeSort(int n, int* arr[])
{
	if (n < 2)
		return arr;
	int mid = n/2;
	int l = mid, r = n-mid;
	int left[mid], right[n-mid];
	for(int i = 0; i< mid; i++)
		left[i] = arr[i];
	for(int i = mid; i< n; i++)
		right[i] = arr[i];
	mergeSort(mid, left);
	mergeSort(n-mid, right);
	merge(left, right, l, r);
}

int main () {

int n, i, arr[100];

cout<<"Enter the size of the array: ";
cin>>n;
cout<<"\nEnter the array: "<<endl;
for(i=0; i<n; i++)
	cin>>arr[i];
cout<<"...Sorting..."<<endl;
arr = mergeSort(n, arr);
cout<<"After sorting: "<<endl;

for(i=0;i<n; i++)
	cout<<arr[i]<<" ";
return 0 ;
}
