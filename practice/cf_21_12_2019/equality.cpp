#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define FOR(_i , N) for(ll _i = 0 ;_i < N ; _i ++)
#define FORE(_i , N) for(ll _i = N ;_i > 0 ; _i --)

template< class Key, class T, class Hash, class KeyEqual, class Allocator >
bool operator==( const unordered_map<Key,T,Hash,KeyEqual,Allocator>& hm1,
                 const unordered_map<Key,T,Hash,KeyEqual,Allocator>& hm2 );

template< class Key, class T, class Hash, class KeyEqual, class Allocator >
bool operator!=( const unordered_map<Key,T,Hash,KeyEqual,Allocator>& hm1,
                 const unordered_map<Key,T,Hash,KeyEqual,Allocator>& hm2 );                 

// bool areEqual(ll arr1[], ll arr2[], ll n) 
// { 
//     for (ll i = 0; i < n; i++) 
//         if (arr1[i] != arr2[i]) 
//             return false; 
  
//     // If all elements were same. 
//     return true; 
// } 

bool areEqual(unordered_map<ll,ll> lhs,unordered_map<ll,ll> rhs) 
{
    //[lhs_eq1, lhs_eq2) obtained from lhs.equal_range(lhs_eq1)
    if(lhs.size() != rhs.size())
    return false;
    else 
    {
        if(distance(lhs.equal_range(lhs) != distance(rhs.equal_range(rhs))
        return false;
        else
        {
            if(is_permutation(lhs.equal_range(lhs), lhs.equal_range(lhs), rhs.equal_range(rhs)) == true)
            return true;
            else 
            return false;
        }

    }
} 

// void print(ll arr[] , ll n)
// {
//     FOR(i,n)
//     {
//         cout << arr[i] ;
//     }
//     cout << endl;
// }

int main()
{
    ll n, m;
    cin >> n >> m;
    ll arr1[n], arr2[n];
    FOR(i,n)
    {
        cin >> arr1[i];
    }
    FOR(j,n)
    {
        cin >> arr2[j];
    }
    unordered_map<ll, ll> hm1, hm2;
    // for (ll i=0; i<n; i++) 
    // hm1[arr1[i]]++;

    for (ll i=0; i<n; i++) 
    hm2[arr2[i]]++;

    // ll a = sizeof(arr1)/sizeof(arr1[0]);
    // sort(arr1, arr1 + a);
    // sort(arr2, arr2 + a);
    FOR(j, m)
    {
        FOR(k,n)
        {
           arr1[k] = ((arr1[k] + j)%m);
        }
        //sort(arr1, arr1 + a);
        //print(arr1,n);
        //print(arr2,n);
        //cout << "in here" << j << endl;

        for (int i=0; i<n; i++) 
        hm1[arr1[i]]++;

//        cout << hm1 << endl;
        if(areEqual(hm1,hm2))
        {
            //cout << "in here check" << j << endl;
            cout << j << endl;
            return 0;
        }


    }

}