#include <iostream>

using namespace std;

int* mergeSort(int n, int arr[])
{
	if (n < 2)
		return arr;
	int mid = n/2;
	int left[mid], right[n-mid];
	for(int i = 0; i< mid; i++)
		left[i] = arr[i];
	for(int i = mid; i< n; i++)
		right[i] = arr[i];
	left = mergeSort(mid, left);
	right = mergeSort(n-mid, right);
	
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
