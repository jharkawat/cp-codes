#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i<t; i++)
    {
        int n,s;
        cin >> n;
        double arrn[n], arrd[n], arrf[n];
        for(int j=0 ; j<n ; j++)
        {
            cin >> arrn[j];
        }
        for(int j=0 ; j<n ; j++)
        {
            cin >> arrd[j];
        }
        for(int j=0 ; j<n ; j++)
        {
            arrf[j] = ((arrn[j])/(arrd[j]));
        } 

        s = sizeof(arrf) / sizeof(arrf[0]); 
        unordered_map<double, double> mp; 
  
        for (int i = 0; i < s; i++) 
            mp[arrf[i]]++; 
  
        for (auto x : mp) 
            cout << x.first << " " << x.second << endl; 

        int l,m;
        double ele, find, result, count, search, count2, z;
        count = 0;
        for (auto& l: mp) 
        {
            ele = l.first;
            if(ele < 0.50000)
            {
                find = 1.0000000- ele;
                for(auto& m: mp)
                {
                    search = m.first;
                    if(find == search)
                    {
                        count = count + (l.second)*(m.second);
                    }

                }
            }
            else if( ele == 0.5000000)
            {
                z = l.second;
                count2 = 0;
                z--;
                while(z > 0)
                {
                    count2 = count2 + z;
                    z--;
                }
                count = count + count2;
            }
        } 
        cout << count << endl;

    }
}
