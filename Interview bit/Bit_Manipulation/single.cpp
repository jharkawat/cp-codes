int Solution::singleNumber(const vector<int> &A) 
{
    int x = 0;
    if(A.size() == 1)
    {
        return A[0];
    }
    x = A[0]^A[1];
    for(int i = 2; i< A.size(); i++)
    {
        x ^= A[i];
    }
    return x;
}

