/*

	A frugal number is a number whose number of digits 
	is strictly greater than the number of digits in its prime factorization (including exponents). 
	If the exponent is 1 for a certain prime, involved in the prime factorization, 
	then that exponent does not contribute to the number of digits in the prime factorization.

 Some examples of frugal numbers are:

1) 125 = 5^3, here the number of digits in the number is three (1, 2 and 5) 
			  which is strictly greater than the number of digits in its prime factorization which is two (5 and 3).

2) 512 = 2^9, here the number of digits in the number is three (5, 1 and 2) 
			  which is strictly greater than the number of digits in its prime factorization which is two (2 and 9).

3) 1029 = 3 × 7^3, here the number of digits in the number is four (1, 0, 2 and 9) 
			  which is strictly greater than the number of digits its prime factorization which is three (3, 7 and 3).
			  
			  
explanation Credits: GeeksForGeeks. 
Link: https://www.geeksforgeeks.org/frugal-number/


*/



#include <iostream>
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
map<int, int> primeFactors(int n)
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
	return m;
}

int digits (int n)
{
	int cd = 0;
	while(n)
	{
		cd++;
		n /= 10;
	}
	return cd;	
}

bool isFrugal (int n)
{
	if (n<125)
		return false;
    if (isPrime(n))
    	return false;	
    map<int, int> m = primeFactors(n);
	map <int, int>::iterator itr = m.begin();
	int nd = digits(n);
	int count = 0;
	while(itr != m.end())
	{   
	    if (itr->second==1)
	    	count += digits(itr->first);
	    else if (itr->second > 1)
	    {
	    	count += digits(itr->first);
	    	count += digits(itr->second);
		}
		itr++;
	}
	if (count < nd)
	 	return true;
	return false;	
}


int main() {
 int n;
 while (true)
 {
 cout<<"Enter the number: ";
 cin>>n;
 if (isFrugal(n))
 	cout<<"Frugal Number\n";
 else
 	cout<<"Not a frugal Number\n";
    cout<<endl;
 }
return 0;
}
