#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define For(_i , N) for(int _i = 0 ;_i < N ; _i ++)
#define ForR(_i , N) for(int _i = N ;_i > 0 ; _i --)
#define ForI(_i , a , N) for(int _i = a ;_i < N ; _i ++)
#define ForIR(_i , a , N) for(int _i = N ;_i > a ; _i --)
#define INF (2139062143)

int main()
{
    ll n;
    cin >> n;
    ll arr[n];
    ll ans[n];
    For(i,n)
    {
        ans[i] = 0;
    }
    ll count = 0;
    For(i, n)
    {
        ll x; 
        cin >> x;
        arr[i] = x;
        //cout << "in x " << x << endl;
        if( x != 0)
        {
           ans[x-1] = 1; 
           count++;
        }
        //cout <<"count = " << count << endl;
    }
    count = n - count;
    //cout << count << endl;
    ll sim[count] ;
    For(i, n)
    {
        if(ans[i] == 0)
        {
            sim[count-1] = i+1;
            //cout << "in up" << sim[count-1] << endl;
            count--;
        }
    }
    ll k =0;
    For(i, n)
    {
        if(arr[i] == 0)
        {
            if((i+1 == sim[k]) && (k!=count))
            {
                ll a;
                a = sim[k];
                sim[k] = sim[k+1];
                sim[k+1] = a;
            }
            else if((i+1 == sim[k]) && (k==count))
            {
                ll a;
                a = sim[k];
                sim[k] = sim[0];
                sim[0] = a;
            }
            k++;
        }
    }
    k = 0;
    For(i , n)
    {
        if(arr[i] == 0)
        {
            arr[i] = sim[k];
            //cout << "in" << sim[k] << endl;
            k++;
        }
    }
    For(i , n)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    // For(i , count)
    // {
    //     cout << sim[i] << endl;
    // }
    

}