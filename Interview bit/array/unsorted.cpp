typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef pair< long long int ,long long int > iil;
 
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( auto i = (c).begin(); i != (c).end(); i++)
 
#define edl '\n'
#define ll long long int
#define ff first
#define ss second


vector<int> Solution::subUnsort(vector<int> &A) 
{
    vector<int > fin = {-1};
    int small = -1; 
    int large = -1;
    int stag = 1;
    int flag = 1;
    int i=0;
    int j= A.size()-1;
    int total = A.size();
    for(int k = 0; k<A.size(); k++)
    {
        if(A[i]>A[i+1] && (i<A.size()-1) && stag)
        {
            small = A[i+1];
            i++;
            stag = 0;
        }
        else if(stag)
        {
            i++;
        }
        if((A[j]<A[j-1]) && (j>0) && flag)
        {
            large = A[j-1];
            j--;
            flag = 0;
        }
        else if(flag)
        {
            j--;
        }
        if((small != -1) && i<A.size()-1)
        {
            //debug(small, A[i]);
            if(small > A[i])
            {
                small = A[i];
            }
            //debug(small);
            i++;
        }
        if((large != -1) && j>-1)
        {
            //debug(large);
            large = max(large, A[j]);
            j--;
        }
        
    }
    //debug(small,large);
    if(small == -1 && large == -1)
    {
        return fin;
    }
    else
    {
        stag = 1;
        flag = 1;
        i = 0;
        j = A.size()-1;
        while(stag || flag)
        {
            if((A[i] > small) && stag)
            {
                //debug(i);
                stag = 0;
            }
            else if(stag)
            {
                i++;
            }
            if((A[j] < large) && flag)
            {
                //debug(j);
                flag = 0;
            }
            else if(flag)
            {
                j--;
            }
        }
    }
    fin.erase(fin.begin() + 0);
    fin.pb(i);
    fin.pb(j);
    return fin;
    
}

//code with more time complexity
// vector<int> Solution::subUnsort(vector<int> &A) 
// {
//     vector<int > copy;
//     vector<int > fin = {-1};
//     for(int i = 0 ; i<A.size(); i++)
//     {
//         copy.pb(A[i]);
//     }
//     sort(copy.begin(), copy.end());
//     int flag = 1;
//     int stag = 1;
//     int i = 0; 
//     int j = A.size()-1;
//     int total = A.size();
//     int start = 0;
//     int end = A.size()-1;
//     while((flag || stag) && total)
//     {
//         //debug(stag,flag);
//         if(copy[i] == A[i])
//         {
//             //debug(copy[i], A[i]);
//             copy.erase(copy.begin()+i);
//             A.erase(A.begin()+i);
//             j--;
//             total--;
//             start++;
//         }
//         else
//         {
//             flag = 0;
//         }
//         if((copy[j] == A[j]) && total)
//         {
//             //debug(copy[j], A[j]);
//             copy.erase(copy.begin()+j);
//             A.erase(A.begin()+j);
//             j--;
//             total--;
//             end--;
//         }
//         else
//         {
//             stag = 0;
//         }
//     }
//         if(total == 0)
//         {
//             return fin;
//         }
//         else
//         {
//             fin.pop_back();
//             fin.pb(start);
//             fin.pb(end);
//         }

//     return fin;
    
// }

