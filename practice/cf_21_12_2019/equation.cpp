#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define FOR(_i , N) for(ll _i = 0 ;_i < N ; _i ++)
#define FORE(_i , N) for(ll _i = N ;_i > 0 ; _i --)

bool iscomposite(ll n)
{
    for(ll i = 2; i< n/2 ; i++)
    {
        if((n%i) == 0)
        return true; 
    }
    return false;

}

int main()
{
    ll n, x, y;
    cin >> n;
    for(ll j = 1; j<1000000000 ; j++)
    {
        if(iscomposite(j))
        {
            if(iscomposite(j+n))
            {
                cout << (j+n) << " " << j << endl;
                return 0;
            }
        }
    }
}