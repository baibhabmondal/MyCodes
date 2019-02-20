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
