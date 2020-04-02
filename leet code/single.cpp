#include<bits/stdc++.h>

using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test() int t;cin>>t;while(t--)
#define ll long long
#define For(_i , N) for(int _i = 0 ;_i < N ; _i ++)
#define ForR(_i , N) for(int _i = N ;_i > 0 ; _i --)
#define ForI(_i , a , N) for(int _i = a ;_i < N ; _i ++)
#define ForIR(_i , a , N) for(int _i = N ;_i > a ; _i --)
#define INF (2139062143)

int main()
{
    vector<int> v1; 
    int a[] = { 1, 2, 3, 3, 2 }; 
  
    // assign first 2 values 
    v1.assign(a, a + 5); 
    // cout << "Elements of vector1 are\n"; 
    // for (int i = 0; i < v1.size(); i++) 
    //     cout << v1[i] << " ";  

    unordered_set<int> inset;

    for(int i =0; i< v1.size(); i++)
    {
        if(inset.find(v1[i]) == inset.end())
        {
            inset.insert(v1[i]);
        }
        else
        {
            inset.erase(inset.find(v1[i]));
        }

    }
    int ans;
    for (auto it = inset.begin(); it != inset.end(); it++) 
    { 
        ans = *it ; 
    }   
    return ans; 
}