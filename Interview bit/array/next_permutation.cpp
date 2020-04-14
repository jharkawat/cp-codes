#define ll long long int
#define INF (2139062143)
vector<int> Solution::nextPermutation(vector<int> &A) 
{
    int pivot = 0;
    for(int i = A.size()-1; i>-1; i--)
    {
        if((ll)A[i] > (ll)A[i-1])
        {
            pivot = i-1;
            break;
        }
    }
    ll value = INF;
    int index = -1;
    for(int i = pivot; i<A.size(); i++)
    {
        if((ll)A[i]>(ll)A[pivot])
        {
            value = min(value,(ll)A[i]);
            index = i;
        }
    }
    if(index != -1)
    {
        ll swap;
        swap = (ll)A[index];
        A[index] = A[pivot];
        A[pivot] = swap;
    }
    int j = A.size()-1;
    for(int i = pivot + 1; i<pivot + 1+ ((A.size()-pivot)/2); i++)
    {
        ll swap = (ll)A[i];
        A[i] = A[j];
        A[j] = swap;
        j--;
    }
    return A;
}
