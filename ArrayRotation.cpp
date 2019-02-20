#include <iostream>
#include <cctype>
#include <stdlib.h>
#include <cstring>
using namespace std;

/*void reverse(int arr[], int start, int end)
{
	int temp;
	while(start<end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
		
	}
}

void rotateleft(int n, int arr[], int pivot)
{
	reverse(arr, 0, pivot-1);
	reverse(arr, pivot, n-1);
	reverse(arr, 0, n-1);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}

int main()
{
	int n, arr[100];
	int pivot;
	cout<<"Enter the size:";
	cin>>n;
	cout<<"\nEnter the array:\n";
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"\nEnter the pivot: ";
	cin>>pivot;
	rotateleft(n,arr, pivot);
	return 0;
	
} */

int main ()
{
	string s;
	char temp;
	cin>>s;
	string s2 = s;	
	int start = 0;
	int end = s.length()-1;
	while(start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
	cout<<s2<<endl<<s<<endl;
	if (s == s2)
		cout<<"Palindrome";
	else
		cout<<"Not palindrome";
	return 0;

}
