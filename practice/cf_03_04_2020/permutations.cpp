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
	test()
	{
        int n;
        cin >> n;
        vector<int> vec;
        vector<int> vec2;
        vector<int> first;
        vector<int> second;
        int count = 0;
        
    //     For(i,n)
    //     {
    //         int p;
    //         cin >> p;
    //         vec.push_back(p);
    //         vec2.push_back(p);
    //     }
    //     int total_sum;
    //     int sum = 0;
    //     total_sum = accumulate(vec.begin(), vec.end(), 0);
    //     For(i,n)
    //     {
    //         sum += vec[i];
    //         if(sum == (((i+2)*(i+1))/2))
    //         {
    //             int remain = total_sum - sum;
    //             if(remain == (((n-i-1)*(n-i))/2))
    //             {
    //                 count++;
    //                 first.push_back(i+1);
    //                 second.push_back(n-i-1);

    //             }
    //         }

    //     }
    //     int index = count;
    //     int wrong1 = 0;
    //     int wrong2 = 0;
    //     For(j,index)
    //     {
    //         vector<int>::iterator ip;
    //         ip = std::unique(vec.begin(), vec.begin() + first[j]); 
    //         vec.resize(std::distance(vec.begin(), ip)); 
    //         vector<int>::iterator ip2;
    //         ip2 = std::unique(vec2.begin() + first[j], vec2.begin() + n);
    //         vec2.resize(std::distance(vec2.begin(), ip2)); 
    //         if((vec.size() != n) || (vec2.size() != n))
    //         {
    //             count--;
    //             //int rem1 = first[j];
    //             first.erase(first.begin()+j);
    //             //int rem2 = second[j];
    //             second.erase(second.begin()+j);
    //             //wrong1 = 0;
    //             //wrong2 = 0;                
    //         }

    //     }


    //     // int index = count;
    //     // int wrong1 = 0;
    //     // int wrong2 = 0;
    //     // For(j,index)
    //     // {
    //     //     unordered_set<int> set1;
    //     //     unordered_set<int> set2;            
    //     //     For(k,first[j])
    //     //     {
    //     //         if(set1.find(vec[k]) == set1.end())
    //     //         {
    //     //             set1.insert(vec[k]);
    //     //         }
    //     //         else
    //     //         {
    //     //             //cout << first[j] << "In here" << endl;
    //     //             wrong1 = 1;
    //     //         }
    //     //     }
    //     //     for(int l = first[j]; l<n; l++)
    //     //     {
    //     //         if(set2.find(vec[l]) == set2.end())
    //     //         {
    //     //             set2.insert(vec[l]);
    //     //         }
    //     //         else
    //     //         {
    //     //             //cout << second[j] << "In here 2" << endl;
    //     //             wrong2 = 1;
    //     //         }
    //     //     }
    //     //     if(wrong1 || wrong2)
    //     //     {
    //     //         count--;
    //     //         //int rem1 = first[j];
    //     //         first.erase(first.begin()+j);
    //     //         //int rem2 = second[j];
    //     //         second.erase(second.begin()+j);
    //     //         wrong1 = 0;
    //     //         wrong2 = 0;

    //     //     }
    //     // }
    //     cout << count << endl;
    //     For(i,count)
    //     {
    //         cout << first[i] << " " << second[i] << endl;
    //     } 

	// }

}