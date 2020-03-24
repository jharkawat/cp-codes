#include <iostream>
using namespace std;

int main()
{
	int n,i;
	bool isprime = true;
	
	cout << "Enter a positive number :\n";
	cin >> n;
	
	for (i =2 ; i<=n/2 ; i++)
	{
		if(n%i == 0)
		{
			isprime = false;
			break;
		}
	}
	if (isprime)
		cout << "this is a prime number \n";
	else 
		cout << "this is not a prime number \n";
	
	return 0;

}
