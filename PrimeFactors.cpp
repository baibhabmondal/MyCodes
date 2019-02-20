/*
Program to calculate the prime factors and their powers. 
Sample Input: 20

ouput: 

Factors -> powers

2 -> 2
5 -> 1

Explanation: 20 has three prime factors, 2, 2, and 5. That is, 2*2*5 = 20. therefore, 2's power is 2. And 5's power is 1. 

Example 2: 

i/p: 576
o/p:  2 -> 6
	  3 -> 2
	  
explanation: 2^6 * 3^2 = 576

*/





#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

bool isPrime (int n)
{
	if (n == 2 || n == 3)
		return true;
	if (n < 2 || n % 2 == 0)
		return false;
	if (n < 9 )
 		return true;
	if (n%3 == 0)
 		return false;
 	int f = 5;
 	while(f <= sqrt(n))
	 {
	 	if (n % f == 0)
	 		return false;
	 	if  (n%(f+2) == 0)
	 		return false;
	 	f += 6;
	 }
	return true;
}

void primeFactors (int n)
{
	int tn = n, i = 2;
	map <int, int> m;
	while (i < n/2){
		tn = n;
		if( tn % i == 0 && isPrime(i))
		{
		  int count = 0;
		  while(tn)
		  {
		  	if (tn % i == 0)
		  	{
			  	count++;
			  	tn /= i;
			} 
		  	else
		  	 break;
		  }
		 if(count)
			 m.insert(pair<int, int>(i, count));		
		}
		i++;
	}	
	map <int, int>::iterator itr = m.begin();
	while(itr != m.end())
	{
		cout<<itr->first<<" -> "<<itr->second<<endl;
		itr++;
	}	
}


int main() {
 int n;
 cout<<"Enter the Number:";
 cin>>n;
 cout<<"Prime Factors:\n";
 cout<<"Factor -> Powers\n";
primeFactors(n);
return 0;
}
