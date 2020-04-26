int Solution::findMinXor(vector<int> &A) 
{
    sort(A.begin(),A.end());
    int mi = A[0]^A[1];
    for(int i =1; i<A.size();i++)
    {
        int t = A[i]^A[i+1];
        mi = min(mi,t);
        if(mi == 0)
        {
            return mi;
        }
    }
    return mi;
}
